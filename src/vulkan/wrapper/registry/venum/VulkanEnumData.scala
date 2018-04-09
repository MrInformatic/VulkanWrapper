package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.{Registry, VulkanComponent, VulkanComponentMappedData, VulkanComponentSequentalData}

class VulkanEnumData(registry: Registry,components: Traversable[VulkanEnum]) extends VulkanComponentSequentalData(registry,components){
  val mapedEnums: Map[String,VulkanEnum] = components.filter(_.name.nonEmpty).map(i => (i.name.get,i)).toMap
  val enumValues: Map[String,VulkanEnumEnum] = components.flatMap(_.enums.components).map(i => (i.name,i)).toMap

  def byName(name: String): VulkanEnum = mapedEnums(name)
  def byNameOption(name:String): Option[VulkanEnum] = mapedEnums.get(name)
  def enumByName(name: String): VulkanEnumEnum = enumValues(name)
  def enumByNameOption(name: String): Option[VulkanEnumEnum] = enumValues.get(name)

  /*def ++(other: VulkanEnumData): VulkanEnumData =
    VulkanEnumData(registry,components ++ other.components)*/
}

object VulkanEnumData {
  def apply(registry: Registry,components: Traversable[VulkanEnum]): VulkanEnumData =
    new VulkanEnumData(registry,components)

  def apply(datas: VulkanEnumData*): VulkanEnumData =
    new VulkanEnumData(datas.head.registry,datas.flatMap(_.components))

  def fromSeq(datas: Traversable[VulkanEnumData]): VulkanEnumData =
    new VulkanEnumData(datas.head.registry,datas.flatMap(_.components))
}
