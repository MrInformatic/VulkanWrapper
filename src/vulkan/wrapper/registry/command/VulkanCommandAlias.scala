package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.{Registry, RegistryType}

import scala.xml.Node

class VulkanCommandAlias(registry: Registry, val node: Node) extends RegistryType(registry){
  val name: String = node \@ "name"
  lazy val alias: VulkanCommand = registry.commands(node \@ "alias")
}

object VulkanCommandAlias {
  def apply(registry: Registry): Map[String,VulkanCommandAlias] =
    (registry.xml \ "commands" \ "command").filter(_.attribute("alias").nonEmpty).map(new VulkanCommandAlias(registry,_))
      .map(i => (i.name,i)).toMap
}


