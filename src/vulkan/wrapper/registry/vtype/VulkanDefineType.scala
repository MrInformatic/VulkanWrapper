package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanDefineType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanDefineType {
  def apply(registry: Registry): Map[String,VulkanDefineType] =
    (registry.xml \ "types" \ "type").filter(t => t \@ "category" == "define").map(new VulkanDefineType(registry,_)).map(i => (i.name,i)).toMap
}
