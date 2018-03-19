package vulkan.wrapper.registry.command

object VulkanCommandPiplines extends Enumeration {
  type VulkanCommandPipline = Value
  val compute,transfer,graphics = Value
}
