package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

class VulkanEnumUnused(registry: Registry, val vulkanEnum: VulkanEnum, val node: Node) extends RegistryType(registry){
  val start: String = node \@ "start"
  val end: Option[String] = node \@@ "end"
  val vendor: Option[String] = node \@@ " vendor"
  val comment: Option[String] = node \@@ "comment"
}

object VulkanEnumUnused {
  def apply(registry: Registry, vulkanEnum: VulkanEnum, node: Node): Traversable[VulkanEnumUnused] =
    (node \ "unused").map(new VulkanEnumUnused(registry,vulkanEnum,_))
}
