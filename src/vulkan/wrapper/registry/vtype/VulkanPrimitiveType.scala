package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanPrimitiveType(registry: Registry, node: Node) extends VulkanType(registry,node) {

}

object VulkanPrimitiveType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanPrimitiveType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => t \@ "category" == "enum").map(new VulkanPrimitiveType(registry,_)))
}
