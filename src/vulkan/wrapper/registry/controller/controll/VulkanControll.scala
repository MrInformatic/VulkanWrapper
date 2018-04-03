package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controlled._

import scala.xml.Node

abstract class VulkanControll[+T <: VulkanController](registry: Registry, val vulkanController: T, node: Node) extends VulkanComponent(registry,node) {
  type This[X <: VulkanController] <: VulkanControll[X]
  def getThis: This[T]
  def getSupper: VulkanControll[T] = this
  val types: VulkanComponentMappedData[VulkanControlledType[This,T]] = VulkanControlledType[This,T](registry,getThis,node)
  val enumValues: VulkanComponentMappedData[VulkanControlledEnumValue[This,T]] = VulkanControlledEnumValue[This,T](registry,getThis,node)
  val enumBitposes: VulkanComponentMappedData[VulkanControlledEnumBitpos[This,T]] = VulkanControlledEnumBitpos[This,T](registry,getThis,node)
  val enumAlias: VulkanComponentMappedData[VulkanControlledEnumAlias[This,T]] = VulkanControlledEnumAlias[This,T](registry,getThis,node)
  val enumOffset: VulkanComponentMappedData[VulkanControlledEnumOffset[This,T]] = VulkanControlledEnumOffset[This,T](registry,getThis,node)
  val enumReference: VulkanComponentMappedData[VulkanControlledEnumReference[This,T]] = VulkanControlledEnumReference[This,T](registry,getThis,node)
  val commands: VulkanComponentMappedData[VulkanControlledCommand[This,T]] = VulkanControlledCommand[This,T](registry,getThis,node)

  val enumExtends: VulkanComponentMappedData[VulkanControlledEnumExtends[This,T]] =
    enumValues ++ enumBitposes ++ enumAlias

  val enum: VulkanComponentMappedData[VulkanControlledEnum[This,T]] =
    enumExtends ++ enumOffset ++ enumReference

  def controlled: VulkanComponentMappedData[VulkanControlled[This,T]] =
    types ++ enum ++ commands

  def profile: Option[String] = node \@@ "profile"
  def comment: Option[String] = node \@@ "comment"
  def api: Option[String] = node \@@ "api"
}
