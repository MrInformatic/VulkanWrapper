package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.venum.{VulkanEnum, VulkanEnumNormalEnum}

import scala.xml.Node

class VulkanControlledEnumAlias[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnumExtends[T,U](registry,vulkanControll,node) {
  lazy val alias: VulkanEnumNormalEnum = registry.enums.enumByName(node \@ "alias")
  override lazy val value: String = alias.value
}

object VulkanControlledEnumAlias {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry, vulkanControll: T, node: Node): VulkanControlledOptionData[VulkanControlledEnumAlias[T,U],T,U,VulkanEnum] =
    VulkanControlledOptionData[VulkanControlledEnumAlias[T,U],T,U,VulkanEnum](registry,
      (node \ "enum").filter(n => n.attribute("alias").nonEmpty).map(new VulkanControlledEnumAlias[T,U](registry,vulkanControll,_)),
      (i: VulkanControlledEnumAlias[T,U]) => i.enumExtends)
}
