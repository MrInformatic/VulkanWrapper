package vulkan.wrapper.generator

/**
  * Created by philipp on 06.09.17.
  */
abstract class VulkanCastableType extends VulkanType{
  override def converteToCpp(inputName: String): String = s"$improvedName($inputName)"

  override def converteToC(inputName: String): String = s"($name)$inputName"
}
