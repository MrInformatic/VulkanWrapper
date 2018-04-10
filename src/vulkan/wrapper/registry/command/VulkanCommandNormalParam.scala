package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanCommandNormalParam(registry: Registry, vulkanCommand: VulkanCommandNode, node: Node) extends VulkanCommandParam(registry,vulkanCommand,node) {

}

object VulkanCommandNormalParam {
  def apply(registry: Registry, vulkanCommand: VulkanCommandNode, node: Node): VulkanComponentMappedData[VulkanCommandNormalParam] =
    VulkanComponentMappedData(registry,(node \ "param").map(new VulkanCommandNormalParam(registry,vulkanCommand,_)))
}
