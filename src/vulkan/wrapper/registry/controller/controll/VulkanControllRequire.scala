package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.{VulkanController, VulkanExtension, VulkanFeature}

import scala.xml.Node

class VulkanControllRequire[+T <: VulkanController](registry: Registry, vulkanController: T, node: Node) extends VulkanControll[T](registry,vulkanController,node) {
  override type This[+X <: VulkanController] = VulkanControllRequire[X]
  override def getThis: VulkanControllRequire[T] = this

  def extension: Option[VulkanExtension] = (node \@@ "extension").flatMap(registry.extensions.byNameOption)
  def feature: Option[VulkanFeature] = (node \@@ "feature").flatMap(registry.features.byNameOption)
}

object VulkanControllRequire {
  def apply[T <: VulkanController](registry: Registry,vulkanController: T,node: Node): VulkanComponentSequentalData[VulkanControllRequire[T]] =
    VulkanComponentSequentalData(registry,(node \ "require").map(new VulkanControllRequire(registry,vulkanController,_)))
}
