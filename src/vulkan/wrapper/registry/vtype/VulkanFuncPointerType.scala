package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanFuncPointerType(registry: Registry, node: Node) extends VulkanOtherType(registry,node) {

}

object VulkanFuncPointerType {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanFuncPointerType] =
    VulkanComponentMappedData(registry,(registry.xml \ "types" \ "type").filter(t => t \@ "category" == "funcpointer").map(new VulkanFuncPointerType(registry,_)))
}
