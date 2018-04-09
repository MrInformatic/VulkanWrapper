package vulkan.wrapper.registry

class VulkanComponentSequentalData[+T <: VulkanComponent](registry: Registry, val components: Traversable[T]) extends RegistryComponentData(registry) {

}

object VulkanComponentSequentalData {
  def apply[T <: VulkanComponent](registry: Registry,components: Traversable[T]): VulkanComponentSequentalData[T] =
    new VulkanComponentSequentalData(registry,components)

  def apply[T <: VulkanComponent](datas: VulkanComponentSequentalData[T]*): VulkanComponentSequentalData[T] =
    new VulkanComponentSequentalData[T](datas.head.registry,datas.flatMap(_.components))

  def fromSeq[T <: VulkanComponent](datas: Traversable[VulkanComponentSequentalData[T]]): VulkanComponentSequentalData[T] =
    new VulkanComponentSequentalData[T](datas.head.registry,datas.flatMap(_.components))

  //implicit def data2Seq[T <: VulkanComponent](data: VulkanComponentSequentalData[T]): Traversable[T] = data.components
}
