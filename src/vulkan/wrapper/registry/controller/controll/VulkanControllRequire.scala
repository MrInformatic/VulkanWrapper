package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController

import scala.xml.Node

class VulkanControllRequire[T <: VulkanController](registry: Registry, vulkanController: T, node: Node) extends VulkanControll[T](registry,vulkanController,node) {
  override type This[X <: VulkanController] = VulkanControllRequire[X]
  override def getThis: VulkanControllRequire[T] = this

  def extension: Option[String] = node \@@ "extension"
  def feature: Option[String] = node \@@ "feature"
}

object VulkanControllRequire {
  def apply[T <: VulkanController](registry: Registry,vulkanController: T,node: Node): Traversable[VulkanControllRequire[T]] =
    (node \ "require").map(new VulkanControllRequire(registry,vulkanController,_))
}
