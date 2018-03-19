package vulkan.wrapper

import java.security.Policy.Parameters
import java.sql.Connection

import org.w3c.dom.{Document, Element, Node}

import scala.collection.mutable
import scala.collection.mutable.ListBuffer

/**
  * Created by philipp on 19.09.17.
  */
class VulkanXmlWrapper(input:Document) {
  input.getElementsByTagName("comment")
    .foreach(e => e.getParentNode().removeChild(e));

  val basetypes = Map("VkDeviceSize" -> "std::size_t",
    "VkBool32" -> "bool")

  val registry = input.getDocumentElement

  val prefixes = registry.getChildsWithTagName("vendorids")
    .flatMap(e => e.getChildsWithTagName("vendorid")
      .map(e => new Prefix(e.getAttribute("name")))
      .map(e => (e.name, e)))
    .toMap ++ registry.getChildsWithTagName("tags")
    .flatMap(_.getChildsWithTagName("tag")
      .map(e => new Prefix(e.getAttribute("name")))
      .map(e => (e.name, e)))
    .toMap

  val types = registry.getChildsWithTagName("types")
    .flatMap(_.getChildsWithTagName("type"))

  val handles = types.filter(_.getAttribute("category") == "handle")
    .map(e => new Handle(e.getFirstChildWithTagName("name").getTextContent, e.getAttribute("parent").split(",").filter(_.nonEmpty)))
    .map(e => (e.name, e))
    .toMap

  val commands = registry.getChildsWithTagName("commands")
    .flatMap(_.getChildsWithTagName("command"))
    .map(e => (e.getFirstChildWithTagName("proto"), e.getChildsWithTagName("param"),e))
    .map(e => new Command(e._1.getFirstChildWithTagName("name").getTextContent,
      betterSplit(e._1.getTextContent).init.mkString(" "),
      e._1.getFirstChildWithTagName("type").getTextContent,
      e._2.map(i => new Param(i.getFirstChildWithTagName("name").getTextContent,
        betterSplit(i.getTextContent).init.mkString(" "),
        i.getFirstChildWithTagName("type").getTextContent,
        i.getAttribute("len").split(",").filter(_.nonEmpty),
        i.getAttribute("optional").split(",").filter(_.nonEmpty),
        i.getAttribute("externsync"),
        i.getAttribute("noautovalidity")))
        .toArray,
      e._3.getAttribute("queues").split(",").filter(_.nonEmpty),
      e._3.getAttribute("pipeline"),
      e._3.getAttribute("cmdbufferlevel"),
      e._3.getAttribute("renderpass"),
      e._3.getAttribute("successcodes").split(",").filter(_.nonEmpty),
      e._3.getAttribute("errorcodes").split(",").filter(_.nonEmpty)))
    .map(e => (e.name, e))
    .toMap

  val bitMasks = types.filter(_.getAttribute("category") == "bitmask")
    .map(e => new BitMask(e.getFirstChildWithTagName("name").getTextContent))
    .map(e => (e.name,e))
    .toMap

  val enumElements = registry.getChildsWithTagName("enums")

  enumElements.filter(_.getAttribute("type") == "bitmask")
    .map(e => (e.getAttribute("name"),e.getChildsWithTagName("enum").map(i => new Bit(i.getAttribute("name")))))
    .foreach(e => {
      val bitmask = bitMasks(e._1.replace("FlagBits","Flags"))
      bitmask.bitName = e._1
      bitmask.bits = e._2.toArray
      e._2.foreach(i => i.bitMask = bitmask);
    })

  val enums = types.filter(_.getAttribute("category") == "enum")
    .map(e => new Enum(e.getAttribute("name")))
    .map(e => (e.name,e))
    .toMap

  enumElements.filter(_.getAttribute("type") == "enum")
    .foreach(e => enums(e.getAttribute("name")).values = e.getChildsWithTagName("enum").map(_.getAttribute("name")).toArray)

  val funcPointers = types.filter(_.getAttribute("category") == "funcpointer")
    .map(e => (e.getTextContent,e.getFirstChildWithTagName("name").getTextContent,e.getChildsWithTagName("type").map(_.getTextContent)))
    .map(e => (e._2,
      e._1
        .stripPrefix("typedef ")
        .takeWhile(_!='(')
        .trim,
      e._1
        .dropWhile(_!='(')
        .drop(1)
        .dropWhile(_!='(')
        .drop(1)
        .takeWhile(_!=')')
        .split(",")
        .filter(_.nonEmpty)
        .map(i => betterSplit(i))
        .zip(e._3)
        .map(i => (i._1.init.mkString(" "),i._2,i._1.last))))
    .map(e => new FuncPointer(e._1,e._2,e._2/*.replaceAll("*","").replaceAll("const","").trim*/,e._3.map(i => new FuncPointerParam(i._3,i._1,i._2))))
    .map(e => (e.name,e))
    .toMap

