package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlled(registry: Registry, val vulkanControll: VulkanControll, val node: Node) {
  def name: String = node \@ "name"
  def comment: Option[String] = node \@@ "comment"
}
