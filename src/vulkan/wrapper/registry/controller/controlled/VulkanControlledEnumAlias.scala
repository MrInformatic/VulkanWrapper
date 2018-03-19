package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.Registry
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumAlias(registry: Registry, vulkanControll: VulkanControll, node: Node) extends VulkanControlledEnumOther(registry,vulkanControll,node) {
  val alias: String = node \@ "alias"
}

object VulkanControlledEnumAlias {
  def apply(registry: Registry, vulkanControll: VulkanControll, node: Node): Traversable[VulkanControlledEnumAlias] =
    (node \ "enum").filter(n => n.attribute("alias").nonEmpty)
      .map(new VulkanControlledEnumAlias(registry,vulkanControll,_))
}
