package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanOtherType(registry: Registry, node: Node) extends VulkanType(registry,node){
  def code: String = node.text
  def types: Traversable[String] = (node \ "type").map(_.text)
  def apientrys: Traversable[String] = (node \ "apientry").map(_.text)
}
