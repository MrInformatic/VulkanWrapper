package vulkan.wrapper.registry.tag

import vulkan.wrapper.registry.{Registry, RegistryComponent, VulkanComponentMappedData, VulkanNamedComponent}

import scala.xml.Node

class VulkanTag(registry: Registry,node: Node) extends VulkanNamedComponent(registry,node){
  override val name: String = node \@ "name"
  val author: String = node \@ "author"
  val contact: String = node \@ "contact"
}

object VulkanTag {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanTag] =
    VulkanComponentMappedData(registry,(registry.xml \ "tags" \ "tag").map(new VulkanTag(registry,_)))
}


