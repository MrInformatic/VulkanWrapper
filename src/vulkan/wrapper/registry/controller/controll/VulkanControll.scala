package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controlled._

import scala.xml.Node

abstract class VulkanControll[T <: VulkanController](registry: Registry, val vulkanController: T, val node: Node) extends RegistryType(registry) {
  type This[X <: VulkanController] <: VulkanControll[X]
  def getThis: This[T]
  def getSupper: VulkanControll[T] = this
  val types: Traversable[VulkanControlledType[This,T]] = VulkanControlledType[This,T](registry,getThis,node)
  val enumValues: Traversable[VulkanControlledEnumValue[This,T]] = VulkanControlledEnumValue[This,T](registry,getThis,node)
  val enumBitposes: Traversable[VulkanControlledEnumBitpos[This,T]] = VulkanControlledEnumBitpos[This,T](registry,getThis,node)
  val enumAlias: Traversable[VulkanControlledEnumAlias[This,T]] = VulkanControlledEnumAlias[This,T](registry,getThis,node)
  val enumExtends: Traversable[VulkanControlledEnumExtends[This,T]] = VulkanControlledEnumExtends[This,T](registry,getThis,node)
  val enumPures: Traversable[VulkanControlledEnumPure[This,T]] = VulkanControlledEnumPure[This,T](registry,getThis,node)
  val commands: Traversable[VulkanControlledCommand[This,T]] = VulkanControlledCommand[This,T](registry,getThis,node)

  val enumOther: Traversable[VulkanControlledEnumOther[This,T]] = enumValues ++ enumBitposes ++ enumAlias
  val enum: Traversable[VulkanControlledEnum[This,T]] = enumOther ++ enumExtends ++ enumPures

  def controlled: Traversable[VulkanControlled[This,T]] =
    types ++
    enum ++
    commands

  def profile: Option[String] = node \@@ "profile"
  def comment: Option[String] = node \@@ "comment"
  def api: Option[String] = node \@@ "api"
}
