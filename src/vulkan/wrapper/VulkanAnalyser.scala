package vulkan.wrapper

import org.w3c.dom.{Document, Element, Node, Attr}

/**
  * Created by philipp on 29.09.17.
  */
class VulkanAnalyser(input:Document) {
  input.getElementsByTagName("comment")
    .foreach(e => e.getParentNode().removeChild(e))

  val registry = input.getDocumentElement

  val types = registry.getChildsWithTagName("types")
    .flatMap(_.getChildsWithTagName("type"))

  printAttributes(types.filter(_.getAttribute("category") == "struct"))
  println()
  printAttributes(types.flatMap(_.getChildsWithTagName("member")))
  println()
  printAttributes(registry.getChildsWithTagName("commands")
    .flatMap(_.getChildsWithTagName("command")))
  println()
  printAttributes(registry.getChildsWithTagName("commands")
    .flatMap(_.getChildsWithTagName("command"))
    .flatMap(_.getChildsWithTagName("proto")))
  println()
  printAttributes(registry.getChildsWithTagName("commands")
    .flatMap(_.getChildsWithTagName("command"))
    .flatMap(_.getChildsWithTagName("param")))

  def printAttributes(elements:Traversable[Element]): Unit ={
    val attributes = elements
      .map(_.getAttributes)
      .flatMap(e => (0 until e.getLength)
        .map(e.item(_))
        .filter(_.getNodeType==Node.ATTRIBUTE_NODE)
        .map(e => e.asInstanceOf[Attr])
        .map(e => e.getName))
      .toSet

    attributes.foreach(println(_))
  }
}
