package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.vtype.VulkanType

import scala.xml.Node

class VulkanControlledType[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlled[T,U](registry,vulkanControll,node) {
  lazy val typeName = registry.types.byName(name)
}

object VulkanControlledType {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry,vulkanControll: T,node: Node): VulkanControlledData[VulkanControlledType[T,U],T,U,VulkanType] =
    VulkanControlledData[VulkanControlledType[T,U],T,U,VulkanType](registry,(node \ "type").map(new VulkanControlledType[T,U](registry,vulkanControll,_)),
      (i: VulkanControlledType[T,U]) => i.typeName)
}
