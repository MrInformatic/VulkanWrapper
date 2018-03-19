package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanExtension(registry: Registry, node: Node) extends VulkanController(registry,node){
  def name: String = node \@ "name"
  def number: String = node \@ "number"
  def author: Option[String] = node \@@ "author"
  def contact: Option[String] = node \@@ "contact"
  def typeName: String = node \@ "type"
  def requires: Option[String] = node \@@ "requires"
  def protect: Option[String] = node \@@ "protect"
  def platform: Option[String] = node \@@ "platform"
  def supported: String = node \@ "supported"
  def comment: Option[String] = node \@@ "comment"

}

object VulkanExtension {
  def apply(registry: Registry): Map[String,VulkanExtension] =
    (registry.xml \ "extensions" \ "extension").map(new VulkanExtension(registry,_)).map(i => (i.name,i)).toMap
}
