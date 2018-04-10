package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.controller.controlled.VulkanControlledCommand
import vulkan.wrapper.registry.{Registry, RegistryComponent, VulkanComponentMappedData, VulkanNamedComponent}

import scala.xml.Node

class VulkanCommandAlias(registry: Registry, node: Node) extends VulkanCommand(registry,node){
  override val name: String = node \@ "name"
  override lazy val command: VulkanCommandNode = registry.commandsNode(node \@ "alias")
}

object VulkanCommandAlias {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanCommandAlias] =
    VulkanComponentMappedData(registry,(registry.xml \ "commands" \ "command").filter(_.attribute("alias").nonEmpty).map(new VulkanCommandAlias(registry,_)))
}


