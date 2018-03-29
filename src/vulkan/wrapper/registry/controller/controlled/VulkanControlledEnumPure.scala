package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.Registry
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

import scala.xml.Node

class VulkanControlledEnumPure[T[X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node) extends VulkanControlledEnumOther(registry,vulkanControll,node) {

}

object VulkanControlledEnumPure {
  def apply[T[X <: VulkanController] <: VulkanControll[X],U <: VulkanController](registry: Registry, vulkanControll: T[U], node: Node): Traversable[VulkanControlledEnumPure[T,U]] =
    (node \ "enum").filter(_.attributes.forall(i => Set("name","comment","api").contains(i.key)))
      .map(new VulkanControlledEnumPure[T,U](registry,vulkanControll,_))
}
