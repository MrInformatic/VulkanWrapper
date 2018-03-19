package vulkan.wrapper

import org.w3c.dom.{Attr, NamedNodeMap, Node}

/**
  * Created by philipp on 23.02.18.
  */
package object entitycomponent {
  implicit def SeqToWorld(entities: Traversable[Entity]): World = new World(entities)
  implicit def WorldToSeq(world: World): Traversable[Entity] = world.entities
}
