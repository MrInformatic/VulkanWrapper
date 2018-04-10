package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.venum.VulkanEnum

import scala.xml.Node

class VulkanControlledEnumOffset[+T <: VulkanControll[U],+U <: VulkanController](registry: Registry, vulkanControll: T, node: Node) extends VulkanControlledEnum[T,U](registry,vulkanControll,node) {
  lazy val enumExtends: VulkanEnum = registry.enums.byName(node \@ "extends")
  val offset: Int = (node \@ "offset").toInt
  val extnumber: Option[Int] = (node \@@ "extnumber").map(_.toInt)
  val dir: Boolean = (node \@@ "dir").contains("-")

  val extensionNumber: Int = extnumber.getOrElse(vulkanControll.vulkanController.extNumber)

  override val value: String = if(dir)
      (1000000000 + (extensionNumber-1)*1000 + offset).toString
    else
      (-(1000000000 + (extensionNumber-1)*1000 + offset)).toString
}

object VulkanControlledEnumOffset {
  def apply[T <: VulkanControll[U],U <: VulkanController](registry: Registry, vulkanControll: T, node: Node): VulkanControlledData[VulkanControlledEnumOffset[T,U],T,U,VulkanEnum] =
    VulkanControlledData[VulkanControlledEnumOffset[T,U],T,U,VulkanEnum](registry,
      (node \ "enum").filter(n => n.attribute("offset").nonEmpty).map(new VulkanControlledEnumOffset[T,U](registry,vulkanControll,_)),
        (i: VulkanControlledEnumOffset[T,U]) => i.enumExtends)
}
