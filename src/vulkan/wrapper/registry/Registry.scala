package vulkan.wrapper.registry

import vulkan.wrapper.registry.command.{VulkanCommand, VulkanCommandAlias, VulkanCommandNode, VulkanCommandNode$}
import vulkan.wrapper.registry.controller.controll.{VulkanControllRemove, VulkanControllRequire}
import vulkan.wrapper.registry.controller.{VulkanController, VulkanControllerData, VulkanExtension, VulkanFeature}
import vulkan.wrapper.registry.tag.VulkanTag
import vulkan.wrapper.registry.vendorid.VulkanVendorId
import vulkan.wrapper.registry.venum.{VulkanEnum, VulkanEnumData, VulkanEnumEnum, VulkanResultData}
import vulkan.wrapper.registry.vtype._

import scala.xml.XML

class Registry {
  val xml = XML.loadFile("vk.xml")

  val tags: VulkanComponentMappedData[VulkanTag] = VulkanTag(this)

  val vendorIds: VulkanComponentMappedData[VulkanVendorId] = VulkanVendorId(this)

  val primitiveTypes: VulkanComponentMappedData[VulkanPrimitiveType] = VulkanPrimitiveType(this)
  val includeTypes: VulkanComponentMappedData[VulkanIncludeType] = VulkanIncludeType(this)
  val defineTypes: VulkanComponentMappedData[VulkanDefineType] = VulkanDefineType(this)
  val baseTypes: VulkanComponentMappedData[VulkanBaseType] = VulkanBaseType(this)
  val handleTypes: VulkanComponentMappedData[VulkanHandleType] = VulkanHandleType(this)
  val enumTypes: VulkanComponentMappedData[VulkanEnumType] = VulkanEnumType(this)
  val groupTypes: VulkanComponentMappedData[VulkanGroupType] = VulkanGroupType(this)
  val bitmaskTypes: VulkanComponentMappedData[VulkanBitmaskType] = VulkanBitmaskType(this)
  val funcPointerTypes: VulkanComponentMappedData[VulkanFuncPointerType] = VulkanFuncPointerType(this)
  val structTypes: VulkanComponentMappedData[VulkanStructType] = VulkanStructType(this)
  val unionTypes: VulkanComponentMappedData[VulkanUnionType] = VulkanUnionType(this)

  val types: VulkanComponentMappedData[VulkanType] =
    VulkanComponentMappedData(this,
      primitiveTypes,
      includeTypes,
      defineTypes,
      baseTypes,
      handleTypes,
      enumTypes,
      groupTypes,
      bitmaskTypes,
      funcPointerTypes,
      structTypes,
      unionTypes)

  val enums: VulkanEnumData = VulkanEnum(this)

  val commandsNode: VulkanComponentMappedData[VulkanCommandNode] = VulkanCommandNode(this)
  val commandsAlias: VulkanComponentMappedData[VulkanCommandAlias] = VulkanCommandAlias(this)
  val commands: VulkanComponentMappedData[VulkanCommand] = VulkanComponentMappedData(this,commandsNode,commandsAlias)

  val features: VulkanControllerData[VulkanFeature] = VulkanFeature(this)

  val extensions: VulkanControllerData[VulkanExtension] = VulkanExtension(this)

  val controllers: VulkanControllerData[VulkanController] = VulkanControllerData(this,features,extensions)

  /*val featuresRequireingCommand: Map[VulkanCommand, Traversable[VulkanControllRequire[VulkanFeature]]] = features.components
    .flatMap(_.requiresTags.components)
    .flatMap(i => i.commands.map(n => (n.command,i)))
    .groupBy(_._1)
    .map(i => (i._1,i._2.map(_._2)))

  val featuresRemoveingCommand: Map[VulkanCommand,Traversable[VulkanControllRemove[VulkanFeature]]] = features.components
    .flatMap(_.removesTags.components)
    .flatMap(i => i.commands.map(n => (i,n.command)))
    .groupBy(_._2)
    .map(i => (i._1,i._2.map(_._1)))

  val featuresUseingCommand: Map[VulkanCommand,Traversable[VulkanFeature]] =
    (featuresRequireingCommand ++ featuresRemoveingCommand).map(i => (i._1,i._2.map(_.vulkanController)))

  val extensionsRequireingCommand: Map[VulkanCommand,Traversable[VulkanControllRequire[VulkanExtension]]] = extensions.components
    .flatMap(_.requiresTags.components)
    .flatMap(i => i.commands.map(n => (n.command,i)))
    .groupBy(_._1)
    .map(i => (i._1,i._2.map(_._2)))

  val extensionsRemoveingCommand: Map[VulkanCommand,Traversable[VulkanControllRemove[VulkanExtension]]] = extensions.components
    .flatMap(_.removesTags.components)
    .flatMap(i => i.commands.map(n => (i,n.command)))
    .groupBy(_._2)
    .map(i => (i._1,i._2.map(_._1)))

  val extensionsUseingCommand: Map[VulkanCommand,Traversable[VulkanExtension]] =
    (extensionsRequireingCommand ++ extensionsRemoveingCommand).map(i => (i._1,i._2.map(_.vulkanController)))

  val controllerRequireingCommand: Map[VulkanCommand,Traversable[VulkanControllRequire[_ <: VulkanController]]] =
    featuresRequireingCommand ++ extensionsRequireingCommand

  val controllerRemoveingCommand: Map[VulkanCommand,Traversable[VulkanControllRemove[_ <: VulkanController]]] =
    featuresRemoveingCommand ++ extensionsRemoveingCommand*/

  val result: VulkanResultData = VulkanResultData(this)
}
