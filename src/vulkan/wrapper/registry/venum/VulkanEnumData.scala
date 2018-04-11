package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.controller.controlled._
import vulkan.wrapper.registry.{Registry, VulkanComponent, VulkanComponentMappedData, VulkanComponentSequentalData, VulkanNamedComponent}

class VulkanEnumData(registry: Registry,components: Traversable[VulkanEnum]) extends VulkanComponentSequentalData(registry,components){
  val mapedEnums: Map[String,VulkanEnum] = components.filter(_.name.nonEmpty).map(i => (i.name.get,i)).toMap
  //lazy val enumValues: Map[String,VulkanNamedComponent with VulkanEnumEnum] = components.flatMap(_.enums.components).map(i => (i.name,i)).toMap
  val valueEnums: VulkanComponentMappedData[VulkanEnumValue] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.valueEnums))

  val bitposEnums: VulkanComponentMappedData[VulkanEnumBitpos] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.bitposEnums))

  val aliasEnums: VulkanComponentMappedData[VulkanEnumAlias] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.aliasEnums))

  val normalEnum: VulkanComponentMappedData[VulkanEnumNormalEnum] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.normalEnum))

  lazy val controlledValueEnums: VulkanComponentMappedData[VulkanControlledEnumValue[VulkanControll[VulkanController], VulkanController]] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.controlledValueEnums))

  lazy val controlledBitposEnums: VulkanComponentMappedData[VulkanControlledEnumBitpos[VulkanControll[VulkanController], VulkanController]] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.controlledBitposEnums))

  lazy val controlledAliasEnums: VulkanComponentMappedData[VulkanControlledEnumAlias[VulkanControll[VulkanController], VulkanController]] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.controlledAliasEnums))

  lazy val controlledExtendsEnum: VulkanComponentMappedData[VulkanControlledEnumExtends[VulkanControll[VulkanController], VulkanController]] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.controlledExtendsEnum))

  lazy val controlledOffsetEnums: VulkanComponentMappedData[VulkanControlledEnumOffset[VulkanControll[VulkanController], VulkanController]] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.controlledOffsetEnums))

  lazy val controlledEnum: VulkanComponentMappedData[VulkanControlledEnum[VulkanControll[VulkanController], VulkanController]] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.controlledEnum))

  lazy val enums: VulkanComponentMappedData[VulkanNamedComponent with VulkanEnumEnum] =
    VulkanComponentMappedData.fromSeq(registry,components.map(_.enums))

  def byName(name: String): VulkanEnum = mapedEnums(name)
  def byNameOption(name:String): Option[VulkanEnum] = mapedEnums.get(name)

  /*def ++(other: VulkanEnumData): VulkanEnumData =
    VulkanEnumData(registry,components ++ other.components)*/
}

object VulkanEnumData {
  def apply(registry: Registry,components: Traversable[VulkanEnum]): VulkanEnumData =
    new VulkanEnumData(registry,components)

  def apply(registry: Registry,datas: VulkanEnumData*): VulkanEnumData =
    new VulkanEnumData(registry,datas.flatMap(_.components))

  def fromSeq(registry: Registry,datas: Traversable[VulkanEnumData]): VulkanEnumData =
    new VulkanEnumData(registry,datas.flatMap(_.components))
}
