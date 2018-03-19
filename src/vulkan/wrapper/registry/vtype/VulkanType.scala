package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, RegistryType, _}

import scala.xml.Node

class VulkanType(registry: Registry,val node: Node) extends RegistryType(registry){
  val name: String = node \\@ "name"
  val requires: Option[String] = node \@@ "requires"
  val alias: Option[String] = node \@@ "alias"
  val api: Option[String] = node \@@ "api"
  val comment: Option[String] = node \@@ "comment"
}


