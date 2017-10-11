package vulkan.wrapper.generator

import org.w3c.dom.Element

/**
  * Created by philipp on 04.09.17.
  */
class VulkanFuncpointer(element:Element,registry: VulkanRegistry) extends VulkanType with VulkanGenerator{
  val data = "typedef\\s+([^\\(]*)\\(\\s*VKAPI_PTR\\s+\\*PFN_vk(\\w+)\\s*\\)\\s*\\(([^)]*)\\);".r
    .findFirstMatchIn(element.getTextContent).get

  lazy val name = "PFN_vk"+data.group(2)
  lazy val improvedName = data.group(2)
  val originalReturnType = "(\\S+)".r.findAllMatchIn(data.group(1))
    .map(_.group(1))
    .mkString(" ");
  //def returnType = registry.typeConvert(originalReturnType)

  val members = data.group(3)
    .split(",")
    .map(x => "(\\S+)".r.findAllMatchIn(x).map(_.group(1)).toArray)
    .filterNot(x => x.length==1&&(x(0)=="void"||x(0)==""))
    .map(x => (x.init.mkString(" "),x.last))

  override def getCpp: String = //s"typedef std::function<$returnType(${members.map(x => registry.typeConvert(x._1)).mkString(",")})> ${improvedName}Lamda;\n" +
    s"\n"

  override def converteToCpp(inputName: String): String = ???

  override def converteToC(inputName: String): String = s"$inputName. "
}
