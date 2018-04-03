package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanUnionType(registry: Registry, node: Node) extends VulkanMemberType(registry, node)  {

}

object VulkanUnionType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanUnionType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => Set("struct","union").contains(t \@ "category")).map(new VulkanUnionType(registry,_)))
}
