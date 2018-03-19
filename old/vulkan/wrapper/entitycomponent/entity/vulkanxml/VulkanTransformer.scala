package vulkan.wrapper.entitycomponent.entity.vulkanxml

import vulkan.wrapper.entitycomponent.{Entity, World}
import vulkan.wrapper.entitycomponent.pipeline.WorldPipeline

/**
  * Created by philipp on 25.02.18.
  */
object VulkanTransformer {
  /*val transformRegistryPipe: WorldPipeline = (w:World) => transformRegistry(w)

  def transformRegistry(world: World): World ={
    world ++ world.getEntities[XMLNode]
      .filter(XMLNode.checkXMLPath(_,Traversable("registry")))
      .map(new RegistryEntity(_))
  }

  val transformVendorIdsPipe: WorldPipeline = (w:World) => transformVendorIds(w)

  def transformVendorIds(world: World): World ={
    world.getEntities[XMLNode]
      .filter(XMLNode.checkXMLPath(_,Traversable("vendorid","vendorids","registry")))
      .map(_.attribute)
      .foreach(println)

    world.getEntities[XMLNode]
      .filter(XMLNode.checkXMLPath(_,Traversable("vendorid","vendorids","registry")))
      .map(e => new VendorIdEntity(e.attribute("name"),e.attribute("id").toInt,e.attribute.get("comment")))
      .foreach(e => println(s"name = ${e.name} id = ${e.id}"))

    world ++ world.getEntities[XMLNode]
      .filter(XMLNode.checkXMLPath(_,Traversable("vendorid","vendorids","registry")))
      .map(e => new VendorIdEntity(e.attribute("name"),e.attribute("id").toInt,e.attribute.get("comment")))
  }

  val transformPipe: WorldPipeline = transformRegistryPipe -->
    transformVendorIdsPipe*/
}
