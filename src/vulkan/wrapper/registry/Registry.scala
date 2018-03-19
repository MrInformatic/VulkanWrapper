package vulkan.wrapper.registry

import scala.xml.XML
import vulkan._
import vulkan.wrapper.registry.command.VulkanCommand
import vulkan.wrapper.registry.controller.{VulkanExtension, VulkanFeature}
import vulkan.wrapper.registry.tag.VulkanTag
import vulkan.wrapper.registry.vendorid.VulkanVendorId
import vulkan.wrapper.registry.venum.{VulkanEnum, VulkanEnumEnum}
import vulkan.wrapper.registry.vtype._

class Registry {
  val xml = XML.loadFile("vk.xml")

  val tags: Map[String,VulkanTag] = VulkanTag(this)

  val vendorIds: Map[String,VulkanVendorId] = VulkanVendorId(this)

  val primitiveTypes: Map[String,VulkanPrimitiveType] = VulkanPrimitiveType(this)
  val includeTypes: Map[String,VulkanIncludeType] = VulkanIncludeType(this)
  val defineTypes: Map[String,VulkanDefineType] = VulkanDefineType(this)
  val baseTypes: Map[String,VulkanBaseType] = VulkanBaseType(this)
  val handleTypes: Map[String,VulkanHandleType] = VulkanHandleType(this)
  val enumTypes: Map[String,VulkanGroupType] = VulkanGroupType(this)
  val groupTypes: Map[String,VulkanGroupType] = VulkanGroupType(this)
  val bitmaskTypes: Map[String,VulkanBitmaskType] = VulkanBitmaskType(this)
  val funcPointerTypes: Map[String,VulkanFuncPointerType] = VulkanFuncPointerType(this)
  val structTypes: Map[String,VulkanStructType] = VulkanStructType(this)
  val unionTypes: Map[String,VulkanUnionType] = VulkanUnionType(this)

  val types: Map[String,VulkanType] =
    primitiveTypes ++
    includeTypes ++
    defineTypes ++
    baseTypes ++
    handleTypes ++
    enumTypes ++
    groupTypes ++
    bitmaskTypes ++
    funcPointerTypes ++
    structTypes ++
    unionTypes

  val enums: Traversable[VulkanEnum] = VulkanEnum(this)
  val mapedEnums: Map[String,VulkanEnum] = enums.filter(_.name.nonEmpty).map(i => (i.name.get,i)).toMap

  val commands: Map[String,VulkanCommand] = VulkanCommand(this)

  val features: Map[String,VulkanFeature] = VulkanFeature(this)

  val extension: Map[String,VulkanExtension] = VulkanExtension(this)

  val resultCodes: Map[String,VulkanEnumEnum] = mapedEnums("VkResult").enums.map(i => (i.name,i)).toMap
  val successCodes: Map[String,VulkanEnumEnum] = resultCodes.filter(_._2.value.toInt >= 0)
  val errorCodes: Map[String,VulkanEnumEnum] = resultCodes.filter(_._2.value.toInt < 0)
}
