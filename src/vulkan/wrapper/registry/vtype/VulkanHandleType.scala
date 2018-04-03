package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

class VulkanHandleType(registry: Registry, node: Node) extends VulkanOtherType(registry,node){
  def parent: Option[VulkanOtherType] = (node \@@ "parent").flatMap(registry.handleTypes.byNameOption)
}

object VulkanHandleType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanHandleType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(_ \@ "category" == "handle").map(new VulkanHandleType(registry,_)))
}
