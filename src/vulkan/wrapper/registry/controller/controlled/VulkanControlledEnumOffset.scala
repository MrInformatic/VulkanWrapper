package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.venum.VulkanEnum

import scala.xml.Node

class VulkanControlledEnumOffset[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnum[T,U](registry,vulkanControll,node) {
  lazy val enumExtends: VulkanEnum = registry.enums.byName(node \@ "extends")
  val offset: String = node \@ "offset"
  val extnumber: Option[String] = node \@@ "extnumber"
  val dir: Option[String] = node \@@ "dir"
}

object VulkanControlledEnumOffset {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry, vulkanControll: T, node: Node): VulkanControlledData[VulkanControlledEnumOffset[T,U],T,U,VulkanEnum] =
    VulkanControlledData[VulkanControlledEnumOffset[T,U],T,U,VulkanEnum](registry,
      (node \ "enum").filter(n => n.attribute("offset").nonEmpty).map(new VulkanControlledEnumOffset[T,U](registry,vulkanControll,_)),
        (i: VulkanControlledEnumOffset[T,U]) => i.enumExtends)
}
