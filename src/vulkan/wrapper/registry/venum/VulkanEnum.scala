package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

class VulkanEnum(registry: Registry,val node: Node) extends RegistryType(registry){
  val valueEnums: Map[String,VulkanEnumValue] = VulkanEnumValue(registry,this,node)
  val bitposEnums: Map[String,VulkanEnumBitpos] = VulkanEnumBitpos(registry,this,node)
  val aliasEnums: Map[String,VulkanEnumAlias] = VulkanEnumAlias(registry,this,node)
  val enums: Map[String,VulkanEnumEnum] = valueEnums ++ bitposEnums ++ aliasEnums

  val unused: Traversable[VulkanEnumUnused] = VulkanEnumUnused(registry,this,node)
  val name: Option[String] = node \@@ "name"
  val typeName: Option[String] = node \@@ "type"
  val start: Option[String] = node \@@ "start"
  val end: Option[String] = node \@@ "end"
  val vendor: Option[String] = node \@@ "vendor"
  val comment: Option[String] = node \@@ "comment"
}

object VulkanEnum {
  def apply(registry: Registry): Traversable[VulkanEnum] =
    (registry.xml \ "enums").map(new VulkanEnum(registry,_))
}
