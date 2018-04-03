package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.{Registry, RegistryComponent, VulkanComponentMappedData, VulkanComponentSequentalData, VulkanNamedComponent}

import scala.xml.Node

abstract class VulkanController(registry: Registry, node: Node) extends VulkanNamedComponent(registry,node){
  type This <: VulkanController
  def getThis: This

  var requiresTags: VulkanComponentSequentalData[VulkanControllRequire[This]] = VulkanControllRequire[This](registry,getThis,node)
  var removesTags: VulkanComponentSequentalData[VulkanControllRemove[This]] = VulkanControllRemove[This](registry,getThis,node)
  val controllTags: VulkanComponentSequentalData[VulkanControll[This]] =
    requiresTags ++ removesTags
}
