package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumValue(registry: Registry, vulkanControll: VulkanControll, node: Node) extends VulkanControlledEnumOther(registry,vulkanControll,node) {
  def value: String = node \@ "value"
  def typeName: Option[String] = node \@@ "type"
}

object VulkanControlledEnumValue {
  def apply(registry: Registry, vulkanControll: VulkanControll, node: Node): Traversable[VulkanControlledEnumValue] =
    (node \ "enum").filter(n => n.attribute("value").nonEmpty)
      .map(new VulkanControlledEnumValue(registry,vulkanControll,_))
}
