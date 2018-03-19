package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController

import scala.xml.Node

class VulkanControllRequire(registry: Registry, vulkanController: VulkanController, node: Node) extends VulkanControll(registry,vulkanController,node) {
  def extension: Option[String] = node \@@ "extension"
  def feature: Option[String] = node \@@ "feature"
}

object VulkanControllRequire {
  def apply(registry: Registry,vulkanController: VulkanController,node: Node): Traversable[VulkanControllRequire] =
    (node \ "require").map(new VulkanControllRequire(registry,vulkanController,_))
}
