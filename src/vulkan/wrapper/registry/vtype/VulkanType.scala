package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, RegistryType, _}

import scala.xml.Node

abstract class VulkanType(registry: Registry,val node: Node) extends RegistryType(registry){
  val name: String = node \\@ "name"
  lazy val requires: Option[VulkanType] = (node \@@ "requires").flatMap(registry.types.get)
  lazy val alias: Option[VulkanType] = (node \@@ "alias").flatMap(registry.types.get)
  val api: Option[String] = node \@@ "api"
  val comment: Option[String] = node \@@ "comment"
}


