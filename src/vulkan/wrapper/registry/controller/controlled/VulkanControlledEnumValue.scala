package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumValue[T[X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node) extends VulkanControlledEnumOther(registry,vulkanControll,node) {
  def value: String = node \@ "value"
  def typeName: Option[String] = node \@@ "type"
}

object VulkanControlledEnumValue {
  def apply[T[X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node): Traversable[VulkanControlledEnumValue[T,U]] =
    (node \ "enum").filter(n => n.attribute("value").nonEmpty)
      .map(new VulkanControlledEnumValue[T,U](registry,vulkanControll,_))
}
