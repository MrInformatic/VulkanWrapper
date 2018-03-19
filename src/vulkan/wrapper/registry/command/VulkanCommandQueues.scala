package vulkan.wrapper.registry.command

object VulkanCommandQueues extends Enumeration {
  type VulkanCommandQueue = Value
  val compute, transfer, graphics = Value
}
