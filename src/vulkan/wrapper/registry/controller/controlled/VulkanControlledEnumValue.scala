package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.venum.VulkanEnum

import scala.xml.Node

class VulkanControlledEnumValue[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnumExtends[T,U](registry,vulkanControll,node) {
  override val value: String = node \@ "value"
  val typeName: Option[String] = node \@@ "type"
}

object VulkanControlledEnumValue {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry, vulkanControll: T, node: Node): VulkanControlledOptionData[VulkanControlledEnumValue[T,U],T,U,VulkanEnum] =
    VulkanControlledOptionData[VulkanControlledEnumValue[T,U],T,U,VulkanEnum](registry,
      (node \ "enum").filter(n => n.attribute("value").nonEmpty).map(new VulkanControlledEnumValue[T,U](registry,vulkanControll,_)),
      (i: VulkanControlledEnumValue[T,U]) => i.enumExtends)
}
