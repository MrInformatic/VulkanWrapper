package vulkan.wrapper.generator

/**
  * Created by philipp on 02.09.17.
  */
abstract class VulkanType() {
  val name : String
  val improvedName : String
  def converteToCpp(inputName:String) : String
  def converteToC(inputName:String) : String
}
