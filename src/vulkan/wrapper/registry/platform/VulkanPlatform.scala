package vulkan.wrapper.registry.platform

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanPlatform(registry: Registry, val node: Node) extends RegistryType(registry){
  val name: String = node \@ "name"
  val protect: String = node \@ "protect"
  val comment: Option[String] = node \@@ "comment"
}

object VulkanPlatform {
  def apply(registry: Registry): Map[String,VulkanPlatform] =
    (registry.xml \ "platforms" \ "platform").map(new VulkanPlatform(registry,_)).map(i => (i.name,i)).toMap
}