  val structs = types.filter(_.getAttribute("type") == "struct")
    .map(e => new Struct(e.getAttribute("name"),
      e.getAttribute("structextends").split(",").filter(_.nonEmpty),
      e.getAttribute("returnedonly"),
      e.getChildsWithTagName("member")
        .map(e => (betterSplit(e.getTextContent),e))
        .map(e => new Member(e._1.last,
          e._1.init.mkString(" "),
          e._2.getFirstChildWithTagName("type").getTextContent,
          e._2.getAttribute("len").split(",").filter(_.nonEmpty),
          e._2.getAttribute("values").split(",").filter(_.nonEmpty),
          e._2.getAttribute("optional").split(",").filter(_.nonEmpty),
          e._2.getAttribute("externsync"),
          e._2.getAttribute("noautovalidity")))
        .toArray))

  val unions = types.filter(_.getAttribute("type") == "struct")
    .map(e => new Union(e.getAttribute("name"),
      e.getAttribute("returnedonly"),
      e.getChildsWithTagName("member")
        .map(e => (betterSplit(e.getTextContent),e))
        .map(e => new Member(e._1.last,
          e._1.init.mkString(" "),
          e._2.getFirstChildWithTagName("type").getTextContent,
          e._2.getAttribute("len").split(",").filter(_.nonEmpty),
          e._2.getAttribute("values").split(",").filter(_.nonEmpty),
          e._2.getAttribute("optional").split(",").filter(_.nonEmpty),
          e._2.getAttribute("externsync"),
          e._2.getAttribute("noautovalidity")))
        .toArray))

  bitMasks.values.foreach(_.update1())
  handles.values.foreach(_.update1())
  commands.values.foreach(_.update1())

  commands.map(c => c._2.improvedName.takeWhile(d => d.isLower)).toSet.foreach((c:String) => println(c))

  class Prefix(val name:String){

  }

  class Handle(val name:String,val parents:Array[String]){
    val improvedName = name.stripPrefix("Vk")
    val varName = firstLower(improvedName)
    var improvedParents:Array[Handle] = null
    var improvedChilds:Array[Handle] = null
    var childs:Array[String] = null
    val commandConfigurations:ListBuffer[CommandConfiguration] = ListBuffer()

    def update1(): Unit ={
      improvedParents = parents.map(handles(_))
      improvedChilds = handles.values.filter(_.parents.contains(name)).toArray
      childs = improvedChilds.map(_.name)
    }

    def isParrent(handle: Handle): Array[Handle] =
      if(handle == this)
        return Array(this)
      else
        improvedParents.map(_.isParrent(handle)).find(_.nonEmpty).map(a => Array(this) ++ a).getOrElse(Array.empty)

    def isChild(handle: Handle): Array[Handle] =
      if(handle == this)
        return Array(this)
      else
        improvedChilds.map(_.isChild(handle)).find(_.nonEmpty).map(a => Array(this) ++ a).getOrElse(Array.empty)

    def isRelated(handle: Handle): Array[Handle] = Option(isParrent(handle)).filter(_.nonEmpty).getOrElse(Option(isChild(handle)).filter(_.nonEmpty).getOrElse(if(handle==this) Array(this) else Array()))
  }

  class Command(val name:String,val returnType:String,val pureReturnType:String,val parameters: Array[Param],val queues:Array[String],val pipeline:String,val cmdbufferlevel:String,val renderpass:String,val successcodes:Array[String],val errorcodes:Array[String]){
    parameters.foreach(_.command = this);

    val improvedName = firstLower(name.stripPrefix("vk"))
    val graphicCommand = improvedName.startsWith("cmd")
    var commandConfigurations: Array[CommandConfiguration] = Array()
    var opperation = improvedName.takeWhile(_.isLower)

    def update1(): Unit ={
      parameters.foreach(_.update1())

      val improvedHandles = parameters
        .filter(p => handles.contains(p.valueType))
        .map(p => (p,handles(p.valueType)))

      val highest = improvedHandles.filterNot(h => improvedHandles.filter(_!=h).exists(_._2.isParrent(h._2).nonEmpty))

      commandConfigurations = highest
        .map(h => new CommandConfiguration(this,h._2,improvedHandles.filter(_._2.isChild(h._2).nonEmpty).map(_._1) ++ Array(h._1)))

      commandConfigurations.foreach(c => c.masterHandle.commandConfigurations += c)
    }
  }

  class CommandConfiguration(val command: Command, val masterHandle: Handle, val parrentHandleProperties: Array[Param]){
    val parameters = command.parameters
      .map(p => (p,parrentHandleProperties.contains(p)))
      .map(p => new ParamConfiguration(p._1,p._2,if(p._2) masterHandle.isParrent(handles(p._1.valueType)) else Array.empty))
  }

