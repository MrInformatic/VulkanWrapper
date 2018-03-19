package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controlled._

import scala.xml.Node

class VulkanControll(registry: Registry, val vulkanController: VulkanController, val node: Node) extends RegistryType(registry) {
  val types: Traversable[VulkanControlledType] = VulkanControlledType(registry,this,node)
  val enumValues: Traversable[VulkanControlledEnumValue] = VulkanControlledEnumValue(registry,this,node)
  val enumBitposes: Traversable[VulkanControlledEnumBitpos] = VulkanControlledEnumBitpos(registry,this,node)
  val enumAlias: Traversable[VulkanControlledEnumAlias] = VulkanControlledEnumAlias(registry,this,node)
  val enumExtends: Traversable[VulkanControlledEnumExtends] = VulkanControlledEnumExtends(registry,this,node)
  val commands: Traversable[VulkanControlledCommand] = VulkanControlledCommand(registry,this,node)

  def controlled: Traversable[VulkanControlled] =
    types ++
    enumValues ++
    enumValues ++
    enumAlias ++
    enumExtends ++
    commands

  def profile: Option[String] = node \@@ "profile"
  def comment: Option[String] = node \@@ "comment"
  def api: Option[String] = node \@@ "api"
}
