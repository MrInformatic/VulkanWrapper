package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.{Registry, VulkanNamedComponent}

import scala.xml.Node

/**
  * Created by philipp on 10.04.18.
  */
abstract class VulkanCommand(registry: Registry,node: Node) extends VulkanNamedComponent(registry,node){
  val command: VulkanCommandNode
}
