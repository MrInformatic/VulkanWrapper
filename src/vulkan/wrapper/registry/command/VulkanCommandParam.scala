package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.vtype.VulkanType
import vulkan.wrapper.registry.{Registry, RegistryType, _}

import scala.xml.Node

class VulkanCommandParam(registry: Registry,val vulkanCommand: VulkanCommand,val node: Node,val implicitexternsyncparams:Boolean) extends RegistryType(registry){
  val len: Traversable[String] = (node \@@ "len").seq.flatMap(_.split(",").seq)
  val altlen: Traversable[String] = (node \@@ "altlen").seq.flatMap(_.split(",").seq)
  val clen: Traversable[String] = genClen()

  val optional: Boolean = (node \@@ "optional").exists(_.toBoolean)
  val noautovalidity: Boolean = (node \@@ "noautovalidity").exists(_.toBoolean)
  val externsync: Boolean = (node \@@ "externsync").exists(_.toBoolean)
  val typeName: Option[VulkanType] = (node \@\ "type").flatMap(registry.types.get)
  val name: String = node @\\ "name"

  private def genClen(_len: Traversable[String] = len,_altlen: Traversable[String] = altlen): Traversable[String] =
    if(len.nonEmpty)
      Traversable(if (_len.head.startsWith("latexmath:")) _altlen.head else _len.head) ++ genClen(_len.tail, if (_len.head.startsWith("latexmath:")) _altlen.tail else _altlen)
    else
      Traversable()
}

object VulkanCommandParam {
  def apply(registry: Registry,vulkanCommand: VulkanCommand,node: Node,implicitexternsyncparams: Boolean): Traversable[VulkanCommandParam] =
    (node \ "param").map(new VulkanCommandParam(registry,vulkanCommand,_,implicitexternsyncparams))
}
