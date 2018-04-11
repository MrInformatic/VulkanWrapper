package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.command.{VulkanCommand, VulkanCommandNode$}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controlled._
import vulkan.wrapper.registry.venum.{VulkanEnum, VulkanEnumEnum, VulkanEnumNormalEnum}
import vulkan.wrapper.registry.vtype.VulkanType

import scala.xml.Node

abstract class VulkanControll[+T <: VulkanController](registry: Registry, val vulkanController: T, node: Node) extends VulkanComponent(registry,node) {
  def getThis: this.type

  val types: VulkanControlledData[VulkanControlledType[this.type,T],this.type,T,VulkanType] =
    VulkanControlledType[this.type,T](registry,getThis,node)

  val enumValues: VulkanControlledOptionData[VulkanControlledEnumValue[this.type,T],this.type,T,VulkanEnum] =
    VulkanControlledEnumValue[this.type,T](registry,getThis,node)

  val enumBitposes: VulkanControlledOptionData[VulkanControlledEnumBitpos[this.type,T],this.type,T,VulkanEnum] =
    VulkanControlledEnumBitpos[this.type,T](registry,getThis,node)

  val enumAlias: VulkanControlledOptionData[VulkanControlledEnumAlias[this.type,T],this.type,T,VulkanEnum] =
    VulkanControlledEnumAlias[this.type,T](registry,getThis,node)

  val enumOffset: VulkanControlledData[VulkanControlledEnumOffset[this.type,T],this.type,T,VulkanEnum] =
    VulkanControlledEnumOffset[this.type,T](registry,getThis,node)

  val enumReference: VulkanControlledData[VulkanControlledEnumReference[this.type,T],this.type,T,VulkanNamedComponent with VulkanEnumEnum] =
    VulkanControlledEnumReference[this.type,T](registry,getThis,node)

  val commands: VulkanControlledData[VulkanControlledCommand[this.type,T],this.type,T,VulkanCommand] =
    VulkanControlledCommand[this.type,T](registry,getThis,node)

  val enumExtends: VulkanControlledOptionData[VulkanControlledEnumExtends[this.type,T],this.type,T,VulkanEnum] =
    VulkanControlledOptionData(registry, enumValues, enumBitposes, enumAlias)

  val enum: VulkanComponentMappedData[VulkanControlledEnum[this.type,T]] =
    VulkanComponentMappedData(registry, enumExtends, enumOffset, enumReference)

  def controlled: VulkanComponentMappedData[VulkanControlled[this.type,T]] =
    VulkanComponentMappedData(registry, types, enum, commands)

  def profile: Option[String] = node \@@ "profile"
  def comment: Option[String] = node \@@ "comment"
  def api: Option[String] = node \@@ "api"
}
