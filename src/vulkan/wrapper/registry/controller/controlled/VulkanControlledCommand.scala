package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledCommand[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlled[T,U](registry,vulkanControll,node) {
  lazy val command = registry.commands(name)
}

object VulkanControlledCommand {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry,vulkanControll: T,node: Node): VulkanComponentMappedData[VulkanControlledCommand[T,U]] =
    VulkanComponentMappedData(registry,(node \ "command").map(new VulkanControlledCommand[T,U](registry,vulkanControll,_)))
}
