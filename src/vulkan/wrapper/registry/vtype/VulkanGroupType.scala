package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanGroupType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanGroupType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanGroupType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => t \@ "category" == "group").map(new VulkanGroupType(registry,_)))
}
