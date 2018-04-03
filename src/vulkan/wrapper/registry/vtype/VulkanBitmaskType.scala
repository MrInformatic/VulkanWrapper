package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanBitmaskType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanBitmaskType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanBitmaskType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => t \@ "category" == "bitmask").map(new VulkanBitmaskType(registry,_)))
}
