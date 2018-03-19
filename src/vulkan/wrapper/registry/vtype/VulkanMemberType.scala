package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanMemberType(registry: Registry,node: Node) extends VulkanType(registry, node){
  val members = VulkanMember(registry, this,node)
  def returnedonly: Option[String] = node \@@ "returnedonly"
  def structextends: Traversable[String] = (node \@@ "structextends").flatMap(_.split(",").seq)
}
