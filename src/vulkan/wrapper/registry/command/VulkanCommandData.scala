package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.controller.VulkanController
import vulkan.wrapper.registry.controller.controll.{VulkanControll, VulkanControllData}
import vulkan.wrapper.registry.controller.controlled.VulkanControlled
import vulkan.wrapper.registry.venum.{VulkanEnumEnum, VulkanEnumNormalEnum}
import vulkan.wrapper.registry.vtype.VulkanType
import vulkan.wrapper.registry._

import scala.xml.Node

/**
  * Created by philipp on 10.04.18.
  */
class VulkanCommandData(registry: Registry,vulkanCommand: VulkanCommand,node: Node) extends VulkanComponent(registry, node){
  val params: VulkanComponentMappedData[VulkanCommandNormalParam] = VulkanCommandNormalParam(registry,vulkanCommand,node)
  val implicitexternsyncparams: VulkanComponentMappedData[VulkanCommandImplicitExternsyncParam] =
    VulkanCommandImplicitExternsyncParam(registry,vulkanCommand,node)

  val allparams: VulkanComponentMappedData[VulkanCommandParam] = VulkanComponentMappedData(registry,params,implicitexternsyncparams)

  val queues: Traversable[VulkanCommandQueues.VulkanCommandQueue] =
    (node \@@ "queues").seq.flatMap(_.split(",").seq.map(VulkanCommandQueues.withName))

  lazy val successcodes: Traversable[VulkanEnumEnum] = (node \@@ "successcodes").seq.flatMap(_.split(",").seq).flatMap(registry.result.successByNameOption)
  lazy val errorcodes: Traversable[VulkanEnumEnum] = (node \@@ "errorcodes").seq.flatMap(_.split(",").seq).flatMap(registry.result.errorByNameOption)

  val renderpass: Option[VulkanCommandRenderPasses.VulkanCommandRenderPass] =
    (node \@@ "renderpass").map(VulkanCommandRenderPasses.withName)

  val cmdbufferlevel: Traversable[VulkanCommandCMDBufferLevels.VulkanCommandCMDBufferLevel] =
    (node \@@ "cmdbufferlevel").seq.flatMap(_.split(",").seq.map(VulkanCommandCMDBufferLevels.withName))

  val pipeline: Traversable[VulkanCommandPiplines.VulkanCommandPipline] =
    (node \@@ "pipeline").seq.flatMap(_.split(",").seq.map(VulkanCommandPiplines.withName))

  val comment: Option[String] = node \@@ "comment"

  lazy val typeName: Option[VulkanType] = ((node \ "proto").head \@\ "type").flatMap(registry.types.byNameOption)

  lazy val alias: Option[VulkanCommand] = (node \@\ "alias").flatMap(registry.commands.byNameOption)

  val description: Option[String] = node \@\ "description"
}
