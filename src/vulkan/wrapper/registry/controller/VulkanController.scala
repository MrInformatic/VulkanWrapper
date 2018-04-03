package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.{Registry, RegistryComponent, VulkanComponentMappedData, VulkanComponentSequentalData, VulkanNamedComponent}

import scala.xml.Node

abstract class VulkanController(registry: Registry, node: Node) extends VulkanNamedComponent(registry,node){
  def getThis: this.type

  var requiresTags: VulkanComponentSequentalData[VulkanControllRequire[this.type]] = VulkanControllRequire[this.type](registry,getThis,node)
  var removesTags: VulkanComponentSequentalData[VulkanControllRemove[this.type]] = VulkanControllRemove[this.type](registry,getThis,node)
  val controllTags: VulkanComponentSequentalData[VulkanControll[this.type]] =
    requiresTags ++ removesTags
}
