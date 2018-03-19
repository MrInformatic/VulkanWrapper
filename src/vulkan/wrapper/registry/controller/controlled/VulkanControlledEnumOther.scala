package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumOther(registry: Registry, vulkanControll: VulkanControll, node: Node) extends VulkanControlledEnum(registry,vulkanControll,node) {
  val enumExtends: Option[String] = node \@@ "extends"
}
