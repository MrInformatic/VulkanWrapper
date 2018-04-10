package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.{Registry, VulkanComponent, VulkanComponentMappedData, VulkanComponentSequentalData}

class VulkanEnumData(registry: Registry,components: Traversable[VulkanEnum]) extends VulkanComponentSequentalData(registry,components){
  val mapedEnums: Map[String,VulkanEnum] = components.filter(_.name.nonEmpty).map(i => (i.name.get,i)).toMap
  val enumValues: Map[String,VulkanEnumNormalEnum] = components.flatMap(_.enums.components).map(i => (i.name,i)).toMap

  def byName(name: String): VulkanEnum = mapedEnums(name)
  def byNameOption(name:String): Option[VulkanEnum] = mapedEnums.get(name)
  def enumByName(name: String): VulkanEnumNormalEnum = enumValues(name)
  def enumByNameOption(name: String): Option[VulkanEnumNormalEnum] = enumValues.get(name)

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
