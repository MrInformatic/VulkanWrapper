package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanDefineType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanDefineType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanDefineType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => t \@ "category" == "define").map(new VulkanDefineType(registry,_)))
}
