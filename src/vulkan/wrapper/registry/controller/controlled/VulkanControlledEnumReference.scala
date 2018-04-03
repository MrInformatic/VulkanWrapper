package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.venum.VulkanEnumEnum

import scala.xml.Node

class VulkanControlledEnumReference[+T[+X <: VulkanController] <: VulkanControll[X],+U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node) extends VulkanControlledEnumExtends(registry,vulkanControll,node) {
  lazy val enum: VulkanEnumEnum = registry.enums.enumByName(name)
}

object VulkanControlledEnumReference {
  def apply[T[+X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node): VulkanComponentMappedData[VulkanControlledEnumReference[T,U]] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(_.attributes.forall(i => Set("name","comment","api").contains(i.key)))
      .map(new VulkanControlledEnumReference[T,U](registry,vulkanControll,_)))
}
