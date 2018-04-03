package vulkan.wrapper.registry

class VulkanComponentSequentalData[+T <: VulkanComponent](registry: Registry, val components: Traversable[T]) extends RegistryComponentData(registry) {
  def ++[U >: T <: VulkanComponent](other: VulkanComponentSequentalData[U]): VulkanComponentSequentalData[U] =
    VulkanComponentSequentalData(registry,components ++ other.components)
}

object VulkanComponentSequentalData {
  def apply[T <: VulkanComponent](registry: Registry,components: Traversable[T]): VulkanComponentSequentalData[T] =
    new VulkanComponentSequentalData(registry,components)

  def apply[T <: VulkanComponent](registry: Registry,datas: VulkanComponentSequentalData[T]*): VulkanComponentSequentalData[T] =
    datas.head

  //implicit def data2Seq[T <: VulkanComponent](data: VulkanComponentSequentalData[T]): Traversable[T] = data.components
}
