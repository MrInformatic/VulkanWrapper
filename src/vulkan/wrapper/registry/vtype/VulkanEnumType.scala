package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.venum.VulkanEnum
import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanEnumType(registry: Registry, node: Node) extends VulkanType(registry,node) {
  lazy val enum: VulkanEnum = registry.enums.byName(name)
}

object VulkanEnumType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanEnumType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => t \@ "category" == "enum").map(new VulkanEnumType(registry,_)))
}
