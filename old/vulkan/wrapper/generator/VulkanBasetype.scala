package vulkan.wrapper.generator

import org.w3c.dom.Element

/**
  * Created by philipp on 04.09.17.
  */
class VulkanBasetype(element:Element,registry:VulkanRegistry) extends VulkanCastableType with VulkanGenerator{
  lazy val name: String = element.getElementsByTagName("name").item(0).getTextContent
  lazy val improvedName: String = name.stripPrefix("Vk")

  override def getCpp: String = s"typedef $name $improvedName"
}
