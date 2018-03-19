package vulkan.wrapper.registry.tag

import vulkan.wrapper.registry.{Registry, RegistryType}

import scala.xml.Node

class VulkanTag(registry: Registry,val node: Node) extends RegistryType(registry){
  val name: String = node \@ "name"
  val author: String = node \@ "author"
  val contact: String = node \@ "contact"
}

object VulkanTag {
  def apply(registry: Registry): Map[String,VulkanTag] =
    (registry.xml \ "tags" \ "tag").map(new VulkanTag(registry,_)).map(i => (i.name,i)).toMap
}


