package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledType[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlled[T,U](registry,vulkanControll,node) {

}

object VulkanControlledType {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry,vulkanControll: T,node: Node): VulkanComponentMappedData[VulkanControlledType[T,U]] =
    VulkanComponentMappedData(registry,(node \ "type").map(new VulkanControlledType[T,U](registry,vulkanControll,_)))
}
