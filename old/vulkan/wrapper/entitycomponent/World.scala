package vulkan.wrapper.entitycomponent


import scala.reflect.ClassTag

/**
  * Created by philipp on 19.02.18.
  */
class World(val entities: Traversable[Entity] = Traversable()) {
  entities.foreach(_.world = Option(this))

  def getEntities[T <: Entity](implicit tag:ClassTag[T]): Traversable[T] = {
    entities.filter(tag.runtimeClass.isInstance).map(_.asInstanceOf[T])
  }
}

