package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanEnumAlias(registry: Registry, vulkanEnum: VulkanEnum, node: Node) extends VulkanEnumEnum(registry,vulkanEnum,node){
  val alias: VulkanEnumEnum = vulkanEnum.enums(node \@ "alias")
  override val value: String = alias.value
}

object VulkanEnumAlias {
  def apply(registry: Registry,vulkanEnum: VulkanEnum,node: Node): Traversable[VulkanEnumAlias] =
    (node \ "enum").filter(_.attribute("alias").nonEmpty).map(new VulkanEnumAlias(registry,vulkanEnum,_))
}
