package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.Registry
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumBitpos(registry: Registry, vulkanControll: VulkanControll, node: Node) extends VulkanControlledEnumOther(registry,vulkanControll,node) {
  def bitpos: String = node \@ "bitpos"
}

object VulkanControlledEnumBitpos {
  def apply(registry: Registry, vulkanControll: VulkanControll, node: Node): Traversable[VulkanControlledEnumBitpos] =
    (node \ "enum").filter(n => n.attribute("bitpos").nonEmpty)
      .map(new VulkanControlledEnumBitpos(registry,vulkanControll,_))
}
