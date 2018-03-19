package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanPrimitiveType(registry: Registry,node: Node) extends VulkanType(registry,node) {

}

object VulkanPrimitiveType {
  def apply(registry: Registry): Map[String,VulkanPrimitiveType] =
    (registry.xml \ "types" \ "type").filter(t => t \@ "category" == "enum").map(new VulkanPrimitiveType(registry,_)).map(i => (i.name,i)).toMap
}
