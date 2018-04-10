package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

import scala.xml.Node

class VulkanEnumBitpos(registry: Registry, vulkanEnum: VulkanEnum, node: Node) extends VulkanEnumNormalEnum(registry,vulkanEnum,node) {
  val bitpos: Int = (node \@ "bitpos").toInt
  val bitValue: Int = 2 ^ bitpos
  override val value: String = bitValue.toString
}

object VulkanEnumBitpos {
  def apply(registry: Registry,vulkanEnum: VulkanEnum,node: Node): VulkanComponentMappedData[VulkanEnumBitpos] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(_.attribute("bitpos").nonEmpty).map(new VulkanEnumBitpos(registry,vulkanEnum,_)))
}


