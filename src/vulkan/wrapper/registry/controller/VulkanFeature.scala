package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry._

import scala.xml.Node

class VulkanFeature(registry: Registry, node: Node) extends VulkanController(registry,node){
  def api: String = node \@ "api"
  def name: String = node \@ "name"
  def number: String = node \@ "number"
  def protect: Option[String] = node \@@ "protect"
  def comment: Option[String] = node \@@ "comment"
}

object VulkanFeature {
  def apply(registry: Registry): Map[String,VulkanFeature] =
    (registry.xml \ "feature").map(new VulkanFeature(registry,_)).map(i => (i.name,i)).toMap
}