  class Param(val name:String,val valueType:String,val pureType:String,val len:Array[String],val optional:Array[String],val externsync:String,val noautovalidity:String) {
    var improvedType = "";
    var improvedPureType = "";
    var lenParams:mutable.ListBuffer[Param] = mutable.ListBuffer()
    if (handles.contains(pureType)) {
      improvedType = handles(pureType).improvedName
      improvedPureType = handles(pureType).improvedName
      //println(pureType,improvedType)
    }else if (basetypes.contains(pureType)) {
      improvedType = valueType.replace(pureType, basetypes(pureType))
      improvedPureType = basetypes(pureType)
      //println(pureType,improvedType)
    }else{
      improvedType = valueType
      improvedPureType = pureType
    }
    val improvedName = firstLower(name.stripPrefix("p*[A-Z]".r.findPrefixOf(name).getOrElse("").dropRight(1)))

    var command:Command = null

    var writeParam:Boolean = true

    var lenParam:Param = null;

    var returnParam = !valueType.startsWith("const") && !valueType.startsWith("struct") && valueType.endsWith("*")
    var orginReturnParam = returnParam;

    def update1(): Unit ={
      if(len.nonEmpty){
        improvedType = improvedPureType
      }

      for(leni <- len.reverse){
        if(leni == "null-terminated"){
          improvedType = "std::string"
        }else{
          //TODO: Parameter Reduction+
          lenParams ++= command.parameters.filter(_.name == leni)
          improvedType = s"std::vector<$improvedType>"
        }
      }
      lenParams.foreach(_.writeParam = false)
      lenParams.foreach(_.lenParam = this)

      if(returnParam)
        lenParams.foreach(_.returnParam = true)
    }
  }

  class ParamConfiguration(val param: Param,val isHandle:Boolean,val handlePath:Array[Handle]){

  }

  class BitMask(val name:String){
    var vendor = ""
    var improvedName = ""
    var bitName:String = ""
    var bits:Array[Bit] = Array()

    def update1(): Unit ={
      for(prefix <- prefixes.keys){
        if(name.endsWith(prefix)){
          vendor = prefix
        }
      }
      improvedName = name.stripPrefix("Vk").stripSuffix(vendor).stripSuffix("Flags")
      bits.foreach(_.update1())
    }
  }

  class Bit(val name:String){
    var improvedName = ""
    var bitMask:BitMask = null
    def update1(): Unit ={
      improvedName = firstLower(name.split("_")
        .drop(1)
        .filterNot(_ == "BIT")
        .filterNot(prefixes.contains(_))
        .map(e => e.charAt(0) + e.substring(1).toLowerCase)
        .mkString("")
        .replace(bitMask.improvedName,""))
    }
  }

  class Enum(val name:String){
    var values:Array[String] = Array()
  }

  class FuncPointer(val name:String,val returnType:String,val pureReturnType:String,val parameters: Array[FuncPointerParam]){
    val improvedName = name.stripPrefix("PFN_vk")
  }

  class FuncPointerParam(val name:String,val valueType:String,val pureType:String){

  }

  class Union(val name:String,val returnedOnly:String,val members: Array[Member]){
    val improvedName = name.stripPrefix("Vk")
    val lens = members.flatMap(_.len).toSet
    val improvedMembers = members.filterNot(m => lens.contains(m.name)).filter(_.values.isEmpty)
    val improvedValueMembers = members.filter(_.values.nonEmpty)
  }

  class Struct(val name:String,val structExtends:Array[String],val returnedOnly:String,val members: Array[Member]){
    val improvedName = name.stripPrefix("Vk")
    val lens = members.flatMap(_.len).toSet
    val improvedMembers = members.filterNot(m => lens.contains(m.name))
  }

  class Member(val name:String,val valueType:String,val pureType:String,val len:Array[String],val values:Array[String],val optional:Array[String],val externSync:String,val noautovalidity:String){

  }

  class Extension(val name:String){

  }


