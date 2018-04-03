package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumOffset[+T[+X <: VulkanController] <: VulkanControll[X],+U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node) extends VulkanControlledEnum(registry,vulkanControll,node) {
  val enumExtends: String = node \@ "extends"
  val offset: String = node \@ "offset"
  val extnumber: Option[String] = node \@@ "extnumber"
  val dir: Option[String] = node \@@ "dir"
}

object VulkanControlledEnumOffset {
  def apply[T[+X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node): VulkanComponentMappedData[VulkanControlledEnumOffset[T,U]] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(n => n.attribute("offset").nonEmpty)
      .map(new VulkanControlledEnumOffset[T,U](registry,vulkanControll,_)))
}
