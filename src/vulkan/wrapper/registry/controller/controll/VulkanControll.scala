package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controlled._

import scala.xml.Node

abstract class VulkanControll[+T <: VulkanController](registry: Registry, val vulkanController: T, node: Node) extends VulkanComponent(registry,node) {
  def getThis: this.type
  val types: VulkanComponentMappedData[VulkanControlledType[this.type,T]] = VulkanControlledType[this.type,T](registry,getThis,node)
  val enumValues: VulkanComponentMappedData[VulkanControlledEnumValue[this.type,T]] = VulkanControlledEnumValue[this.type,T](registry,getThis,node)
  val enumBitposes: VulkanComponentMappedData[VulkanControlledEnumBitpos[this.type,T]] = VulkanControlledEnumBitpos[this.type,T](registry,getThis,node)
  val enumAlias: VulkanComponentMappedData[VulkanControlledEnumAlias[this.type,T]] = VulkanControlledEnumAlias[this.type,T](registry,getThis,node)
  val enumOffset: VulkanComponentMappedData[VulkanControlledEnumOffset[this.type,T]] = VulkanControlledEnumOffset[this.type,T](registry,getThis,node)
  val enumReference: VulkanComponentMappedData[VulkanControlledEnumReference[this.type,T]] = VulkanControlledEnumReference[this.type,T](registry,getThis,node)
  val commands: VulkanComponentMappedData[VulkanControlledCommand[this.type,T]] = VulkanControlledCommand[this.type,T](registry,getThis,node)

  val enumExtends: VulkanComponentMappedData[VulkanControlledEnumExtends[this.type,T]] =
    enumValues ++ enumBitposes ++ enumAlias

  val enum: VulkanComponentMappedData[VulkanControlledEnum[this.type,T]] =
    enumExtends ++ enumOffset ++ enumReference

  def controlled: VulkanComponentMappedData[VulkanControlled[this.type,T]] =
    types ++ enum ++ commands

  def profile: Option[String] = node \@@ "profile"
  def comment: Option[String] = node \@@ "comment"
  def api: Option[String] = node \@@ "api"
}
