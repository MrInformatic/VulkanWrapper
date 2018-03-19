package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnum(registry: Registry, vulkanControll: VulkanControll, node: Node) extends VulkanControlled(registry,vulkanControll,node) {
  val api: Option[String] = node \@@ "api"
}
