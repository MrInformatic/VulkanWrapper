package vulkan.wrapper.generator

import org.w3c.dom.Element

/**
  * Created by philipp on 31.08.17.
  */
class VulkanRegistry(element:Element) extends VulkanGenerator{
  /*val elements = nodeListToElementArray(element.getChildNodes)

  val typeElements = elements.filter(_.getTagName=="types")
    .flatMap(e => nodeListToElementArray(e.getChildNodes).filter(_.getTagName=="type"))
    .filter(_.hasAttribute("category"))

  val tags = elements.filter(_.getTagName=="tags")
    .flatMap(e => nodeListToElementArray(e.getChildNodes).filter(_.getTagName=="tag")
      .map(_.getAttribute("name")))
    .toSet

  val enums = typeElements
    .filter(_.getAttribute("category") == "enum")
    .map(new VulkanEnum(_,this))
    .map(enum => (enum.name,enum))
    .toMap

  val bitmasks = typeElements
    .filter(_.getAttribute("category") == "bitmask")
    .map(new VulkanBitEnum(_,this))
    .map(bitmask => (bitmask.name,bitmask))
    .toMap

  val enumElements = elements.filter(_.getTagName=="enums")

  enumElements
    .filter(_.getAttribute("type") == "enum")
    .foreach(e => enums(e.getAttribute("name")).setValues(e))

  enumElements
    .filter(_.getAttribute("type") == "bitmask")
    .foreach(e => bitmasks(e.getAttribute("name")).setValues(e))

  //TODO: All Bitmasks

  val handles = typeElements
    .filter(_.getAttribute("category")=="handle")
    .map(new VulkanHandle(_,this))
    .map(handle => (handle.name,handle))
    .toMap

  val basetypes = typeElements
    .filter(_.getAttribute("category")=="basetype")
    .map(new VulkanBasetype(_,this))
    .map(basetype => (basetype.name,basetype))
    .toMap

  val types = handles ++ enums ++ bitmasks ++ bitmasks.map(b => (b._2.bitmask.name,b._2.bitmask)) ++ basetypes

  val commandElements = elements.filter(_.getTagName == "commands")
    .flatMap(e => nodeListToElementArray(e.getChildNodes).filter(_.getTagName == "command"))

  val funcpointers = typeElements
    .filter(_.getAttribute("category")=="funcpointer")
    .map(new VulkanFuncpointer(_,this))
    .map(funcpointer => (funcpointer.name,funcpointer))
    .toMap

  /*commandElements
    .map(e => (nodeListToElementArray(e.getChildNodes).filter(_.getTagName == "proto")
        .map(i => i.getElementsByTagName("name").item(0).getTextContent),
      nodeListToElementArray(e.getChildNodes).filter(_.getTagName == "param")
        .map(i => i.getElementsByTagName("type").item(0).getTextContent)
        .takeWhile(handles.contains(_))))
    .filter(e => e._2.size==0)
    .foreach(e => println(e._1.mkString(","),e._2.mkString(",")))*/

  def typeConvert(typeName:String):String =
    if(types.contains(typeName))
      types(typeName).improvedName
    else {
      val data = "\\s*(?:(const)\\s+)?(\\w+)\\s*\\*([\\S\\s]*)".r.findFirstMatchIn(typeName)
      if (data.nonEmpty)
        if(data.get.group(2)=="char")
          typeConvert("std::string" + data.get.group(3))
        else
          if(data.get.group(1)=="const")
            typeConvert(s"std::vector<${typeConvert(data.get.group(2))}>" + data.get.group(3));
          else
            typeConvert(s"std::unique_ptr<${typeConvert(data.get.group(2))}>" + data.get.group(3));
      else
        typeName
    }

  def converterToCpp(typeName:String): String ={
    ""
  }

  def converterToC(typeName:String): String ={
    ""
  }
  def converterToCCopy(typeName:String): String ={
    ""
  }*/

  override def getCpp: String = s"namespace vulkan{\n" +
    //s"  ${enums.map(_._2.getCpp).mkString("\n\n").replaceAll("\n","\n  ")}\n" +
    s"  \n" +
    //s"  ${bitmasks.map(_._2.getCpp).mkString("\n\n").replaceAll("\n","\n  ")}\n" +
    s"  \n" +
    //s"  ${bitmasks.map(_._2.bitmask.getCpp).mkString("\n\n").replaceAll("\n","\n  ")}\n" +
    s"  \n" +
    //s"  ${handles.map(_._2.getCpp).mkString("\n\n").replaceAll("\n","\n  ")}\n" +
    s"  \n" +
    //s"  ${funcpointers.map(_._2.getCpp).mkString("\n\n").replaceAll("\n","\n  ")}\n" +
    s"}"
}
