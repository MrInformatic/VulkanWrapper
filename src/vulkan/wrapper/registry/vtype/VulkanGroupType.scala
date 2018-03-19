package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanGroupType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanGroupType {
  def apply(registry: Registry): Map[String,VulkanGroupType] =
    (registry.xml \ "types" \ "type").filter(t => t \@ "category" == "group").map(new VulkanGroupType(registry,_)).map(i => (i.name,i)).toMap
}
