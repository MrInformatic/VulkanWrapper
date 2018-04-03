package vulkan.wrapper.registry

class VulkanComponentMappedData[+T <: VulkanNamedComponent](registry: Registry, components: Traversable[T]) extends VulkanComponentSequentalData[T](registry,components) {
  val mappedComponents: Map[String,T] = components.map(i => (i.name,i)).toMap

  def apply(name: String): T = byName(name)
  def byName(name: String): T = mappedComponents(name)
  def byNameOption(name:String): Option[T] = mappedComponents.get(name)

  def ++[U >: T <: VulkanNamedComponent](other: VulkanComponentMappedData[U]): VulkanComponentMappedData[U] =
    VulkanComponentMappedData(registry,components ++ other.components)
}

object VulkanComponentMappedData {
  def apply[T <: VulkanNamedComponent](registry: Registry,components: Traversable[T]): VulkanComponentMappedData[T] =
    new VulkanComponentMappedData(registry,components)

  //implicit def data2Seq[T <: VulkanComponent](data: VulkanComponentMappedData[T]): Traversable[T] = data.components
}
