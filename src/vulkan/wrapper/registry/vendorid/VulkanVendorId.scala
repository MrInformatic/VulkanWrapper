package vulkan.wrapper.registry.vendorid

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanVendorId(registry: Registry, node: Node) extends VulkanNamedComponent(registry,node){
  override val name: String = node \@ "name"
  val id: String = node \@ "id"
  val comment: Option[String] = node \@@ "comment"
}

object VulkanVendorId {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanVendorId] =
    VulkanComponentMappedData(registry,(registry.xml \ "vendorids" \ "vendorid").map(new VulkanVendorId(registry,_)))
}
