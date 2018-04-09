package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry.{Registry, VulkanComponentSequentalData}
import vulkan.wrapper.registry.controller.VulkanController

import scala.xml.Node

class VulkanControllRemove[+T <: VulkanController](registry: Registry, vulkanController: T, node: Node) extends VulkanControll[T](registry,vulkanController,node) {
  override def getThis: this.type = this
}

object VulkanControllRemove {
  def apply[T <: VulkanController](registry: Registry,vulkanController: T, node: Node):VulkanControllData[VulkanControllRemove[T],T] =
    VulkanControllData[VulkanControllRemove[T],T](registry,(node \ "remove").map(new VulkanControllRemove[T](registry,vulkanController,_)))
}
