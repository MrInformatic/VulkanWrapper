package vulkan.wrapper.generator

import org.w3c.dom.Element

/**
  * Created by philipp on 01.09.17.
  */
class VulkanHandle(element:Element,val registry:VulkanRegistry) extends VulkanCastableType with VulkanGenerator{
  lazy val name = element.getElementsByTagName("name").item(0).getTextContent
  lazy val improvedName = name.stripPrefix("Vk")
  val memberName = improvedName.charAt(0).toLower + improvedName.substring(1)
  val parent = element.getAttribute("parent").stripPrefix("Vk")
  val memberParent = if(parent!="") parent.charAt(0).toLower + parent.substring(1) else ""

  override def getCpp: String = s"class $improvedName{\n" +
    s"  public:\n" +
    s"    $improvedName() : $memberName(VK_NULL_HANDLE){}\n" +
    s"    \n" +
    s"    $improvedName(std::nullptr_t) : $memberName(VK_NULL_HANDLE){}\n" +
    s"    \n" +
    s"    explicit $improvedName($name ${memberName}_) : $memberName(${memberName}_){}\n${
      if (parent != "")
        s"    \n" +
          s"    $improvedName($name ${memberName}_,$parent ${memberParent}_) : $memberName(${memberName}_),$memberParent(${memberParent}_){}\n"
      else ""
    }" +
    s"    \n" +
    s"    explicit operator $name() const{\n" +
    s"      return $memberName;\n" +
    s"    }\n" +
    s"    \n" +
    s"    explicit operator bool() const{\n" +
    s"      return $memberName!=VK_NULL_HANDLE;\n" +
    s"    }\n" +
    s"    bool operator!() const{\n" +
    s"      return $memberName==VK_NULL_HANDLE;\n" +
    s"    }\n" +
    s"    \n" +
    s"    bool operator==($improvedName const & ${memberName}_){\n" +
    s"      return $memberName == ${memberName}_.$memberName;\n" +
    s"    }\n" +
    s"    \n" +
    s"    bool operator!=($improvedName const & ${memberName}_){\n" +
    s"      return $memberName != ${memberName}_.$memberName;\n" +
    s"    }\n" +
    s"    \n" +
    s"    $improvedName & operator=($name ${memberName}_){\n" +
    s"      $memberName = ${memberName}_;\n" +
    s"      return *this;\n" +
    s"    }\n" +
    s"    \n" +
    s"    $improvedName & operator=(std::nullptr_t){\n" +
    s"      $memberName = VK_NULL_HANDLE;\n" +
    s"      return *this;\n" +
    s"    }\n${
      if (parent != "")
        s"    \n" +
          s"    $parent getParent(){\n" +
          s"      return $memberParent;\n" +
          s"    }\n"
      else ""
    }"+
    s"  private:\n" +
    s"    $name $memberName;\n${
      if (parent != "")
        s"    $parent $memberParent;\n"
      else ""
    }" +
    s"};\n"
}
