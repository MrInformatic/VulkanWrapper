package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllData, VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.{Registry, RegistryComponent, VulkanComponentMappedData, VulkanComponentSequentalData, VulkanNamedComponent}

import scala.xml.Node

abstract class VulkanController(registry: Registry, node: Node) extends VulkanNamedComponent(registry,node){
  def getThis: this.type

  var requireTags: VulkanControllData[VulkanControllRequire[this.type],this.type] =
    VulkanControllRequire[this.type](registry,getThis,node)
  var removeTags: VulkanControllData[VulkanControllRemove[this.type],this.type] =
    VulkanControllRemove[this.type](registry,getThis,node)
  val controllTags: VulkanControllData[VulkanControll[this.type],this.type] =
    VulkanControllData(registry,requireTags, removeTags)
}
