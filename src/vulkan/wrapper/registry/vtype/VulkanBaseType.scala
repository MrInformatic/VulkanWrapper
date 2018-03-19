package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanBaseType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanBaseType {
  def apply(registry: Registry): Map[String,VulkanBaseType] =
    (registry.xml \ "types" \ "type").filter(t => t \@ "category" == "basetype").map(new VulkanBaseType(registry,_)).map(i => (i.name,i)).toMap
}
