package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.venum.VulkanEnum

import scala.xml.Node

class VulkanControlledEnumExtends[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnum[T,U](registry,vulkanControll,node) {
  lazy val enumExtends: Option[VulkanEnum] = (node \@@ "extends").flatMap(registry.enums.byNameOption)
}
