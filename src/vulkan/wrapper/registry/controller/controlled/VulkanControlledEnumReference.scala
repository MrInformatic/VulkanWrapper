package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData, VulkanNamedComponent}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.venum.{VulkanEnumEnum, VulkanEnumNormalEnum}

import scala.xml.Node

class VulkanControlledEnumReference[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnumExtends[T,U](registry,vulkanControll,node) {
  lazy val enum: VulkanEnumNormalEnum = registry.enums.normalEnum.byName(name)
  override lazy val value: String = enum.value
}

object VulkanControlledEnumReference {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry, vulkanControll: T, node: Node): VulkanControlledData[VulkanControlledEnumReference[T,U],T,U,VulkanNamedComponent with VulkanEnumEnum] =
    VulkanControlledData[VulkanControlledEnumReference[T,U],T,U,VulkanNamedComponent with VulkanEnumEnum](registry,
      (node \ "enum").filter(_.attributes.forall(i => Set("name","comment","api").contains(i.key)))
        .map(new VulkanControlledEnumReference[T,U](registry,vulkanControll,_)),
          (i: VulkanControlledEnumReference[T,U]) => i.enum)
}
