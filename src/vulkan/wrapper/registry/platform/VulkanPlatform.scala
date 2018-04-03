package vulkan.wrapper.registry.platform

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanPlatform(registry: Registry, node: Node) extends VulkanNamedComponent(registry,node){
  override val name: String = node \@ "name"
  val protect: String = node \@ "protect"
  val comment: Option[String] = node \@@ "comment"
}

object VulkanPlatform {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanPlatform] =
    VulkanComponentMappedData(registry,(registry.xml \ "platforms" \ "platform").map(new VulkanPlatform(registry,_)))
}
