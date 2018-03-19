package vulkan.wrapper

import scala.xml.XML
import java.io.{BufferedWriter, File, FileWriter}
import java.sql.DriverManager
import javax.xml.parsers.DocumentBuilderFactory

import org.w3c.dom.{Element, NodeList}
import vulkan.wrapper.generator.VulkanRegistry
import javax.xml.transform.TransformerFactory
import javax.xml.transform.dom.DOMSource
import javax.xml.transform.stream.StreamResult

import vulkan.wrapper.entitycomponent.World
import vulkan.wrapper.entitycomponent.entity.vulkanxml.VulkanTransformer
import vulkan.wrapper.entitycomponent.pipeline._
import vulkan.wrapper.registry.Registry
import vulkan.wrapper.util.Requestable

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