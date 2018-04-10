package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.venum.VulkanEnum

import scala.xml.Node

class VulkanControlledEnumBitpos[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnumExtends[T,U](registry,vulkanControll,node) {
  def bitpos: Int = (node \@ "bitpos").toInt
  def bitvalue: Int = 2 ^ bitpos
  override val value: String = bitvalue.toString
}

object VulkanControlledEnumBitpos {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry, vulkanControll: T, node: Node): VulkanControlledOptionData[VulkanControlledEnumBitpos[T,U],T,U,VulkanEnum] =
    VulkanControlledOptionData[VulkanControlledEnumBitpos[T,U],T,U,VulkanEnum](registry,
      (node \ "enum").filter(n => n.attribute("bitpos").nonEmpty).map(new VulkanControlledEnumBitpos[T,U](registry,vulkanControll,_)),
      (i: VulkanControlledEnumBitpos[T,U]) => i.enumExtends)
}
