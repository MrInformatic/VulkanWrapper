package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumExtends(registry: Registry, vulkanControll: VulkanControll, node: Node) extends VulkanControlledEnum(registry,vulkanControll,node) {
  val enumExtends: String = node \@ "extends"
  val offset: String = node \@ "offset"
  val extnumber: Option[String] = node \@@ "extnumber"
  val dir: Option[String] = node \@@ "dir"
}

object VulkanControlledEnumExtends {
  def apply(registry: Registry, vulkanControll: VulkanControll, node: Node): Traversable[VulkanControlledEnumExtends] =
    (node \ "enum").filter(n => n.attribute("offset").nonEmpty)
      .map(new VulkanControlledEnumExtends(registry,vulkanControll,_))
}
