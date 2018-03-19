package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanIncludeType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanIncludeType {
  def apply(registry: Registry): Map[String,VulkanIncludeType] =
    (registry.xml \ "types" \ "type").filter(t => t \@ "category" == "include").map(new VulkanIncludeType(registry,_)).map(i => (i.name,i)).toMap
}
