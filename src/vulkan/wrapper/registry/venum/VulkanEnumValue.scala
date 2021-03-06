package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanEnumValue(registry: Registry, vulkanEnum: VulkanEnum, node: Node) extends VulkanEnumNormalEnum(registry,vulkanEnum,node) {
  val typeName: Option[String] = node \@@ "type"
  override val value: String = node \@ "value"
}

object VulkanEnumValue {
  def apply(registry: Registry,vulkanEnum: VulkanEnum,node: Node): VulkanComponentMappedData[VulkanEnumValue] =
    VulkanComponentMappedData(registry,(node \ "enum").filter(_.attribute("value").nonEmpty).map(new VulkanEnumValue(registry,vulkanEnum,_)))
}
