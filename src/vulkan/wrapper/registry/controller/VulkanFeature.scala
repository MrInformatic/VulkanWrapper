package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanFeature(registry: Registry, node: Node) extends VulkanController(registry,node){
  override def getThis: this.type = this

  override val extNumber: Int = 0

  val api: String = node \@ "api"
  override val name: String = node \@ "name"
  val number: String = node \@ "number"
  val protect: Option[String] = node \@@ "protect"
  val comment: Option[String] = node \@@ "comment"
}

object VulkanFeature {
  def apply(registry: Registry): VulkanControllerData[VulkanFeature] =
    VulkanControllerData(registry,(registry.xml \ "feature").map(new VulkanFeature(registry,_)))
}
