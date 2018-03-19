package vulkan.wrapper.registry.command

import vulkan.wrapper.registry.venum.VulkanEnumEnum
import vulkan.wrapper.registry.vtype.VulkanType
import vulkan.wrapper.registry.{Registry, RegistryType, _}

import scala.xml.Node

class VulkanCommand(registry: Registry, val node: Node) extends RegistryType(registry){
  val params: Traversable[VulkanCommandParam] = VulkanCommandParam(registry,this,node,false)
  val implicitexternsyncparams: Traversable[VulkanCommandParam] = VulkanCommandParam(registry,this,(node \ "implicitexternsyncparams").head,true)

  val queues: Traversable[VulkanCommandQueues.VulkanCommandQueue] =
    (node \@@ "queues").seq.flatMap(_.split(",").seq.map(VulkanCommandQueues.withName))

  lazy val successcodes: Traversable[VulkanEnumEnum] = (node \@@ "successcodes").flatMap(_.split(",").seq).flatMap(registry.successCodes.get)
  lazy val errorcodes: Traversable[VulkanEnumEnum] = (node \@@ "errorcodes").flatMap(_.split(",").seq).flatMap(registry.errorCodes.get)

  val renderpass: Option[VulkanCommandRenderPasses.VulkanCommandRenderPass] =
    (node \@@ "renderpass").map(VulkanCommandRenderPasses.withName)

  val cmdbufferlevel: Traversable[VulkanCommandCMDBufferLevels.VulkanCommandCMDBufferLevel] =
    (node \@@ "cmdbufferlevel").seq.flatMap(_.split(",").seq.map(VulkanCommandCMDBufferLevels.withName))

  val pipeline: Traversable[VulkanCommandPiplines.VulkanCommandPipline] =
    (node \@@ "pipeline").seq.flatMap(_.split(",").seq.map(VulkanCommandPiplines.withName))

  val comment: Option[String] = node \@@ "comment"

  lazy val typeName: Option[VulkanType] = ((node \ "proto").head \@\ "type").flatMap(registry.types.get)

  val name: String = (node \ "proto").head @\\ "name"

  lazy val alias: Option[VulkanCommand] = (node \@\ "alias").flatMap(registry.commands.get)

  val description: Option[String] = node \@\ "description"
}

object VulkanCommand {
  def apply(registry: Registry): Map[String,VulkanCommand] =
    (registry.xml \ "commands" \ "command").filter(_.attribute("alias").isEmpty).map(new VulkanCommand(registry,_))
      .map(i => (i.name,i)).toMap
}

