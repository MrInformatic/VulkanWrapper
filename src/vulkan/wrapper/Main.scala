package vulkan.wrapper

import java.io.File
import javax.xml.parsers.DocumentBuilderFactory

import vulkan.wrapper.registry.Registry

/**
  * Created by philipp on 29.08.17.
  */
object Main {
  def main(args:Array[String]): Unit = {
    val dbf = DocumentBuilderFactory.newInstance
    val db = dbf.newDocumentBuilder
    val input = db.parse(new File("vk.xml"))


    new Registry
  }
}