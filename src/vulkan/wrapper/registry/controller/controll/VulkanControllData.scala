package vulkan.wrapper.registry.controller.controll

import vulkan.wrapper.registry.command.{VulkanCommand, VulkanCommandNode$}
import vulkan.wrapper.registry.{Registry, VulkanComponentSequentalData}
import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controlled._
import vulkan.wrapper.registry.venum.{VulkanEnum, VulkanEnumNormalEnum}
import vulkan.wrapper.registry.vtype.VulkanType

class VulkanControllData[+T <: VulkanControll[U], +U <: VulkanController](registry: Registry,components: Traversable[T]) extends VulkanComponentSequentalData(registry,components){
  /*def ++[V >: T <: VulkanControll[W],W >: U <: VulkanController](other: VulkanControllData[V,W]) =
    VulkanControllData[V,W](registry,components ++ other.components)*/

  val types: VulkanControlledData[VulkanControlledType[T,U],T,U,VulkanType] =
    VulkanControlledData.fromSeq(registry,components.map(_.types))

  val enumValues: VulkanControlledOptionData[VulkanControlledEnumValue[T,U],T,U,VulkanEnum] =
    VulkanControlledOptionData.fromSeq(registry,components.map(_.enumValues))

  val enumBitposes: VulkanControlledOptionData[VulkanControlledEnumBitpos[T,U],T,U,VulkanEnum] =
    VulkanControlledOptionData.fromSeq(registry,components.map(_.enumBitposes))

  val enumAlias: VulkanControlledOptionData[VulkanControlledEnumAlias[T,U],T,U,VulkanEnum] =
    VulkanControlledOptionData.fromSeq(registry,components.map(_.enumAlias))

  val enumOffset: VulkanControlledData[VulkanControlledEnumOffset[T,U],T,U,VulkanEnum] =
    VulkanControlledData.fromSeq(registry,components.map(_.enumOffset))

  val enumReference: VulkanControlledData[VulkanControlledEnumReference[T,U],T,U,VulkanEnumNormalEnum] =
    VulkanControlledData.fromSeq(registry,components.map(_.enumReference))

  val commands: VulkanControlledData[VulkanControlledCommand[T,U],T,U,VulkanCommand] =
    VulkanControlledData.fromSeq(registry,components.map(_.commands))

  val enumExtends: VulkanControlledOptionData[VulkanControlledEnumExtends[T,U],T,U,VulkanEnum] =
    VulkanControlledOptionData.fromSeq(registry,components.map(_.enumExtends))
}

object VulkanControllData {
  def apply[T <: VulkanControll[U], U <: VulkanController](registry: Registry,components: Traversable[T]): VulkanControllData[T,U] =
    new VulkanControllData[T,U](registry,components)

  def apply[T <: VulkanControll[U], U <: VulkanController](registry: Registry,datas: VulkanControllData[T,U]*): VulkanControllData[T,U] =
    new VulkanControllData[T,U](registry,datas.flatMap(_.components))

  def fromSeq[T <: VulkanControll[U], U <: VulkanController](registry: Registry,datas: Traversable[VulkanControllData[T,U]]): VulkanControllData[T,U] =
    new VulkanControllData[T,U](registry,datas.flatMap(_.components))
}
