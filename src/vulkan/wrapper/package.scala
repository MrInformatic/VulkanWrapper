package vulkan

import java.io.{BufferedReader, Reader}
import java.nio.CharBuffer

import org.w3c.dom.{Element, Node, NodeList}

/**
  * Created by philipp on 30.08.17.
  */
package object wrapper {
  implicit def nodeListToArray(nodeList: NodeList) = (0 until nodeList.getLength).map(nodeList.item(_))

  def firstLower(value:String):String = value.charAt(0).toLower + value.substring(1)
  def firstUpper(value:String):String = value.charAt(0).toUpper + value.substring(1)
  def betterSplit(value:String):Array[String] = "(\\S+)".r.findAllMatchIn(value.trim).map(_.group(1)).toArray

  def indentation(value:String,indentation:String):String = value.replaceAll("\n",s"\n$indentation")

  class BetterElement(val element: Element){
    def getChildsWithTagName(tagName:String) = element.getChildNodes
      .filter(_.getNodeType==Node.ELEMENT_NODE)
      .map(e => e.asInstanceOf[Element])
      .filter(_.getTagName==tagName)

    def getFirstChildWithTagName(tagName:String) = getChildsWithTagName(tagName)(0)
  }

  implicit def toBetterElement(element:Element):BetterElement = new BetterElement(element);
  implicit def toElement(betterElement:BetterElement):Element = betterElement.element;

}
