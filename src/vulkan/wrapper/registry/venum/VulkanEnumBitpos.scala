package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.Registry

import scala.xml.Node

class VulkanEnumBitpos(registry: Registry, vulkanEnum: VulkanEnum, node: Node) extends VulkanEnumEnum(registry,vulkanEnum,node) {
  val bitpos: Int = (node \@ "bitpos").toInt
  val bitValue: Int = 2 ^ bitpos
  override val value: String = bitValue.toString
}

object VulkanEnumBitpos {
  def apply(registry: Registry,vulkanEnum: VulkanEnum,node: Node): Traversable[VulkanEnumBitpos] =
    (node \ "enum").filter(_.attribute("bitpos").nonEmpty).map(new VulkanEnumBitpos(registry,vulkanEnum,_))
}

