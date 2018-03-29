package vulkan.wrapper.registry

import vulkan.wrapper.registry.command.VulkanCommand
import vulkan.wrapper.registry.controller.controll.{VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.controller.{VulkanController, VulkanExtension, VulkanFeature}
import vulkan.wrapper.registry.tag.VulkanTag
import vulkan.wrapper.registry.vendorid.VulkanVendorId
import vulkan.wrapper.registry.venum.{VulkanEnum, VulkanEnumEnum}
import vulkan.wrapper.registry.vtype._

import scala.xml.XML

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
  val enumValues: Map[String,VulkanEnumEnum] = enums.flatMap(_.enums.seq).toMap

  val commands: Map[String,VulkanCommand] = VulkanCommand(this)

  val features: Map[String,VulkanFeature] = VulkanFeature(this)

  val extensions: Map[String,VulkanExtension] = VulkanExtension(this)

  val featuresRequireingCommand: Map[VulkanCommand, Traversable[VulkanControllRequire[VulkanFeature]]] = features.values
    .flatMap(_.requiresTags)
    .flatMap(i => i.commands.map(n => (n.command,i)))
    .groupBy(_._1)
    .map(i => (i._1,i._2.map(_._2)))

  val featuresRemoveingCommand: Map[VulkanCommand,Traversable[VulkanControllRemove[VulkanFeature]]] = features.values
    .flatMap(_.removesTags)
    .flatMap(i => i.commands.map(n => (i,n.command)))
    .groupBy(_._2)
    .map(i => (i._1,i._2.map(_._1)))

  val featuresUseingCommand: Map[VulkanCommand,Traversable[VulkanFeature]] =
    (featuresRequireingCommand ++ featuresRemoveingCommand).map(i => (i._1,i._2.map(_.vulkanController)))

  val extensionsRequireingCommand: Map[VulkanCommand,Traversable[VulkanControllRequire[VulkanExtension]]] = extensions.values
    .flatMap(_.requiresTags)
    .flatMap(i => i.commands.map(n => (n.command,i)))
    .groupBy(_._1)
    .map(i => (i._1,i._2.map(_._2)))

  val extensionsRemoveingCommand: Map[VulkanCommand,Traversable[VulkanControllRemove[VulkanExtension]]] = extensions.values
    .flatMap(_.removesTags)
    .flatMap(i => i.commands.map(n => (i,n.command)))
    .groupBy(_._2)
    .map(i => (i._1,i._2.map(_._1)))

  val extensionsUseingCommand: Map[VulkanCommand,Traversable[VulkanExtension]] =
    (extensionsRequireingCommand ++ extensionsRemoveingCommand).map(i => (i._1,i._2.map(_.vulkanController)))

  val controllerRequireingCommand: Map[VulkanCommand,Traversable[VulkanControllRequire[_ <: VulkanController]]] =
    featuresRequireingCommand ++ extensionsRequireingCommand

  val controllerRemoveingCommand: Map[VulkanCommand,Traversable[VulkanControllRemove[_ <: VulkanController]]] =
    featuresRemoveingCommand ++ extensionsRemoveingCommand

  val resultCodes: Map[String,VulkanEnumEnum] = mapedEnums("VkResult").enums
  val successCodes: Map[String,VulkanEnumEnum] = resultCodes.filter(_._2.value.toInt >= 0)
  val errorCodes: Map[String,VulkanEnumEnum] = resultCodes.filter(_._2.value.toInt < 0)
}
