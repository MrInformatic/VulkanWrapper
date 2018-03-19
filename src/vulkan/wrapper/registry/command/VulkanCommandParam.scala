package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.vtype.VulkanType
import vulkan.wrapper.registry.{Registry, RegistryType, _}

import scala.xml.Node

class VulkanCommandParam(registry: Registry,val vulkanCommand: VulkanCommand,val node: Node,val implicitexternsyncparams:Boolean) extends RegistryType(registry){
  val len: Option[String] = node \@@ "len"
  val altlen: Option[String] = node \@@ "altlen"
  val clen: Option[String] = altlen match {
    case Some(_) => altlen
    case None => len
  }

  val optional: Boolean = (node \@@ "optional").exists(_.toBoolean)
  val noautovalidity: Boolean = (node \@@ "noautovalidity").exists(_.toBoolean)
  val externsync: Boolean = (node \@@ "externsync").exists(_.toBoolean)
  val typeName: Option[VulkanType] = (node \@\ "type").flatMap(registry.types.get)
  val name: String = node @\\ "name"
}

object VulkanCommandParam {
  def apply(registry: Registry,vulkanCommand: VulkanCommand,node: Node,implicitexternsyncparams: Boolean): Traversable[VulkanCommandParam] =
    (node \ "param").map(new VulkanCommandParam(registry,vulkanCommand,_,implicitexternsyncparams))
}
