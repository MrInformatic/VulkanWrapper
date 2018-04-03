package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanMemberType(registry: Registry, node: Node) extends VulkanType(registry, node){
  val members = VulkanMember(registry, this,node)
  def returnedonly: Boolean = (node \@@ "returnedonly").exists(_.toBoolean)
  def structextends: Traversable[VulkanStructType] = (node \@@ "structextends").seq.flatMap(_.split(",").seq).flatMap(registry.structTypes.byNameOption)
}
