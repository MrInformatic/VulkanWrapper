package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumAlias[+T[+X <: VulkanController] <: VulkanControll[X],+U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node) extends VulkanControlledEnumExtends(registry,vulkanControll,node) {
  val alias: String = node \@ "alias"
}

object VulkanControlledEnumAlias {
  def apply[T[+X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node): VulkanComponentMappedData[VulkanControlledEnumAlias[T,U]] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(n => n.attribute("alias").nonEmpty)
      .map(new VulkanControlledEnumAlias[T,U](registry,vulkanControll,_)))
}
