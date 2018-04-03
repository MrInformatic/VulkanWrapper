package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumBitpos[+T[+X <: VulkanController] <: VulkanControll[X],+U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node) extends VulkanControlledEnumExtends(registry,vulkanControll,node) {
  def bitpos: String = node \@ "bitpos"
}

object VulkanControlledEnumBitpos {
  def apply[T[+X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node): VulkanComponentMappedData[VulkanControlledEnumBitpos[T,U]] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(n => n.attribute("bitpos").nonEmpty)
      .map(new VulkanControlledEnumBitpos[T,U](registry,vulkanControll,_)))
}
