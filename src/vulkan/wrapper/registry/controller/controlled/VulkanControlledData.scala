package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponent, VulkanComponentMappedData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

class VulkanControlledData[+T <: VulkanControlled[U,V],+U <: VulkanControll[V],+V <: VulkanController,W <: VulkanComponent](registry: Registry, components: Traversable[T], val groupedComponents: Map[W, Traversable[T]]) extends VulkanComponentMappedData(registry,components){
  val groupedControllComponents: Map[W,Traversable[U]] = groupedComponents.mapValues(_.map(_.vulkanControll).toSet)
  val groupedControllerComponents: Map[W,Traversable[V]] = groupedControllComponents.mapValues(_.map(_.vulkanController).toSet)

  def controlledComponents(component: W): Traversable[T] = groupedComponents.getOrElse(component,Traversable())
  def controllComponents(component: W): Traversable[U] = groupedControllComponents.getOrElse(component,Traversable())
  def controllerComponents(component: W): Traversable[V] = groupedControllerComponents.getOrElse(component,Traversable())
}

object VulkanControlledData {
  def apply[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](registry: Registry, components: Traversable[T],getComponent: T => W): VulkanControlledData[T,U,V,W] =
    new VulkanControlledData[T,U,V,W](registry,components,components.groupBy(getComponent))

  def apply[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](datas: VulkanControlledData[T,U,V,W]*): VulkanControlledData[T,U,V,W] =
    new VulkanControlledData[T,U,V,W](datas.head.registry,datas.flatMap(_.components),
      datas.flatMap(_.groupedComponents.toSeq).groupBy(_._1).mapValues(_.flatMap(_._2)))

  def fromSeq[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](datas: Traversable[VulkanControlledData[T,U,V,W]]): VulkanControlledData[T,U,V,W] =
    new VulkanControlledData[T,U,V,W](datas.head.registry,datas.flatMap(_.components),
      datas.flatMap(_.groupedComponents.toSeq).groupBy(_._1).mapValues(_.flatMap(_._2)))
}
