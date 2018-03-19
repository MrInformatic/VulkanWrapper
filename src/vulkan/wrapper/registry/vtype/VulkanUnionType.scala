package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanUnionType(registry: Registry,node: Node) extends VulkanMemberType(registry, node)  {

}

object VulkanUnionType {
  def apply(registry: Registry): Map[String,VulkanUnionType] =
    (registry.xml \ "types" \ "type").filter(t => Set("struct","union").contains(t \@ "category")).map(new VulkanUnionType(registry,_)).map(i => (i.name,i)).toMap
}
