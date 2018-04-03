package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanBaseType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanBaseType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanBaseType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => t \@ "category" == "basetype").map(new VulkanBaseType(registry,_)))
}
