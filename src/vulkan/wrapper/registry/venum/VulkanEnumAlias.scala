package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanEnumAlias(registry: Registry, vulkanEnum: VulkanEnum, node: Node) extends VulkanEnumEnum(registry,vulkanEnum,node){
  lazy val alias: VulkanEnumEnum = vulkanEnum.enums(node \@ "alias")
  lazy val value: String = alias.value
}

object VulkanEnumAlias {
  def apply(registry: Registry,vulkanEnum: VulkanEnum,node: Node): VulkanComponentMappedData[VulkanEnumAlias] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(_.attribute("alias").nonEmpty).map(new VulkanEnumAlias(registry,vulkanEnum,_)))
}
