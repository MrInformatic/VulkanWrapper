namespace vk{
  class DescriptorPool{
    public:
      DescriptorPool(VkDescriptorPool descriptorPool_,Device device_)
        : descriptorPool(descriptorPool_),
          device(device_){
      }
      
      VkResult freeDescriptorSets(std::vector<DescriptorSet> descriptorSets){
        vkFreeDescriptorSets(descriptorSets);
      }
      
      VkResult resetDescriptorPool(VkDescriptorPoolResetFlags flags){
        vkResetDescriptorPool(flags);
      }
      
      void destroyDescriptorPool(const VkAllocationCallbacks* allocator){
        vkDestroyDescriptorPool(allocator);
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
        vkAcquireNextImageKHR(swapchain,timeout,fence,imageIndex);
      }
      
      void destroySemaphore(const VkAllocationCallbacks* allocator){
        vkDestroySemaphore(allocator);
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
        vkGetValidationCacheDataEXT(data);
      }
      
      VkResult mergeValidationCachesEXT(std::vector<ValidationCacheEXT> srcCaches){
        vkMergeValidationCachesEXT(srcCaches);
      }
      
      void destroyValidationCacheEXT(const VkAllocationCallbacks* allocator){
        vkDestroyValidationCacheEXT(allocator);
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
        vkDestroyRenderPass(allocator);
      }
      
      void getRenderAreaGranularity(VkExtent2D* granularity){
        vkGetRenderAreaGranularity(granularity);
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
        vkGetDisplayPlaneCapabilitiesKHR(planeIndex,capabilities);
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
        vkDestroySampler(allocator);
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
        vkQueueWaitIdle();
      }
      
      VkResult queueSubmit(std::vector<VkSubmitInfo> submits,Fence fence){
        vkQueueSubmit(submits,fence);
      }
      
      VkResult queueBindSparse(std::vector<VkBindSparseInfo> bindInfo,Fence fence){
        vkQueueBindSparse(bindInfo,fence);
      }
      
      VkResult queuePresentKHR(const VkPresentInfoKHR* presentInfo){
        vkQueuePresentKHR(presentInfo);
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
        vkDestroySamplerYcbcrConversionKHR(allocator);
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
        vkTrimCommandPoolKHR(flags);
      }
      
      VkResult resetCommandPool(VkCommandPoolResetFlags flags){
        vkResetCommandPool(flags);
      }
      
      void destroyCommandPool(const VkAllocationCallbacks* allocator){
        vkDestroyCommandPool(allocator);
      }
      
      void freeCommandBuffers(std::vector<CommandBuffer> commandBuffers){
        vkFreeCommandBuffers(commandBuffers);
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
        vkUpdateDescriptorSetWithTemplateKHR(descriptorUpdateTemplate,data);
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
        vkDestroyDescriptorSetLayout(allocator);
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
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,rects);
      }
      
      void destroySurfaceKHR(const VkAllocationCallbacks* allocator){
        vkDestroySurfaceKHR(allocator);
      }
      
      VkResult getPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice physicalDevice,std::vector<VkPresentModeKHR> presentModes){
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,presentModes);
      }
      
      VkResult getDeviceGroupSurfacePresentModesKHX(Device device,VkDeviceGroupPresentModeFlagsKHX* modes){
        vkGetDeviceGroupSurfacePresentModesKHX(device,modes);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2EXT(PhysicalDevice physicalDevice,VkSurfaceCapabilities2EXT* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceSurfaceSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex,bool* supported){
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,supported);
      }
      
      VkResult getPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice physicalDevice,std::vector<VkSurfaceFormatKHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surfaceFormats);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice physicalDevice,VkSurfaceCapabilitiesKHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surfaceCapabilities);
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
        vkCmdResetEvent(commandBuffer,stageMask);
      }
      
      void destroyEvent(const VkAllocationCallbacks* allocator){
        vkDestroyEvent(allocator);
      }
      
      void cmdSetEvent(CommandBuffer commandBuffer,VkPipelineStageFlags stageMask){
        vkCmdSetEvent(commandBuffer,stageMask);
      }
      
      VkResult resetEvent(){
        vkResetEvent();
      }
      
      VkResult setEvent(){
        vkSetEvent();
      }
      
      VkResult getEventStatus(){
        vkGetEventStatus();
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
        vkDestroyBufferView(allocator);
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
        vkDestroyPipelineLayout(allocator);
      }
      
      void cmdPushDescriptorSetKHR(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        vkCmdPushDescriptorSetKHR(commandBuffer,pipelineBindPoint,set,descriptorWrites);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplate,set,data);
      }
      
      void cmdPushConstants(CommandBuffer commandBuffer,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        vkCmdPushConstants(commandBuffer,stageFlags,offset,values);
      }
      
      void cmdBindDescriptorSets(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        vkCmdBindDescriptorSets(commandBuffer,pipelineBindPoint,firstSet,descriptorSets,dynamicOffsets);
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
        vkCreateXlibSurfaceKHR(createInfo,allocator,surface);
      }
      
      VkResult createWin32SurfaceKHR(const VkWin32SurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateWin32SurfaceKHR(createInfo,allocator,surface);
      }
      
      PFN_vkVoidFunction getInstanceProcAddr(std::string name){
        vkGetInstanceProcAddr(name);
      }
      
      VkResult createWaylandSurfaceKHR(const VkWaylandSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateWaylandSurfaceKHR(createInfo,allocator,surface);
      }
      
      VkResult createIOSSurfaceMVK(const VkIOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateIOSSurfaceMVK(createInfo,allocator,surface);
      }
      
      VkResult createAndroidSurfaceKHR(const VkAndroidSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateAndroidSurfaceKHR(createInfo,allocator,surface);
      }
      
      VkResult createDebugReportCallbackEXT(const VkDebugReportCallbackCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator,DebugReportCallbackEXT* callback){
        vkCreateDebugReportCallbackEXT(createInfo,allocator,callback);
      }
      
      VkResult createViSurfaceNN(const VkViSurfaceCreateInfoNN* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateViSurfaceNN(createInfo,allocator,surface);
      }
      
      VkResult enumeratePhysicalDevices(std::vector<PhysicalDevice> physicalDevices){
        vkEnumeratePhysicalDevices(physicalDevices);
      }
      
      VkResult createMacOSSurfaceMVK(const VkMacOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateMacOSSurfaceMVK(createInfo,allocator,surface);
      }
      
      VkResult createXcbSurfaceKHR(const VkXcbSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateXcbSurfaceKHR(createInfo,allocator,surface);
      }
      
      void destroyInstance(const VkAllocationCallbacks* allocator){
        vkDestroyInstance(allocator);
      }
      
      void debugReportMessageEXT(VkDebugReportFlagsEXT flags,VkDebugReportObjectTypeEXT objectType,uint64_t object,size_t location,int32_t messageCode,std::string layerPrefix,std::string message){
        vkDebugReportMessageEXT(flags,objectType,object,location,messageCode,layerPrefix,message);
      }
      
      VkResult enumeratePhysicalDeviceGroupsKHX(std::vector<VkPhysicalDeviceGroupPropertiesKHX> physicalDeviceGroupProperties){
        vkEnumeratePhysicalDeviceGroupsKHX(physicalDeviceGroupProperties);
      }
      
      VkResult createMirSurfaceKHR(const VkMirSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateMirSurfaceKHR(createInfo,allocator,surface);
      }
      
      VkResult createDisplayPlaneSurfaceKHR(const VkDisplaySurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SurfaceKHR* surface){
        vkCreateDisplayPlaneSurfaceKHR(createInfo,allocator,surface);
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
        vkGetPhysicalDeviceQueueFamilyProperties(queueFamilyProperties);
      }
      
      void getPhysicalDeviceSparseImageFormatProperties2KHR(const VkPhysicalDeviceSparseImageFormatInfo2KHR* formatInfo,std::vector<VkSparseImageFormatProperties2KHR> properties){
        vkGetPhysicalDeviceSparseImageFormatProperties2KHR(formatInfo,properties);
      }
      
      void getPhysicalDeviceGeneratedCommandsPropertiesNVX(VkDeviceGeneratedCommandsFeaturesNVX* features,VkDeviceGeneratedCommandsLimitsNVX* limits){
        vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(features,limits);
      }
      
      VkResult getPhysicalDeviceSurfaceFormats2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo,std::vector<VkSurfaceFormat2KHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormats2KHR(surfaceInfo,surfaceFormats);
      }
      
      VkResult getPhysicalDevicePresentRectanglesKHX(SurfaceKHR surface,std::vector<VkRect2D> rects){
        vkGetPhysicalDevicePresentRectanglesKHX(surface,rects);
      }
      
      VkBool32 getPhysicalDeviceWaylandPresentationSupportKHR(uint32_t queueFamilyIndex,struct wl_display* display){
        vkGetPhysicalDeviceWaylandPresentationSupportKHR(queueFamilyIndex,display);
      }
      
      VkResult createDevice(const VkDeviceCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Device* device){
        vkCreateDevice(createInfo,allocator,device);
      }
      
      VkResult createDisplayModeKHR(DisplayKHR display,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,DisplayModeKHR* mode){
        vkCreateDisplayModeKHR(display,createInfo,allocator,mode);
      }
      
      VkResult enumerateDeviceLayerProperties(std::vector<VkLayerProperties> properties){
        vkEnumerateDeviceLayerProperties(properties);
      }
      
      void getPhysicalDeviceFeatures(VkPhysicalDeviceFeatures* features){
        vkGetPhysicalDeviceFeatures(features);
      }
      
      void getPhysicalDeviceQueueFamilyProperties2KHR(std::vector<VkQueueFamilyProperties2KHR> queueFamilyProperties){
        vkGetPhysicalDeviceQueueFamilyProperties2KHR(queueFamilyProperties);
      }
      
      void getPhysicalDeviceExternalSemaphorePropertiesKHR(const VkPhysicalDeviceExternalSemaphoreInfoKHR* externalSemaphoreInfo,VkExternalSemaphorePropertiesKHR* externalSemaphoreProperties){
        vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(externalSemaphoreInfo,externalSemaphoreProperties);
      }
      
      void getPhysicalDeviceFeatures2KHR(VkPhysicalDeviceFeatures2KHR* features){
        vkGetPhysicalDeviceFeatures2KHR(features);
      }
      
      void getPhysicalDeviceMultisamplePropertiesEXT(VkSampleCountFlagBits samples,VkMultisamplePropertiesEXT* multisampleProperties){
        vkGetPhysicalDeviceMultisamplePropertiesEXT(samples,multisampleProperties);
      }
      
      void getPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties* memoryProperties){
        vkGetPhysicalDeviceMemoryProperties(memoryProperties);
      }
      
      VkResult getDisplayModePropertiesKHR(DisplayKHR display,std::vector<VkDisplayModePropertiesKHR> properties){
        vkGetDisplayModePropertiesKHR(display,properties);
      }
      
      VkResult getPhysicalDeviceSurfacePresentModesKHR(SurfaceKHR surface,std::vector<VkPresentModeKHR> presentModes){
        vkGetPhysicalDeviceSurfacePresentModesKHR(surface,presentModes);
      }
      
      VkResult acquireXlibDisplayEXT(Display* dpy,DisplayKHR display){
        vkAcquireXlibDisplayEXT(dpy,display);
      }
      
      void getPhysicalDeviceProperties2KHR(VkPhysicalDeviceProperties2KHR* properties){
        vkGetPhysicalDeviceProperties2KHR(properties);
      }
      
      VkResult getDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex,std::vector<DisplayKHR> displays){
        vkGetDisplayPlaneSupportedDisplaysKHR(planeIndex,displays);
      }
      
      void getPhysicalDeviceMemoryProperties2KHR(VkPhysicalDeviceMemoryProperties2KHR* memoryProperties){
        vkGetPhysicalDeviceMemoryProperties2KHR(memoryProperties);
      }
      
      VkBool32 getPhysicalDeviceXcbPresentationSupportKHR(uint32_t queueFamilyIndex,xcb_connection_t* connection,xcb_visualid_t visual_id){
        vkGetPhysicalDeviceXcbPresentationSupportKHR(queueFamilyIndex,connection,visual_id);
      }
      
      VkResult getRandROutputDisplayEXT(Display* dpy,RROutput rrOutput,DisplayKHR* display){
        vkGetRandROutputDisplayEXT(dpy,rrOutput,display);
      }
      
      void getPhysicalDeviceFormatProperties(VkFormat format,VkFormatProperties* formatProperties){
        vkGetPhysicalDeviceFormatProperties(format,formatProperties);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2EXT(SurfaceKHR surface,VkSurfaceCapabilities2EXT* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(surface,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex,SurfaceKHR surface,bool* supported){
        vkGetPhysicalDeviceSurfaceSupportKHR(queueFamilyIndex,surface,supported);
      }
      
      VkResult getPhysicalDeviceImageFormatProperties2KHR(const VkPhysicalDeviceImageFormatInfo2KHR* imageFormatInfo,VkImageFormatProperties2KHR* imageFormatProperties){
        vkGetPhysicalDeviceImageFormatProperties2KHR(imageFormatInfo,imageFormatProperties);
      }
      
      VkBool32 getPhysicalDeviceWin32PresentationSupportKHR(uint32_t queueFamilyIndex){
        vkGetPhysicalDeviceWin32PresentationSupportKHR(queueFamilyIndex);
      }
      
      VkBool32 getPhysicalDeviceXlibPresentationSupportKHR(uint32_t queueFamilyIndex,Display* dpy,VisualID visualID){
        vkGetPhysicalDeviceXlibPresentationSupportKHR(queueFamilyIndex,dpy,visualID);
      }
      
      VkResult getPhysicalDeviceImageFormatProperties(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkImageFormatProperties* imageFormatProperties){
        vkGetPhysicalDeviceImageFormatProperties(format,type,tiling,usage,flags,imageFormatProperties);
      }
      
      VkResult enumerateDeviceExtensionProperties(std::string layerName,std::vector<VkExtensionProperties> properties){
        vkEnumerateDeviceExtensionProperties(layerName,properties);
      }
      
      void getPhysicalDeviceExternalFencePropertiesKHR(const VkPhysicalDeviceExternalFenceInfoKHR* externalFenceInfo,VkExternalFencePropertiesKHR* externalFenceProperties){
        vkGetPhysicalDeviceExternalFencePropertiesKHR(externalFenceInfo,externalFenceProperties);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilities2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo,VkSurfaceCapabilities2KHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilities2KHR(surfaceInfo,surfaceCapabilities);
      }
      
      VkResult getPhysicalDeviceExternalImageFormatPropertiesNV(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkExternalMemoryHandleTypeFlagsNV externalHandleType,VkExternalImageFormatPropertiesNV* externalImageFormatProperties){
        vkGetPhysicalDeviceExternalImageFormatPropertiesNV(format,type,tiling,usage,flags,externalHandleType,externalImageFormatProperties);
      }
      
      void getPhysicalDeviceExternalBufferPropertiesKHR(const VkPhysicalDeviceExternalBufferInfoKHR* externalBufferInfo,VkExternalBufferPropertiesKHR* externalBufferProperties){
        vkGetPhysicalDeviceExternalBufferPropertiesKHR(externalBufferInfo,externalBufferProperties);
      }
      
      VkResult getPhysicalDeviceDisplayPlanePropertiesKHR(std::vector<VkDisplayPlanePropertiesKHR> properties){
        vkGetPhysicalDeviceDisplayPlanePropertiesKHR(properties);
      }
      
      VkResult getPhysicalDeviceDisplayPropertiesKHR(std::vector<VkDisplayPropertiesKHR> properties){
        vkGetPhysicalDeviceDisplayPropertiesKHR(properties);
      }
      
      void getPhysicalDeviceSparseImageFormatProperties(VkFormat format,VkImageType type,VkSampleCountFlagBits samples,VkImageUsageFlags usage,VkImageTiling tiling,std::vector<VkSparseImageFormatProperties> properties){
        vkGetPhysicalDeviceSparseImageFormatProperties(format,type,samples,usage,tiling,properties);
      }
      
      void getPhysicalDeviceProperties(VkPhysicalDeviceProperties* properties){
        vkGetPhysicalDeviceProperties(properties);
      }
      
      VkResult getPhysicalDeviceSurfaceFormatsKHR(SurfaceKHR surface,std::vector<VkSurfaceFormatKHR> surfaceFormats){
        vkGetPhysicalDeviceSurfaceFormatsKHR(surface,surfaceFormats);
      }
      
      VkResult getPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHR surface,VkSurfaceCapabilitiesKHR* surfaceCapabilities){
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(surface,surfaceCapabilities);
      }
      
      VkBool32 getPhysicalDeviceMirPresentationSupportKHR(uint32_t queueFamilyIndex,MirConnection* connection){
        vkGetPhysicalDeviceMirPresentationSupportKHR(queueFamilyIndex,connection);
      }
      
      VkResult releaseDisplayEXT(DisplayKHR display){
        vkReleaseDisplayEXT(display);
      }
      
      void getPhysicalDeviceFormatProperties2KHR(VkFormat format,VkFormatProperties2KHR* formatProperties){
        vkGetPhysicalDeviceFormatProperties2KHR(format,formatProperties);
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
        vkCreateDisplayModeKHR(physicalDevice,createInfo,allocator,mode);
      }
      
      VkResult displayPowerControlEXT(Device device,const VkDisplayPowerInfoEXT* displayPowerInfo){
        vkDisplayPowerControlEXT(device,displayPowerInfo);
      }
      
      VkResult getDisplayModePropertiesKHR(PhysicalDevice physicalDevice,std::vector<VkDisplayModePropertiesKHR> properties){
        vkGetDisplayModePropertiesKHR(physicalDevice,properties);
      }
      
      VkResult acquireXlibDisplayEXT(PhysicalDevice physicalDevice,Display* dpy){
        vkAcquireXlibDisplayEXT(physicalDevice,dpy);
      }
      
      VkResult registerDisplayEventEXT(Device device,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkRegisterDisplayEventEXT(device,displayEventInfo,allocator,fence);
      }
      
      VkResult releaseDisplayEXT(PhysicalDevice physicalDevice){
        vkReleaseDisplayEXT(physicalDevice);
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
        vkDestroyImageView(allocator);
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
        vkDestroyIndirectCommandsLayoutNVX(allocator);
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
        vkSetHdrMetadataEXT(swapchains,metadata);
      }
      
      VkResult createSamplerYcbcrConversionKHR(const VkSamplerYcbcrConversionCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SamplerYcbcrConversionKHR* ycbcrConversion){
        vkCreateSamplerYcbcrConversionKHR(createInfo,allocator,ycbcrConversion);
      }
      
      void updateDescriptorSets(std::vector<VkWriteDescriptorSet> descriptorWrites,std::vector<VkCopyDescriptorSet> descriptorCopies){
        vkUpdateDescriptorSets(descriptorWrites,descriptorCopies);
      }
      
      VkResult getSwapchainImagesKHR(SwapchainKHR swapchain,std::vector<Image> swapchainImages){
        vkGetSwapchainImagesKHR(swapchain,swapchainImages);
      }
      
      VkResult importFenceWin32HandleKHR(const VkImportFenceWin32HandleInfoKHR* importFenceWin32HandleInfo){
        vkImportFenceWin32HandleKHR(importFenceWin32HandleInfo);
      }
      
      VkResult debugMarkerSetObjectNameEXT(const VkDebugMarkerObjectNameInfoEXT* nameInfo){
        vkDebugMarkerSetObjectNameEXT(nameInfo);
      }
      
      VkResult getRefreshCycleDurationGOOGLE(SwapchainKHR swapchain,VkRefreshCycleDurationGOOGLE* displayTimingProperties){
        vkGetRefreshCycleDurationGOOGLE(swapchain,displayTimingProperties);
      }
      
      VkResult bindImageMemory2KHR(std::vector<VkBindImageMemoryInfoKHR> bindInfos){
        vkBindImageMemory2KHR(bindInfos);
      }
      
      VkResult bindBufferMemory2KHR(std::vector<VkBindBufferMemoryInfoKHR> bindInfos){
        vkBindBufferMemory2KHR(bindInfos);
      }
      
      VkResult importSemaphoreWin32HandleKHR(const VkImportSemaphoreWin32HandleInfoKHR* importSemaphoreWin32HandleInfo){
        vkImportSemaphoreWin32HandleKHR(importSemaphoreWin32HandleInfo);
      }
      
      VkResult getSemaphoreFdKHR(const VkSemaphoreGetFdInfoKHR* getFdInfo,int* fd){
        vkGetSemaphoreFdKHR(getFdInfo,fd);
      }
      
      VkResult getMemoryWin32HandlePropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,HANDLE handle,VkMemoryWin32HandlePropertiesKHR* memoryWin32HandleProperties){
        vkGetMemoryWin32HandlePropertiesKHR(handleType,handle,memoryWin32HandleProperties);
      }
      
      VkResult createDescriptorUpdateTemplateKHR(const VkDescriptorUpdateTemplateCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,DescriptorUpdateTemplateKHR* descriptorUpdateTemplate){
        vkCreateDescriptorUpdateTemplateKHR(createInfo,allocator,descriptorUpdateTemplate);
      }
      
      VkResult flushMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        vkFlushMappedMemoryRanges(memoryRanges);
      }
      
      VkResult createDescriptorPool(const VkDescriptorPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,DescriptorPool* descriptorPool){
        vkCreateDescriptorPool(createInfo,allocator,descriptorPool);
      }
      
      VkResult resetFences(std::vector<Fence> fences){
        vkResetFences(fences);
      }
      
      void getImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2KHR* info,std::vector<VkSparseImageMemoryRequirements2KHR> sparseMemoryRequirements){
        vkGetImageSparseMemoryRequirements2KHR(info,sparseMemoryRequirements);
      }
      
      VkResult createImage(const VkImageCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Image* image){
        vkCreateImage(createInfo,allocator,image);
      }
      
      VkResult createShaderModule(const VkShaderModuleCreateInfo* createInfo,const VkAllocationCallbacks* allocator,ShaderModule* shaderModule){
        vkCreateShaderModule(createInfo,allocator,shaderModule);
      }
      
      VkResult acquireNextImage2KHX(const VkAcquireNextImageInfoKHX* acquireInfo,uint32_t* imageIndex){
        vkAcquireNextImage2KHX(acquireInfo,imageIndex);
      }
      
      void destroyDevice(const VkAllocationCallbacks* allocator){
        vkDestroyDevice(allocator);
      }
      
      VkResult getSwapchainStatusKHR(SwapchainKHR swapchain){
        vkGetSwapchainStatusKHR(swapchain);
      }
      
      VkResult createBuffer(const VkBufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Buffer* buffer){
        vkCreateBuffer(createInfo,allocator,buffer);
      }
      
      VkResult importSemaphoreFdKHR(const VkImportSemaphoreFdInfoKHR* importSemaphoreFdInfo){
        vkImportSemaphoreFdKHR(importSemaphoreFdInfo);
      }
      
      VkResult createEvent(const VkEventCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Event* event){
        vkCreateEvent(createInfo,allocator,event);
      }
      
      VkResult displayPowerControlEXT(DisplayKHR display,const VkDisplayPowerInfoEXT* displayPowerInfo){
        vkDisplayPowerControlEXT(display,displayPowerInfo);
      }
      
      VkResult createIndirectCommandsLayoutNVX(const VkIndirectCommandsLayoutCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator,IndirectCommandsLayoutNVX* indirectCommandsLayout){
        vkCreateIndirectCommandsLayoutNVX(createInfo,allocator,indirectCommandsLayout);
      }
      
      VkResult getPastPresentationTimingGOOGLE(SwapchainKHR swapchain,std::vector<VkPastPresentationTimingGOOGLE> presentationTimings){
        vkGetPastPresentationTimingGOOGLE(swapchain,presentationTimings);
      }
      
      VkResult createFence(const VkFenceCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkCreateFence(createInfo,allocator,fence);
      }
      
      VkResult createImageView(const VkImageViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator,ImageView* view){
        vkCreateImageView(createInfo,allocator,view);
      }
      
      VkResult getDeviceGroupSurfacePresentModesKHX(SurfaceKHR surface,VkDeviceGroupPresentModeFlagsKHX* modes){
        vkGetDeviceGroupSurfacePresentModesKHX(surface,modes);
      }
      
      VkResult createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator,DescriptorSetLayout* setLayout){
        vkCreateDescriptorSetLayout(createInfo,allocator,setLayout);
      }
      
      VkResult createQueryPool(const VkQueryPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,QueryPool* queryPool){
        vkCreateQueryPool(createInfo,allocator,queryPool);
      }
      
      VkResult createRenderPass(const VkRenderPassCreateInfo* createInfo,const VkAllocationCallbacks* allocator,RenderPass* renderPass){
        vkCreateRenderPass(createInfo,allocator,renderPass);
      }
      
      VkResult deviceWaitIdle(){
        vkDeviceWaitIdle();
      }
      
      VkResult allocateCommandBuffers(const VkCommandBufferAllocateInfo* allocateInfo,std::vector<CommandBuffer> commandBuffers){
        vkAllocateCommandBuffers(allocateInfo,commandBuffers);
      }
      
      void getDeviceQueue(uint32_t queueFamilyIndex,uint32_t queueIndex,Queue* queue){
        vkGetDeviceQueue(queueFamilyIndex,queueIndex,queue);
      }
      
      VkResult registerDisplayEventEXT(DisplayKHR display,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkRegisterDisplayEventEXT(display,displayEventInfo,allocator,fence);
      }
      
      VkResult createPipelineLayout(const VkPipelineLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator,PipelineLayout* pipelineLayout){
        vkCreatePipelineLayout(createInfo,allocator,pipelineLayout);
      }
      
      VkResult createFramebuffer(const VkFramebufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Framebuffer* framebuffer){
        vkCreateFramebuffer(createInfo,allocator,framebuffer);
      }
      
      VkResult getFenceFdKHR(const VkFenceGetFdInfoKHR* getFdInfo,int* fd){
        vkGetFenceFdKHR(getFdInfo,fd);
      }
      
      void getDeviceGroupPeerMemoryFeaturesKHX(uint32_t heapIndex,uint32_t localDeviceIndex,uint32_t remoteDeviceIndex,VkPeerMemoryFeatureFlagsKHX* peerMemoryFeatures){
        vkGetDeviceGroupPeerMemoryFeaturesKHX(heapIndex,localDeviceIndex,remoteDeviceIndex,peerMemoryFeatures);
      }
      
      void getImageMemoryRequirements2KHR(const VkImageMemoryRequirementsInfo2KHR* info,VkMemoryRequirements2KHR* memoryRequirements){
        vkGetImageMemoryRequirements2KHR(info,memoryRequirements);
      }
      
      VkResult createBufferView(const VkBufferViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator,BufferView* view){
        vkCreateBufferView(createInfo,allocator,view);
      }
      
      VkResult createSemaphore(const VkSemaphoreCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Semaphore* semaphore){
        vkCreateSemaphore(createInfo,allocator,semaphore);
      }
      
      VkResult createObjectTableNVX(const VkObjectTableCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator,ObjectTableNVX* objectTable){
        vkCreateObjectTableNVX(createInfo,allocator,objectTable);
      }
      
      VkResult importFenceFdKHR(const VkImportFenceFdInfoKHR* importFenceFdInfo){
        vkImportFenceFdKHR(importFenceFdInfo);
      }
      
      VkResult createSharedSwapchainsKHR(std::vector<VkSwapchainCreateInfoKHR> createInfos,const VkAllocationCallbacks* allocator,std::vector<SwapchainKHR> swapchains){
        vkCreateSharedSwapchainsKHR(createInfos,allocator,swapchains);
      }
      
      VkResult createCommandPool(const VkCommandPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator,CommandPool* commandPool){
        vkCreateCommandPool(createInfo,allocator,commandPool);
      }
      
      VkResult getSemaphoreWin32HandleKHR(const VkSemaphoreGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetSemaphoreWin32HandleKHR(getWin32HandleInfo,handle);
      }
      
      VkResult getFenceWin32HandleKHR(const VkFenceGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetFenceWin32HandleKHR(getWin32HandleInfo,handle);
      }
      
      VkResult waitForFences(std::vector<Fence> fences,bool waitAll,uint64_t timeout){
        vkWaitForFences(fences,waitAll,timeout);
      }
      
      VkResult createSwapchainKHR(const VkSwapchainCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator,SwapchainKHR* swapchain){
        vkCreateSwapchainKHR(createInfo,allocator,swapchain);
      }
      
      VkResult getMemoryFdPropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,int fd,VkMemoryFdPropertiesKHR* memoryFdProperties){
        vkGetMemoryFdPropertiesKHR(handleType,fd,memoryFdProperties);
      }
      
      VkResult createValidationCacheEXT(const VkValidationCacheCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator,ValidationCacheEXT* validationCache){
        vkCreateValidationCacheEXT(createInfo,allocator,validationCache);
      }
      
      VkResult getDeviceGroupPresentCapabilitiesKHX(VkDeviceGroupPresentCapabilitiesKHX* deviceGroupPresentCapabilities){
        vkGetDeviceGroupPresentCapabilitiesKHX(deviceGroupPresentCapabilities);
      }
      
      void destroySwapchainKHR(SwapchainKHR swapchain,const VkAllocationCallbacks* allocator){
        vkDestroySwapchainKHR(swapchain,allocator);
      }
      
      VkResult invalidateMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        vkInvalidateMappedMemoryRanges(memoryRanges);
      }
      
      VkResult getSwapchainCounterEXT(SwapchainKHR swapchain,VkSurfaceCounterFlagBitsEXT counter,uint64_t* counterValue){
        vkGetSwapchainCounterEXT(swapchain,counter,counterValue);
      }
      
      VkResult createSampler(const VkSamplerCreateInfo* createInfo,const VkAllocationCallbacks* allocator,Sampler* sampler){
        vkCreateSampler(createInfo,allocator,sampler);
      }
      
      VkResult createPipelineCache(const VkPipelineCacheCreateInfo* createInfo,const VkAllocationCallbacks* allocator,PipelineCache* pipelineCache){
        vkCreatePipelineCache(createInfo,allocator,pipelineCache);
      }
      
      VkResult getMemoryFdKHR(const VkMemoryGetFdInfoKHR* getFdInfo,int* fd){
        vkGetMemoryFdKHR(getFdInfo,fd);
      }
      
      VkResult debugMarkerSetObjectTagEXT(const VkDebugMarkerObjectTagInfoEXT* tagInfo){
        vkDebugMarkerSetObjectTagEXT(tagInfo);
      }
      
      PFN_vkVoidFunction getDeviceProcAddr(std::string name){
        vkGetDeviceProcAddr(name);
      }
      
      VkResult getMemoryWin32HandleKHR(const VkMemoryGetWin32HandleInfoKHR* getWin32HandleInfo,HANDLE* handle){
        vkGetMemoryWin32HandleKHR(getWin32HandleInfo,handle);
      }
      
      VkResult allocateDescriptorSets(const VkDescriptorSetAllocateInfo* allocateInfo,std::vector<DescriptorSet> descriptorSets){
        vkAllocateDescriptorSets(allocateInfo,descriptorSets);
      }
      
      VkResult allocateMemory(const VkMemoryAllocateInfo* allocateInfo,const VkAllocationCallbacks* allocator,DeviceMemory* memory){
        vkAllocateMemory(allocateInfo,allocator,memory);
      }
      
      void getBufferMemoryRequirements2KHR(const VkBufferMemoryRequirementsInfo2KHR* info,VkMemoryRequirements2KHR* memoryRequirements){
        vkGetBufferMemoryRequirements2KHR(info,memoryRequirements);
      }
      
      VkResult registerDeviceEventEXT(const VkDeviceEventInfoEXT* deviceEventInfo,const VkAllocationCallbacks* allocator,Fence* fence){
        vkRegisterDeviceEventEXT(deviceEventInfo,allocator,fence);
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
        vkDestroyDescriptorUpdateTemplateKHR(allocator);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,PipelineLayout layout,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,layout,set,data);
      }
      
      void updateDescriptorSetWithTemplateKHR(DescriptorSet descriptorSet,const void* data){
        vkUpdateDescriptorSetWithTemplateKHR(descriptorSet,data);
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
        vkCmdUpdateBuffer(dstBuffer,dstOffset,data);
      }
      
      VkResult beginCommandBuffer(const VkCommandBufferBeginInfo* beginInfo){
        vkBeginCommandBuffer(beginInfo);
      }
      
      void cmdSetDiscardRectangleEXT(uint32_t firstDiscardRectangle,std::vector<VkRect2D> discardRectangles){
        vkCmdSetDiscardRectangleEXT(firstDiscardRectangle,discardRectangles);
      }
      
      void cmdSetViewportWScalingNV(uint32_t firstViewport,std::vector<VkViewportWScalingNV> viewportWScalings){
        vkCmdSetViewportWScalingNV(firstViewport,viewportWScalings);
      }
      
      void cmdProcessCommandsNVX(const VkCmdProcessCommandsInfoNVX* processCommandsInfo){
        vkCmdProcessCommandsNVX(processCommandsInfo);
      }
      
      void cmdDispatchBaseKHX(uint32_t baseGroupX,uint32_t baseGroupY,uint32_t baseGroupZ,uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        vkCmdDispatchBaseKHX(baseGroupX,baseGroupY,baseGroupZ,groupCountX,groupCountY,groupCountZ);
      }
      
      void cmdResetEvent(Event event,VkPipelineStageFlags stageMask){
        vkCmdResetEvent(event,stageMask);
      }
      
      void cmdBindVertexBuffers(uint32_t firstBinding,std::vector<Buffer> buffers,std::vector<std::size_t> offsets){
        vkCmdBindVertexBuffers(firstBinding,buffers,offsets);
      }
      
      void cmdDispatch(uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        vkCmdDispatch(groupCountX,groupCountY,groupCountZ);
      }
      
      void cmdNextSubpass(VkSubpassContents contents){
        vkCmdNextSubpass(contents);
      }
      
      void cmdPushDescriptorSetKHR(VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        vkCmdPushDescriptorSetKHR(pipelineBindPoint,layout,set,descriptorWrites);
      }
      
      void cmdSetViewport(uint32_t firstViewport,std::vector<VkViewport> viewports){
        vkCmdSetViewport(firstViewport,viewports);
      }
      
      void cmdCopyQueryPoolResults(QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,Buffer dstBuffer,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        vkCmdCopyQueryPoolResults(queryPool,firstQuery,queryCount,dstBuffer,dstOffset,stride,flags);
      }
      
      void cmdDrawIndexed(uint32_t indexCount,uint32_t instanceCount,uint32_t firstIndex,int32_t vertexOffset,uint32_t firstInstance){
        vkCmdDrawIndexed(indexCount,instanceCount,firstIndex,vertexOffset,firstInstance);
      }
      
      void cmdSetEvent(Event event,VkPipelineStageFlags stageMask){
        vkCmdSetEvent(event,stageMask);
      }
      
      void cmdSetSampleLocationsEXT(const VkSampleLocationsInfoEXT* sampleLocationsInfo){
        vkCmdSetSampleLocationsEXT(sampleLocationsInfo);
      }
      
      void cmdSetScissor(uint32_t firstScissor,std::vector<VkRect2D> scissors){
        vkCmdSetScissor(firstScissor,scissors);
      }
      
      void cmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage,QueryPool queryPool,uint32_t query){
        vkCmdWriteTimestamp(pipelineStage,queryPool,query);
      }
      
      void cmdSetLineWidth(float lineWidth){
        vkCmdSetLineWidth(lineWidth);
      }
      
      void cmdDrawIndirect(Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndirect(buffer,offset,drawCount,stride);
      }
      
      void cmdDebugMarkerEndEXT(){
        vkCmdDebugMarkerEndEXT();
      }
      
      void cmdResolveImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageResolve> regions){
        vkCmdResolveImage(srcImage,srcImageLayout,dstImage,dstImageLayout,regions);
      }
      
      void cmdEndRenderPass(){
        vkCmdEndRenderPass();
      }
      
      void cmdResetQueryPool(QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount){
        vkCmdResetQueryPool(queryPool,firstQuery,queryCount);
      }
      
      void cmdCopyImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        vkCmdCopyImage(srcImage,srcImageLayout,dstImage,dstImageLayout,regions);
      }
      
      void cmdReserveSpaceForCommandsNVX(const VkCmdReserveSpaceForCommandsInfoNVX* reserveSpaceInfo){
        vkCmdReserveSpaceForCommandsNVX(reserveSpaceInfo);
      }
      
      void cmdBlitImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        vkCmdBlitImage(srcImage,srcImageLayout,dstImage,dstImageLayout,regions,filter);
      }
      
      void cmdSetStencilWriteMask(VkStencilFaceFlags faceMask,uint32_t writeMask){
        vkCmdSetStencilWriteMask(faceMask,writeMask);
      }
      
      void cmdExecuteCommands(std::vector<CommandBuffer> commandBuffers){
        vkCmdExecuteCommands(commandBuffers);
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(DescriptorUpdateTemplateKHR descriptorUpdateTemplate,PipelineLayout layout,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(descriptorUpdateTemplate,layout,set,data);
      }
      
      void cmdPipelineBarrier(VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,VkDependencyFlags dependencyFlags,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        vkCmdPipelineBarrier(srcStageMask,dstStageMask,dependencyFlags,memoryBarriers,bufferMemoryBarriers,imageMemoryBarriers);
      }
      
      void cmdWaitEvents(std::vector<Event> events,VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        vkCmdWaitEvents(events,srcStageMask,dstStageMask,memoryBarriers,bufferMemoryBarriers,imageMemoryBarriers);
      }
      
      void cmdDrawIndexedIndirectCountAMD(Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndexedIndirectCountAMD(buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDraw(uint32_t vertexCount,uint32_t instanceCount,uint32_t firstVertex,uint32_t firstInstance){
        vkCmdDraw(vertexCount,instanceCount,firstVertex,firstInstance);
      }
      
      void cmdDrawIndexedIndirect(Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndexedIndirect(buffer,offset,drawCount,stride);
      }
      
      void cmdCopyImageToBuffer(Image srcImage,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(srcImage,srcImageLayout,dstBuffer,regions);
      }
      
      void cmdDebugMarkerInsertEXT(const VkDebugMarkerMarkerInfoEXT* markerInfo){
        vkCmdDebugMarkerInsertEXT(markerInfo);
      }
      
      void cmdSetStencilCompareMask(VkStencilFaceFlags faceMask,uint32_t compareMask){
        vkCmdSetStencilCompareMask(faceMask,compareMask);
      }
      
      void cmdPushConstants(PipelineLayout layout,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        vkCmdPushConstants(layout,stageFlags,offset,values);
      }
      
      void cmdDrawIndirectCountAMD(Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndirectCountAMD(buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDispatchIndirect(Buffer buffer,std::size_t offset){
        vkCmdDispatchIndirect(buffer,offset);
      }
      
      void cmdCopyBufferToImage(Buffer srcBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(srcBuffer,dstImage,dstImageLayout,regions);
      }
      
      void cmdBindPipeline(VkPipelineBindPoint pipelineBindPoint,Pipeline pipeline){
        vkCmdBindPipeline(pipelineBindPoint,pipeline);
      }
      
      void cmdDebugMarkerBeginEXT(const VkDebugMarkerMarkerInfoEXT* markerInfo){
        vkCmdDebugMarkerBeginEXT(markerInfo);
      }
      
      VkResult endCommandBuffer(){
        vkEndCommandBuffer();
      }
      
      VkResult resetCommandBuffer(VkCommandBufferResetFlags flags){
        vkResetCommandBuffer(flags);
      }
      
      void cmdSetStencilReference(VkStencilFaceFlags faceMask,uint32_t reference){
        vkCmdSetStencilReference(faceMask,reference);
      }
      
      void cmdEndQuery(QueryPool queryPool,uint32_t query){
        vkCmdEndQuery(queryPool,query);
      }
      
      void cmdBindIndexBuffer(Buffer buffer,std::size_t offset,VkIndexType indexType){
        vkCmdBindIndexBuffer(buffer,offset,indexType);
      }
      
      void cmdSetDeviceMaskKHX(uint32_t deviceMask){
        vkCmdSetDeviceMaskKHX(deviceMask);
      }
      
      void cmdSetDepthBias(float depthBiasConstantFactor,float depthBiasClamp,float depthBiasSlopeFactor){
        vkCmdSetDepthBias(depthBiasConstantFactor,depthBiasClamp,depthBiasSlopeFactor);
      }
      
      void cmdSetDepthBounds(float minDepthBounds,float maxDepthBounds){
        vkCmdSetDepthBounds(minDepthBounds,maxDepthBounds);
      }
      
      void cmdClearDepthStencilImage(Image image,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearDepthStencilImage(image,imageLayout,depthStencil,ranges);
      }
      
      void cmdClearColorImage(Image image,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearColorImage(image,imageLayout,color,ranges);
      }
      
      void cmdBeginRenderPass(const VkRenderPassBeginInfo* renderPassBegin,VkSubpassContents contents){
        vkCmdBeginRenderPass(renderPassBegin,contents);
      }
      
      void cmdCopyBuffer(Buffer srcBuffer,Buffer dstBuffer,std::vector<VkBufferCopy> regions){
        vkCmdCopyBuffer(srcBuffer,dstBuffer,regions);
      }
      
      void cmdSetBlendConstants(const float blendConstants){
        vkCmdSetBlendConstants(blendConstants);
      }
      
      void cmdFillBuffer(Buffer dstBuffer,std::size_t dstOffset,std::size_t size,uint32_t data){
        vkCmdFillBuffer(dstBuffer,dstOffset,size,data);
      }
      
      void cmdBeginQuery(QueryPool queryPool,uint32_t query,VkQueryControlFlags flags){
        vkCmdBeginQuery(queryPool,query,flags);
      }
      
      void cmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        vkCmdBindDescriptorSets(pipelineBindPoint,layout,firstSet,descriptorSets,dynamicOffsets);
      }
      
      void cmdClearAttachments(std::vector<VkClearAttachment> attachments,std::vector<VkClearRect> rects){
        vkCmdClearAttachments(attachments,rects);
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
        vkGetSwapchainImagesKHR(device,swapchainImages);
      }
      
      VkResult getRefreshCycleDurationGOOGLE(Device device,VkRefreshCycleDurationGOOGLE* displayTimingProperties){
        vkGetRefreshCycleDurationGOOGLE(device,displayTimingProperties);
      }
      
      VkResult getSwapchainStatusKHR(Device device){
        vkGetSwapchainStatusKHR(device);
      }
      
      VkResult acquireNextImageKHR(Device device,uint64_t timeout,Semaphore semaphore,Fence fence,uint32_t* imageIndex){
        vkAcquireNextImageKHR(device,timeout,semaphore,fence,imageIndex);
      }
      
      VkResult getPastPresentationTimingGOOGLE(Device device,std::vector<VkPastPresentationTimingGOOGLE> presentationTimings){
        vkGetPastPresentationTimingGOOGLE(device,presentationTimings);
      }
      
      void destroySwapchainKHR(Device device,const VkAllocationCallbacks* allocator){
        vkDestroySwapchainKHR(device,allocator);
      }
      
      VkResult getSwapchainCounterEXT(Device device,VkSurfaceCounterFlagBitsEXT counter,uint64_t* counterValue){
        vkGetSwapchainCounterEXT(device,counter,counterValue);
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
        vkDestroyDebugReportCallbackEXT(allocator);
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
        vkCmdBindPipeline(commandBuffer,pipelineBindPoint);
      }
      
      void destroyPipeline(const VkAllocationCallbacks* allocator){
        vkDestroyPipeline(allocator);
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
        vkCreateComputePipelines(createInfos,allocator,pipelines);
      }
      
      VkResult createGraphicsPipelines(std::vector<VkGraphicsPipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator,std::vector<Pipeline> pipelines){
        vkCreateGraphicsPipelines(createInfos,allocator,pipelines);
      }
      
      void destroyPipelineCache(const VkAllocationCallbacks* allocator){
        vkDestroyPipelineCache(allocator);
      }
      
      VkResult mergePipelineCaches(std::vector<PipelineCache> srcCaches){
        vkMergePipelineCaches(srcCaches);
      }
      
      VkResult getPipelineCacheData(std::vector<void> data){
        vkGetPipelineCacheData(data);
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
        vkBindBufferMemory(buffer,memoryOffset);
      }
      
      void freeMemory(const VkAllocationCallbacks* allocator){
        vkFreeMemory(allocator);
      }
      
      VkResult mapMemory(std::size_t offset,std::size_t size,VkMemoryMapFlags flags,void** data){
        vkMapMemory(offset,size,flags,data);
      }
      
      void unmapMemory(){
        vkUnmapMemory();
      }
      
      VkResult getMemoryWin32HandleNV(VkExternalMemoryHandleTypeFlagsNV handleType,HANDLE* handle){
        vkGetMemoryWin32HandleNV(handleType,handle);
      }
      
      VkResult bindImageMemory(Image image,std::size_t memoryOffset){
        vkBindImageMemory(image,memoryOffset);
      }
      
      void getDeviceMemoryCommitment(std::size_t* committedMemoryInBytes){
        vkGetDeviceMemoryCommitment(committedMemoryInBytes);
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
        vkCmdUpdateBuffer(commandBuffer,dstOffset,data);
      }
      
      VkResult bindBufferMemory(DeviceMemory memory,std::size_t memoryOffset){
        vkBindBufferMemory(memory,memoryOffset);
      }
      
      void cmdCopyQueryPoolResults(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        vkCmdCopyQueryPoolResults(commandBuffer,queryPool,firstQuery,queryCount,dstOffset,stride,flags);
      }
      
      void cmdDrawIndirect(CommandBuffer commandBuffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndirect(commandBuffer,offset,drawCount,stride);
      }
      
      void cmdDrawIndexedIndirectCountAMD(CommandBuffer commandBuffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndexedIndirectCountAMD(commandBuffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDrawIndexedIndirectCountAMD(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndexedIndirectCountAMD(commandBuffer,buffer,offset,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDrawIndexedIndirect(CommandBuffer commandBuffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        vkCmdDrawIndexedIndirect(commandBuffer,offset,drawCount,stride);
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,srcImage,srcImageLayout,regions);
      }
      
      void destroyBuffer(const VkAllocationCallbacks* allocator){
        vkDestroyBuffer(allocator);
      }
      
      void cmdDrawIndirectCountAMD(CommandBuffer commandBuffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndirectCountAMD(commandBuffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDrawIndirectCountAMD(CommandBuffer commandBuffer,Buffer buffer,std::size_t offset,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndirectCountAMD(commandBuffer,buffer,offset,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDispatchIndirect(CommandBuffer commandBuffer,std::size_t offset){
        vkCmdDispatchIndirect(commandBuffer,offset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,dstImage,dstImageLayout,regions);
      }
      
      void getBufferMemoryRequirements(VkMemoryRequirements* memoryRequirements){
        vkGetBufferMemoryRequirements(memoryRequirements);
      }
      
      void cmdBindIndexBuffer(CommandBuffer commandBuffer,std::size_t offset,VkIndexType indexType){
        vkCmdBindIndexBuffer(commandBuffer,offset,indexType);
      }
      
      void cmdCopyBuffer(CommandBuffer commandBuffer,Buffer dstBuffer,std::vector<VkBufferCopy> regions){
        vkCmdCopyBuffer(commandBuffer,dstBuffer,regions);
      }
      
      void cmdCopyBuffer(CommandBuffer commandBuffer,Buffer srcBuffer,std::vector<VkBufferCopy> regions){
        vkCmdCopyBuffer(commandBuffer,srcBuffer,regions);
      }
      
      void cmdFillBuffer(CommandBuffer commandBuffer,std::size_t dstOffset,std::size_t size,uint32_t data){
        vkCmdFillBuffer(commandBuffer,dstOffset,size,data);
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
        vkDestroyFramebuffer(allocator);
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
        vkDestroyObjectTableNVX(allocator);
      }
      
      VkResult unregisterObjectsNVX(std::vector<VkObjectEntryTypeNVX> objectEntryTypes,std::vector<uint32_t> objectIndices){
        vkUnregisterObjectsNVX(objectEntryTypes,objectIndices);
      }
      
      VkResult registerObjectsNVX(std::vector<VkObjectTableEntryNVX> objectTableEntries,std::vector<uint32_t> objectIndices){
        vkRegisterObjectsNVX(objectTableEntries,objectIndices);
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
        vkDestroyShaderModule(allocator);
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
        vkQueueSubmit(queue,submits);
      }
      
      void destroyFence(const VkAllocationCallbacks* allocator){
        vkDestroyFence(allocator);
      }
      
      VkResult acquireNextImageKHR(SwapchainKHR swapchain,uint64_t timeout,Semaphore semaphore,uint32_t* imageIndex){
        vkAcquireNextImageKHR(swapchain,timeout,semaphore,imageIndex);
      }
      
      VkResult queueBindSparse(Queue queue,std::vector<VkBindSparseInfo> bindInfo){
        vkQueueBindSparse(queue,bindInfo);
      }
      
      VkResult getFenceStatus(){
        vkGetFenceStatus();
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
        vkCmdCopyQueryPoolResults(commandBuffer,firstQuery,queryCount,dstBuffer,dstOffset,stride,flags);
      }
      
      void cmdWriteTimestamp(CommandBuffer commandBuffer,VkPipelineStageFlagBits pipelineStage,uint32_t query){
        vkCmdWriteTimestamp(commandBuffer,pipelineStage,query);
      }
      
      void cmdResetQueryPool(CommandBuffer commandBuffer,uint32_t firstQuery,uint32_t queryCount){
        vkCmdResetQueryPool(commandBuffer,firstQuery,queryCount);
      }
      
      void destroyQueryPool(const VkAllocationCallbacks* allocator){
        vkDestroyQueryPool(allocator);
      }
      
      void cmdEndQuery(CommandBuffer commandBuffer,uint32_t query){
        vkCmdEndQuery(commandBuffer,query);
      }
      
      VkResult getQueryPoolResults(uint32_t firstQuery,uint32_t queryCount,std::vector<void> data,std::size_t stride,VkQueryResultFlags flags){
        vkGetQueryPoolResults(firstQuery,queryCount,data,stride,flags);
      }
      
      void cmdBeginQuery(CommandBuffer commandBuffer,uint32_t query,VkQueryControlFlags flags){
        vkCmdBeginQuery(commandBuffer,query,flags);
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
        vkGetImageSubresourceLayout(subresource,layout);
      }
      
      void cmdResolveImage(CommandBuffer commandBuffer,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageResolve> regions){
        vkCmdResolveImage(commandBuffer,srcImageLayout,dstImage,dstImageLayout,regions);
      }
      
      void cmdResolveImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,VkImageLayout dstImageLayout,std::vector<VkImageResolve> regions){
        vkCmdResolveImage(commandBuffer,srcImage,srcImageLayout,dstImageLayout,regions);
      }
      
      void cmdCopyImage(CommandBuffer commandBuffer,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        vkCmdCopyImage(commandBuffer,srcImageLayout,dstImage,dstImageLayout,regions);
      }
      
      void cmdCopyImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        vkCmdCopyImage(commandBuffer,srcImage,srcImageLayout,dstImageLayout,regions);
      }
      
      void cmdBlitImage(CommandBuffer commandBuffer,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        vkCmdBlitImage(commandBuffer,srcImageLayout,dstImage,dstImageLayout,regions,filter);
      }
      
      void cmdBlitImage(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        vkCmdBlitImage(commandBuffer,srcImage,srcImageLayout,dstImageLayout,regions,filter);
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,srcImageLayout,dstBuffer,regions);
      }
      
      void destroyImage(const VkAllocationCallbacks* allocator){
        vkDestroyImage(allocator);
      }
      
      VkResult bindImageMemory(DeviceMemory memory,std::size_t memoryOffset){
        vkBindImageMemory(memory,memoryOffset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Buffer srcBuffer,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,srcBuffer,dstImageLayout,regions);
      }
      
      void getImageSparseMemoryRequirements(std::vector<VkSparseImageMemoryRequirements> sparseMemoryRequirements){
        vkGetImageSparseMemoryRequirements(sparseMemoryRequirements);
      }
      
      void cmdClearDepthStencilImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearDepthStencilImage(commandBuffer,imageLayout,depthStencil,ranges);
      }
      
      void cmdClearColorImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearColorImage(commandBuffer,imageLayout,color,ranges);
      }
      
      void getImageMemoryRequirements(VkMemoryRequirements* memoryRequirements){
        vkGetImageMemoryRequirements(memoryRequirements);
      }
    private:
      VkImage image;
      Device device;
  }