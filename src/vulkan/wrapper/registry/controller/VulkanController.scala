package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.{Registry, RegistryType}

import scala.xml.Node

abstract class VulkanController(registry: Registry, val node: Node) extends RegistryType(registry){
  type This <: VulkanController
  def getThis: This

  var requiresTags: Traversable[VulkanControllRequire[This]] = VulkanControllRequire[This](registry,getThis,node)
  var removesTags: Traversable[VulkanControllRemove[This]] = VulkanControllRemove[This](registry,getThis,node)
  val controllTags: Traversable[VulkanControll[This]] = requiresTags ++ removesTags
}
