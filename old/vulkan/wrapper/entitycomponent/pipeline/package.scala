package vulkan.wrapper.entitycomponent

/**
  * Created by philipp on 26.02.18.
  */
package object pipeline {
  implicit def funcToWorldPipeline(func: World => World): WorldPipeline = new WorldPipeline(func)
  implicit def worldPipelineTofunc(pipeline: WorldPipeline): World => World = pipeline.func
}
