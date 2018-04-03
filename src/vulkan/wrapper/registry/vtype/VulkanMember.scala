package vulkan.wrapper.registry.vtype

import vulkan.wrapper.registry.venum.VulkanEnumEnum
import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

class VulkanMember(registry: Registry, val vulkanMemberType: VulkanMemberType, node: Node) extends VulkanNamedComponent(registry,node){
  val values: Traversable[String] = (node \@@ "values").seq.flatMap(_.split(",").seq)
  val len: Traversable[String] = (node \@@ "len").seq.flatMap(_.split(",").seq)
  val altlen: Traversable[String] = (node \@@ "altlen").seq.flatMap(_.split(",").seq)
  val clen: Traversable[String] = genClen()
  val externsync: Boolean = (node \@@ "externsync").exists(_.toBoolean)
  val optional: Boolean = (node \@@ "optional").exists(_.toBoolean)
  val noautovalidity: Boolean = (node \@@ "noautovalidity").exists(_.toBoolean)
  val typeName: Option[VulkanType] = (node \@\ "type").flatMap(registry.types.byNameOption)
  override val name: String = node @\\ "name"
  val enum: Option[VulkanEnumEnum] = (node \@\ "enum").flatMap(registry.enums.enumByNameOption)
  val comment: Option[String] = node \@\ "comment"

  private def genClen(_len: Traversable[String] = len,_altlen: Traversable[String] = altlen): Traversable[String] =
    if(len.nonEmpty)
      Traversable(if (_len.head.startsWith("latexmath:")) _altlen.head else _len.head) ++ genClen(_len.tail, if (_len.head.startsWith("latexmath:")) _altlen.tail else _altlen)
    else
      Traversable()
}

object VulkanMember {
  def apply(registry: Registry, vulkanMemberType: VulkanMemberType, node: Node): VulkanComponentMappedData[VulkanMember] =
    VulkanComponentMappedData(registry,(node \ "members").map(new VulkanMember(registry,vulkanMemberType,_)))
}
