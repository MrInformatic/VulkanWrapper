package vulkan.wrapper.generator

/**
  * Created by philipp on 04.09.17.
  */
class VulkanBitmask(val bitEnum:VulkanBitEnum, val registy:VulkanRegistry) extends VulkanCastableType with VulkanGenerator{
  lazy val name: String = bitEnum.name.replace("Bits","s")
  lazy val improvedName: String = name.stripPrefix("Vk")
  val memberName = improvedName.charAt(0).toLower + improvedName.substring(1)

  override def getCpp: String = s"class $improvedName{\n" +
    s"  public:\n" +
    s"    $improvedName() : $memberName(0){}\n" +
    s"    \n" +
    s"    $improvedName(std::nullptr_t) : $memberName(0){}\n" +
    s"    \n" +
    s"    explicit $improvedName($name ${memberName}_) : $memberName(${memberName}_){}\n" +
    s"    \n" +
    s"    explicit operator $name() const{\n" +
    s"      return $memberName;" +
    s"    }\n" +
    s"    \n" +
    s"    $improvedName & operator=(std::nullptr_t){\n" +
    s"      $memberName = 0;\n" +
    s"    }\n" +
    s"    \n" +
    s"    $improvedName & operator=($name ${memberName}_){\n" +
    s"      $memberName = ${memberName}_;\n" +
    s"    }\n" +
    s"    \n" +
    s"    explicit operator bool() const{\n" +
    s"      return !!$memberName;\n" +
    s"    }\n" +
    s"    bool operator!() const{\n" +
    s"      return !$memberName;\n" +
    s"    }\n" +
    s"    \n" +
    s"    bool operator==($improvedName ${memberName}_){\n" +
    s"      return $memberName == ${memberName}_.$memberName;\n" +
    s"    }\n" +
    s"    \n" +
    s"    bool operator!=($improvedName ${memberName}_){\n" +
    s"      return $memberName != ${memberName}_.$memberName;\n" +
    s"    }\n" +
    s"    \n" +
    s"    bool getBit(${bitEnum.improvedName} bit){\n" +
    s"      return $memberName & bit;\n" +
    s"    }\n" +
    s"    \n" +
    s"    void setBit(${bitEnum.improvedName} bit, bool value){\n" +
    s"      if(value){\n" +
    s"        addBit(bit);\n" +
    s"      }else{\n" +
    s"        removeBit(bit);\n" +
    s"      }\n" +
    s"    }\n" +
    s"    \n" +
    s"    void addBit(${bitEnum.improvedName} bit){\n" +
    s"      $memberName |= bit;\n" +
    s"    }\n" +
    s"    \n" +
    s"    void removeBit(${bitEnum.improvedName} bit){\n" +
    s"      $memberName &= ~bit;\n" +
    s"    }\n" +
    s"    \n" +
    s"    void switchBit(${bitEnum.improvedName} bit){\n" +
    s"      $memberName ^= bit;\n" +
    s"    }\n" +
    s"    \n" +
    s"    void setAllBits(std::set<${bitEnum.improvedName}> bits,bool value){\n" +
    s"      for(auto bit : bits){\n" +
    s"        setBit(bit,value);\n" +
    s"      }\n" +
    s"    }\n" +
    s"    \n" +
    s"    void addAllBits(std::set<${bitEnum.improvedName}> bits){\n" +
    s"      for(auto bit : bits){\n" +
    s"        addBit(bit);\n" +
    s"      }\n" +
    s"    }\n" +
    s"    \n" +
    s"    void removeAllBits(std::set<${bitEnum.improvedName}> bits){\n" +
    s"      for(auto bit : bits){\n" +
    s"        removeBit(bit);\n" +
    s"      }\n" +
    s"    }\n" +
    s"    \n" +
    s"    void switchAllBits(std::set<${bitEnum.improvedName}> bits){\n" +
    s"      for(auto bit : bits){\n" +
    s"        switchBit(bit);\n" +
    s"      }\n" +
    s"    }\n" +
    s"    \n" +
    s"    $getGetters\n" +
    s"    \n" +
    s"    $getSetters\n" +
    s"    \n" +
    s"    $getAdders\n" +
    s"    \n" +
    s"    $getRemovers\n" +
    s"    \n" +
    s"    $getSwitchers\n" +
    s"    \n" +
    s"    $getAllSetter\n" +
    s"    \n" +
    s"    $getAllAdder\n" +
    s"    \n" +
    s"    $getAllRemover\n" +
    s"    \n" +
    s"    $getAllSwitcher\n" +
    s"    \n" +
    s"    $getToString\n" +
    s"  private:\n" +
    s"    $name $memberName;\n" +
    s"}\n"

  def getGetters : String = s"${bitEnum.values.map(b => s"bool get${b._2}(){\n" +
    s"  return $memberName & ${bitEnum.improvedName}::${b._2};\n" +
    s"}").mkString("\n\n").replaceAll("\n","\n    ")}"

  def getSetters : String = s"${bitEnum.values.map(b => s"void set${b._2}(bool value){\n" +
    s"  if(value){\n" +
    s"    add${b._2}();\n" +
    s"  }else{\n" +
    s"    remove${b._2}();\n" +
    s"  }\n" +
    s"}").mkString("\n\n").replaceAll("\n","\n    ")}"

  def getAdders : String = s"${bitEnum.values.map(b => s"void add${b._2}(){\n" +
    s"  memberName |= ${bitEnum.improvedName}::e${b._2};\n" +
    s"}").mkString("\n\n").replaceAll("\n","\n    ")}"

  def getRemovers : String = s"${bitEnum.values.map(b => s"void remove${b._2}(){\n" +
    s"  memberName &= ~${bitEnum.improvedName}::e${b._2};\n" +
    s"}").mkString("\n\n").replaceAll("\n","\n    ")}"

  def getSwitchers : String = s"${bitEnum.values.map(b => s"void switch${b._2}(){\n" +
    s"  memberName ^= ${bitEnum.improvedName}::e${b._2};\n" +
    s"}").mkString("\n\n").replaceAll("\n","\n    ")}"

  def getAllSetter : String = s"void setAll(bool value){\n" +
    s"      ${bitEnum.values.map(b => s"set${b._2}(value);").mkString("\n      ")}\n" +
    s"    }"

  def getAllAdder : String = s"void addAll(){\n" +
    s"      ${bitEnum.values.map(b => s"add${b._2}();").mkString("\n      ")}\n" +
    s"    }"

  def getAllRemover : String = s"void removeAll(){\n" +
    s"      ${bitEnum.values.map(b => s"remove${b._2}();").mkString("\n      ")}\n" +
    s"    }"

  def getAllSwitcher : String = s"void switchAll(){\n" +
    s"      ${bitEnum.values.map(b => s"switch${b._2}();").mkString("\n      ")}\n" +
    s"    }"

  def getToString : String = s"std::string toString(){\n" +
    s"      if(!$memberName) return $g{}$g;\n" +
    s"      std::string result;\n" +
    s"      ${bitEnum.values.map(b => s"if(get${b._2}()) result += $g${b._2} | $g;").mkString("\n      ")}\n" +
    s"      return $g{$g + result.substr(0,result.size()-3) + $g}$g;\n" +
    s"    }"
}
