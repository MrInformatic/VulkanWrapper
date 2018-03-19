package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanFuncPointerType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanFuncPointerType {
  def apply(registry: Registry): Map[String,VulkanFuncPointerType] =
    (registry.xml \ "types" \ "type").filter(t => t \@ "category" == "funcpointer").map(new VulkanFuncPointerType(registry,_)).map(i => (i.name,i)).toMap
}
