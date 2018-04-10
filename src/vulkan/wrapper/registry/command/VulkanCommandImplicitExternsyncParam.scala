package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanCommandImplicitExternsyncParam(registry: Registry, vulkanCommand: VulkanCommandNode, node: Node) extends VulkanCommandParam(registry,vulkanCommand,node) {

}

object VulkanCommandImplicitExternsyncParam {
  def apply(registry: Registry, vulkanCommand: VulkanCommandNode, node: Node): VulkanComponentMappedData[VulkanCommandImplicitExternsyncParam] =
    VulkanComponentMappedData[VulkanCommandImplicitExternsyncParam](registry,
      (node \ "implicitexternsyncparams")
        .flatMap(i => (i \ "param").map(new VulkanCommandImplicitExternsyncParam(registry,vulkanCommand,_))))
}
