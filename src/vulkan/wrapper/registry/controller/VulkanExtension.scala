package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry._
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanExtension(registry: Registry, node: Node) extends VulkanController(registry,node){
  override def getThis: this.type = this

  override val name: String = node \@ "name"
  override val extNumber: Int = (node \@ "number").toInt
  val author: Option[String] = node \@@ "author"
  val contact: Option[String] = node \@@ "contact"
  val typeName: String = node \@ "type"
  val requires: Option[String] = node \@@ "requires"
  val protect: Option[String] = node \@@ "protect"
  val platform: Option[String] = node \@@ "platform"
  val supported: String = node \@ "supported"
  val comment: Option[String] = node \@@ "comment"

}

object VulkanExtension {
  def apply(registry: Registry): VulkanControllerData[VulkanExtension] =
    VulkanControllerData(registry,(registry.xml \ "extensions" \ "extension").map(new VulkanExtension(registry,_)))
}
