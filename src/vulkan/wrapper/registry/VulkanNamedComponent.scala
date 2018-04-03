package vulkan.wrapper.registry

import scala.xml.Node

abstract class VulkanNamedComponent(registry: Registry, node: Node) extends VulkanComponent(registry,node) {
  val name: String
}
