package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlled[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, val vulkanControll: T, node: Node) extends VulkanNamedComponent(registry,node) {
  val name: String = node \@ "name"
  val comment: Option[String] = node \@@ "comment"
}
