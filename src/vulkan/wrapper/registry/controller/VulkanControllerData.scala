package vulkan.wrapper.registry.controller

import vulkan.wrapper.registry.command.VulkanCommandNode$
import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllData, VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.controller.controlled.VulkanControlledCommand
import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData}

class VulkanControllerData[+T <: VulkanController](registry: Registry,components: Traversable[T]) extends VulkanComponentMappedData(registry,components) {
  val requireTags: VulkanControllData[VulkanControllRequire[T],T] =
    VulkanControllData.fromSeq[VulkanControllRequire[T],T](registry,components.map(_.requireTags))

  val removeTags: VulkanControllData[VulkanControllRemove[T],T] =
    VulkanControllData.fromSeq[VulkanControllRemove[T],T](registry,components.map(_.removeTags))

  val controllTags: VulkanControllData[VulkanControll[T],T] =
    VulkanControllData.fromSeq[VulkanControll[T],T](registry,components.map(_.controllTags))
}

object VulkanControllerData {
  def apply[T <: VulkanController](registry: Registry,components: Traversable[T]): VulkanControllerData[T] =
    new VulkanControllerData(registry,components)

  def apply[T <: VulkanController](registry: Registry,datas: VulkanControllerData[T]*): VulkanControllerData[T] =
    new VulkanControllerData[T](registry,datas.flatMap(_.components))

  def fromSeq[T <: VulkanController](registry: Registry,datas: Traversable[VulkanControllerData[T]]): VulkanControllerData[T] =
    new VulkanControllerData[T](registry,datas.flatMap(_.components))
}
