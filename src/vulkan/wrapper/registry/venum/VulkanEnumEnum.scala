package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllData}
import vulkan.wrapper.registry.controller.controlled.VulkanControlled
import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

abstract class VulkanEnumEnum(registry: Registry, val vulkanEnum: VulkanEnum, node: Node) extends VulkanNamedComponent(registry,node){
  val value: String

  override val name: String = node \@ "name"
  val api: Option[String] = node \@@ "api"


}
