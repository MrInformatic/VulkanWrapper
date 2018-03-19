package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledType(registry: Registry, vulkanControll: VulkanControll, node: Node) extends VulkanControlled(registry,vulkanControll,node) {

}

object VulkanControlledType {
  def apply(registry: Registry,vulkanControll: VulkanControll,node: Node): Traversable[VulkanControlledType] =
    (node \ "type").map(new VulkanControlledType(registry,vulkanControll,_))
}
