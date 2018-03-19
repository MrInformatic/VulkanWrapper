package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanStructType(registry: Registry,node: Node) extends VulkanMemberType(registry, node) {

}

object VulkanStructType {
  def apply(registry: Registry): Map[String,VulkanStructType] =
    (registry.xml \ "types" \ "type").filter(t => Set("struct","union").contains(t \@ "category")).map(new VulkanStructType(registry,_)).map(i => (i.name,i)).toMap
}
