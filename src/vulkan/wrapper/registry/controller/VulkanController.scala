package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry.controller.controll.{VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.{Registry, RegistryType}

import scala.xml.Node

class VulkanController(registry: Registry, val node: Node) extends RegistryType(registry){
  var requiresTags: Traversable[VulkanControllRequire] = VulkanControllRequire(registry,this,node)
  var removesTags: Traversable[VulkanControllRemove] = VulkanControllRemove(registry,this,node)
}
