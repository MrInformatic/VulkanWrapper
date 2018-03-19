package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

class VulkanMember(registry: Registry, val vulkanMemberType: VulkanMemberType, val node: Node) extends RegistryType(registry){
  val values: Option[String] = node \@@ "values"
  val len: Option[String] = node \@@ "len"
  val altlen: Option[String] = node \@@ "altlen"
  val externsync: Option[String] = node \@@ "externsync"
  val optional: Option[String] = node \@@ "optional"
  val noautovalidity: Option[String] = node \@@ "noautovalidity"
  val typeName: Option[String] = node \@\ "type"
  val name: String = node @\\ "name"
  val enum: Option[String] = node \@\ "enum"
  val comment: Option[String] = node \@\ "comment"
}

object VulkanMember {
  def apply(registry: Registry, vulkanMemberType: VulkanMemberType, node: Node): Traversable[VulkanMember] =
    (node \ "members").map(new VulkanMember(registry,vulkanMemberType,_))
}
