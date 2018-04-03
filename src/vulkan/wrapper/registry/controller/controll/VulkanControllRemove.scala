package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry.{Registry, VulkanComponentSequentalData}
import vulkan.wrapper.registry.controller.VulkanController

import scala.xml.Node

class VulkanControllRemove[+T <: VulkanController](registry: Registry, vulkanController: T, node: Node) extends VulkanControll[T](registry,vulkanController,node) {
  override def getThis: this.type = this
}

object VulkanControllRemove {
  def apply[T <: VulkanController](registry: Registry,vulkanController: T, node: Node):VulkanComponentSequentalData[VulkanControllRemove[T]] =
    VulkanComponentSequentalData(registry,(node \ "remove").map(new VulkanControllRemove[T](registry,vulkanController,_)))
}
