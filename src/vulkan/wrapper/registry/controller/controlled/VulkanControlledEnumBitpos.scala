package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumBitpos[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnumExtends[T,U](registry,vulkanControll,node) {
  def bitpos: String = node \@ "bitpos"
}

object VulkanControlledEnumBitpos {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry, vulkanControll: T, node: Node): VulkanComponentMappedData[VulkanControlledEnumBitpos[T,U]] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(n => n.attribute("bitpos").nonEmpty)
      .map(new VulkanControlledEnumBitpos[T,U](registry,vulkanControll,_)))
}
