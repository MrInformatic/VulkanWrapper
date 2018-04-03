package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanFeature(registry: Registry, node: Node) extends VulkanController(registry,node){
  override def getThis: this.type = this

  def api: String = node \@ "api"
  override val name: String = node \@ "name"
  def number: String = node \@ "number"
  def protect: Option[String] = node \@@ "protect"
  def comment: Option[String] = node \@@ "comment"
}

object VulkanFeature {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanFeature] =
    VulkanComponentMappedData(registry,(registry.xml \ "feature").map(new VulkanFeature(registry,_)))
}