  def generateCpp17():String = {
    def writeHandle(handle: Handle): String = {
      def writeParrentVar(handle: Handle):String = {
        s"${handle.improvedName} ${handle.varName};"
      }

      def writeParrentParam(handle: Handle):String = {
        s"${handle.improvedName} ${handle.varName}_"
      }

      def writeParrentInit(handle: Handle):String ={
        s"${handle.varName}(${handle.varName}_)"
      }

      /*def writeCommand(commandConfiguration: CommandConfiguration): String ={
        def writeParameter(paramConfiguration: ParamConfiguration): String ={
          s"${paramConfiguration.param.improvedType} ${paramConfiguration.param.improvedName}"
        }

        def writeProcess(paramConfiguration: ParamConfiguration):String ={
          if(paramConfiguration.isHandle)
            if(paramConfiguration.handlePath.length==1)
              s"${paramConfiguration.handlePath(0).varName}"
            else
              s"(${paramConfiguration.handlePath.last.name})${paramConfiguration.handlePath.drop(1).map(_.varName).mkString(".")}"
          else
            if(paramConfiguration.param.lenParams.nonEmpty)
              s"${paramConfiguration.param.improvedName}.data()"
            else
              if(paramConfiguration.param.lenParam!=null)
                s"${paramConfiguration.param.lenParam.improvedName}.size()"
              else
                s"${paramConfiguration.param.improvedName}"
        }

        def writeReturnParam(paramConfiguration: ParamConfiguration):String ={
          s"${paramConfiguration.param.valueType} ${paramConfiguration.param.name};"
        }

        def writeCommandReturn(paramConfiguration: Array[ParamConfiguration],i:Int):String ={
          if(paramConfiguration.nonEmpty)
            s"${paramConfiguration(i).param.improvedType} ${paramConfiguration(i).param.improvedName}${if(paramConfiguration(i).param.lenParams.nonEmpty) paramConfiguration(i).param.lenParams.map(_.improvedName).mkString("(",",",")") else ""};\n" +
              s"${commandConfiguration.command.name}(${commandConfiguration.parameters.map(p => if(!p.param.returnParam) writeProcess(p) else if(paramConfiguration.take(i+1).contains(p)) {if(p.param.lenParams.nonEmpty) p.param.improvedName+".data()" else p.param.improvedName} else "null").mkString(",")});"
          else
            s"${commandConfiguration.command.name}(${commandConfiguration.parameters.map(writeProcess(_)).mkString(",")});"
        }

        val returns = commandConfiguration.parameters.filter(_.param.returnParam);

        s"${commandConfiguration.command.improvedReturnType} ${commandConfiguration.command.improvedName}(${commandConfiguration.parameters.filterNot(_.isHandle).filter(_.param.writeParam).map(writeParameter(_)).mkString(",")}){\n" +
          s"  ${if(returns.isEmpty) if(commandConfiguration.command.improvedReturnType=="void") writeCommandReturn(Array(),0) else "return "+writeCommandReturn(Array(),0) else indentation((0 until returns.length).map(writeCommandReturn(returns,_)).mkString("\n\n"),"  ")}\n" +
          s"${commandConfiguration.parameters.reverse.find(_.param.returnParam).map(p => "  \n  return "+p.param.improvedName+";\n").getOrElse("")}" +
          s"}"
      }*/

      def writeCommand(commandConfiguration: CommandConfiguration): String ={
        def writeCommandReturnType(commandConfiguration: CommandConfiguration): String ={
          val returns = commandConfiguration.parameters.filter(_.param.returnParam).filterNot(_.isHandle).filter(_.param.writeParam).map(_.param.improvedType) ++ Option(commandConfiguration.command.returnType).filterNot(_=="void")
          returns.length match {
            case 0 => s"void"
            case 1 => s"${returns.head}"
            case x => s"std::tuple<${returns.mkString(",")}>"
          }
        }

        def writeCommandParameters(commandConfiguration: CommandConfiguration):String ={
          def writeCommandParameter(paramConfiguration: ParamConfiguration): String ={
            s"${paramConfiguration.param.improvedType} ${paramConfiguration.param.improvedName}"
          }

          s"${commandConfiguration.parameters.filterNot(_.isHandle).filter(_.param.writeParam).filterNot(_.param.returnParam).map(writeCommandParameter(_)).mkString(",")}"
        }

        s"${writeCommandReturnType(commandConfiguration)} ${commandConfiguration.command.improvedName}(${writeCommandParameters(commandConfiguration)}){\n" +
          s"  \n" +
          s"}"
      }

      s"class ${handle.improvedName}{\n" +
        s"  public:\n" +
        s"    ${handle.improvedName}(${handle.name} ${handle.varName}_,${handle.improvedParents.map(writeParrentParam(_)).mkString(",")})\n" +
        s"      : ${handle.varName}(${handle.varName}_),\n" +
        s"        ${indentation(handle.improvedParents.map(writeParrentInit(_)).mkString(",\n"),"        ")}{\n" +
        s"    }\n" +
        s"    \n" +
        s"    ${indentation(handle.commandConfigurations.map(writeCommand(_)).mkString("\n\n"),"    ")}\n" +
        s"  private:\n" +
        s"    ${handle.name} ${handle.varName};\n" +
        s"    ${indentation(handle.improvedParents.map(writeParrentVar(_)).mkString("\n"),"    ")}\n" +
        s"}"
    }

    "namespace vk{\n" +
      s"  ${indentation(handles.values.map(writeHandle(_)).mkString("\n\n"),"  ")}"
  }
}
