package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.Registry
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledCommand(registry: Registry, vulkanControll: VulkanControll, node: Node) extends VulkanControlled(registry,vulkanControll,node) {

}

object VulkanControlledCommand {
  def apply(registry: Registry,vulkanControll: VulkanControll,node: Node): Traversable[VulkanControlledCommand] =
    (node \ "command").map(new VulkanControlledCommand(registry,vulkanControll,_))
}
