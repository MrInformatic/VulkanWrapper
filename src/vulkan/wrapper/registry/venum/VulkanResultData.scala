package vulkan.wrapper.registry.venum

import vulkan.wrapper.registry.{Registry, VulkanComponentMappedData, VulkanComponentSequentalData}

class VulkanResultData(registry: Registry, val vulkanEnumData: VulkanEnumData)
  extends VulkanComponentMappedData(registry,vulkanEnumData.byName("VkResult").enums.components){

  val successCodes: Map[String,VulkanEnumEnum] = mappedComponents.filter(_._2.value.toInt >= 0)
  val errorCodes: Map[String,VulkanEnumEnum] = mappedComponents.filter(_._2.value.toInt < 0)

  def successByName(name: String): VulkanEnumEnum = successCodes(name)
  def successByNameOption(name: String): Option[VulkanEnumEnum] = successCodes.get(name)
  def errorByName(name: String): VulkanEnumEnum = errorCodes(name)
  def errorByNameOption(name: String): Option[VulkanEnumEnum] = errorCodes.get(name)
}

object VulkanResultData {
  def apply(registry: Registry): VulkanResultData =
    new VulkanResultData(registry,registry.enums)
}
