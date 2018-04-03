package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanStructType(registry: Registry, node: Node) extends VulkanMemberType(registry, node) {

}

object VulkanStructType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanStructType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => Set("struct","union").contains(t \@ "category")).map(new VulkanStructType(registry,_)))
}
