package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllData}
import vulkan.wrapper.registry.controller.controlled.VulkanControlled
import vulkan.wrapper.registry.{Registry, VulkanNamedComponent}

import scala.xml.Node

/**
  * Created by philipp on 10.04.18.
  */
abstract class VulkanCommand(registry: Registry,node: Node) extends VulkanNamedComponent(registry,node){
  val data: VulkanCommandData

  def typeController[T <: VulkanControll[U],U <: VulkanController](data: VulkanControllData[T,U]): Traversable[VulkanController] =
    data.commands.controllerComponents(this)

  def typeControll[T <: VulkanControll[U],U <: VulkanController](data: VulkanControllData[T,U]): Traversable[VulkanControll[U]] =
    data.commands.controllComponents(this)

  def typeControlled[T <: VulkanControll[U],U <: VulkanController](data: VulkanControllData[T,U]): Traversable[VulkanControlled[T,U]] =
    data.commands.controlledComponents(this)
}
