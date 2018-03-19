package vulkan.wrapper.registry.vendorid

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanVendorId(registry: Registry,val node: Node) extends RegistryType(registry){
  val name: String = node \@ "name"
  val id: String = node \@ "id"
  val comment: Option[String] = node \@@ "comment"
}

object VulkanVendorId {
  def apply(registry: Registry): Map[String,VulkanVendorId] =
    (registry.xml \ "vendorids" \ "vendorid").map(new VulkanVendorId(registry,_)).map(i => (i.name,i)).toMap
}
