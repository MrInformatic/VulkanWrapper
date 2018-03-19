package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

class VulkanHandleType(registry: Registry,node: Node) extends VulkanOtherType(registry,node){
  def parent: Option[String] = node \@@ "parent"
}

object VulkanHandleType {
  def apply(registry: Registry): Map[String,VulkanHandleType] =
    (registry.xml \ "types" \ "type").filter(_ \@ "category" == "handle").map(new VulkanHandleType(registry,_)).map(i => (i.name,i)).toMap
}
