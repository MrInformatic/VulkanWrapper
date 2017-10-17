namespace vk{
  class DescriptorPool{
    public:
      DescriptorPool(VkDescriptorPool descriptorPool_,Device device_)
        : descriptorPool(descriptorPool_),
          device(device_){
      }
      
      VkResult freeDescriptorSets(std::vector<DescriptorSet> descriptorSets){
        vkFreeDescriptorSets((VkDevice)device,descriptorPool,descriptorSetCount,descriptorSets);
      }
      
      VkResult resetDescriptorPool(VkDescriptorPoolResetFlags flags){
        vkResetDescriptorPool((VkDevice)device,descriptorPool,flags);
      }
      
      void destroyDescriptorPool(const VkAllocationCallbacks* allocator){
        vkDestroyDescriptorPool((VkDevice)device,descriptorPool,allocator);
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
      
      VkResult acquireNextImageKHR(SwapchainKHR swapchain,uint64_t timeout,Fence fence,uint32_t* imageIndex){
        vkAcquireNextImageKHR((VkDevice)device,swapchain,timeout,semaphore,fence,imageIndex);
      }
      
      void destroySemaphore(const VkAllocationCallbacks* allocator){
        vkDestroySemaphore((VkDevice)device,semaphore,allocator);
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
      
      VkResult getValidationCacheDataEXT(std::vector<void> data){
        vkGetValidationCacheDataEXT((VkDevice)device,validationCacheEXT,dataSize,data);
      }
      
      VkResult mergeValidationCachesEXT(std::vector<ValidationCacheEXT> srcCaches){
        vkMergeValidationCachesEXT((VkDevice)device,validationCacheEXT,srcCacheCount,srcCaches);
      }
      
      void destroyValidationCacheEXT(const VkAllocationCallbacks* allocator){
        vkDestroyValidationCacheEXT((VkDevice)device,validationCacheEXT,allocator);
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
      
      void destroyRenderPass(const VkAllocationCallbacks* allocator){
        vkDestroyRenderPass((VkDevice)device,renderPass,allocator);
      }
      
      void getRenderAreaGranularity(VkExtent2D* granularity){
        vkGetRenderAreaGranularity((VkDevice)device,renderPass,granularity);
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
      
      VkResult getDisplayPlaneCapabilitiesKHR(uint32_t planeIndex,VkDisplayPlaneCapabilitiesKHR* capabilities){
        vkGetDisplayPlaneCapabilitiesKHR((VkPhysicalDevice)physicalDevice,displayModeKHR,planeIndex,capabilities);
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
      
      void destroySampler(const VkAllocationCallbacks* allocator){
        vkDestroySampler((VkDevice)device,sampler,allocator);
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
      
      VkResult queueWaitIdle(){
        vkQueueWaitIdle(queue);
      }
      
      VkResult queueSubmit(std::vector<VkSubmitInfo> submits,Fence fence){
        vkQueueSubmit(queue,submitCount,submits,fence);
      }
      
      VkResult queueBindSparse(std::vector<VkBindSparseInfo> bindInfo,Fence fence){
        vkQueueBindSparse(queue,bindInfoCount,bindInfo,fence);
      }
      
      VkResult queuePresentKHR(const VkPresentInfoKHR* presentInfo){
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
      
      void destroySamplerYcbcrConversionKHR(const VkAllocationCallbacks* allocator){
        vkDestroySamplerYcbcrConversionKHR((VkDevice)device,samplerYcbcrConversionKHR,allocator);
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
      
      void trimCommandPoolKHR(VkCommandPoolTrimFlagsKHR flags){
        vkTrimCommandPoolKHR((VkDevice)device,commandPool,flags);
      }
      
      VkResult resetCommandPool(VkCommandPoolResetFlags flags){
        vkResetCommandPool((VkDevice)device,commandPool,flags);
      }
      
      void destroyCommandPool(const VkAllocationCallbacks* allocator){
        vkDestroyCommandPool((VkDevice)device,commandPool,allocator);
      }
      
      void freeCommandBuffers(std::vector<CommandBuffer> commandBuffers){
        vkFreeCommandBuffers((VkDevice)device,commandPool,commandBufferCount,commandBuffers);
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
      
      void updateDescriptorSetWithTemplateKHR(DescriptorUpdateTemplateKHR descriptorUpdateTemplate,const void* data){
        vkUpdateDescriptorSetWithTemplateKHR((VkDevice)descriptorPool.device,descriptorSet,descriptorUpdateTemplate,data);
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
      
      void destroyDescriptorSetLayout(const VkAllocationCallbacks* allocator){
        vkDestroyDescriptorSetLayout((VkDevice)device,descriptorSetLayout,allocator);
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
      
      VkResult getPhysicalDevicePresentRectanglesKHX(PhysicalDevice physicalDevice,std::vector<VkRect2D> rects){
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surfaceKHR,rectCount,rects);
      }
      
      void destroySurfaceKHR(const VkAllocationCallbacks* allocator){
        vkDestroySurfaceKHR((VkInstance)instance,surfaceKHR,allocator);
      }
      
      VkResult getPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice physicalDevice,std::vector<VkPresentModeKHR> presentModes){
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surfaceKHR,presentModeCount,presentModes);
      }
      
      VkResult getDeviceGroupSurfacePresentModesKHX(Device device,VkDeviceGroupPresentModeFlagsKHX* modes){
        vkGetDeviceGroupSurfacePresentModesKHX(device,surfaceKHR,modes);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2EXT(PhysicalDevice physicalDevice,VkSurfaceCapabilities2EXT* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surfaceKHR,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceSurfaceSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex,bool* supported){
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,surfaceKHR,supported);
      }
      
      VkResult getPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice physicalDevice,std::vector<VkSurfaceFormatKHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surfaceKHR,surfaceFormatCount,surfaceFormats);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice physicalDevice,VkSurfaceCapabilitiesKHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surfaceKHR,surfaceCapabilities);
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
      
      void cmdResetEvent(CommandBuffer commandBuffer,VkPipelineStageFlags stageMask){
        vkCmdResetEvent(commandBuffer,event,stageMask);
      }
      
      void destroyEvent(const VkAllocationCallbacks* allocator){
        vkDestroyEvent((VkDevice)device,event,allocator);
      }
      
      void cmdSetEvent(CommandBuffer commandBuffer,VkPipelineStageFlags stageMask){
        vkCmdSetEvent(commandBuffer,event,stageMask);
      }
      
      VkResult resetEvent(){
        vkResetEvent((VkDevice)device,event);
      }
      
      VkResult setEvent(){
        vkSetEvent((VkDevice)device,event);
      }
      
      VkResult getEventStatus(){
        vkGetEventStatus((VkDevice)device,event);
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
      
      void destroyBufferView(const VkAllocationCallbacks* allocator){
        vkDestroyBufferView((VkDevice)device,bufferView,allocator);
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
      
      void destroyPipelineLayout(const VkAllocationCallbacks* allocator){
        vkDestroyPipelineLayout((VkDevice)device,pipelineLayout,allocator);
      }
      
      void cmdPushDescriptorSetKHR(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        vkCmdPushDescriptorSetKHR(commandBuffer,pipelineBindPoint,pipelineLayout,set,descriptorWriteCount,descriptorWrites);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplate,pipelineLayout,set,data);
      }
      
      void cmdPushConstants(CommandBuffer commandBuffer,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        vkCmdPushConstants(commandBuffer,pipelineLayout,stageFlags,offset,size,values);
      }
      
      void cmdBindDescriptorSets(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        vkCmdBindDescriptorSets(commandBuffer,pipelineBindPoint,pipelineLayout,firstSet,descriptorSetCount,descriptorSets,dynamicOffsetCount,dynamicOffsets);
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
      
      VkResult createXlibSurfaceKHR(const VkXlibSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateXlibSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      VkResult createWin32SurfaceKHR(const VkWin32SurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateWin32SurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      PFN_vkVoidFunction getInstanceProcAddr(std::string name){
        vkGetInstanceProcAddr(instance,name);
      }
      
      VkResult createWaylandSurfaceKHR(const VkWaylandSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateWaylandSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      VkResult createIOSSurfaceMVK(const VkIOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateIOSSurfaceMVK(instance,createInfo,allocator,surface);
      }
      
      VkResult createAndroidSurfaceKHR(const VkAndroidSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateAndroidSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      VkResult createDebugReportCallbackEXT(const VkDebugReportCallbackCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator,DebugReportCallbackEXT* callback){
        vkCreateDebugReportCallbackEXT(instance,createInfo,allocator,callback);
      }
      
      VkResult createViSurfaceNN(const VkViSurfaceCreateInfoNN* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateViSurfaceNN(instance,createInfo,allocator,surface);
      }
      
      VkResult enumeratePhysicalDevices(std::vector<PhysicalDevice> physicalDevices){
        vkEnumeratePhysicalDevices(instance,physicalDeviceCount,physicalDevices);
      }
      
      VkResult createMacOSSurfaceMVK(const VkMacOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateMacOSSurfaceMVK(instance,createInfo,allocator,surface);
      }
      
      VkResult createXcbSurfaceKHR(const VkXcbSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateXcbSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      void destroyInstance(const VkAllocationCallbacks* allocator){
        vkDestroyInstance(instance,allocator);
      }
      
      void debugReportMessageEXT(VkDebugReportFlagsEXT flags,VkDebugReportObjectTypeEXT objectType,uint64_t object,size_t location,int32_t messageCode,std::string layerPrefix,std::string message){
        vkDebugReportMessageEXT(instance,flags,objectType,object,location,messageCode,layerPrefix,message);
      }
      
      VkResult enumeratePhysicalDeviceGroupsKHX(std::vector<VkPhysicalDeviceGroupPropertiesKHX> physicalDeviceGroupProperties){
        vkEnumeratePhysicalDeviceGroupsKHX(instance,physicalDeviceGroupCount,physicalDeviceGroupProperties);
      }
      
      VkResult createMirSurfaceKHR(const VkMirSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateMirSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      VkResult createDisplayPlaneSurfaceKHR(const VkDisplaySurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
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
      
      void getPhysicalDeviceQueueFamilyProperties(std::vector<VkQueueFamilyProperties> queueFamilyProperties){
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice,queueFamilyPropertyCount,queueFamilyProperties);
      }
      
      void getPhysicalDeviceSparseImageFormatProperties2KHR(const VkPhysicalDeviceSparseImageFormatInfo2KHR* formatInfo,std::vector<VkSparseImageFormatProperties2KHR> properties){
        vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice,formatInfo,propertyCount,properties);
      }
      
      void getPhysicalDeviceGeneratedCommandsPropertiesNVX(VkDeviceGeneratedCommandsFeaturesNVX* features,VkDeviceGeneratedCommandsLimitsNVX* limits){
        vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice,features,limits);
      }
      
      VkResult getPhysicalDeviceSurfaceFormats2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo,std::vector<VkSurfaceFormat2KHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice,surfaceInfo,surfaceFormatCount,surfaceFormats);
      }
      
      VkResult getPhysicalDevicePresentRectanglesKHX(SurfaceKHR surface,std::vector<VkRect2D> rects){
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surface,rectCount,rects);
      }
      
      VkBool32 getPhysicalDeviceWaylandPresentationSupportKHR(uint32_t queueFamilyIndex,struct wl_display* display){
        vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice,queueFamilyIndex,display);
      }
      
      VkResult createDevice(const VkDeviceCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Device* device){
        vkCreateDevice(physicalDevice,createInfo,allocator,device);
      }
      
      VkResult createDisplayModeKHR(DisplayKHR display,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,DisplayModeKHR* mode){
        vkCreateDisplayModeKHR(physicalDevice,display,createInfo,allocator,mode);
      }
      
      VkResult enumerateDeviceLayerProperties(std::vector<VkLayerProperties> properties){
        vkEnumerateDeviceLayerProperties(physicalDevice,propertyCount,properties);
      }
      
      void getPhysicalDeviceFeatures(VkPhysicalDeviceFeatures* features){
        vkGetPhysicalDeviceFeatures(physicalDevice,features);
      }
      
      void getPhysicalDeviceQueueFamilyProperties2KHR(std::vector<VkQueueFamilyProperties2KHR> queueFamilyProperties){
        vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice,queueFamilyPropertyCount,queueFamilyProperties);
      }
      
      void getPhysicalDeviceExternalSemaphorePropertiesKHR(const VkPhysicalDeviceExternalSemaphoreInfoKHR* externalSemaphoreInfo,VkExternalSemaphorePropertiesKHR* externalSemaphoreProperties){
        vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice,externalSemaphoreInfo,externalSemaphoreProperties);
      }
      
      void getPhysicalDeviceFeatures2KHR(VkPhysicalDeviceFeatures2KHR* features){
        vkGetPhysicalDeviceFeatures2KHR(physicalDevice,features);
      }
      
      void getPhysicalDeviceMultisamplePropertiesEXT(VkSampleCountFlagBits samples,VkMultisamplePropertiesEXT* multisampleProperties){
        vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice,samples,multisampleProperties);
      }
      
      void getPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties* memoryProperties){
        vkGetPhysicalDeviceMemoryProperties(physicalDevice,memoryProperties);
      }
      
      VkResult getDisplayModePropertiesKHR(DisplayKHR display,std::vector<VkDisplayModePropertiesKHR> properties){
        vkGetDisplayModePropertiesKHR(physicalDevice,display,propertyCount,properties);
      }
      
      VkResult getPhysicalDeviceSurfacePresentModesKHR(SurfaceKHR surface,std::vector<VkPresentModeKHR> presentModes){
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surface,presentModeCount,presentModes);
      }
      
      VkResult acquireXlibDisplayEXT(Display* dpy,DisplayKHR display){
        vkAcquireXlibDisplayEXT(physicalDevice,dpy,display);
      }
      
      void getPhysicalDeviceProperties2KHR(VkPhysicalDeviceProperties2KHR* properties){
        vkGetPhysicalDeviceProperties2KHR(physicalDevice,properties);
      }
      
      VkResult getDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex,std::vector<DisplayKHR> displays){
        vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice,planeIndex,displayCount,displays);
      }
      
      void getPhysicalDeviceMemoryProperties2KHR(VkPhysicalDeviceMemoryProperties2KHR* memoryProperties){
        vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice,memoryProperties);
      }
      
      VkBool32 getPhysicalDeviceXcbPresentationSupportKHR(uint32_t queueFamilyIndex,xcb_connection_t* connection,xcb_visualid_t visual_id){
        vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice,queueFamilyIndex,connection,visual_id);
      }
      
      VkResult getRandROutputDisplayEXT(Display* dpy,RROutput rrOutput,DisplayKHR* display){
        vkGetRandROutputDisplayEXT(physicalDevice,dpy,rrOutput,display);
      }
      
      void getPhysicalDeviceFormatProperties(VkFormat format,VkFormatProperties* formatProperties){
        vkGetPhysicalDeviceFormatProperties(physicalDevice,format,formatProperties);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2EXT(SurfaceKHR surface,VkSurfaceCapabilities2EXT* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surface,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex,SurfaceKHR surface,bool* supported){
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,surface,supported);
      }
      
      VkResult getPhysicalDeviceImageFormatProperties2KHR(const VkPhysicalDeviceImageFormatInfo2KHR* imageFormatInfo,VkImageFormatProperties2KHR* imageFormatProperties){
        vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice,imageFormatInfo,imageFormatProperties);
      }
      
      VkBool32 getPhysicalDeviceWin32PresentationSupportKHR(uint32_t queueFamilyIndex){
        vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice,queueFamilyIndex);
      }
      
      VkBool32 getPhysicalDeviceXlibPresentationSupportKHR(uint32_t queueFamilyIndex,Display* dpy,VisualID visualID){
        vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice,queueFamilyIndex,dpy,visualID);
      }
      
      VkResult getPhysicalDeviceImageFormatProperties(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkImageFormatProperties* imageFormatProperties){
        vkGetPhysicalDeviceImageFormatProperties(physicalDevice,format,type,tiling,usage,flags,imageFormatProperties);
      }
      
      VkResult enumerateDeviceExtensionProperties(std::string layerName,std::vector<VkExtensionProperties> properties){
        vkEnumerateDeviceExtensionProperties(physicalDevice,layerName,propertyCount,properties);
      }
      
      void getPhysicalDeviceExternalFencePropertiesKHR(const VkPhysicalDeviceExternalFenceInfoKHR* externalFenceInfo,VkExternalFencePropertiesKHR* externalFenceProperties){
        vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice,externalFenceInfo,externalFenceProperties);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo,VkSurfaceCapabilities2KHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice,surfaceInfo,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceExternalImageFormatPropertiesNV(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkExternalMemoryHandleTypeFlagsNV externalHandleType,VkExternalImageFormatPropertiesNV* externalImageFormatProperties){
        vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice,format,type,tiling,usage,flags,externalHandleType,externalImageFormatProperties);
      }
      
      void getPhysicalDeviceExternalBufferPropertiesKHR(const VkPhysicalDeviceExternalBufferInfoKHR* externalBufferInfo,VkExternalBufferPropertiesKHR* externalBufferProperties){
        vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice,externalBufferInfo,externalBufferProperties);
      }
      
      VkResult getPhysicalDeviceDisplayPlanePropertiesKHR(std::vector<VkDisplayPlanePropertiesKHR> properties){
        vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice,propertyCount,properties);
      }
      
      VkResult getPhysicalDeviceDisplayPropertiesKHR(std::vector<VkDisplayPropertiesKHR> properties){
        vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice,propertyCount,properties);
      }
      
      void getPhysicalDeviceSparseImageFormatProperties(VkFormat format,VkImageType type,VkSampleCountFlagBits samples,VkImageUsageFlags usage,VkImageTiling tiling,std::vector<VkSparseImageFormatProperties> properties){
        vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice,format,type,samples,usage,tiling,propertyCount,properties);
      }
      
      void getPhysicalDeviceProperties(VkPhysicalDeviceProperties* properties){
        vkGetPhysicalDeviceProperties(physicalDevice,properties);
      }
      
      VkResult getPhysicalDeviceSurfaceFormatsKHR(SurfaceKHR surface,std::vector<VkSurfaceFormatKHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surface,surfaceFormatCount,surfaceFormats);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHR surface,VkSurfaceCapabilitiesKHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surface,surfaceCapabilities);
      }
      
      VkBool32 getPhysicalDeviceMirPresentationSupportKHR(uint32_t queueFamilyIndex,MirConnection* connection){
        vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice,queueFamilyIndex,connection);
      }
      
      VkResult releaseDisplayEXT(DisplayKHR display){
        vkReleaseDisplayEXT(physicalDevice,display);
      }
      
      void getPhysicalDeviceFormatProperties2KHR(VkFormat format,VkFormatProperties2KHR* formatProperties){
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
      
      VkResult createDisplayModeKHR(PhysicalDevice physicalDevice,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,DisplayModeKHR* mode){
        vkCreateDisplayModeKHR(physicalDevice,displayKHR,createInfo,allocator,mode);
      }
      
      VkResult displayPowerControlEXT(Device device,const VkDisplayPowerInfoEXT* displayPowerInfo){
        vkDisplayPowerControlEXT(device,displayKHR,displayPowerInfo);
      }
      
      VkResult getDisplayModePropertiesKHR(PhysicalDevice physicalDevice,std::vector<VkDisplayModePropertiesKHR> properties){
        vkGetDisplayModePropertiesKHR(physicalDevice,displayKHR,propertyCount,properties);
      }
      
      VkResult acquireXlibDisplayEXT(PhysicalDevice physicalDevice,Display* dpy){
        vkAcquireXlibDisplayEXT(physicalDevice,dpy,displayKHR);
      }
      
      VkResult registerDisplayEventEXT(Device device,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkRegisterDisplayEventEXT(device,displayKHR,displayEventInfo,allocator,fence);
      }
      
      VkResult releaseDisplayEXT(PhysicalDevice physicalDevice){
        vkReleaseDisplayEXT(physicalDevice,displayKHR);
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
      
      void destroyImageView(const VkAllocationCallbacks* allocator){
        vkDestroyImageView((VkDevice)device,imageView,allocator);
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
      
      void destroyIndirectCommandsLayoutNVX(const VkAllocationCallbacks* allocator){
        vkDestroyIndirectCommandsLayoutNVX((VkDevice)device,indirectCommandsLayoutNVX,allocator);
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
      
      void setHdrMetadataEXT(std::vector<SwapchainKHR> swapchains,std::vector<VkHdrMetadataEXT> metadata){
        vkSetHdrMetadataEXT(device,swapchainCount,swapchains,metadata);
      }
      
      VkResult createSamplerYcbcrConversionKHR(const VkSamplerYcbcrConversionCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SamplerYcbcrConversionKHR* ycbcrConversion){
        vkCreateSamplerYcbcrConversionKHR(device,createInfo,allocator,ycbcrConversion);
      }
      
      void updateDescriptorSets(std::vector<VkWriteDescriptorSet> descriptorWrites,std::vector<VkCopyDescriptorSet> descriptorCopies){
        vkUpdateDescriptorSets(device,descriptorWriteCount,descriptorWrites,descriptorCopyCount,descriptorCopies);
      }
      
      VkResult getSwapchainImagesKHR(SwapchainKHR swapchain,std::vector<Image> swapchainImages){
        vkGetSwapchainImagesKHR(device,swapchain,swapchainImageCount,swapchainImages);
      }
      
      VkResult importFenceWin32HandleKHR(const VkImportFenceWin32HandleInfoKHR* importFenceWin32HandleInfo){
        vkImportFenceWin32HandleKHR(device,importFenceWin32HandleInfo);
      }
      
      VkResult debugMarkerSetObjectNameEXT(const VkDebugMarkerObjectNameInfoEXT* nameInfo){
        vkDebugMarkerSetObjectNameEXT(device,nameInfo);
      }
      
      VkResult getRefreshCycleDurationGOOGLE(SwapchainKHR swapchain,VkRefreshCycleDurationGOOGLE* displayTimingProperties){
        vkGetRefreshCycleDurationGOOGLE(device,swapchain,displayTimingProperties);
      }
      
      VkResult bindImageMemory2KHR(std::vector<VkBindImageMemoryInfoKHR> bindInfos){
        vkBindImageMemory2KHR(device,bindInfoCount,bindInfos);
      }
      
      VkResult bindBufferMemory2KHR(std::vector<VkBindBufferMemoryInfoKHR> bindInfos){
        vkBindBufferMemory2KHR(device,bindInfoCount,bindInfos);
      }
      
      VkResult importSemaphoreWin32HandleKHR(const VkImportSemaphoreWin32HandleInfoKHR* importSemaphoreWin32HandleInfo){
        vkImportSemaphoreWin32HandleKHR(device,importSemaphoreWin32HandleInfo);
      }
      
      VkResult getSemaphoreFdKHR(const VkSemaphoreGetFdInfoKHR* getFdInfo,int* fd){
        vkGetSemaphoreFdKHR(device,getFdInfo,fd);
      }
      
      VkResult getMemoryWin32HandlePropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,HANDLE handle,VkMemoryWin32HandlePropertiesKHR* memoryWin32HandleProperties){
        vkGetMemoryWin32HandlePropertiesKHR(device,handleType,handle,memoryWin32HandleProperties);
      }
      
      VkResult createDescriptorUpdateTemplateKHR(const VkDescriptorUpdateTemplateCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,DescriptorUpdateTemplateKHR* descriptorUpdateTemplate){
        vkCreateDescriptorUpdateTemplateKHR(device,createInfo,allocator,descriptorUpdateTemplate);
      }
      
      VkResult flushMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        vkFlushMappedMemoryRanges(device,memoryRangeCount,memoryRanges);
      }
      
      VkResult createDescriptorPool(const VkDescriptorPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,DescriptorPool* descriptorPool){
        vkCreateDescriptorPool(device,createInfo,allocator,descriptorPool);
      }
      
      VkResult resetFences(std::vector<Fence> fences){
        vkResetFences(device,fenceCount,fences);
      }
      
      void getImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2KHR* info,std::vector<VkSparseImageMemoryRequirements2KHR> sparseMemoryRequirements){
        vkGetImageSparseMemoryRequirements2KHR(device,info,sparseMemoryRequirementCount,sparseMemoryRequirements);
      }
      
      VkResult createImage(const VkImageCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Image* image){
        vkCreateImage(device,createInfo,allocator,image);
      }
      
      VkResult createShaderModule(const VkShaderModuleCreateInfo* createInfo,const VkAllocationCallbacks* allocator,ShaderModule* shaderModule){
        vkCreateShaderModule(device,createInfo,allocator,shaderModule);
      }
      
      VkResult acquireNextImage2KHX(const VkAcquireNextImageInfoKHX* acquireInfo,uint32_t* imageIndex){
        vkAcquireNextImage2KHX(device,acquireInfo,imageIndex);
      }
      
      void destroyDevice(const VkAllocationCallbacks* allocator){
        vkDestroyDevice(device,allocator);
      }
      
      VkResult getSwapchainStatusKHR(SwapchainKHR swapchain){
        vkGetSwapchainStatusKHR(device,swapchain);
      }
      
      VkResult createBuffer(const VkBufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Buffer* buffer){
        vkCreateBuffer(device,createInfo,allocator,buffer);
      }
      
      VkResult importSemaphoreFdKHR(const VkImportSemaphoreFdInfoKHR* importSemaphoreFdInfo){
        vkImportSemaphoreFdKHR(device,importSemaphoreFdInfo);
      }
      
      VkResult createEvent(const VkEventCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Event* event){
        vkCreateEvent(device,createInfo,allocator,event);
      }
      
      VkResult displayPowerControlEXT(DisplayKHR display,const VkDisplayPowerInfoEXT* displayPowerInfo){
        vkDisplayPowerControlEXT(device,display,displayPowerInfo);
      }
      
      VkResult createIndirectCommandsLayoutNVX(const VkIndirectCommandsLayoutCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator,IndirectCommandsLayoutNVX* indirectCommandsLayout){
        vkCreateIndirectCommandsLayoutNVX(device,createInfo,allocator,indirectCommandsLayout);
      }
      
      VkResult getPastPresentationTimingGOOGLE(SwapchainKHR swapchain,std::vector<VkPastPresentationTimingGOOGLE> presentationTimings){
        vkGetPastPresentationTimingGOOGLE(device,swapchain,presentationTimingCount,presentationTimings);
      }
      
      VkResult createFence(const VkFenceCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkCreateFence(device,createInfo,allocator,fence);
      }
      
      VkResult createImageView(const VkImageViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator,ImageView* view){
        vkCreateImageView(device,createInfo,allocator,view);
      }
      
      VkResult getDeviceGroupSurfacePresentModesKHX(SurfaceKHR surface,VkDeviceGroupPresentModeFlagsKHX* modes){
        vkGetDeviceGroupSurfacePresentModesKHX(device,surface,modes);
      }
      
      VkResult createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator,DescriptorSetLayout* setLayout){
        vkCreateDescriptorSetLayout(device,createInfo,allocator,setLayout);
      }
      
      VkResult createQueryPool(const VkQueryPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,QueryPool* queryPool){
        vkCreateQueryPool(device,createInfo,allocator,queryPool);
      }
      
      VkResult createRenderPass(const VkRenderPassCreateInfo* createInfo,const VkAllocationCallbacks* allocator,RenderPass* renderPass){
        vkCreateRenderPass(device,createInfo,allocator,renderPass);
      }
      
      VkResult deviceWaitIdle(){
        vkDeviceWaitIdle(device);
      }
      
      VkResult allocateCommandBuffers(const VkCommandBufferAllocateInfo* allocateInfo,std::vector<CommandBuffer> commandBuffers){
        vkAllocateCommandBuffers(device,allocateInfo,commandBuffers);
      }
      
      void getDeviceQueue(uint32_t queueFamilyIndex,uint32_t queueIndex,Queue* queue){
        vkGetDeviceQueue(device,queueFamilyIndex,queueIndex,queue);
      }
      
      VkResult registerDisplayEventEXT(DisplayKHR display,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkRegisterDisplayEventEXT(device,display,displayEventInfo,allocator,fence);
      }
      
      VkResult createPipelineLayout(const VkPipelineLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator,PipelineLayout* pipelineLayout){
        vkCreatePipelineLayout(device,createInfo,allocator,pipelineLayout);
      }
      
      VkResult createFramebuffer(const VkFramebufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Framebuffer* framebuffer){
        vkCreateFramebuffer(device,createInfo,allocator,framebuffer);
      }
      
      VkResult getFenceFdKHR(const VkFenceGetFdInfoKHR* getFdInfo,int* fd){
        vkGetFenceFdKHR(device,getFdInfo,fd);
      }
      
      void getDeviceGroupPeerMemoryFeaturesKHX(uint32_t heapIndex,uint32_t localDeviceIndex,uint32_t remoteDeviceIndex,VkPeerMemoryFeatureFlagsKHX* peerMemoryFeatures){
        vkGetDeviceGroupPeerMemoryFeaturesKHX(device,heapIndex,localDeviceIndex,remoteDeviceIndex,peerMemoryFeatures);
      }
      
      void getImageMemoryRequirements2KHR(const VkImageMemoryRequirementsInfo2KHR* info,VkMemoryRequirements2KHR* memoryRequirements){
        vkGetImageMemoryRequirements2KHR(device,info,memoryRequirements);
      }
      
      VkResult createBufferView(const VkBufferViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator,BufferView* view){
        vkCreateBufferView(device,createInfo,allocator,view);
      }
      
      VkResult createSemaphore(const VkSemaphoreCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Semaphore* semaphore){
        vkCreateSemaphore(device,createInfo,allocator,semaphore);
      }
      
      VkResult createObjectTableNVX(const VkObjectTableCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator,ObjectTableNVX* objectTable){
        vkCreateObjectTableNVX(device,createInfo,allocator,objectTable);
      }
      
      VkResult importFenceFdKHR(const VkImportFenceFdInfoKHR* importFenceFdInfo){
        vkImportFenceFdKHR(device,importFenceFdInfo);
      }
      
      VkResult createSharedSwapchainsKHR(std::vector<VkSwapchainCreateInfoKHR> createInfos,const VkAllocationCallbacks* allocator,std::vector<SwapchainKHR> swapchains){
        vkCreateSharedSwapchainsKHR(device,swapchainCount,createInfos,allocator,swapchains);
      }
      
      VkResult createCommandPool(const VkCommandPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,CommandPool* commandPool){
        vkCreateCommandPool(device,createInfo,allocator,commandPool);
      }
      
      VkResult getSemaphoreWin32HandleKHR(const VkSemaphoreGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetSemaphoreWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      VkResult getFenceWin32HandleKHR(const VkFenceGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetFenceWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      VkResult waitForFences(std::vector<Fence> fences,bool waitAll,uint64_t timeout){
        vkWaitForFences(device,fenceCount,fences,waitAll,timeout);
      }
      
      VkResult createSwapchainKHR(const VkSwapchainCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SwapchainKHR* swapchain){
        vkCreateSwapchainKHR(device,createInfo,allocator,swapchain);
      }
      
      VkResult getMemoryFdPropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,int fd,VkMemoryFdPropertiesKHR* memoryFdProperties){
        vkGetMemoryFdPropertiesKHR(device,handleType,fd,memoryFdProperties);
      }
      
      VkResult createValidationCacheEXT(const VkValidationCacheCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator,ValidationCacheEXT* validationCache){
        vkCreateValidationCacheEXT(device,createInfo,allocator,validationCache);
      }
      
      VkResult getDeviceGroupPresentCapabilitiesKHX(VkDeviceGroupPresentCapabilitiesKHX* deviceGroupPresentCapabilities){
        vkGetDeviceGroupPresentCapabilitiesKHX(device,deviceGroupPresentCapabilities);
      }
      
      void destroySwapchainKHR(SwapchainKHR swapchain,const VkAllocationCallbacks* allocator){
        vkDestroySwapchainKHR(device,swapchain,allocator);
      }
      
      VkResult invalidateMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        vkInvalidateMappedMemoryRanges(device,memoryRangeCount,memoryRanges);
      }
      
      VkResult getSwapchainCounterEXT(SwapchainKHR swapchain,VkSurfaceCounterFlagBitsEXT counter,uint64_t* counterValue){
        vkGetSwapchainCounterEXT(device,swapchain,counter,counterValue);
      }
      
      VkResult createSampler(const VkSamplerCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Sampler* sampler){
        vkCreateSampler(device,createInfo,allocator,sampler);
      }
      
      VkResult createPipelineCache(const VkPipelineCacheCreateInfo* createInfo,const VkAllocationCallbacks* allocator,PipelineCache* pipelineCache){
        vkCreatePipelineCache(device,createInfo,allocator,pipelineCache);
      }
      
      VkResult getMemoryFdKHR(const VkMemoryGetFdInfoKHR* getFdInfo,int* fd){
        vkGetMemoryFdKHR(device,getFdInfo,fd);
      }
      
      VkResult debugMarkerSetObjectTagEXT(const VkDebugMarkerObjectTagInfoEXT* tagInfo){
        vkDebugMarkerSetObjectTagEXT(device,tagInfo);
      }
      
      PFN_vkVoidFunction getDeviceProcAddr(std::string name){
        vkGetDeviceProcAddr(device,name);
      }
      
      VkResult getMemoryWin32HandleKHR(const VkMemoryGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetMemoryWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      VkResult allocateDescriptorSets(const VkDescriptorSetAllocateInfo* allocateInfo,std::vector<DescriptorSet> descriptorSets){
        vkAllocateDescriptorSets(device,allocateInfo,descriptorSets);
      }
      
      VkResult allocateMemory(const VkMemoryAllocateInfo* allocateInfo,const VkAllocationCallbacks* allocator,DeviceMemory* memory){
        vkAllocateMemory(device,allocateInfo,allocator,memory);
      }
      
      void getBufferMemoryRequirements2KHR(const VkBufferMemoryRequirementsInfo2KHR* info,VkMemoryRequirements2KHR* memoryRequirements){
        vkGetBufferMemoryRequirements2KHR(device,info,memoryRequirements);
      }
      
      VkResult registerDeviceEventEXT(const VkDeviceEventInfoEXT* deviceEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
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
      
      void destroyDescriptorUpdateTemplateKHR(const VkAllocationCallbacks* allocator){
        vkDestroyDescriptorUpdateTemplateKHR((VkDevice)device,descriptorUpdateTemplateKHR,allocator);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,PipelineLayout layout,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplateKHR,layout,set,data);
      }
      
      void updateDescriptorSetWithTemplateKHR(DescriptorSet descriptorSet,const void* data){
        vkUpdateDescriptorSetWithTemplateKHR((VkDevice)device,descriptorSet,descriptorUpdateTemplateKHR,data);
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
      
      void cmdUpdateBuffer(Buffer dstBuffer,std::size_t dstOffset,std::vector<void> data){
        vkCmdUpdateBuffer(commandBuffer,dstBuffer,dstOffset,dataSize,data);
      }
      
      VkResult beginCommandBuffer(const VkCommandBufferBeginInfo* beginInfo){
        vkBeginCommandBuffer(commandBuffer,beginInfo);
      }
      
      void cmdSetDiscardRectangleEXT(uint32_t firstDiscardRectangle,std::vector<VkRect2D> discardRectangles){
        vkCmdSetDiscardRectangleEXT(commandBuffer,firstDiscardRectangle,discardRectangleCount,discardRectangles);
      }
      
      void cmdSetViewportWScalingNV(uint32_t firstViewport,std::vector<VkViewportWScalingNV> viewportWScalings){
        vkCmdSetViewportWScalingNV(commandBuffer,firstViewport,viewportCount,viewportWScalings);
      }
      
      void cmdProcessCommandsNVX(const VkCmdProcessCommandsInfoNVX* processCommandsInfo){
        vkCmdProcessCommandsNVX(commandBuffer,processCommandsInfo);
      }
      
      void cmdDispatchBaseKHX(uint32_t baseGroupX,uint32_t baseGroupY,uint32_t baseGroupZ,uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        vkCmdDispatchBaseKHX(commandBuffer,baseGroupX,baseGroupY,baseGroupZ,groupCountX,groupCountY,groupCountZ);
      }
      
      void cmdResetEvent(Event event,VkPipelineStageFlags stageMask){
        vkCmdResetEvent(commandBuffer,event,stageMask);
      }
      
      void cmdBindVertexBuffers(uint32_t firstBinding,std::vector<Buffer> buffers,std::vector<std::size_t> offsets){
        vkCmdBindVertexBuffers(commandBuffer,firstBinding,bindingCount,buffers,offsets);
      }
      
      void cmdDispatch(uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        vkCmdDispatch(commandBuffer,groupCountX,groupCountY,groupCountZ);
      }
      
      void cmdNextSubpass(VkSubpassContents contents){
        vkCmdNextSubpass(commandBuffer,contents);
      }
      
      void cmdPushDescriptorSetKHR(VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        vkCmdPushDescriptorSetKHR(commandBuffer,pipelineBindPoint,layout,set,descriptorWriteCount,descriptorWrites);
      }
      
      void cmdSetViewport(uint32_t firstViewport,std::vector<VkViewport> viewports){
        vkCmdSetViewport(commandBuffer,firstViewport,viewportCount,viewports);
      }
      
      void cmdCopyQueryPoolResults(QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,Buffer dstBuffer,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        vkCmdCopyQueryPoolResults(commandBuffer,queryPool,firstQuery,queryCount,dstBuffer,dstOffset,stride,flags);
      }
      
      void cmdDrawIndexed(uint32_t indexCount,uint32_t instanceCount,uint32_t firstIndex,int32_t vertexOffset,uint32_t firstInstance){
        vkCmdDrawIndexed(commandBuffer,indexCount,instanceCount,firstIndex,vertexOffset,firstInstance);
      }
      
      void cmdSetEvent(Event event,VkPipelineStageFlags stageMask){
        vkCmdSetEvent(commandBuffer,event,stageMask);
      }
      
      void cmdSetSampleLocationsEXT(const VkSampleLocationsInfoEXT* sampleLocationsInfo){
        vkCmdSetSampleLocationsEXT(commandBuffer,sampleLocationsInfo);
      }
      
      void cmdSetScissor(uint32_t firstScissor,std::vector<VkRect2D> scissors){
        vkCmdSetScissor(commandBuffer,firstScissor,scissorCount,scissors);
      }
      
      void cmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage,QueryPool queryPool,uint32_t query){
        vkCmdWriteTimestamp(commandBuffer,pipelineStage,queryPool,query);
      }
      
      void cmdSetLineWidth(float lineWidth){
        vkCmdSetLineWidth(commandBuffer,lineWidth);
      }
      
      void cmdDrawIndirect(Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndirect(commandBuffer,buffer,offset,drawCount,stride);
      }
      
      void cmdDebugMarkerEndEXT(){
        vkCmdDebugMarkerEndEXT(commandBuffer);
      }
      
      void cmdResolveImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageResolve> regions){
        vkCmdResolveImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdEndRenderPass(){
        vkCmdEndRenderPass(commandBuffer);
      }
      
      void cmdResetQueryPool(QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount){
        vkCmdResetQueryPool(commandBuffer,queryPool,firstQuery,queryCount);
      }
      
      void cmdCopyImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        vkCmdCopyImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdReserveSpaceForCommandsNVX(const VkCmdReserveSpaceForCommandsInfoNVX* reserveSpaceInfo){
        vkCmdReserveSpaceForCommandsNVX(commandBuffer,reserveSpaceInfo);
      }
      
      void cmdBlitImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        vkCmdBlitImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regionCount,regions,filter);
      }
      
      void cmdSetStencilWriteMask(VkStencilFaceFlags faceMask,uint32_t writeMask){
        vkCmdSetStencilWriteMask(commandBuffer,faceMask,writeMask);
      }
      
      void cmdExecuteCommands(std::vector<CommandBuffer> commandBuffers){
        vkCmdExecuteCommands(commandBuffer,commandBufferCount,commandBuffers);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(DescriptorUpdateTemplateKHR descriptorUpdateTemplate,PipelineLayout layout,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplate,layout,set,data);
      }
      
      void cmdPipelineBarrier(VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,VkDependencyFlags dependencyFlags,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        vkCmdPipelineBarrier(commandBuffer,srcStageMask,dstStageMask,dependencyFlags,memoryBarrierCount,memoryBarriers,bufferMemoryBarrierCount,bufferMemoryBarriers,imageMemoryBarrierCount,imageMemoryBarriers);
      }
      
      void cmdWaitEvents(std::vector<Event> events,VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        vkCmdWaitEvents(commandBuffer,eventCount,events,srcStageMask,dstStageMask,memoryBarrierCount,memoryBarriers,bufferMemoryBarrierCount,bufferMemoryBarriers,imageMemoryBarrierCount,imageMemoryBarriers);
      }
      
      void cmdDrawIndexedIndirectCountAMD(Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndexedIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDraw(uint32_t vertexCount,uint32_t instanceCount,uint32_t firstVertex,uint32_t firstInstance){
        vkCmdDraw(commandBuffer,vertexCount,instanceCount,firstVertex,firstInstance);
      }
      
      void cmdDrawIndexedIndirect(Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndexedIndirect(commandBuffer,buffer,offset,drawCount,stride);
      }
      
      void cmdCopyImageToBuffer(Image srcImage,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,srcImage,srcImageLayout,dstBuffer,regionCount,regions);
      }
      
      void cmdDebugMarkerInsertEXT(const VkDebugMarkerMarkerInfoEXT* markerInfo){
        vkCmdDebugMarkerInsertEXT(commandBuffer,markerInfo);
      }
      
      void cmdSetStencilCompareMask(VkStencilFaceFlags faceMask,uint32_t compareMask){
        vkCmdSetStencilCompareMask(commandBuffer,faceMask,compareMask);
      }
      
      void cmdPushConstants(PipelineLayout layout,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        vkCmdPushConstants(commandBuffer,layout,stageFlags,offset,size,values);
      }
      
      void cmdDrawIndirectCountAMD(Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDispatchIndirect(Buffer buffer,std::size_t offset){
        vkCmdDispatchIndirect(commandBuffer,buffer,offset);
      }
      
      void cmdCopyBufferToImage(Buffer srcBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,srcBuffer,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void cmdBindPipeline(VkPipelineBindPoint pipelineBindPoint,Pipeline pipeline){
        vkCmdBindPipeline(commandBuffer,pipelineBindPoint,pipeline);
      }
      
      void cmdDebugMarkerBeginEXT(const VkDebugMarkerMarkerInfoEXT* markerInfo){
        vkCmdDebugMarkerBeginEXT(commandBuffer,markerInfo);
      }
      
      VkResult endCommandBuffer(){
        vkEndCommandBuffer(commandBuffer);
      }
      
      VkResult resetCommandBuffer(VkCommandBufferResetFlags flags){
        vkResetCommandBuffer(commandBuffer,flags);
      }
      
      void cmdSetStencilReference(VkStencilFaceFlags faceMask,uint32_t reference){
        vkCmdSetStencilReference(commandBuffer,faceMask,reference);
      }
      
      void cmdEndQuery(QueryPool queryPool,uint32_t query){
        vkCmdEndQuery(commandBuffer,queryPool,query);
      }
      
      void cmdBindIndexBuffer(Buffer buffer,std::size_t offset,VkIndexType indexType){
        vkCmdBindIndexBuffer(commandBuffer,buffer,offset,indexType);
      }
      
      void cmdSetDeviceMaskKHX(uint32_t deviceMask){
        vkCmdSetDeviceMaskKHX(commandBuffer,deviceMask);
      }
      
      void cmdSetDepthBias(float depthBiasConstantFactor,float depthBiasClamp,float depthBiasSlopeFactor){
        vkCmdSetDepthBias(commandBuffer,depthBiasConstantFactor,depthBiasClamp,depthBiasSlopeFactor);
      }
      
      void cmdSetDepthBounds(float minDepthBounds,float maxDepthBounds){
        vkCmdSetDepthBounds(commandBuffer,minDepthBounds,maxDepthBounds);
      }
      
      void cmdClearDepthStencilImage(Image image,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearDepthStencilImage(commandBuffer,image,imageLayout,depthStencil,rangeCount,ranges);
      }
      
      void cmdClearColorImage(Image image,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearColorImage(commandBuffer,image,imageLayout,color,rangeCount,ranges);
      }
      
      void cmdBeginRenderPass(const VkRenderPassBeginInfo* renderPassBegin,VkSubpassContents contents){
        vkCmdBeginRenderPass(commandBuffer,renderPassBegin,contents);
      }
      
      void cmdCopyBuffer(Buffer srcBuffer,Buffer dstBuffer,std::vector<VkBufferCopy> regions){
        vkCmdCopyBuffer(commandBuffer,srcBuffer,dstBuffer,regionCount,regions);
      }
      
      void cmdSetBlendConstants(const float blendConstants){
        vkCmdSetBlendConstants(commandBuffer,blendConstants);
      }
      
      void cmdFillBuffer(Buffer dstBuffer,std::size_t dstOffset,std::size_t size,uint32_t data){
        vkCmdFillBuffer(commandBuffer,dstBuffer,dstOffset,size,data);
      }
      
      void cmdBeginQuery(QueryPool queryPool,uint32_t query,VkQueryControlFlags flags){
        vkCmdBeginQuery(commandBuffer,queryPool,query,flags);
      }
      
      void cmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        vkCmdBindDescriptorSets(commandBuffer,pipelineBindPoint,layout,firstSet,descriptorSetCount,descriptorSets,dynamicOffsetCount,dynamicOffsets);
      }
      
      void cmdClearAttachments(std::vector<VkClearAttachment> attachments,std::vector<VkClearRect> rects){
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
      
      VkResult getSwapchainImagesKHR(Device device,std::vector<Image> swapchainImages){
        vkGetSwapchainImagesKHR(device,swapchainKHR,swapchainImageCount,swapchainImages);
      }
      
      VkResult getRefreshCycleDurationGOOGLE(Device device,VkRefreshCycleDurationGOOGLE* displayTimingProperties){
        vkGetRefreshCycleDurationGOOGLE(device,swapchainKHR,displayTimingProperties);
      }
      
      VkResult getSwapchainStatusKHR(Device device){
        vkGetSwapchainStatusKHR(device,swapchainKHR);
      }
      
      VkResult acquireNextImageKHR(Device device,uint64_t timeout,Semaphore semaphore,Fence fence,uint32_t* imageIndex){
        vkAcquireNextImageKHR(device,swapchainKHR,timeout,semaphore,fence,imageIndex);
      }
      
      VkResult getPastPresentationTimingGOOGLE(Device device,std::vector<VkPastPresentationTimingGOOGLE> presentationTimings){
        vkGetPastPresentationTimingGOOGLE(device,swapchainKHR,presentationTimingCount,presentationTimings);
      }
      
      void destroySwapchainKHR(Device device,const VkAllocationCallbacks* allocator){
        vkDestroySwapchainKHR(device,swapchainKHR,allocator);
      }
      
      VkResult getSwapchainCounterEXT(Device device,VkSurfaceCounterFlagBitsEXT counter,uint64_t* counterValue){
        vkGetSwapchainCounterEXT(device,swapchainKHR,counter,counterValue);
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
      
      void destroyDebugReportCallbackEXT(const VkAllocationCallbacks* allocator){
        vkDestroyDebugReportCallbackEXT((VkInstance)instance,debugReportCallbackEXT,allocator);
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
      
      void cmdBindPipeline(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint){
        vkCmdBindPipeline(commandBuffer,pipelineBindPoint,pipeline);
      }
      
      void destroyPipeline(const VkAllocationCallbacks* allocator){
        vkDestroyPipeline((VkDevice)device,pipeline,allocator);
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
      
      VkResult createComputePipelines(std::vector<VkComputePipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator,std::vector<Pipeline> pipelines){
        vkCreateComputePipelines((VkDevice)device,pipelineCache,createInfoCount,createInfos,allocator,pipelines);
      }
      
      VkResult createGraphicsPipelines(std::vector<VkGraphicsPipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator,std::vector<Pipeline> pipelines){
        vkCreateGraphicsPipelines((VkDevice)device,pipelineCache,createInfoCount,createInfos,allocator,pipelines);
      }
      
      void destroyPipelineCache(const VkAllocationCallbacks* allocator){
        vkDestroyPipelineCache((VkDevice)device,pipelineCache,allocator);
      }
      
      VkResult mergePipelineCaches(std::vector<PipelineCache> srcCaches){
        vkMergePipelineCaches((VkDevice)device,pipelineCache,srcCacheCount,srcCaches);
      }
      
      VkResult getPipelineCacheData(std::vector<void> data){
        vkGetPipelineCacheData((VkDevice)device,pipelineCache,dataSize,data);
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
      
      VkResult bindBufferMemory(Buffer buffer,std::size_t memoryOffset){
        vkBindBufferMemory((VkDevice)device,buffer,deviceMemory,memoryOffset);
      }
      
      void freeMemory(const VkAllocationCallbacks* allocator){
        vkFreeMemory((VkDevice)device,deviceMemory,allocator);
      }
      
      VkResult mapMemory(std::size_t offset,std::size_t size,VkMemoryMapFlags flags,void** data){
        vkMapMemory((VkDevice)device,deviceMemory,offset,size,flags,data);
      }
      
      void unmapMemory(){
        vkUnmapMemory((VkDevice)device,deviceMemory);
      }
      
      VkResult getMemoryWin32HandleNV(VkExternalMemoryHandleTypeFlagsNV handleType,HANDLE* handle){
        vkGetMemoryWin32HandleNV((VkDevice)device,deviceMemory,handleType,handle);
      }
      
      VkResult bindImageMemory(Image image,std::size_t memoryOffset){
        vkBindImageMemory((VkDevice)device,image,deviceMemory,memoryOffset);
      }
      
      void getDeviceMemoryCommitment(std::size_t* committedMemoryInBytes){
        vkGetDeviceMemoryCommitment((VkDevice)device,deviceMemory,committedMemoryInBytes);
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
      
      void cmdUpdateBuffer(CommandBuffer commandBuffer,std::size_t dstOffset,std::vector<void> data){
        vkCmdUpdateBuffer(commandBuffer,buffer,dstOffset,dataSize,data);
      }
      
      VkResult bindBufferMemory(DeviceMemory memory,std::size_t memoryOffset){
        vkBindBufferMemory((VkDevice)device,buffer,memory,memoryOffset);
      }
      
      void cmdCopyQueryPoolResults(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        vkCmdCopyQueryPoolResults(commandBuffer,queryPool,firstQuery,queryCount,buffer,dstOffset,stride,flags);
      }
      
      void cmdDrawIndirect(CommandBuffer commandBuffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndirect(commandBuffer,buffer,offset,drawCount,stride);
      }
      
      void cmdDrawIndexedIndirect(CommandBuffer commandBuffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndexedIndirect(commandBuffer,buffer,offset,drawCount,stride);
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,srcImage,srcImageLayout,buffer,regionCount,regions);
      }
      
      void destroyBuffer(const VkAllocationCallbacks* allocator){
        vkDestroyBuffer((VkDevice)device,buffer,allocator);
      }
      
      void cmdDispatchIndirect(CommandBuffer commandBuffer,std::size_t offset){
        vkCmdDispatchIndirect(commandBuffer,buffer,offset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,buffer,dstImage,dstImageLayout,regionCount,regions);
      }
      
      void getBufferMemoryRequirements(VkMemoryRequirements* memoryRequirements){
        vkGetBufferMemoryRequirements((VkDevice)device,buffer,memoryRequirements);
      }
      
      void cmdBindIndexBuffer(CommandBuffer commandBuffer,std::size_t offset,VkIndexType indexType){
        vkCmdBindIndexBuffer(commandBuffer,buffer,offset,indexType);
      }
      
      void cmdFillBuffer(CommandBuffer commandBuffer,std::size_t dstOffset,std::size_t size,uint32_t data){
        vkCmdFillBuffer(commandBuffer,buffer,dstOffset,size,data);
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
      
      void destroyFramebuffer(const VkAllocationCallbacks* allocator){
        vkDestroyFramebuffer((VkDevice)device,framebuffer,allocator);
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
      
      void destroyObjectTableNVX(const VkAllocationCallbacks* allocator){
        vkDestroyObjectTableNVX((VkDevice)device,objectTableNVX,allocator);
      }
      
      VkResult unregisterObjectsNVX(std::vector<VkObjectEntryTypeNVX> objectEntryTypes,std::vector<uint32_t> objectIndices){
        vkUnregisterObjectsNVX((VkDevice)device,objectTableNVX,objectCount,objectEntryTypes,objectIndices);
      }
      
      VkResult registerObjectsNVX(std::vector<VkObjectTableEntryNVX> objectTableEntries,std::vector<uint32_t> objectIndices){
        vkRegisterObjectsNVX((VkDevice)device,objectTableNVX,objectCount,objectTableEntries,objectIndices);
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
      
      void destroyShaderModule(const VkAllocationCallbacks* allocator){
        vkDestroyShaderModule((VkDevice)device,shaderModule,allocator);
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
      
      VkResult queueSubmit(Queue queue,std::vector<VkSubmitInfo> submits){
        vkQueueSubmit(queue,submitCount,submits,fence);
      }
      
      void destroyFence(const VkAllocationCallbacks* allocator){
        vkDestroyFence((VkDevice)device,fence,allocator);
      }
      
      VkResult acquireNextImageKHR(SwapchainKHR swapchain,uint64_t timeout,Semaphore semaphore,uint32_t* imageIndex){
        vkAcquireNextImageKHR((VkDevice)device,swapchain,timeout,semaphore,fence,imageIndex);
      }
      
      VkResult queueBindSparse(Queue queue,std::vector<VkBindSparseInfo> bindInfo){
        vkQueueBindSparse(queue,bindInfoCount,bindInfo,fence);
      }
      
      VkResult getFenceStatus(){
        vkGetFenceStatus((VkDevice)device,fence);
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
      
      void cmdCopyQueryPoolResults(CommandBuffer commandBuffer,uint32_t firstQuery,uint32_t queryCount,Buffer dstBuffer,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        vkCmdCopyQueryPoolResults(commandBuffer,queryPool,firstQuery,queryCount,dstBuffer,dstOffset,stride,flags);
      }
      
      void cmdWriteTimestamp(CommandBuffer commandBuffer,VkPipelineStageFlagBits pipelineStage,uint32_t query){
        vkCmdWriteTimestamp(commandBuffer,pipelineStage,queryPool,query);
      }
      
      void cmdResetQueryPool(CommandBuffer commandBuffer,uint32_t firstQuery,uint32_t queryCount){
        vkCmdResetQueryPool(commandBuffer,queryPool,firstQuery,queryCount);
      }
      
      void destroyQueryPool(const VkAllocationCallbacks* allocator){
        vkDestroyQueryPool((VkDevice)device,queryPool,allocator);
      }
      
      void cmdEndQuery(CommandBuffer commandBuffer,uint32_t query){
        vkCmdEndQuery(commandBuffer,queryPool,query);
      }
      
      VkResult getQueryPoolResults(uint32_t firstQuery,uint32_t queryCount,std::vector<void> data,std::size_t stride,VkQueryResultFlags flags){
        vkGetQueryPoolResults((VkDevice)device,queryPool,firstQuery,queryCount,dataSize,data,stride,flags);
      }
      
      void cmdBeginQuery(CommandBuffer commandBuffer,uint32_t query,VkQueryControlFlags flags){
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
      
      void getImageSubresourceLayout(const VkImageSubresource* subresource,VkSubresourceLayout* layout){
        vkGetImageSubresourceLayout((VkDevice)device,image,subresource,layout);
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,image,srcImageLayout,dstBuffer,regionCount,regions);
      }
      
      void destroyImage(const VkAllocationCallbacks* allocator){
        vkDestroyImage((VkDevice)device,image,allocator);
      }
      
      VkResult bindImageMemory(DeviceMemory memory,std::size_t memoryOffset){
        vkBindImageMemory((VkDevice)device,image,memory,memoryOffset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Buffer srcBuffer,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,srcBuffer,image,dstImageLayout,regionCount,regions);
      }
      
      void getImageSparseMemoryRequirements(std::vector<VkSparseImageMemoryRequirements> sparseMemoryRequirements){
        vkGetImageSparseMemoryRequirements((VkDevice)device,image,sparseMemoryRequirementCount,sparseMemoryRequirements);
      }
      
      void cmdClearDepthStencilImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearDepthStencilImage(commandBuffer,image,imageLayout,depthStencil,rangeCount,ranges);
      }
      
      void cmdClearColorImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearColorImage(commandBuffer,image,imageLayout,color,rangeCount,ranges);
      }
      
      void getImageMemoryRequirements(VkMemoryRequirements* memoryRequirements){
        vkGetImageMemoryRequirements((VkDevice)device,image,memoryRequirements);
      }
    private:
      VkImage image;
      Device device;
  }