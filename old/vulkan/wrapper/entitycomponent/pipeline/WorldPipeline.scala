package vulkan.wrapper.entitycomponent.pipeline

import vulkan.wrapper.entitycomponent.World

/**
  * Created by philipp on 26.02.18.
  */
class WorldPipeline(val func: World => World){
  def -->(worldPipeline: WorldPipeline) = new WorldPipeline(world => worldPipeline.func(func(world)))
}
