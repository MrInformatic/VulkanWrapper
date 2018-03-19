package vulkan.wrapper.generator

import org.w3c.dom.Element

/**
  * Created by philipp on 04.09.17.
  */
class VulkanEnum(element:Element,val registy:VulkanRegistry) extends VulkanType with VulkanGenerator{
  lazy val name = element.getAttribute("name")
  lazy val improvedName = name.stripPrefix("Vk")
  val memberName = improvedName.charAt(0).toLower + improvedName.substring(1)
  var values = Array[(String,String)]();

  /*def setValues(element: Element): Unit ={
    values = nodeListToElementArray(element.getChildNodes)
      .filter(_.getTagName=="enum")
      .map(_.getAttribute("name"))
      .map(n => (n,n.split("_")
        .filterNot(registy.tags.contains(_))
        .map(s => s.charAt(0) + s.substring(1).toLowerCase)
        .filterNot(name.contains(_))
        .mkString("")))
  }*/

  override def getCpp: String = s"enum class $improvedName{\n" +
    s"  ${values.map(n => s"e${n._2} = ${n._1}").mkString(",\n  ")}\n" +
    s"};\n" +
    s"\n" +
    s"std::string toString($improvedName $memberName){\n" +
    s"  switch($memberName){\n" +
    s"    ${values.map(v => s"case $name::e${v._2} : return $g${v._2}$g;").mkString("\n    ")}\n" +
    s"    default : return ${g}invalid$g;\n" +
    s"  }\n" +
    s"}\n"

  override def converteToCpp(inputName: String): String = s"static_cast<$improvedName>($inputName)"

  override def converteToC(inputName: String): String = s"static_cast<$name>($inputName)"
}
