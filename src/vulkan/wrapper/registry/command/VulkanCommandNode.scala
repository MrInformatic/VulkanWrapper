package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.controller.{VulkanController, VulkanFeature}
import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllData, VulkanControllRequire}
import vulkan.wrapper.registry.controller.controlled.VulkanControlled
import vulkan.wrapper.registry.venum.VulkanEnumNormalEnum
import vulkan.wrapper.registry.vtype.VulkanType
import vulkan.wrapper.registry.{Registry, RegistryComponent, _}

import scala.xml.Node

class VulkanCommandNode(registry: Registry, node: Node) extends VulkanCommand(registry,node){
  override val data: VulkanCommandData = new VulkanCommandData(registry,this,node)
  override val name: String = (node \ "proto").head @\\ "name"
}

object VulkanCommandNode {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanCommandNode] =
    VulkanComponentMappedData(registry,(registry.xml \ "commands" \ "command").filter(_.attribute("alias").isEmpty).map(new VulkanCommandNode(registry,_)))
}

