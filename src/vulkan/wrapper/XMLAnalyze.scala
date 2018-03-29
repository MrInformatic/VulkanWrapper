package vulkan.wrapper

import scala.xml.XML

object XMLAnalyze {
  def main(args: Array[String]): Unit ={
    val xml = XML.loadFile("vk.xml")

    /*(xml \ "extensions" \ "extension" \ "require" \ "enum")
      .filter(_.attributes.forall(i => Set("name","comment").contains(i.key)))
      .map(_ \@ "name").foreach(println)*/

    val attrs = (xml \ "extensions" \ "extension" \ "require" \ "enum")
      .map(_.attributes.map(_.key).toSet)
      .toSet

    attrs
      .foreach(println)

    /*println("--Required--")
    val required = attrs
      .reduce(_ & _)
    required.foreach(println)

    println("--Option--")
    val option = attrs
      .reduce(_ | _) &~ required
    option.foreach(println)*/

    val attr = attrs
      .reduce(_ | _)

    /*val test = attr
      .subsets
      .filter(i => attrs.forall(_.count(i.contains)<=1))

    test
      //.filterNot(i => test.filterNot(i => true).exists(n => i subsetOf n))
      .foreach(println)

    val test2 = Set(Set(1),Set(1,2))
    test2.filterNot(i => test2.filterNot(i==_).exists(n => i subsetOf n))
      .foreach(println)*/
  }
}
