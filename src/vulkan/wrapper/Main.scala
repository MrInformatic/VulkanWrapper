package vulkan.wrapper

import java.io.{BufferedWriter, File, FileWriter}
import java.sql.DriverManager
import javax.xml.parsers.DocumentBuilderFactory

import org.w3c.dom.{Element, NodeList}
import vulkan.wrapper.generator.VulkanRegistry
import javax.xml.transform.TransformerFactory
import javax.xml.transform.dom.DOMSource
import javax.xml.transform.stream.StreamResult

/**
  * Created by philipp on 29.08.17.
  */
object Main {
  def main(args:Array[String]): Unit = {
    val dbf = DocumentBuilderFactory.newInstance
    val db = dbf.newDocumentBuilder
    val input = db.parse(new File("vk.xml"))

    val registry = new VulkanXmlWrapper(input)

    val writer = new BufferedWriter(new FileWriter(new File("vulkanwrapper.hpp")))
    writer.write(registry.generateCpp17())
    writer.close()
  }
}
