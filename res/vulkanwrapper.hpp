namespace vk{
  class DescriptorPool{
    public:
      DescriptorPool(VkDescriptorPool descriptorPool_,Device device_)
        : descriptorPool(descriptorPool_),
          device(device_){
      }
      
      VkResult freeDescriptorSets(Device device,DescriptorPool descriptorPool,std::vector<DescriptorSet> descriptorSets){
        vkFreeDescriptorSets(device,descriptorPool,descriptorSetCount,descriptorSets);
      }
      
      VkResult resetDescriptorPool(Device device,DescriptorPool descriptorPool,VkDescriptorPoolResetFlags flags){
        vkResetDescriptorPool(device,descriptorPool,flags);
      }
      
      void destroyDescriptorPool(Device device,DescriptorPool descriptorPool,const VkAllocationCallbacks* allocator){
        vkDestroyDescriptorPool(device,descriptorPool,allocator);
      }
    private:
      VkDescriptorPool descriptorPool;
      Device device;
  }
  
  class Semaphore{
    public:
      Semaphore(VkSemaphore semaphore_,Device device_)
        : semaphore(semaphore_),
          device(device_){
      }
      
      VkResult acquireNextImageKHR(Device device,SwapchainKHR swapchain,uint64_t timeout,Semaphore semaphore,Fence fence,uint32_t* imageIndex){
        vkAcquireNextImageKHR(device,swapchain,timeout,semaphore,fence,imageIndex);
      }
      
      void destroySemaphore(Device device,Semaphore semaphore,const VkAllocationCallbacks* allocator){
        vkDestroySemaphore(device,semaphore,allocator);
      }
    private:
      VkSemaphore semaphore;
      Device device;
  }
  
  class ValidationCacheEXT{
    public:
      ValidationCacheEXT(VkValidationCacheEXT validationCacheEXT_,Device device_)
        : validationCacheEXT(validationCacheEXT_),
          device(device_){
      }
      
      VkResult getValidationCacheDataEXT(Device device,ValidationCacheEXT validationCache,std::vector<void> data){
        vkGetValidationCacheDataEXT(device,validationCache,dataSize,data);
      }
      
      VkResult mergeValidationCachesEXT(Device device,ValidationCacheEXT dstCache,std::vector<ValidationCacheEXT> srcCaches){
        vkMergeValidationCachesEXT(device,dstCache,srcCacheCount,srcCaches);
      }
      
      void destroyValidationCacheEXT(Device device,ValidationCacheEXT validationCache,const VkAllocationCallbacks* allocator){
        vkDestroyValidationCacheEXT(device,validationCache,allocator);
      }
    private:
      VkValidationCacheEXT validationCacheEXT;
      Device device;
  }
  
  class RenderPass{
    public:
      RenderPass(VkRenderPass renderPass_,Device device_)
        : renderPass(renderPass_),
          device(device_){
      }
      
      void destroyRenderPass(Device device,RenderPass renderPass,const VkAllocationCallbacks* allocator){
        vkDestroyRenderPass(device,renderPass,allocator);
      }
      
      void getRenderAreaGranularity(Device device,RenderPass renderPass,VkExtent2D* granularity){
        vkGetRenderAreaGranularity(device,renderPass,granularity);
      }
    private:
      VkRenderPass renderPass;
      Device device;
  }
  
  class DisplayModeKHR{
    public:
      DisplayModeKHR(VkDisplayModeKHR displayModeKHR_,PhysicalDevice physicalDevice_,DisplayKHR displayKHR_)
        : displayModeKHR(displayModeKHR_),
          physicalDevice(physicalDevice_),
          displayKHR(displayKHR_){
      }
      
      VkResult getDisplayPlaneCapabilitiesKHR(PhysicalDevice physicalDevice,DisplayModeKHR mode,uint32_t planeIndex,VkDisplayPlaneCapabilitiesKHR* capabilities){
        vkGetDisplayPlaneCapabilitiesKHR(physicalDevice,mode,planeIndex,capabilities);
      }
    private:
      VkDisplayModeKHR displayModeKHR;
      PhysicalDevice physicalDevice;
      DisplayKHR displayKHR;
  }
  
  class Sampler{
    public:
      Sampler(VkSampler sampler_,Device device_)
        : sampler(sampler_),
          device(device_){
      }
      
      void destroySampler(Device device,Sampler sampler,const VkAllocationCallbacks* allocator){
        vkDestroySampler(device,sampler,allocator);
      }
    private:
      VkSampler sampler;
      Device device;
  }
  
  class Queue{
    public:
      Queue(VkQueue queue_,Device device_)
        : queue(queue_),
          device(device_){
      }
      
      VkResult queueWaitIdle(Queue queue){
        vkQueueWaitIdle(queue);
      }
      
      VkResult queueSubmit(Queue queue,std::vector<VkSubmitInfo> submits,Fence fence){
        vkQueueSubmit(queue,submitCount,submits,fence);
      }
      
      VkResult queueBindSparse(Queue queue,std::vector<VkBindSparseInfo> bindInfo,Fence fence){
        vkQueueBindSparse(queue,bindInfoCount,bindInfo,fence);
      }
      
      VkResult queuePresentKHR(Queue queue,const VkPresentInfoKHR* presentInfo){
        vkQueuePresentKHR(queue,presentInfo);
      }
    private:
      VkQueue queue;
      Device device;
  }
  
  class SamplerYcbcrConversionKHR{
    public:
      SamplerYcbcrConversionKHR(VkSamplerYcbcrConversionKHR samplerYcbcrConversionKHR_,Device device_)
        : samplerYcbcrConversionKHR(samplerYcbcrConversionKHR_),
          device(device_){
      }
      
      void destroySamplerYcbcrConversionKHR(Device device,SamplerYcbcrConversionKHR ycbcrConversion,const VkAllocationCallbacks* allocator){
        vkDestroySamplerYcbcrConversionKHR(device,ycbcrConversion,allocator);
      }
    private:
      VkSamplerYcbcrConversionKHR samplerYcbcrConversionKHR;
      Device device;
  }
  
  class CommandPool{
    public:
      CommandPool(VkCommandPool commandPool_,Device device_)
        : commandPool(commandPool_),
          device(device_){
      }
      
      void trimCommandPoolKHR(Device device,CommandPool commandPool,VkCommandPoolTrimFlagsKHR flags){
        vkTrimCommandPoolKHR(device,commandPool,flags);
      }
      
      VkResult resetCommandPool(Device device,CommandPool commandPool,VkCommandPoolResetFlags flags){
        vkResetCommandPool(device,commandPool,flags);
      }
      
      void destroyCommandPool(Device device,CommandPool commandPool,const VkAllocationCallbacks* allocator){
        vkDestroyCommandPool(device,commandPool,allocator);
      }
      
      void freeCommandBuffers(Device device,CommandPool commandPool,std::vector<CommandBuffer> commandBuffers){
        vkFreeCommandBuffers(device,commandPool,commandBufferCount,commandBuffers);
      }
    private:
      VkCommandPool commandPool;
      Device device;
  }
  
  class DescriptorSet{
    public:
      DescriptorSet(VkDescriptorSet descriptorSet_,DescriptorPool descriptorPool_)
        : descriptorSet(descriptorSet_),
          descriptorPool(descriptorPool_){
      }
      
      void updateDescriptorSetWithTemplateKHR(Device device,DescriptorSet descriptorSet,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,const void* data){
        vkUpdateDescriptorSetWithTemplateKHR(device,descriptorSet,descriptorUpdateTemplate,data);
      }
    private:
      VkDescriptorSet descriptorSet;
      DescriptorPool descriptorPool;
  }
  
  class DescriptorSetLayout{
    public:
      DescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout_,Device device_)
        : descriptorSetLayout(descriptorSetLayout_),
          device(device_){
      }
      
      void destroyDescriptorSetLayout(Device device,DescriptorSetLayout descriptorSetLayout,const VkAllocationCallbacks* allocator){
        vkDestroyDescriptorSetLayout(device,descriptorSetLayout,allocator);
      }
    private:
      VkDescriptorSetLayout descriptorSetLayout;
      Device device;
  }
  
  class SurfaceKHR{
    public:
      SurfaceKHR(VkSurfaceKHR surfaceKHR_,Instance instance_)
        : surfaceKHR(surfaceKHR_),
          instance(instance_){
      }
      
      VkResult getPhysicalDevicePresentRectanglesKHX(PhysicalDevice physicalDevice,SurfaceKHR surface,std::vector<VkRect2D> rects){
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surface,rectCount,rects);
      }
      
      void destroySurfaceKHR(Instance instance,SurfaceKHR surface,const VkAllocationCallbacks* allocator){
        vkDestroySurfaceKHR(instance,surface,allocator);
      }
      
      VkResult getPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice physicalDevice,SurfaceKHR surface,std::vector<VkPresentModeKHR> presentModes){
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surface,presentModeCount,presentModes);
      }
      
      VkResult getDeviceGroupSurfacePresentModesKHX(Device device,SurfaceKHR surface,VkDeviceGroupPresentModeFlagsKHX* modes){
        vkGetDeviceGroupSurfacePresentModesKHX(device,surface,modes);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2EXT(PhysicalDevice physicalDevice,SurfaceKHR surface,VkSurfaceCapabilities2EXT* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surface,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceSurfaceSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex,SurfaceKHR surface,bool* supported){
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,surface,supported);
      }
      
      VkResult getPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice physicalDevice,SurfaceKHR surface,std::vector<VkSurfaceFormatKHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surface,surfaceFormatCount,surfaceFormats);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice physicalDevice,SurfaceKHR surface,VkSurfaceCapabilitiesKHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surface,surfaceCapabilities);
      }
    private:
      VkSurfaceKHR surfaceKHR;
      Instance instance;
  }
  
  class Event{
    public:
      Event(VkEvent event_,Device device_)
        : event(event_),
          device(device_){
      }
      
      void cmdResetEvent(CommandBuffer commandBuffer,Event event,VkPipelineStageFlags stageMask){
        vkCmdResetEvent(commandBuffer,event,stageMask);
      }
      
      void destroyEvent(Device device,Event event,const VkAllocationCallbacks* allocator){
        vkDestroyEvent(device,event,allocator);
      }
      
      void cmdSetEvent(CommandBuffer commandBuffer,Event event,VkPipelineStageFlags stageMask){
        vkCmdSetEvent(commandBuffer,event,stageMask);
      }
      
      VkResult resetEvent(Device device,Event event){
        vkResetEvent(device,event);
      }
      
      VkResult setEvent(Device device,Event event){
        vkSetEvent(device,event);
      }
      
      VkResult getEventStatus(Device device,Event event){
        vkGetEventStatus(device,event);
      }
    private:
      VkEvent event;
      Device device;
  }
  
  class BufferView{
    public:
      BufferView(VkBufferView bufferView_,Device device_)
        : bufferView(bufferView_),
          device(device_){
      }
      
      void destroyBufferView(Device device,BufferView bufferView,const VkAllocationCallbacks* allocator){
        vkDestroyBufferView(device,bufferView,allocator);
      }
    private:
      VkBufferView bufferView;
      Device device;
  }
  
  class PipelineLayout{
    public:
      PipelineLayout(VkPipelineLayout pipelineLayout_,Device device_)
        : pipelineLayout(pipelineLayout_),
          device(device_){
      }
      
      void destroyPipelineLayout(Device device,PipelineLayout pipelineLayout,const VkAllocationCallbacks* allocator){
        vkDestroyPipelineLayout(device,pipelineLayout,allocator);
      }
      
      void cmdPushDescriptorSetKHR(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        vkCmdPushDescriptorSetKHR(commandBuffer,pipelineBindPoint,layout,set,descriptorWriteCount,descriptorWrites);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,PipelineLayout layout,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplate,layout,set,data);
      }
      
      void cmdPushConstants(CommandBuffer commandBuffer,PipelineLayout layout,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        vkCmdPushConstants(commandBuffer,layout,stageFlags,offset,size,values);
      }
      
      void cmdBindDescriptorSets(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        vkCmdBindDescriptorSets(commandBuffer,pipelineBindPoint,layout,firstSet,descriptorSetCount,descriptorSets,dynamicOffsetCount,dynamicOffsets);
      }
    private:
      VkPipelineLayout pipelineLayout;
      Device device;
  }
  
  class Instance{
    public:
      Instance(VkInstance instance_,)
        : instance(instance_),
          {
      }
      
      VkResult createXlibSurfaceKHR(Instance instance,const VkXlibSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateXlibSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      VkResult createWin32SurfaceKHR(Instance instance,const VkWin32SurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateWin32SurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      PFN_vkVoidFunction getInstanceProcAddr(Instance instance,std::string name){
        vkGetInstanceProcAddr(instance,name);
      }
      
      VkResult createWaylandSurfaceKHR(Instance instance,const VkWaylandSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateWaylandSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      VkResult createIOSSurfaceMVK(Instance instance,const VkIOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateIOSSurfaceMVK(instance,createInfo,allocator,surface);
      }
      
      VkResult createAndroidSurfaceKHR(Instance instance,const VkAndroidSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateAndroidSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      VkResult createDebugReportCallbackEXT(Instance instance,const VkDebugReportCallbackCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator,DebugReportCallbackEXT* callback){
        vkCreateDebugReportCallbackEXT(instance,createInfo,allocator,callback);
      }
      
      VkResult createViSurfaceNN(Instance instance,const VkViSurfaceCreateInfoNN* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateViSurfaceNN(instance,createInfo,allocator,surface);
      }
      
      VkResult enumeratePhysicalDevices(Instance instance,std::vector<PhysicalDevice> physicalDevices){
        vkEnumeratePhysicalDevices(instance,physicalDeviceCount,physicalDevices);
      }
      
      VkResult createMacOSSurfaceMVK(Instance instance,const VkMacOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateMacOSSurfaceMVK(instance,createInfo,allocator,surface);
      }
      
      VkResult createXcbSurfaceKHR(Instance instance,const VkXcbSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateXcbSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      void destroyInstance(Instance instance,const VkAllocationCallbacks* allocator){
        vkDestroyInstance(instance,allocator);
      }
      
      void debugReportMessageEXT(Instance instance,VkDebugReportFlagsEXT flags,VkDebugReportObjectTypeEXT objectType,uint64_t object,size_t location,int32_t messageCode,std::string layerPrefix,std::string message){
        vkDebugReportMessageEXT(instance,flags,objectType,object,location,messageCode,layerPrefix,message);
      }
      
      VkResult enumeratePhysicalDeviceGroupsKHX(Instance instance,std::vector<VkPhysicalDeviceGroupPropertiesKHX> physicalDeviceGroupProperties){
        vkEnumeratePhysicalDeviceGroupsKHX(instance,physicalDeviceGroupCount,physicalDeviceGroupProperties);
      }
      
      VkResult createMirSurfaceKHR(Instance instance,const VkMirSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateMirSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      VkResult createDisplayPlaneSurfaceKHR(Instance instance,const VkDisplaySurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateDisplayPlaneSurfaceKHR(instance,createInfo,allocator,surface);
      }
    private:
      VkInstance instance;
      
  }
  
  class PhysicalDevice{
    public:
      PhysicalDevice(VkPhysicalDevice physicalDevice_,Instance instance_)
        : physicalDevice(physicalDevice_),
          instance(instance_){
      }
      
      void getPhysicalDeviceQueueFamilyProperties(PhysicalDevice physicalDevice,std::vector<VkQueueFamilyProperties> queueFamilyProperties){
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice,queueFamilyPropertyCount,queueFamilyProperties);
      }
      
      void getPhysicalDeviceSparseImageFormatProperties2KHR(PhysicalDevice physicalDevice,const VkPhysicalDeviceSparseImageFormatInfo2KHR* formatInfo,std::vector<VkSparseImageFormatProperties2KHR> properties){
        vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice,formatInfo,propertyCount,properties);
      }
      
      void getPhysicalDeviceGeneratedCommandsPropertiesNVX(PhysicalDevice physicalDevice,VkDeviceGeneratedCommandsFeaturesNVX* features,VkDeviceGeneratedCommandsLimitsNVX* limits){
        vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice,features,limits);
      }
      
      VkResult getPhysicalDeviceSurfaceFormats2KHR(PhysicalDevice physicalDevice,const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo,std::vector<VkSurfaceFormat2KHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice,surfaceInfo,surfaceFormatCount,surfaceFormats);
      }
      
      VkResult getPhysicalDevicePresentRectanglesKHX(PhysicalDevice physicalDevice,SurfaceKHR surface,std::vector<VkRect2D> rects){
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surface,rectCount,rects);
      }
      
      VkBool32 getPhysicalDeviceWaylandPresentationSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex,struct wl_display* display){
        vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice,queueFamilyIndex,display);
      }
      
      VkResult createDevice(PhysicalDevice physicalDevice,const VkDeviceCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Device* device){
        vkCreateDevice(physicalDevice,createInfo,allocator,device);
      }
      
      VkResult createDisplayModeKHR(PhysicalDevice physicalDevice,DisplayKHR display,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,DisplayModeKHR* mode){
        vkCreateDisplayModeKHR(physicalDevice,display,createInfo,allocator,mode);
      }
      
      VkResult enumerateDeviceLayerProperties(PhysicalDevice physicalDevice,std::vector<VkLayerProperties> properties){
        vkEnumerateDeviceLayerProperties(physicalDevice,propertyCount,properties);
      }
      
      void getPhysicalDeviceFeatures(PhysicalDevice physicalDevice,VkPhysicalDeviceFeatures* features){
        vkGetPhysicalDeviceFeatures(physicalDevice,features);
      }
      
      void getPhysicalDeviceQueueFamilyProperties2KHR(PhysicalDevice physicalDevice,std::vector<VkQueueFamilyProperties2KHR> queueFamilyProperties){
        vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice,queueFamilyPropertyCount,queueFamilyProperties);
      }
      
      void getPhysicalDeviceExternalSemaphorePropertiesKHR(PhysicalDevice physicalDevice,const VkPhysicalDeviceExternalSemaphoreInfoKHR* externalSemaphoreInfo,VkExternalSemaphorePropertiesKHR* externalSemaphoreProperties){
        vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice,externalSemaphoreInfo,externalSemaphoreProperties);
      }
      
      void getPhysicalDeviceFeatures2KHR(PhysicalDevice physicalDevice,VkPhysicalDeviceFeatures2KHR* features){
        vkGetPhysicalDeviceFeatures2KHR(physicalDevice,features);
      }
      
      void getPhysicalDeviceMultisamplePropertiesEXT(PhysicalDevice physicalDevice,VkSampleCountFlagBits samples,VkMultisamplePropertiesEXT* multisampleProperties){
        vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice,samples,multisampleProperties);
      }
      
      void getPhysicalDeviceMemoryProperties(PhysicalDevice physicalDevice,VkPhysicalDeviceMemoryProperties* memoryProperties){
        vkGetPhysicalDeviceMemoryProperties(physicalDevice,memoryProperties);
      }
      
      VkResult getDisplayModePropertiesKHR(PhysicalDevice physicalDevice,DisplayKHR display,std::vector<VkDisplayModePropertiesKHR> properties){
        vkGetDisplayModePropertiesKHR(physicalDevice,display,propertyCount,properties);
      }
      
      VkResult getPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice physicalDevice,SurfaceKHR surface,std::vector<VkPresentModeKHR> presentModes){
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surface,presentModeCount,presentModes);
      }
      
      VkResult acquireXlibDisplayEXT(PhysicalDevice physicalDevice,Display* dpy,DisplayKHR display){
        vkAcquireXlibDisplayEXT(physicalDevice,dpy,display);
      }
      
      void getPhysicalDeviceProperties2KHR(PhysicalDevice physicalDevice,VkPhysicalDeviceProperties2KHR* properties){
        vkGetPhysicalDeviceProperties2KHR(physicalDevice,properties);
      }
      
      VkResult getDisplayPlaneSupportedDisplaysKHR(PhysicalDevice physicalDevice,uint32_t planeIndex,std::vector<DisplayKHR> displays){
        vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice,planeIndex,displayCount,displays);
      }
      
      void getPhysicalDeviceMemoryProperties2KHR(PhysicalDevice physicalDevice,VkPhysicalDeviceMemoryProperties2KHR* memoryProperties){
        vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice,memoryProperties);
      }
      
      VkBool32 getPhysicalDeviceXcbPresentationSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex,xcb_connection_t* connection,xcb_visualid_t visual_id){
        vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice,queueFamilyIndex,connection,visual_id);
      }
      
      VkResult getRandROutputDisplayEXT(PhysicalDevice physicalDevice,Display* dpy,RROutput rrOutput,DisplayKHR* display){
        vkGetRandROutputDisplayEXT(physicalDevice,dpy,rrOutput,display);
      }
      
      void getPhysicalDeviceFormatProperties(PhysicalDevice physicalDevice,VkFormat format,VkFormatProperties* formatProperties){
        vkGetPhysicalDeviceFormatProperties(physicalDevice,format,formatProperties);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2EXT(PhysicalDevice physicalDevice,SurfaceKHR surface,VkSurfaceCapabilities2EXT* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surface,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceSurfaceSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex,SurfaceKHR surface,bool* supported){
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,surface,supported);
      }
      
      VkResult getPhysicalDeviceImageFormatProperties2KHR(PhysicalDevice physicalDevice,const VkPhysicalDeviceImageFormatInfo2KHR* imageFormatInfo,VkImageFormatProperties2KHR* imageFormatProperties){
        vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice,imageFormatInfo,imageFormatProperties);
      }
      
      VkBool32 getPhysicalDeviceWin32PresentationSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex){
        vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice,queueFamilyIndex);
      }
      
      VkBool32 getPhysicalDeviceXlibPresentationSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex,Display* dpy,VisualID visualID){
        vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice,queueFamilyIndex,dpy,visualID);
      }
      
      VkResult getPhysicalDeviceImageFormatProperties(PhysicalDevice physicalDevice,VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkImageFormatProperties* imageFormatProperties){
        vkGetPhysicalDeviceImageFormatProperties(physicalDevice,format,type,tiling,usage,flags,imageFormatProperties);
      }
      
      VkResult enumerateDeviceExtensionProperties(PhysicalDevice physicalDevice,std::string layerName,std::vector<VkExtensionProperties> properties){
        vkEnumerateDeviceExtensionProperties(physicalDevice,layerName,propertyCount,properties);
      }
      
      void getPhysicalDeviceExternalFencePropertiesKHR(PhysicalDevice physicalDevice,const VkPhysicalDeviceExternalFenceInfoKHR* externalFenceInfo,VkExternalFencePropertiesKHR* externalFenceProperties){
        vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice,externalFenceInfo,externalFenceProperties);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2KHR(PhysicalDevice physicalDevice,const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo,VkSurfaceCapabilities2KHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice,surfaceInfo,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceExternalImageFormatPropertiesNV(PhysicalDevice physicalDevice,VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkExternalMemoryHandleTypeFlagsNV externalHandleType,VkExternalImageFormatPropertiesNV* externalImageFormatProperties){
        vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice,format,type,tiling,usage,flags,externalHandleType,externalImageFormatProperties);
      }
      
      void getPhysicalDeviceExternalBufferPropertiesKHR(PhysicalDevice physicalDevice,const VkPhysicalDeviceExternalBufferInfoKHR* externalBufferInfo,VkExternalBufferPropertiesKHR* externalBufferProperties){
        vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice,externalBufferInfo,externalBufferProperties);
      }
      
      VkResult getPhysicalDeviceDisplayPlanePropertiesKHR(PhysicalDevice physicalDevice,std::vector<VkDisplayPlanePropertiesKHR> properties){
        vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice,propertyCount,properties);
      }
      
      VkResult getPhysicalDeviceDisplayPropertiesKHR(PhysicalDevice physicalDevice,std::vector<VkDisplayPropertiesKHR> properties){
        vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice,propertyCount,properties);
      }
      
      void getPhysicalDeviceSparseImageFormatProperties(PhysicalDevice physicalDevice,VkFormat format,VkImageType type,VkSampleCountFlagBits samples,VkImageUsageFlags usage,VkImageTiling tiling,std::vector<VkSparseImageFormatProperties> properties){
        vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice,format,type,samples,usage,tiling,propertyCount,properties);
      }
      
      void getPhysicalDeviceProperties(PhysicalDevice physicalDevice,VkPhysicalDeviceProperties* properties){
        vkGetPhysicalDeviceProperties(physicalDevice,properties);
      }
      
      VkResult getPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice physicalDevice,SurfaceKHR surface,std::vector<VkSurfaceFormatKHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surface,surfaceFormatCount,surfaceFormats);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice physicalDevice,SurfaceKHR surface,VkSurfaceCapabilitiesKHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surface,surfaceCapabilities);
      }
      
      VkBool32 getPhysicalDeviceMirPresentationSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex,MirConnection* connection){
        vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice,queueFamilyIndex,connection);
      }
      
      VkResult releaseDisplayEXT(PhysicalDevice physicalDevice,DisplayKHR display){
        vkReleaseDisplayEXT(physicalDevice,display);
      }
      
      void getPhysicalDeviceFormatProperties2KHR(PhysicalDevice physicalDevice,VkFormat format,VkFormatProperties2KHR* formatProperties){
        vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice,format,formatProperties);
      }
    private:
      VkPhysicalDevice physicalDevice;
      Instance instance;
  }
  
  class DisplayKHR{
    public:
      DisplayKHR(VkDisplayKHR displayKHR_,)
        : displayKHR(displayKHR_),
          {
      }
      
      VkResult createDisplayModeKHR(PhysicalDevice physicalDevice,DisplayKHR display,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,DisplayModeKHR* mode){
        vkCreateDisplayModeKHR(physicalDevice,display,createInfo,allocator,mode);
      }
      
      VkResult displayPowerControlEXT(Device device,DisplayKHR display,const VkDisplayPowerInfoEXT* displayPowerInfo){
        vkDisplayPowerControlEXT(device,display,displayPowerInfo);
      }
      
      VkResult getDisplayModePropertiesKHR(PhysicalDevice physicalDevice,DisplayKHR display,std::vector<VkDisplayModePropertiesKHR> properties){
        vkGetDisplayModePropertiesKHR(physicalDevice,display,propertyCount,properties);
      }
      
      VkResult acquireXlibDisplayEXT(PhysicalDevice physicalDevice,Display* dpy,DisplayKHR display){
        vkAcquireXlibDisplayEXT(physicalDevice,dpy,display);
      }
      
      VkResult registerDisplayEventEXT(Device device,DisplayKHR display,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkRegisterDisplayEventEXT(device,display,displayEventInfo,allocator,fence);
      }
      
      VkResult releaseDisplayEXT(PhysicalDevice physicalDevice,DisplayKHR display){
        vkReleaseDisplayEXT(physicalDevice,display);
      }
    private:
      VkDisplayKHR displayKHR;
      
  }
  
  class ImageView{
    public:
      ImageView(VkImageView imageView_,Device device_)
        : imageView(imageView_),
          device(device_){
      }
      
      void destroyImageView(Device device,ImageView imageView,const VkAllocationCallbacks* allocator){
        vkDestroyImageView(device,imageView,allocator);
      }
    private:
      VkImageView imageView;
      Device device;
  }
  
  class IndirectCommandsLayoutNVX{
    public:
      IndirectCommandsLayoutNVX(VkIndirectCommandsLayoutNVX indirectCommandsLayoutNVX_,Device device_)
        : indirectCommandsLayoutNVX(indirectCommandsLayoutNVX_),
          device(device_){
      }
      
      void destroyIndirectCommandsLayoutNVX(Device device,IndirectCommandsLayoutNVX indirectCommandsLayout,const VkAllocationCallbacks* allocator){
        vkDestroyIndirectCommandsLayoutNVX(device,indirectCommandsLayout,allocator);
      }
    private:
      VkIndirectCommandsLayoutNVX indirectCommandsLayoutNVX;
      Device device;
  }
  
  class Device{
    public:
      Device(VkDevice device_,PhysicalDevice physicalDevice_)
        : device(device_),
          physicalDevice(physicalDevice_){
      }
      
      void setHdrMetadataEXT(Device device,std::vector<SwapchainKHR> swapchains,std::vector<VkHdrMetadataEXT> metadata){
        vkSetHdrMetadataEXT(device,swapchainCount,swapchains,metadata);
      }
      
      VkResult createSamplerYcbcrConversionKHR(Device device,const VkSamplerYcbcrConversionCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SamplerYcbcrConversionKHR* ycbcrConversion){
        vkCreateSamplerYcbcrConversionKHR(device,createInfo,allocator,ycbcrConversion);
      }
      
      void updateDescriptorSets(Device device,std::vector<VkWriteDescriptorSet> descriptorWrites,std::vector<VkCopyDescriptorSet> descriptorCopies){
        vkUpdateDescriptorSets(device,descriptorWriteCount,descriptorWrites,descriptorCopyCount,descriptorCopies);
      }
      
      VkResult getSwapchainImagesKHR(Device device,SwapchainKHR swapchain,std::vector<Image> swapchainImages){
        vkGetSwapchainImagesKHR(device,swapchain,swapchainImageCount,swapchainImages);
      }
      
      VkResult importFenceWin32HandleKHR(Device device,const VkImportFenceWin32HandleInfoKHR* importFenceWin32HandleInfo){
        vkImportFenceWin32HandleKHR(device,importFenceWin32HandleInfo);
      }
      
      VkResult debugMarkerSetObjectNameEXT(Device device,const VkDebugMarkerObjectNameInfoEXT* nameInfo){
        vkDebugMarkerSetObjectNameEXT(device,nameInfo);
      }
      
      VkResult getRefreshCycleDurationGOOGLE(Device device,SwapchainKHR swapchain,VkRefreshCycleDurationGOOGLE* displayTimingProperties){
        vkGetRefreshCycleDurationGOOGLE(device,swapchain,displayTimingProperties);
      }
      
      VkResult bindImageMemory2KHR(Device device,std::vector<VkBindImageMemoryInfoKHR> bindInfos){
        vkBindImageMemory2KHR(device,bindInfoCount,bindInfos);
      }
      
      VkResult bindBufferMemory2KHR(Device device,std::vector<VkBindBufferMemoryInfoKHR> bindInfos){
        vkBindBufferMemory2KHR(device,bindInfoCount,bindInfos);
      }
      
      VkResult importSemaphoreWin32HandleKHR(Device device,const VkImportSemaphoreWin32HandleInfoKHR* importSemaphoreWin32HandleInfo){
        vkImportSemaphoreWin32HandleKHR(device,importSemaphoreWin32HandleInfo);
      }
      
      VkResult getSemaphoreFdKHR(Device device,const VkSemaphoreGetFdInfoKHR* getFdInfo,int* fd){
        vkGetSemaphoreFdKHR(device,getFdInfo,fd);
      }
      
      VkResult getMemoryWin32HandlePropertiesKHR(Device device,VkExternalMemoryHandleTypeFlagBitsKHR handleType,HANDLE handle,VkMemoryWin32HandlePropertiesKHR* memoryWin32HandleProperties){
        vkGetMemoryWin32HandlePropertiesKHR(device,handleType,handle,memoryWin32HandleProperties);
      }
      
      VkResult createDescriptorUpdateTemplateKHR(Device device,const VkDescriptorUpdateTemplateCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,DescriptorUpdateTemplateKHR* descriptorUpdateTemplate){
        vkCreateDescriptorUpdateTemplateKHR(device,createInfo,allocator,descriptorUpdateTemplate);
      }
      
      VkResult flushMappedMemoryRanges(Device device,std::vector<VkMappedMemoryRange> memoryRanges){
        vkFlushMappedMemoryRanges(device,memoryRangeCount,memoryRanges);
      }
      
      VkResult createDescriptorPool(Device device,const VkDescriptorPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,DescriptorPool* descriptorPool){
        vkCreateDescriptorPool(device,createInfo,allocator,descriptorPool);
      }
      
      VkResult resetFences(Device device,std::vector<Fence> fences){
        vkResetFences(device,fenceCount,fences);
      }
      
      void getImageSparseMemoryRequirements2KHR(Device device,const VkImageSparseMemoryRequirementsInfo2KHR* info,std::vector<VkSparseImageMemoryRequirements2KHR> sparseMemoryRequirements){
        vkGetImageSparseMemoryRequirements2KHR(device,info,sparseMemoryRequirementCount,sparseMemoryRequirements);
      }
      
      VkResult createImage(Device device,const VkImageCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Image* image){
        vkCreateImage(device,createInfo,allocator,image);
      }
      
      VkResult createShaderModule(Device device,const VkShaderModuleCreateInfo* createInfo,const VkAllocationCallbacks* allocator,ShaderModule* shaderModule){
        vkCreateShaderModule(device,createInfo,allocator,shaderModule);
      }
      
      VkResult acquireNextImage2KHX(Device device,const VkAcquireNextImageInfoKHX* acquireInfo,uint32_t* imageIndex){
        vkAcquireNextImage2KHX(device,acquireInfo,imageIndex);
      }
      
      void destroyDevice(Device device,const VkAllocationCallbacks* allocator){
        vkDestroyDevice(device,allocator);
      }
      
      VkResult getSwapchainStatusKHR(Device device,SwapchainKHR swapchain){
        vkGetSwapchainStatusKHR(device,swapchain);
      }
      
      VkResult createBuffer(Device device,const VkBufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Buffer* buffer){
        vkCreateBuffer(device,createInfo,allocator,buffer);
      }
      
      VkResult importSemaphoreFdKHR(Device device,const VkImportSemaphoreFdInfoKHR* importSemaphoreFdInfo){
        vkImportSemaphoreFdKHR(device,importSemaphoreFdInfo);
      }
      
      VkResult createEvent(Device device,const VkEventCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Event* event){
        vkCreateEvent(device,createInfo,allocator,event);
      }
      
      VkResult displayPowerControlEXT(Device device,DisplayKHR display,const VkDisplayPowerInfoEXT* displayPowerInfo){
        vkDisplayPowerControlEXT(device,display,displayPowerInfo);
      }
      
      VkResult createIndirectCommandsLayoutNVX(Device device,const VkIndirectCommandsLayoutCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator,IndirectCommandsLayoutNVX* indirectCommandsLayout){
        vkCreateIndirectCommandsLayoutNVX(device,createInfo,allocator,indirectCommandsLayout);
      }
      
      VkResult getPastPresentationTimingGOOGLE(Device device,SwapchainKHR swapchain,std::vector<VkPastPresentationTimingGOOGLE> presentationTimings){
        vkGetPastPresentationTimingGOOGLE(device,swapchain,presentationTimingCount,presentationTimings);
      }
      
      VkResult createFence(Device device,const VkFenceCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkCreateFence(device,createInfo,allocator,fence);
      }
      
      VkResult createImageView(Device device,const VkImageViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator,ImageView* view){
        vkCreateImageView(device,createInfo,allocator,view);
      }
      
      VkResult getDeviceGroupSurfacePresentModesKHX(Device device,SurfaceKHR surface,VkDeviceGroupPresentModeFlagsKHX* modes){
        vkGetDeviceGroupSurfacePresentModesKHX(device,surface,modes);
      }
      
      VkResult createDescriptorSetLayout(Device device,const VkDescriptorSetLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator,DescriptorSetLayout* setLayout){
        vkCreateDescriptorSetLayout(device,createInfo,allocator,setLayout);
      }
      
      VkResult createQueryPool(Device device,const VkQueryPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,QueryPool* queryPool){
        vkCreateQueryPool(device,createInfo,allocator,queryPool);
      }
      
      VkResult createRenderPass(Device device,const VkRenderPassCreateInfo* createInfo,const VkAllocationCallbacks* allocator,RenderPass* renderPass){
        vkCreateRenderPass(device,createInfo,allocator,renderPass);
      }
      
      VkResult deviceWaitIdle(Device device){
        vkDeviceWaitIdle(device);
      }
      
      VkResult allocateCommandBuffers(Device device,const VkCommandBufferAllocateInfo* allocateInfo,std::vector<CommandBuffer> commandBuffers){
        vkAllocateCommandBuffers(device,allocateInfo,commandBuffers);
      }
      
      void getDeviceQueue(Device device,uint32_t queueFamilyIndex,uint32_t queueIndex,Queue* queue){
        vkGetDeviceQueue(device,queueFamilyIndex,queueIndex,queue);
      }
      
      VkResult registerDisplayEventEXT(Device device,DisplayKHR display,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkRegisterDisplayEventEXT(device,display,displayEventInfo,allocator,fence);
      }
      
      VkResult createPipelineLayout(Device device,const VkPipelineLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator,PipelineLayout* pipelineLayout){
        vkCreatePipelineLayout(device,createInfo,allocator,pipelineLayout);
      }
      
      VkResult createFramebuffer(Device device,const VkFramebufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Framebuffer* framebuffer){
        vkCreateFramebuffer(device,createInfo,allocator,framebuffer);
      }
      
      VkResult getFenceFdKHR(Device device,const VkFenceGetFdInfoKHR* getFdInfo,int* fd){
        vkGetFenceFdKHR(device,getFdInfo,fd);
      }
      
      void getDeviceGroupPeerMemoryFeaturesKHX(Device device,uint32_t heapIndex,uint32_t localDeviceIndex,uint32_t remoteDeviceIndex,VkPeerMemoryFeatureFlagsKHX* peerMemoryFeatures){
        vkGetDeviceGroupPeerMemoryFeaturesKHX(device,heapIndex,localDeviceIndex,remoteDeviceIndex,peerMemoryFeatures);
      }
      
      void getImageMemoryRequirements2KHR(Device device,const VkImageMemoryRequirementsInfo2KHR* info,VkMemoryRequirements2KHR* memoryRequirements){
        vkGetImageMemoryRequirements2KHR(device,info,memoryRequirements);
      }
      
      VkResult createBufferView(Device device,const VkBufferViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator,BufferView* view){
        vkCreateBufferView(device,createInfo,allocator,view);
      }
      
      VkResult createSemaphore(Device device,const VkSemaphoreCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Semaphore* semaphore){
        vkCreateSemaphore(device,createInfo,allocator,semaphore);
      }
      
      VkResult createObjectTableNVX(Device device,const VkObjectTableCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator,ObjectTableNVX* objectTable){
        vkCreateObjectTableNVX(device,createInfo,allocator,objectTable);
      }
      
      VkResult importFenceFdKHR(Device device,const VkImportFenceFdInfoKHR* importFenceFdInfo){
        vkImportFenceFdKHR(device,importFenceFdInfo);
      }
      
      VkResult createSharedSwapchainsKHR(Device device,std::vector<VkSwapchainCreateInfoKHR> createInfos,const VkAllocationCallbacks* allocator,std::vector<SwapchainKHR> swapchains){
        vkCreateSharedSwapchainsKHR(device,swapchainCount,createInfos,allocator,swapchains);
      }
      
      VkResult createCommandPool(Device device,const VkCommandPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,CommandPool* commandPool){
        vkCreateCommandPool(device,createInfo,allocator,commandPool);
      }
      
      VkResult getSemaphoreWin32HandleKHR(Device device,const VkSemaphoreGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetSemaphoreWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      VkResult getFenceWin32HandleKHR(Device device,const VkFenceGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetFenceWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      VkResult waitForFences(Device device,std::vector<Fence> fences,bool waitAll,uint64_t timeout){
        vkWaitForFences(device,fenceCount,fences,waitAll,timeout);
      }
      
      VkResult createSwapchainKHR(Device device,const VkSwapchainCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SwapchainKHR* swapchain){
        vkCreateSwapchainKHR(device,createInfo,allocator,swapchain);
      }
      
      VkResult getMemoryFdPropertiesKHR(Device device,VkExternalMemoryHandleTypeFlagBitsKHR handleType,int fd,VkMemoryFdPropertiesKHR* memoryFdProperties){
        vkGetMemoryFdPropertiesKHR(device,handleType,fd,memoryFdProperties);
      }
      
      VkResult createValidationCacheEXT(Device device,const VkValidationCacheCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator,ValidationCacheEXT* validationCache){
        vkCreateValidationCacheEXT(device,createInfo,allocator,validationCache);
      }
      
      VkResult getDeviceGroupPresentCapabilitiesKHX(Device device,VkDeviceGroupPresentCapabilitiesKHX* deviceGroupPresentCapabilities){
        vkGetDeviceGroupPresentCapabilitiesKHX(device,deviceGroupPresentCapabilities);
      }
      
      void destroySwapchainKHR(Device device,SwapchainKHR swapchain,const VkAllocationCallbacks* allocator){
        vkDestroySwapchainKHR(device,swapchain,allocator);
      }
      
      VkResult invalidateMappedMemoryRanges(Device device,std::vector<VkMappedMemoryRange> memoryRanges){
        vkInvalidateMappedMemoryRanges(device,memoryRangeCount,memoryRanges);
      }
      
      VkResult getSwapchainCounterEXT(Device device,SwapchainKHR swapchain,VkSurfaceCounterFlagBitsEXT counter,uint64_t* counterValue){
        vkGetSwapchainCounterEXT(device,swapchain,counter,counterValue);
      }
      
      VkResult createSampler(Device device,const VkSamplerCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Sampler* sampler){
        vkCreateSampler(device,createInfo,allocator,sampler);
      }
      
      VkResult createPipelineCache(Device device,const VkPipelineCacheCreateInfo* createInfo,const VkAllocationCallbacks* allocator,PipelineCache* pipelineCache){
        vkCreatePipelineCache(device,createInfo,allocator,pipelineCache);
      }
      
      VkResult getMemoryFdKHR(Device device,const VkMemoryGetFdInfoKHR* getFdInfo,int* fd){
        vkGetMemoryFdKHR(device,getFdInfo,fd);
      }
      
      VkResult debugMarkerSetObjectTagEXT(Device device,const VkDebugMarkerObjectTagInfoEXT* tagInfo){
        vkDebugMarkerSetObjectTagEXT(device,tagInfo);
      }
      
      PFN_vkVoidFunction getDeviceProcAddr(Device device,std::string name){
        vkGetDeviceProcAddr(device,name);
      }
      
      VkResult getMemoryWin32HandleKHR(Device device,const VkMemoryGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetMemoryWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      VkResult allocateDescriptorSets(Device device,const VkDescriptorSetAllocateInfo* allocateInfo,std::vector<DescriptorSet> descriptorSets){
        vkAllocateDescriptorSets(device,allocateInfo,descriptorSets);
      }
      
      VkResult allocateMemory(Device device,const VkMemoryAllocateInfo* allocateInfo,const VkAllocationCallbacks* allocator,DeviceMemory* memory){
        vkAllocateMemory(device,allocateInfo,allocator,memory);
      }
      
      void getBufferMemoryRequirements2KHR(Device device,const VkBufferMemoryRequirementsInfo2KHR* info,VkMemoryRequirements2KHR* memoryRequirements){
        vkGetBufferMemoryRequirements2KHR(device,info,memoryRequirements);
      }
      
      VkResult registerDeviceEventEXT(Device device,const VkDeviceEventInfoEXT* deviceEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkRegisterDeviceEventEXT(device,deviceEventInfo,allocator,fence);
      }
    private:
      VkDevice device;
      PhysicalDevice physicalDevice;
  }
  
  class DescriptorUpdateTemplateKHR{
    public:
      DescriptorUpdateTemplateKHR(VkDescriptorUpdateTemplateKHR descriptorUpdateTemplateKHR_,Device device_)
        : descriptorUpdateTemplateKHR(descriptorUpdateTemplateKHR_),
          device(device_){
      }
      
      void destroyDescriptorUpdateTemplateKHR(Device device,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,const VkAllocationCallbacks* allocator){
        vkDestroyDescriptorUpdateTemplateKHR(device,descriptorUpdateTemplate,allocator);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,PipelineLayout layout,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplate,layout,set,data);
      }
      
      void updateDescriptorSetWithTemplateKHR(Device device,DescriptorSet descriptorSet,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,const void* data){
        vkUpdateDescriptorSetWithTemplateKHR(device,descriptorSet,descriptorUpdateTemplate,data);
      }
    private:
      VkDescriptorUpdateTemplateKHR descriptorUpdateTemplateKHR;
      Device device;
  }
  
  class CommandBuffer{
    public:
      CommandBuffer(VkCommandBuffer commandBuffer_,CommandPool commandPool_)
        : commandBuffer(commandBuffer_),
          commandPool(commandPool_){
      }
      
      void cmdUpdateBuffer(CommandBuffer commandBuffer,Buffer dstBuffer,std::size_t dstOffset,std::vector<void> data){
        vkCmdUpdateBuffer(commandBuffer,dstBuffer,dstOffset,dataSize,data);
      }
      
      VkResult beginCommandBuffer(CommandBuffer commandBuffer,const VkCommandBufferBeginInfo* beginInfo){
        vkBeginCommandBuffer(commandBuffer,beginInfo);
      }
      
      void cmdSetDiscardRectangleEXT(CommandBuffer commandBuffer,uint32_t firstDiscardRectangle,std::vector<VkRect2D> discardRectangles){
        vkCmdSetDiscardRectangleEXT(commandBuffer,firstDiscardRectangle,discardRectangleCount,discardRectangles);
      }
      
      void cmdSetViewportWScalingNV(CommandBuffer commandBuffer,uint32_t firstViewport,std::vector<VkViewportWScalingNV> viewportWScalings){
        vkCmdSetViewportWScalingNV(commandBuffer,firstViewport,viewportCount,viewportWScalings);
      }
      
      void cmdProcessCommandsNVX(CommandBuffer commandBuffer,const VkCmdProcessCommandsInfoNVX* processCommandsInfo){
        vkCmdProcessCommandsNVX(commandBuffer,processCommandsInfo);
      }
      
      void cmdDispatchBaseKHX(CommandBuffer commandBuffer,uint32_t baseGroupX,uint32_t baseGroupY,uint32_t baseGroupZ,uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        vkCmdDispatchBaseKHX(commandBuffer,baseGroupX,baseGroupY,baseGroupZ,groupCountX,groupCountY,groupCountZ);
      }
      
      void cmdResetEvent(CommandBuffer commandBuffer,Event event,VkPipelineStageFlags stageMask){
        vkCmdResetEvent(commandBuffer,event,stageMask);
      }
      
      void cmdBindVertexBuffers(CommandBuffer commandBuffer,uint32_t firstBinding,std::vector<Buffer> buffers,std::vector<std::size_t> offsets){
        vkCmdBindVertexBuffers(commandBuffer,firstBinding,bindingCount,buffers,offsets);
      }
      
      void cmdDispatch(CommandBuffer commandBuffer,uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        vkCmdDispatch(commandBuffer,groupCountX,groupCountY,groupCountZ);
      }
      
      void cmdNextSubpass(CommandBuffer commandBuffer,VkSubpassContents contents){
        vkCmdNextSubpass(commandBuffer,contents);
      }
      
      void cmdPushDescriptorSetKHR(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        vkCmdPushDescriptorSetKHR(commandBuffer,pipelineBindPoint,layout,set,descriptorWriteCount,descriptorWrites);
      }
      
      void cmdSetViewport(CommandBuffer commandBuffer,uint32_t firstViewport,std::vector<VkViewport> viewports){
        vkCmdSetViewport(commandBuffer,firstViewport,viewportCount,viewports);
      }
      
      void cmdCopyQueryPoolResults(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,Buffer dstBuffer,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        vkCmdCopyQueryPoolResults(commandBuffer,queryPool,firstQuery,queryCount,dstBuffer,dstOffset,stride,flags);
      }
      
      void cmdDrawIndexed(CommandBuffer commandBuffer,uint32_t indexCount,uint32_t instanceCount,uint32_t firstIndex,int32_t vertexOffset,uint32_t firstInstance){
        vkCmdDrawIndexed(commandBuffer,indexCount,instanceCount,firstIndex,vertexOffset,firstInstance);
      }
      
      void cmdSetEvent(CommandBuffer commandBuffer,Event event,VkPipelineStageFlags stageMask){
        vkCmdSetEvent(commandBuffer,event,stageMask);
      }
      
      void cmdSetSampleLocationsEXT(CommandBuffer commandBuffer,const VkSampleLocationsInfoEXT* sampleLocationsInfo){
        vkCmdSetSampleLocationsEXT(commandBuffer,sampleLocationsInfo);
      }
      
      void cmdSetScissor(CommandBuffer commandBuffer,uint32_t firstScissor,std::vector<VkRect2D> scissors){
        vkCmdSetScissor(commandBuffer,firstScissor,scissorCount,scissors);
      }
      
      void cmdWriteTimestamp(CommandBuffer commandBuffer,VkPipelineStageFlagBits pipelineStage,QueryPool queryPool,uint32_t query){
        vkCmdWriteTimestamp(commandBuffer,pipelineStage,queryPool,query);
      }
      
      void cmdSetLineWidth(CommandBuffer commandBuffer,float lineWidth){
        vkCmdSetLineWidth(commandBuffer,lineWidth);
      }
      
      void cmdDrawIndirect(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndirect(commandBuffer,buffer,offset,drawCount,stride);
      }
      
      void cmdDebugMarkerEndEXT(CommandBuffer commandBuffer){
        vkCmdDebugMarkerEndEXT(commandBuffer);
      }
      
      void cmdResolveImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageResolve> regions){
        vkCmdResolveImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdEndRenderPass(CommandBuffer commandBuffer){
        vkCmdEndRenderPass(commandBuffer);
      }
      
      void cmdResetQueryPool(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount){
        vkCmdResetQueryPool(commandBuffer,queryPool,firstQuery,queryCount);
      }
      
      void cmdCopyImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        vkCmdCopyImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdReserveSpaceForCommandsNVX(CommandBuffer commandBuffer,const VkCmdReserveSpaceForCommandsInfoNVX* reserveSpaceInfo){
        vkCmdReserveSpaceForCommandsNVX(commandBuffer,reserveSpaceInfo);
      }
      
      void cmdBlitImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        vkCmdBlitImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions,filter);
      }
      
      void cmdSetStencilWriteMask(CommandBuffer commandBuffer,VkStencilFaceFlags faceMask,uint32_t writeMask){
        vkCmdSetStencilWriteMask(commandBuffer,faceMask,writeMask);
      }
      
      void cmdExecuteCommands(CommandBuffer commandBuffer,std::vector<CommandBuffer> commandBuffers){
        vkCmdExecuteCommands(commandBuffer,commandBufferCount,commandBuffers);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,PipelineLayout layout,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplate,layout,set,data);
      }
      
      void cmdPipelineBarrier(CommandBuffer commandBuffer,VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,VkDependencyFlags dependencyFlags,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        vkCmdPipelineBarrier(commandBuffer,srcStageMask,dstStageMask,dependencyFlags,memoryBarrierCount,memoryBarriers,bufferMemoryBarrierCount,bufferMemoryBarriers,imageMemoryBarrierCount,imageMemoryBarriers);
      }
      
      void cmdWaitEvents(CommandBuffer commandBuffer,std::vector<Event> events,VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        vkCmdWaitEvents(commandBuffer,eventCount,events,srcStageMask,dstStageMask,memoryBarrierCount,memoryBarriers,bufferMemoryBarrierCount,bufferMemoryBarriers,imageMemoryBarrierCount,imageMemoryBarriers);
      }
      
      void cmdDrawIndexedIndirectCountAMD(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndexedIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDraw(CommandBuffer commandBuffer,uint32_t vertexCount,uint32_t instanceCount,uint32_t firstVertex,uint32_t firstInstance){
        vkCmdDraw(commandBuffer,vertexCount,instanceCount,firstVertex,firstInstance);
      }
      
      void cmdDrawIndexedIndirect(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndexedIndirect(commandBuffer,buffer,offset,drawCount,stride);
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,srcImage,srcImageLayout,dstBuffer,regionCount,regions);
      }
      
      void cmdDebugMarkerInsertEXT(CommandBuffer commandBuffer,const VkDebugMarkerMarkerInfoEXT* markerInfo){
        vkCmdDebugMarkerInsertEXT(commandBuffer,markerInfo);
      }
      
      void cmdSetStencilCompareMask(CommandBuffer commandBuffer,VkStencilFaceFlags faceMask,uint32_t compareMask){
        vkCmdSetStencilCompareMask(commandBuffer,faceMask,compareMask);
      }
      
      void cmdPushConstants(CommandBuffer commandBuffer,PipelineLayout layout,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        vkCmdPushConstants(commandBuffer,layout,stageFlags,offset,size,values);
      }
      
      void cmdDrawIndirectCountAMD(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDispatchIndirect(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset){
        vkCmdDispatchIndirect(commandBuffer,buffer,offset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Buffer srcBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,srcBuffer,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdBindPipeline(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,Pipeline pipeline){
        vkCmdBindPipeline(commandBuffer,pipelineBindPoint,pipeline);
      }
      
      void cmdDebugMarkerBeginEXT(CommandBuffer commandBuffer,const VkDebugMarkerMarkerInfoEXT* markerInfo){
        vkCmdDebugMarkerBeginEXT(commandBuffer,markerInfo);
      }
      
      VkResult endCommandBuffer(CommandBuffer commandBuffer){
        vkEndCommandBuffer(commandBuffer);
      }
      
      VkResult resetCommandBuffer(CommandBuffer commandBuffer,VkCommandBufferResetFlags flags){
        vkResetCommandBuffer(commandBuffer,flags);
      }
      
      void cmdSetStencilReference(CommandBuffer commandBuffer,VkStencilFaceFlags faceMask,uint32_t reference){
        vkCmdSetStencilReference(commandBuffer,faceMask,reference);
      }
      
      void cmdEndQuery(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t query){
        vkCmdEndQuery(commandBuffer,queryPool,query);
      }
      
      void cmdBindIndexBuffer(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,VkIndexType indexType){
        vkCmdBindIndexBuffer(commandBuffer,buffer,offset,indexType);
      }
      
      void cmdSetDeviceMaskKHX(CommandBuffer commandBuffer,uint32_t deviceMask){
        vkCmdSetDeviceMaskKHX(commandBuffer,deviceMask);
      }
      
      void cmdSetDepthBias(CommandBuffer commandBuffer,float depthBiasConstantFactor,float depthBiasClamp,float depthBiasSlopeFactor){
        vkCmdSetDepthBias(commandBuffer,depthBiasConstantFactor,depthBiasClamp,depthBiasSlopeFactor);
      }
      
      void cmdSetDepthBounds(CommandBuffer commandBuffer,float minDepthBounds,float maxDepthBounds){
        vkCmdSetDepthBounds(commandBuffer,minDepthBounds,maxDepthBounds);
      }
      
      void cmdClearDepthStencilImage(CommandBuffer commandBuffer,Image image,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearDepthStencilImage(commandBuffer,image,imageLayout,depthStencil,rangeCount,ranges);
      }
      
      void cmdClearColorImage(CommandBuffer commandBuffer,Image image,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearColorImage(commandBuffer,image,imageLayout,color,rangeCount,ranges);
      }
      
      void cmdBeginRenderPass(CommandBuffer commandBuffer,const VkRenderPassBeginInfo* renderPassBegin,VkSubpassContents contents){
        vkCmdBeginRenderPass(commandBuffer,renderPassBegin,contents);
      }
      
      void cmdCopyBuffer(CommandBuffer commandBuffer,Buffer srcBuffer,Buffer dstBuffer,std::vector<VkBufferCopy> regions){
        vkCmdCopyBuffer(commandBuffer,srcBuffer,dstBuffer,regionCount,regions);
      }
      
      void cmdSetBlendConstants(CommandBuffer commandBuffer,const float blendConstants){
        vkCmdSetBlendConstants(commandBuffer,blendConstants);
      }
      
      void cmdFillBuffer(CommandBuffer commandBuffer,Buffer dstBuffer,std::size_t dstOffset,std::size_t size,uint32_t data){
        vkCmdFillBuffer(commandBuffer,dstBuffer,dstOffset,size,data);
      }
      
      void cmdBeginQuery(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t query,VkQueryControlFlags flags){
        vkCmdBeginQuery(commandBuffer,queryPool,query,flags);
      }
      
      void cmdBindDescriptorSets(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        vkCmdBindDescriptorSets(commandBuffer,pipelineBindPoint,layout,firstSet,descriptorSetCount,descriptorSets,dynamicOffsetCount,dynamicOffsets);
      }
      
      void cmdClearAttachments(CommandBuffer commandBuffer,std::vector<VkClearAttachment> attachments,std::vector<VkClearRect> rects){
        vkCmdClearAttachments(commandBuffer,attachmentCount,attachments,rectCount,rects);
      }
    private:
      VkCommandBuffer commandBuffer;
      CommandPool commandPool;
  }
  
  class SwapchainKHR{
    public:
      SwapchainKHR(VkSwapchainKHR swapchainKHR_,SurfaceKHR surfaceKHR_)
        : swapchainKHR(swapchainKHR_),
          surfaceKHR(surfaceKHR_){
      }
      
      VkResult getSwapchainImagesKHR(Device device,SwapchainKHR swapchain,std::vector<Image> swapchainImages){
        vkGetSwapchainImagesKHR(device,swapchain,swapchainImageCount,swapchainImages);
      }
      
      VkResult getRefreshCycleDurationGOOGLE(Device device,SwapchainKHR swapchain,VkRefreshCycleDurationGOOGLE* displayTimingProperties){
        vkGetRefreshCycleDurationGOOGLE(device,swapchain,displayTimingProperties);
      }
      
      VkResult getSwapchainStatusKHR(Device device,SwapchainKHR swapchain){
        vkGetSwapchainStatusKHR(device,swapchain);
      }
      
      VkResult acquireNextImageKHR(Device device,SwapchainKHR swapchain,uint64_t timeout,Semaphore semaphore,Fence fence,uint32_t* imageIndex){
        vkAcquireNextImageKHR(device,swapchain,timeout,semaphore,fence,imageIndex);
      }
      
      VkResult getPastPresentationTimingGOOGLE(Device device,SwapchainKHR swapchain,std::vector<VkPastPresentationTimingGOOGLE> presentationTimings){
        vkGetPastPresentationTimingGOOGLE(device,swapchain,presentationTimingCount,presentationTimings);
      }
      
      void destroySwapchainKHR(Device device,SwapchainKHR swapchain,const VkAllocationCallbacks* allocator){
        vkDestroySwapchainKHR(device,swapchain,allocator);
      }
      
      VkResult getSwapchainCounterEXT(Device device,SwapchainKHR swapchain,VkSurfaceCounterFlagBitsEXT counter,uint64_t* counterValue){
        vkGetSwapchainCounterEXT(device,swapchain,counter,counterValue);
      }
    private:
      VkSwapchainKHR swapchainKHR;
      SurfaceKHR surfaceKHR;
  }
  
  class DebugReportCallbackEXT{
    public:
      DebugReportCallbackEXT(VkDebugReportCallbackEXT debugReportCallbackEXT_,Instance instance_)
        : debugReportCallbackEXT(debugReportCallbackEXT_),
          instance(instance_){
      }
      
      void destroyDebugReportCallbackEXT(Instance instance,DebugReportCallbackEXT callback,const VkAllocationCallbacks* allocator){
        vkDestroyDebugReportCallbackEXT(instance,callback,allocator);
      }
    private:
      VkDebugReportCallbackEXT debugReportCallbackEXT;
      Instance instance;
  }
  
  class Pipeline{
    public:
      Pipeline(VkPipeline pipeline_,Device device_)
        : pipeline(pipeline_),
          device(device_){
      }
      
      void cmdBindPipeline(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,Pipeline pipeline){
        vkCmdBindPipeline(commandBuffer,pipelineBindPoint,pipeline);
      }
      
      void destroyPipeline(Device device,Pipeline pipeline,const VkAllocationCallbacks* allocator){
        vkDestroyPipeline(device,pipeline,allocator);
      }
    private:
      VkPipeline pipeline;
      Device device;
  }
  
  class PipelineCache{
    public:
      PipelineCache(VkPipelineCache pipelineCache_,Device device_)
        : pipelineCache(pipelineCache_),
          device(device_){
      }
      
      VkResult createComputePipelines(Device device,PipelineCache pipelineCache,std::vector<VkComputePipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator,std::vector<Pipeline> pipelines){
        vkCreateComputePipelines(device,pipelineCache,createInfoCount,createInfos,allocator,pipelines);
      }
      
      VkResult createGraphicsPipelines(Device device,PipelineCache pipelineCache,std::vector<VkGraphicsPipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator,std::vector<Pipeline> pipelines){
        vkCreateGraphicsPipelines(device,pipelineCache,createInfoCount,createInfos,allocator,pipelines);
      }
      
      void destroyPipelineCache(Device device,PipelineCache pipelineCache,const VkAllocationCallbacks* allocator){
        vkDestroyPipelineCache(device,pipelineCache,allocator);
      }
      
      VkResult mergePipelineCaches(Device device,PipelineCache dstCache,std::vector<PipelineCache> srcCaches){
        vkMergePipelineCaches(device,dstCache,srcCacheCount,srcCaches);
      }
      
      VkResult getPipelineCacheData(Device device,PipelineCache pipelineCache,std::vector<void> data){
        vkGetPipelineCacheData(device,pipelineCache,dataSize,data);
      }
    private:
      VkPipelineCache pipelineCache;
      Device device;
  }
  
  class DeviceMemory{
    public:
      DeviceMemory(VkDeviceMemory deviceMemory_,Device device_)
        : deviceMemory(deviceMemory_),
          device(device_){
      }
      
      VkResult bindBufferMemory(Device device,Buffer buffer,DeviceMemory memory,std::size_t memoryOffset){
        vkBindBufferMemory(device,buffer,memory,memoryOffset);
      }
      
      void freeMemory(Device device,DeviceMemory memory,const VkAllocationCallbacks* allocator){
        vkFreeMemory(device,memory,allocator);
      }
      
      VkResult mapMemory(Device device,DeviceMemory memory,std::size_t offset,std::size_t size,VkMemoryMapFlags flags,void** data){
        vkMapMemory(device,memory,offset,size,flags,data);
      }
      
      void unmapMemory(Device device,DeviceMemory memory){
        vkUnmapMemory(device,memory);
      }
      
      VkResult getMemoryWin32HandleNV(Device device,DeviceMemory memory,VkExternalMemoryHandleTypeFlagsNV handleType,HANDLE* handle){
        vkGetMemoryWin32HandleNV(device,memory,handleType,handle);
      }
      
      VkResult bindImageMemory(Device device,Image image,DeviceMemory memory,std::size_t memoryOffset){
        vkBindImageMemory(device,image,memory,memoryOffset);
      }
      
      void getDeviceMemoryCommitment(Device device,DeviceMemory memory,std::size_t* committedMemoryInBytes){
        vkGetDeviceMemoryCommitment(device,memory,committedMemoryInBytes);
      }
    private:
      VkDeviceMemory deviceMemory;
      Device device;
  }
  
  class Buffer{
    public:
      Buffer(VkBuffer buffer_,Device device_)
        : buffer(buffer_),
          device(device_){
      }
      
      void cmdUpdateBuffer(CommandBuffer commandBuffer,Buffer dstBuffer,std::size_t dstOffset,std::vector<void> data){
        vkCmdUpdateBuffer(commandBuffer,dstBuffer,dstOffset,dataSize,data);
      }
      
      VkResult bindBufferMemory(Device device,Buffer buffer,DeviceMemory memory,std::size_t memoryOffset){
        vkBindBufferMemory(device,buffer,memory,memoryOffset);
      }
      
      void cmdCopyQueryPoolResults(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,Buffer dstBuffer,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        vkCmdCopyQueryPoolResults(commandBuffer,queryPool,firstQuery,queryCount,dstBuffer,dstOffset,stride,flags);
      }
      
      void cmdDrawIndirect(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndirect(commandBuffer,buffer,offset,drawCount,stride);
      }
      
      void cmdDrawIndexedIndirectCountAMD(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndexedIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDrawIndexedIndirectCountAMD(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndexedIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDrawIndexedIndirect(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndexedIndirect(commandBuffer,buffer,offset,drawCount,stride);
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,srcImage,srcImageLayout,dstBuffer,regionCount,regions);
      }
      
      void destroyBuffer(Device device,Buffer buffer,const VkAllocationCallbacks* allocator){
        vkDestroyBuffer(device,buffer,allocator);
      }
      
      void cmdDrawIndirectCountAMD(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDrawIndirectCountAMD(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDispatchIndirect(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset){
        vkCmdDispatchIndirect(commandBuffer,buffer,offset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Buffer srcBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,srcBuffer,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void getBufferMemoryRequirements(Device device,Buffer buffer,VkMemoryRequirements* memoryRequirements){
        vkGetBufferMemoryRequirements(device,buffer,memoryRequirements);
      }
      
      void cmdBindIndexBuffer(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,VkIndexType indexType){
        vkCmdBindIndexBuffer(commandBuffer,buffer,offset,indexType);
      }
      
      void cmdCopyBuffer(CommandBuffer commandBuffer,Buffer srcBuffer,Buffer dstBuffer,std::vector<VkBufferCopy> regions){
        vkCmdCopyBuffer(commandBuffer,srcBuffer,dstBuffer,regionCount,regions);
      }
      
      void cmdCopyBuffer(CommandBuffer commandBuffer,Buffer srcBuffer,Buffer dstBuffer,std::vector<VkBufferCopy> regions){
        vkCmdCopyBuffer(commandBuffer,srcBuffer,dstBuffer,regionCount,regions);
      }
      
      void cmdFillBuffer(CommandBuffer commandBuffer,Buffer dstBuffer,std::size_t dstOffset,std::size_t size,uint32_t data){
        vkCmdFillBuffer(commandBuffer,dstBuffer,dstOffset,size,data);
      }
    private:
      VkBuffer buffer;
      Device device;
  }
  
  class Framebuffer{
    public:
      Framebuffer(VkFramebuffer framebuffer_,Device device_)
        : framebuffer(framebuffer_),
          device(device_){
      }
      
      void destroyFramebuffer(Device device,Framebuffer framebuffer,const VkAllocationCallbacks* allocator){
        vkDestroyFramebuffer(device,framebuffer,allocator);
      }
    private:
      VkFramebuffer framebuffer;
      Device device;
  }
  
  class ObjectTableNVX{
    public:
      ObjectTableNVX(VkObjectTableNVX objectTableNVX_,Device device_)
        : objectTableNVX(objectTableNVX_),
          device(device_){
      }
      
      void destroyObjectTableNVX(Device device,ObjectTableNVX objectTable,const VkAllocationCallbacks* allocator){
        vkDestroyObjectTableNVX(device,objectTable,allocator);
      }
      
      VkResult unregisterObjectsNVX(Device device,ObjectTableNVX objectTable,std::vector<VkObjectEntryTypeNVX> objectEntryTypes,std::vector<uint32_t> objectIndices){
        vkUnregisterObjectsNVX(device,objectTable,objectCount,objectEntryTypes,objectIndices);
      }
      
      VkResult registerObjectsNVX(Device device,ObjectTableNVX objectTable,std::vector<VkObjectTableEntryNVX> objectTableEntries,std::vector<uint32_t> objectIndices){
        vkRegisterObjectsNVX(device,objectTable,objectCount,objectTableEntries,objectIndices);
      }
    private:
      VkObjectTableNVX objectTableNVX;
      Device device;
  }
  
  class ShaderModule{
    public:
      ShaderModule(VkShaderModule shaderModule_,Device device_)
        : shaderModule(shaderModule_),
          device(device_){
      }
      
      void destroyShaderModule(Device device,ShaderModule shaderModule,const VkAllocationCallbacks* allocator){
        vkDestroyShaderModule(device,shaderModule,allocator);
      }
    private:
      VkShaderModule shaderModule;
      Device device;
  }
  
  class Fence{
    public:
      Fence(VkFence fence_,Device device_)
        : fence(fence_),
          device(device_){
      }
      
      VkResult queueSubmit(Queue queue,std::vector<VkSubmitInfo> submits,Fence fence){
        vkQueueSubmit(queue,submitCount,submits,fence);
      }
      
      void destroyFence(Device device,Fence fence,const VkAllocationCallbacks* allocator){
        vkDestroyFence(device,fence,allocator);
      }
      
      VkResult acquireNextImageKHR(Device device,SwapchainKHR swapchain,uint64_t timeout,Semaphore semaphore,Fence fence,uint32_t* imageIndex){
        vkAcquireNextImageKHR(device,swapchain,timeout,semaphore,fence,imageIndex);
      }
      
      VkResult queueBindSparse(Queue queue,std::vector<VkBindSparseInfo> bindInfo,Fence fence){
        vkQueueBindSparse(queue,bindInfoCount,bindInfo,fence);
      }
      
      VkResult getFenceStatus(Device device,Fence fence){
        vkGetFenceStatus(device,fence);
      }
    private:
      VkFence fence;
      Device device;
  }
  
  class QueryPool{
    public:
      QueryPool(VkQueryPool queryPool_,Device device_)
        : queryPool(queryPool_),
          device(device_){
      }
      
      void cmdCopyQueryPoolResults(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,Buffer dstBuffer,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        vkCmdCopyQueryPoolResults(commandBuffer,queryPool,firstQuery,queryCount,dstBuffer,dstOffset,stride,flags);
      }
      
      void cmdWriteTimestamp(CommandBuffer commandBuffer,VkPipelineStageFlagBits pipelineStage,QueryPool queryPool,uint32_t query){
        vkCmdWriteTimestamp(commandBuffer,pipelineStage,queryPool,query);
      }
      
      void cmdResetQueryPool(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount){
        vkCmdResetQueryPool(commandBuffer,queryPool,firstQuery,queryCount);
      }
      
      void destroyQueryPool(Device device,QueryPool queryPool,const VkAllocationCallbacks* allocator){
        vkDestroyQueryPool(device,queryPool,allocator);
      }
      
      void cmdEndQuery(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t query){
        vkCmdEndQuery(commandBuffer,queryPool,query);
      }
      
      VkResult getQueryPoolResults(Device device,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,std::vector<void> data,std::size_t stride,VkQueryResultFlags flags){
        vkGetQueryPoolResults(device,queryPool,firstQuery,queryCount,dataSize,data,stride,flags);
      }
      
      void cmdBeginQuery(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t query,VkQueryControlFlags flags){
        vkCmdBeginQuery(commandBuffer,queryPool,query,flags);
      }
    private:
      VkQueryPool queryPool;
      Device device;
  }
  
  class Image{
    public:
      Image(VkImage image_,Device device_)
        : image(image_),
          device(device_){
      }
      
      void getImageSubresourceLayout(Device device,Image image,const VkImageSubresource* subresource,VkSubresourceLayout* layout){
        vkGetImageSubresourceLayout(device,image,subresource,layout);
      }
      
      void cmdResolveImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageResolve> regions){
        vkCmdResolveImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdResolveImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageResolve> regions){
        vkCmdResolveImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdCopyImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        vkCmdCopyImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdCopyImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        vkCmdCopyImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdBlitImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        vkCmdBlitImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions,filter);
      }
      
      void cmdBlitImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        vkCmdBlitImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions,filter);
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,srcImage,srcImageLayout,dstBuffer,regionCount,regions);
      }
      
      void destroyImage(Device device,Image image,const VkAllocationCallbacks* allocator){
        vkDestroyImage(device,image,allocator);
      }
      
      VkResult bindImageMemory(Device device,Image image,DeviceMemory memory,std::size_t memoryOffset){
        vkBindImageMemory(device,image,memory,memoryOffset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Buffer srcBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,srcBuffer,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void getImageSparseMemoryRequirements(Device device,Image image,std::vector<VkSparseImageMemoryRequirements> sparseMemoryRequirements){
        vkGetImageSparseMemoryRequirements(device,image,sparseMemoryRequirementCount,sparseMemoryRequirements);
      }
      
      void cmdClearDepthStencilImage(CommandBuffer commandBuffer,Image image,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearDepthStencilImage(commandBuffer,image,imageLayout,depthStencil,rangeCount,ranges);
      }
      
      void cmdClearColorImage(CommandBuffer commandBuffer,Image image,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearColorImage(commandBuffer,image,imageLayout,color,rangeCount,ranges);
      }
      
      void getImageMemoryRequirements(Device device,Image image,VkMemoryRequirements* memoryRequirements){
        vkGetImageMemoryRequirements(device,image,memoryRequirements);
      }
    private:
      VkImage image;
      Device device;
  }