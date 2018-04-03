package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumValue[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnumExtends[T,U](registry,vulkanControll,node) {
  def value: String = node \@ "value"
  def typeName: Option[String] = node \@@ "type"
}

object VulkanControlledEnumValue {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry, vulkanControll: T, node: Node): VulkanComponentMappedData[VulkanControlledEnumValue[T,U]] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(n => n.attribute("value").nonEmpty)
      .map(new VulkanControlledEnumValue[T,U](registry,vulkanControll,_)))
}
