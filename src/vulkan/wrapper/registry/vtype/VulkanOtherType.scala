package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

abstract class VulkanOtherType(registry: Registry, node: Node) extends VulkanType(registry,node){
  def code: String = node.text
  def types: Traversable[VulkanType] = (node \ "type").map(_.text).flatMap(registry.types.byNameOption)
  def apientrys: Traversable[String] = (node \ "apientry").map(_.text)
}
