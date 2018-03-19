package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

abstract class VulkanEnumEnum(registry: Registry, val vulkanEnum: VulkanEnum, val node: Node) extends RegistryType(registry){
  val value: String

  val name: String = node \@ "name"
  val api: Option[String] = node \@@ "api"
  val alias: Option[String] = node \@@ "alias"
}
