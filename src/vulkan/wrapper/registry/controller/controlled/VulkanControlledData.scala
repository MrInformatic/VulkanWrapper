package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponent, VulkanComponentMappedData, VulkanComponentSequentalData}
import vulkan.wrapper.registry.controller.{VulkanController, VulkanControllerData}
import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllData}

class VulkanControlledData[+T <: VulkanControlled[U,V],+U <: VulkanControll[V],+V <: VulkanController,W <: VulkanComponent](registry: Registry, components: Traversable[T], val groupedComponents: Map[W, VulkanComponentMappedData[T]]) extends VulkanComponentMappedData(registry,components){
  val groupedControllComponents: Map[W,VulkanControllData[T,U]] = groupedComponents.mapValues(_.components.map(_.vulkanControll).toSet)
  val groupedControllerComponents: Map[W,VulkanControlled[T,U,V,W]] = groupedControllComponents.mapValues(_.map(_.vulkanController).toSet)

  def controlledComponents(component: W): VulkanControllerData[T] = groupedComponents.getOrElse(component,Traversable())
  def controllComponents(component: W): VulkanControllData[T,U] = groupedControllComponents.getOrElse(component,Traversable())
  def controllerComponents(component: W): VulkanControlledData[T,U,V,W] = groupedControllerComponents.getOrElse(component,Traversable())
}

object VulkanControlledData {
  def apply[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](registry: Registry, components: Traversable[T],getComponent: T => W): VulkanControlledData[T,U,V,W] =
    new VulkanControlledData[T,U,V,W](registry,components,components.groupBy(getComponent))

  def apply[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](registry: Registry,datas: VulkanControlledData[T,U,V,W]*): VulkanControlledData[T,U,V,W] =
    new VulkanControlledData[T,U,V,W](registry,datas.flatMap(_.components),
      datas.flatMap(_.groupedComponents.toSeq).groupBy(_._1).mapValues(_.flatMap(_._2)))

  def fromSeq[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](registry: Registry,datas: Traversable[VulkanControlledData[T,U,V,W]]): VulkanControlledData[T,U,V,W] =
    new VulkanControlledData[T,U,V,W](registry,datas.flatMap(_.components),
      datas.flatMap(_.groupedComponents.toSeq).groupBy(_._1).mapValues(_.flatMap(_._2)))
}
