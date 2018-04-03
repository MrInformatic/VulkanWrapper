package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.controller.VulkanFeature
import vulkan.wrapper.registry.controller.controll.VulkanControllRequire
import vulkan.wrapper.registry.venum.VulkanEnumEnum
import vulkan.wrapper.registry.vtype.VulkanType
import vulkan.wrapper.registry.{Registry, RegistryComponent, _}

import scala.xml.Node

class VulkanCommand(registry: Registry, node: Node) extends VulkanNamedComponent(registry,node){
  val params: VulkanComponentMappedData[VulkanCommandNormalParam] = VulkanCommandNormalParam(registry,this,node)
  val implicitexternsyncparams: VulkanComponentMappedData[VulkanCommandImplicitExternsyncParam] =
    VulkanCommandImplicitExternsyncParam(registry,this,node)

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

  override val name: String = (node \ "proto").head @\\ "name"

  lazy val alias: Option[VulkanCommand] = (node \@\ "alias").flatMap(registry.commands.byNameOption)

  val description: Option[String] = node \@\ "description"
}

object VulkanCommand {
  def apply(registry: Registry): VulkanComponentMappedData[VulkanCommand] =
    VulkanComponentMappedData(registry,(registry.xml \ "commands" \ "command").filter(_.attribute("alias").isEmpty).map(new VulkanCommand(registry,_)))
}

