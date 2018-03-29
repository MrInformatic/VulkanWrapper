package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry.Registry
import vulkan.wrapper.registry.controller.VulkanController

import scala.xml.Node

class VulkanControllRemove[T <: VulkanController](registry: Registry, vulkanController: T, node: Node) extends VulkanControll(registry,vulkanController,node) {
  override type This[X <: VulkanController] = VulkanControllRemove[X]
  override def getThis: VulkanControllRemove[T] = this
}

object VulkanControllRemove {
  def apply[T <: VulkanController](registry: Registry,vulkanController: T, node: Node):Traversable[VulkanControllRemove[T]] =
    (node \ "remove").map(new VulkanControllRemove[T](registry,vulkanController,_))
}
