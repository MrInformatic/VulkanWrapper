package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanIncludeType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanIncludeType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanIncludeType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => t \@ "category" == "include").map(new VulkanIncludeType(registry,_)))
}
