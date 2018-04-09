package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllData}
import vulkan.wrapper.registry.controller.controlled.VulkanControlled
import vulkan.wrapper.registry.{Registry, RegistryComponent, _}

import scala.xml.Node

abstract class VulkanType(registry: Registry, node: Node) extends VulkanNamedComponent(registry,node){
  override val name: String = node \\@ "name"
  lazy val requires: Option[VulkanType] = (node \@@ "requires").flatMap(registry.types.byNameOption)
  lazy val alias: Option[VulkanType] = (node \@@ "alias").flatMap(registry.types.byNameOption)
  val api: Option[String] = node \@@ "api"
  val comment: Option[String] = node \@@ "comment"

  def typeController[T <: VulkanControll[U],U <: VulkanController](data: VulkanControllData[T,U]): Traversable[VulkanController] =
    data.types.controllerComponents(this)

  def typeControll[T <: VulkanControll[U],U <: VulkanController](data: VulkanControllData[T,U]): Traversable[VulkanControll[U]] =
    data.types.controllComponents(this)

  def typeControlled[T <: VulkanControll[U],U <: VulkanController](data: VulkanControllData[T,U]): Traversable[VulkanControlled[T,U]] =
    data.types.controlledComponents(this)
}


