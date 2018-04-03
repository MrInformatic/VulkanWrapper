package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry.command.VulkanCommand
import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.controller.controlled.VulkanControlledCommand
import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

class VulkanControllerData[T <: VulkanController](registry: Registry,components: Traversable[T]) extends VulkanComponentMappedData(registry,components) {
  val requireCommandMap: Map[VulkanCommand, Traversable[VulkanControlledCommand[VulkanControllRequire[T], T]]] =
    components.flatMap(_.requiresTags.components).flatMap(_.commands.components).groupBy(_.command)

  val removeCommandMap: Map[VulkanCommand, Traversable[VulkanControlledCommand[VulkanControllRemove[T], T]]] =
    components.flatMap(_.removesTags.components).flatMap(_.commands.components).groupBy(_.command)

  val controllCommand: Map[VulkanCommand, Traversable[VulkanControlledCommand[VulkanControll[T], T]]] =
    components.flatMap(_.controllTags.components)
      .flatMap(_.commands.components).groupBy(_.command)

  def controlledCommand(command: VulkanCommand): Traversable[VulkanControlledCommand[VulkanControllRequire[T], T]] =
    requireCommandMap.getOrElse(command,Traversable())
}
