package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanEnumType(registry: Registry,node: Node) extends VulkanType(registry,node) {

}

object VulkanEnumType {
  def apply(registry: Registry): Map[String,VulkanEnumType] =
    (registry.xml \ "types" \ "type").filter(t => t \@ "category" == "enum").map(new VulkanEnumType(registry,_)).map(i => (i.name,i)).toMap
}
