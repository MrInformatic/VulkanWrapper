package vulkan.wrapper.registry.controller.controlled

import vulkan.wrapper.registry.{Registry, VulkanComponent}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll

class VulkanControlledOptionData[+T <: VulkanControlled[U,V],+U <: VulkanControll[V],+V <: VulkanController,W <: VulkanComponent](registry: Registry, components: Traversable[T], groupedComponents: Map[W, Traversable[T]], val ungroupedComponents: Traversable[T]) extends VulkanControlledData[T,U,V,W](registry, components, groupedComponents) {
}

object VulkanControlledOptionData {
  def apply[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](registry: Registry,components: Traversable[T],getComponent: T => Option[W]): VulkanControlledOptionData[T,U,V,W] ={
    val processedComponents: Traversable[(T,Option[W])] = components.map(i => (i,getComponent(i)))
    new VulkanControlledOptionData[T,U,V,W](registry,components,
      processedComponents.filter(_._2.nonEmpty).map(i => (i._1,i._2.get)).groupBy(_._2).mapValues(_.map(_._1)),
      processedComponents.filter(_._2.isEmpty).map(_._1))
  }

  def apply[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](datas: VulkanControlledOptionData[T,U,V,W]*): VulkanControlledOptionData[T,U,V,W] =
    new VulkanControlledOptionData[T,U,V,W](datas.head.registry,datas.flatMap(_.components),
      datas.flatMap(_.groupedComponents).groupBy(_._1).mapValues(_.flatMap(_._2)),
      datas.flatMap(_.ungroupedComponents))

  /*def apply[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController](datas: VulkanControlledOptionData[T,U,V,_ <: VulkanComponent]*): VulkanControlledOptionData[T,U,V,_ <: VulkanComponent] =
    new VulkanControlledOptionData[T,U,V,_ <: VulkanComponent](datas.head.registry,datas.flatMap(_.components),
      datas.flatMap(_.groupedComponents).groupBy(_._1).mapValues(_.flatMap(_._2)),
      datas.flatMap(_.ungroupedComponents))*/

  def fromSeq[T <: VulkanControlled[U,V],U <: VulkanControll[V],V <: VulkanController,W <: VulkanComponent](datas: Traversable[VulkanControlledOptionData[T,U,V,W]]): VulkanControlledOptionData[T,U,V,W] =
    new VulkanControlledOptionData[T,U,V,W](datas.head.registry,datas.flatMap(_.components),
      datas.flatMap(_.groupedComponents).groupBy(_._1).mapValues(_.flatMap(_._2)),
      datas.flatMap(_.ungroupedComponents))

}
