package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumExtends[T[X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node) extends VulkanControlledEnum(registry,vulkanControll,node) {
  val enumExtends: String = node \@ "extends"
  val offset: String = node \@ "offset"
  val extnumber: Option[String] = node \@@ "extnumber"
  val dir: Option[String] = node \@@ "dir"
}

object VulkanControlledEnumExtends {
  def apply[T[X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node): Traversable[VulkanControlledEnumExtends[T,U]] =
    (node \ "enum").filter(n => n.attribute("offset").nonEmpty)
      .map(new VulkanControlledEnumExtends[T,U](registry,vulkanControll,_))
}
