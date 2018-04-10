package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.VulkanControll
import vulkan.wrapper.registry.controller.controlled.VulkanControlledEnumValue
import vulkan.wrapper.registry.vtype.VulkanEnumType
import vulkan.wrapper.registry.{Registry, _}

import scala.xml.Node

class VulkanEnum(registry: Registry,node: Node) extends VulkanComponent(registry,node){
  val valueEnums: VulkanComponentMappedData[VulkanEnumValue] = VulkanEnumValue(registry,this,node)
  val bitposEnums: VulkanComponentMappedData[VulkanEnumBitpos] = VulkanEnumBitpos(registry,this,node)
  val aliasEnums: VulkanComponentMappedData[VulkanEnumAlias] = VulkanEnumAlias(registry,this,node)
  lazy val controlledValueEnums: VulkanComponentMappedData[VulkanControlledEnumValue[VulkanControll[VulkanController],VulkanController]] =
    registry.controllers.controllTags.enumValues.
  val enums: VulkanComponentMappedData[VulkanEnumNormalEnum] =
    VulkanComponentMappedData(registry, valueEnums, bitposEnums, aliasEnums)

  val unused: VulkanComponentSequentalData[VulkanEnumUnused] = VulkanEnumUnused(registry,this,node)
  val name: Option[String] = node \@@ "name"
  lazy val enumType: Option[VulkanEnumType] = name.flatMap(registry.enumTypes.byNameOption)
  val typeName: Option[String] = node \@@ "type"
  val start: Option[String] = node \@@ "start"
  val end: Option[String] = node \@@ "end"
  val vendor: Option[String] = node \@@ "vendor"
  val comment: Option[String] = node \@@ "comment"
}

object VulkanEnum {
  def apply(registry: Registry): VulkanEnumData =
    VulkanEnumData(registry,(registry.xml \ "enums").map(new VulkanEnum(registry,_)))
}
