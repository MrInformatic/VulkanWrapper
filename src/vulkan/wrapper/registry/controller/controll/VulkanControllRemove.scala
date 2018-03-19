package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry.Registry
import vulkan.wrapper.registry.controller.VulkanController

import scala.xml.Node

class VulkanControllRemove(registry: Registry, vulkanController: VulkanController, node: Node) extends VulkanControll(registry,vulkanController,node) {

}

object VulkanControllRemove {
  def apply(registry: Registry,vulkanController: VulkanController, node: Node) =
    (node \ "remove").map(new VulkanControllRemove(registry,vulkanController,_))
}
