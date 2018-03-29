package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.Registry
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumAlias[T[X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node) extends VulkanControlledEnumOther(registry,vulkanControll,node) {
  val alias: String = node \@ "alias"
}

object VulkanControlledEnumAlias {
  def apply[T[X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node): Traversable[VulkanControlledEnumAlias[T,U]] =
    (node \ "enum").filter(n => n.attribute("alias").nonEmpty)
      .map(new VulkanControlledEnumAlias[T,U](registry,vulkanControll,_))
}
