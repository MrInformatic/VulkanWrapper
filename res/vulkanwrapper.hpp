namespace vk{
  class DescriptorPool{
    public:
      DescriptorPool(VkDescriptorPool descriptorPool_,Device device_)
        : descriptorPool(descriptorPool_),
          device(device_){
      }
      
      VkResult freeDescriptorSets(std::vector<DescriptorSet> descriptorSets){
        return vkFreeDescriptorSets((VkDevice)device,descriptorPool,descriptorSets.size(),descriptorSets.data());
      }
      
      VkResult resetDescriptorPool(VkDescriptorPoolResetFlags flags){
        return vkResetDescriptorPool((VkDevice)device,descriptorPool,flags);
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
      
      uint32_t* acquireNextImageKHR(SwapchainKHR swapchain,uint64_t timeout,Fence fence){
        uint32_t* imageIndex;
        vkAcquireNextImageKHR((VkDevice)device,swapchain,timeout,semaphore,fence,imageIndex);
        
        return imageIndex;
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
      
      std::vector<void> getValidationCacheDataEXT(){
        size_t* dataSize;
        vkGetValidationCacheDataEXT((VkDevice)device,validationCacheEXT,dataSize,null);
        
        std::vector<void> data(dataSize);
        vkGetValidationCacheDataEXT((VkDevice)device,validationCacheEXT,dataSize,data.data());
        
        return data;
      }
      
      VkResult mergeValidationCachesEXT(std::vector<ValidationCacheEXT> srcCaches){
        return vkMergeValidationCachesEXT((VkDevice)device,validationCacheEXT,srcCaches.size(),srcCaches.data());
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
      
      VkExtent2D* getRenderAreaGranularity(){
        VkExtent2D* granularity;
        vkGetRenderAreaGranularity((VkDevice)device,renderPass,granularity);
        
        return granularity;
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
      
      VkDisplayPlaneCapabilitiesKHR* getDisplayPlaneCapabilitiesKHR(uint32_t planeIndex){
        VkDisplayPlaneCapabilitiesKHR* capabilities;
        vkGetDisplayPlaneCapabilitiesKHR((VkPhysicalDevice)physicalDevice,displayModeKHR,planeIndex,capabilities);
        
        return capabilities;
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
        return vkQueueWaitIdle(queue);
      }
      
      VkResult queueSubmit(std::vector<VkSubmitInfo> submits,Fence fence){
        return vkQueueSubmit(queue,submits.size(),submits.data(),fence);
      }
      
      VkResult queueBindSparse(std::vector<VkBindSparseInfo> bindInfo,Fence fence){
        return vkQueueBindSparse(queue,bindInfo.size(),bindInfo.data(),fence);
      }
      
      VkResult queuePresentKHR(const VkPresentInfoKHR* presentInfo){
        return vkQueuePresentKHR(queue,presentInfo);
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
        return vkResetCommandPool((VkDevice)device,commandPool,flags);
      }
      
      void destroyCommandPool(const VkAllocationCallbacks* allocator){
        vkDestroyCommandPool((VkDevice)device,commandPool,allocator);
      }
      
      void freeCommandBuffers(std::vector<CommandBuffer> commandBuffers){
        vkFreeCommandBuffers((VkDevice)device,commandPool,commandBuffers.size(),commandBuffers.data());
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
      
      std::vector<VkRect2D> getPhysicalDevicePresentRectanglesKHX(PhysicalDevice physicalDevice){
        uint32_t* rectCount;
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surfaceKHR,rectCount,null);
        
        std::vector<VkRect2D> rects(rectCount);
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surfaceKHR,rectCount,rects.data());
        
        return rects;
      }
      
      void destroySurfaceKHR(const VkAllocationCallbacks* allocator){
        vkDestroySurfaceKHR((VkInstance)instance,surfaceKHR,allocator);
      }
      
      std::vector<VkPresentModeKHR> getPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice physicalDevice){
        uint32_t* presentModeCount;
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surfaceKHR,presentModeCount,null);
        
        std::vector<VkPresentModeKHR> presentModes(presentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surfaceKHR,presentModeCount,presentModes.data());
        
        return presentModes;
      }
      
      VkDeviceGroupPresentModeFlagsKHX* getDeviceGroupSurfacePresentModesKHX(Device device){
        VkDeviceGroupPresentModeFlagsKHX* modes;
        vkGetDeviceGroupSurfacePresentModesKHX(device,surfaceKHR,modes);
        
        return modes;
      }
      
      VkSurfaceCapabilities2EXT* getPhysicalDeviceSurfaceCapabilities2EXT(PhysicalDevice physicalDevice){
        VkSurfaceCapabilities2EXT* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surfaceKHR,surfaceCapabilities);
        
        return surfaceCapabilities;
      }
      
      bool* getPhysicalDeviceSurfaceSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex){
        bool* supported;
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,surfaceKHR,supported);
        
        return supported;
      }
      
      std::vector<VkSurfaceFormatKHR> getPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice physicalDevice){
        uint32_t* surfaceFormatCount;
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surfaceKHR,surfaceFormatCount,null);
        
        std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surfaceKHR,surfaceFormatCount,surfaceFormats.data());
        
        return surfaceFormats;
      }
      
      VkSurfaceCapabilitiesKHR* getPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice physicalDevice){
        VkSurfaceCapabilitiesKHR* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surfaceKHR,surfaceCapabilities);
        
        return surfaceCapabilities;
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
        return vkResetEvent((VkDevice)device,event);
      }
      
      VkResult setEvent(){
        return vkSetEvent((VkDevice)device,event);
      }
      
      VkResult getEventStatus(){
        return vkGetEventStatus((VkDevice)device,event);
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
        vkCmdPushDescriptorSetKHR(commandBuffer,pipelineBindPoint,pipelineLayout,set,descriptorWrites.size(),descriptorWrites.data());
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplate,pipelineLayout,set,data);
      }
      
      void cmdPushConstants(CommandBuffer commandBuffer,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        vkCmdPushConstants(commandBuffer,pipelineLayout,stageFlags,offset,values.size(),values.data());
      }
      
      void cmdBindDescriptorSets(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        vkCmdBindDescriptorSets(commandBuffer,pipelineBindPoint,pipelineLayout,firstSet,descriptorSets.size(),descriptorSets.data(),dynamicOffsets.size(),dynamicOffsets.data());
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
      
      SurfaceKHR* createXlibSurfaceKHR(const VkXlibSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateXlibSurfaceKHR(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      SurfaceKHR* createWin32SurfaceKHR(const VkWin32SurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateWin32SurfaceKHR(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      PFN_vkVoidFunction getInstanceProcAddr(std::string name){
        return vkGetInstanceProcAddr(instance,name);
      }
      
      SurfaceKHR* createWaylandSurfaceKHR(const VkWaylandSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateWaylandSurfaceKHR(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      SurfaceKHR* createIOSSurfaceMVK(const VkIOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateIOSSurfaceMVK(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      SurfaceKHR* createAndroidSurfaceKHR(const VkAndroidSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateAndroidSurfaceKHR(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      DebugReportCallbackEXT* createDebugReportCallbackEXT(const VkDebugReportCallbackCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator){
        DebugReportCallbackEXT* callback;
        vkCreateDebugReportCallbackEXT(instance,createInfo,allocator,callback);
        
        return callback;
      }
      
      SurfaceKHR* createViSurfaceNN(const VkViSurfaceCreateInfoNN* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateViSurfaceNN(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      std::vector<PhysicalDevice> enumeratePhysicalDevices(){
        uint32_t* physicalDeviceCount;
        vkEnumeratePhysicalDevices(instance,physicalDeviceCount,null);
        
        std::vector<PhysicalDevice> physicalDevices(physicalDeviceCount);
        vkEnumeratePhysicalDevices(instance,physicalDeviceCount,physicalDevices.data());
        
        return physicalDevices;
      }
      
      SurfaceKHR* createMacOSSurfaceMVK(const VkMacOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateMacOSSurfaceMVK(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      SurfaceKHR* createXcbSurfaceKHR(const VkXcbSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateXcbSurfaceKHR(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      void destroyInstance(const VkAllocationCallbacks* allocator){
        vkDestroyInstance(instance,allocator);
      }
      
      void debugReportMessageEXT(VkDebugReportFlagsEXT flags,VkDebugReportObjectTypeEXT objectType,uint64_t object,size_t location,int32_t messageCode,std::string layerPrefix,std::string message){
        vkDebugReportMessageEXT(instance,flags,objectType,object,location,messageCode,layerPrefix,message);
      }
      
      std::vector<VkPhysicalDeviceGroupPropertiesKHX> enumeratePhysicalDeviceGroupsKHX(){
        uint32_t* physicalDeviceGroupCount;
        vkEnumeratePhysicalDeviceGroupsKHX(instance,physicalDeviceGroupCount,null);
        
        std::vector<VkPhysicalDeviceGroupPropertiesKHX> physicalDeviceGroupProperties(physicalDeviceGroupCount);
        vkEnumeratePhysicalDeviceGroupsKHX(instance,physicalDeviceGroupCount,physicalDeviceGroupProperties.data());
        
        return physicalDeviceGroupProperties;
      }
      
      SurfaceKHR* createMirSurfaceKHR(const VkMirSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateMirSurfaceKHR(instance,createInfo,allocator,surface);
        
        return surface;
      }
      
      SurfaceKHR* createDisplayPlaneSurfaceKHR(const VkDisplaySurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateDisplayPlaneSurfaceKHR(instance,createInfo,allocator,surface);
        
        return surface;
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
      
      std::vector<VkQueueFamilyProperties> getPhysicalDeviceQueueFamilyProperties(){
        uint32_t* queueFamilyPropertyCount;
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice,queueFamilyPropertyCount,null);
        
        std::vector<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyPropertyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice,queueFamilyPropertyCount,queueFamilyProperties.data());
        
        return queueFamilyProperties;
      }
      
      std::vector<VkSparseImageFormatProperties2KHR> getPhysicalDeviceSparseImageFormatProperties2KHR(const VkPhysicalDeviceSparseImageFormatInfo2KHR* formatInfo){
        uint32_t* propertyCount;
        vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice,formatInfo,propertyCount,null);
        
        std::vector<VkSparseImageFormatProperties2KHR> properties(propertyCount);
        vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice,formatInfo,propertyCount,properties.data());
        
        return properties;
      }
      
      VkDeviceGeneratedCommandsLimitsNVX* getPhysicalDeviceGeneratedCommandsPropertiesNVX(){
        VkDeviceGeneratedCommandsFeaturesNVX* features;
        vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice,features,null);
        
        VkDeviceGeneratedCommandsLimitsNVX* limits;
        vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice,features,limits);
        
        return limits;
      }
      
      std::vector<VkSurfaceFormat2KHR> getPhysicalDeviceSurfaceFormats2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo){
        uint32_t* surfaceFormatCount;
        vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice,surfaceInfo,surfaceFormatCount,null);
        
        std::vector<VkSurfaceFormat2KHR> surfaceFormats(surfaceFormatCount);
        vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice,surfaceInfo,surfaceFormatCount,surfaceFormats.data());
        
        return surfaceFormats;
      }
      
      std::vector<VkRect2D> getPhysicalDevicePresentRectanglesKHX(SurfaceKHR surface){
        uint32_t* rectCount;
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surface,rectCount,null);
        
        std::vector<VkRect2D> rects(rectCount);
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surface,rectCount,rects.data());
        
        return rects;
      }
      
      VkBool32 getPhysicalDeviceWaylandPresentationSupportKHR(uint32_t queueFamilyIndex,struct wl_display* display){
        return vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice,queueFamilyIndex,display);
      }
      
      Device* createDevice(const VkDeviceCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Device* device;
        vkCreateDevice(physicalDevice,createInfo,allocator,device);
        
        return device;
      }
      
      DisplayModeKHR* createDisplayModeKHR(DisplayKHR display,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        DisplayModeKHR* mode;
        vkCreateDisplayModeKHR(physicalDevice,display,createInfo,allocator,mode);
        
        return mode;
      }
      
      std::vector<VkLayerProperties> enumerateDeviceLayerProperties(){
        uint32_t* propertyCount;
        vkEnumerateDeviceLayerProperties(physicalDevice,propertyCount,null);
        
        std::vector<VkLayerProperties> properties(propertyCount);
        vkEnumerateDeviceLayerProperties(physicalDevice,propertyCount,properties.data());
        
        return properties;
      }
      
      VkPhysicalDeviceFeatures* getPhysicalDeviceFeatures(){
        VkPhysicalDeviceFeatures* features;
        vkGetPhysicalDeviceFeatures(physicalDevice,features);
        
        return features;
      }
      
      std::vector<VkQueueFamilyProperties2KHR> getPhysicalDeviceQueueFamilyProperties2KHR(){
        uint32_t* queueFamilyPropertyCount;
        vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice,queueFamilyPropertyCount,null);
        
        std::vector<VkQueueFamilyProperties2KHR> queueFamilyProperties(queueFamilyPropertyCount);
        vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice,queueFamilyPropertyCount,queueFamilyProperties.data());
        
        return queueFamilyProperties;
      }
      
      VkExternalSemaphorePropertiesKHR* getPhysicalDeviceExternalSemaphorePropertiesKHR(const VkPhysicalDeviceExternalSemaphoreInfoKHR* externalSemaphoreInfo){
        VkExternalSemaphorePropertiesKHR* externalSemaphoreProperties;
        vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice,externalSemaphoreInfo,externalSemaphoreProperties);
        
        return externalSemaphoreProperties;
      }
      
      VkPhysicalDeviceFeatures2KHR* getPhysicalDeviceFeatures2KHR(){
        VkPhysicalDeviceFeatures2KHR* features;
        vkGetPhysicalDeviceFeatures2KHR(physicalDevice,features);
        
        return features;
      }
      
      VkMultisamplePropertiesEXT* getPhysicalDeviceMultisamplePropertiesEXT(VkSampleCountFlagBits samples){
        VkMultisamplePropertiesEXT* multisampleProperties;
        vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice,samples,multisampleProperties);
        
        return multisampleProperties;
      }
      
      VkPhysicalDeviceMemoryProperties* getPhysicalDeviceMemoryProperties(){
        VkPhysicalDeviceMemoryProperties* memoryProperties;
        vkGetPhysicalDeviceMemoryProperties(physicalDevice,memoryProperties);
        
        return memoryProperties;
      }
      
      std::vector<VkDisplayModePropertiesKHR> getDisplayModePropertiesKHR(DisplayKHR display){
        uint32_t* propertyCount;
        vkGetDisplayModePropertiesKHR(physicalDevice,display,propertyCount,null);
        
        std::vector<VkDisplayModePropertiesKHR> properties(propertyCount);
        vkGetDisplayModePropertiesKHR(physicalDevice,display,propertyCount,properties.data());
        
        return properties;
      }
      
      std::vector<VkPresentModeKHR> getPhysicalDeviceSurfacePresentModesKHR(SurfaceKHR surface){
        uint32_t* presentModeCount;
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surface,presentModeCount,null);
        
        std::vector<VkPresentModeKHR> presentModes(presentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surface,presentModeCount,presentModes.data());
        
        return presentModes;
      }
      
      Display* acquireXlibDisplayEXT(DisplayKHR display){
        Display* dpy;
        vkAcquireXlibDisplayEXT(physicalDevice,dpy,display);
        
        return dpy;
      }
      
      VkPhysicalDeviceProperties2KHR* getPhysicalDeviceProperties2KHR(){
        VkPhysicalDeviceProperties2KHR* properties;
        vkGetPhysicalDeviceProperties2KHR(physicalDevice,properties);
        
        return properties;
      }
      
      std::vector<DisplayKHR> getDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex){
        uint32_t* displayCount;
        vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice,planeIndex,displayCount,null);
        
        std::vector<DisplayKHR> displays(displayCount);
        vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice,planeIndex,displayCount,displays.data());
        
        return displays;
      }
      
      VkPhysicalDeviceMemoryProperties2KHR* getPhysicalDeviceMemoryProperties2KHR(){
        VkPhysicalDeviceMemoryProperties2KHR* memoryProperties;
        vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice,memoryProperties);
        
        return memoryProperties;
      }
      
      xcb_connection_t* getPhysicalDeviceXcbPresentationSupportKHR(uint32_t queueFamilyIndex,xcb_visualid_t visual_id){
        xcb_connection_t* connection;
        vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice,queueFamilyIndex,connection,visual_id);
        
        return connection;
      }
      
      DisplayKHR* getRandROutputDisplayEXT(RROutput rrOutput){
        Display* dpy;
        vkGetRandROutputDisplayEXT(physicalDevice,dpy,rrOutput,null);
        
        DisplayKHR* display;
        vkGetRandROutputDisplayEXT(physicalDevice,dpy,rrOutput,display);
        
        return display;
      }
      
      VkFormatProperties* getPhysicalDeviceFormatProperties(VkFormat format){
        VkFormatProperties* formatProperties;
        vkGetPhysicalDeviceFormatProperties(physicalDevice,format,formatProperties);
        
        return formatProperties;
      }
      
      VkSurfaceCapabilities2EXT* getPhysicalDeviceSurfaceCapabilities2EXT(SurfaceKHR surface){
        VkSurfaceCapabilities2EXT* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surface,surfaceCapabilities);
        
        return surfaceCapabilities;
      }
      
      bool* getPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex,SurfaceKHR surface){
        bool* supported;
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,surface,supported);
        
        return supported;
      }
      
      VkImageFormatProperties2KHR* getPhysicalDeviceImageFormatProperties2KHR(const VkPhysicalDeviceImageFormatInfo2KHR* imageFormatInfo){
        VkImageFormatProperties2KHR* imageFormatProperties;
        vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice,imageFormatInfo,imageFormatProperties);
        
        return imageFormatProperties;
      }
      
      VkBool32 getPhysicalDeviceWin32PresentationSupportKHR(uint32_t queueFamilyIndex){
        return vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice,queueFamilyIndex);
      }
      
      Display* getPhysicalDeviceXlibPresentationSupportKHR(uint32_t queueFamilyIndex,VisualID visualID){
        Display* dpy;
        vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice,queueFamilyIndex,dpy,visualID);
        
        return dpy;
      }
      
      VkImageFormatProperties* getPhysicalDeviceImageFormatProperties(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags){
        VkImageFormatProperties* imageFormatProperties;
        vkGetPhysicalDeviceImageFormatProperties(physicalDevice,format,type,tiling,usage,flags,imageFormatProperties);
        
        return imageFormatProperties;
      }
      
      std::vector<VkExtensionProperties> enumerateDeviceExtensionProperties(std::string layerName){
        uint32_t* propertyCount;
        vkEnumerateDeviceExtensionProperties(physicalDevice,layerName,propertyCount,null);
        
        std::vector<VkExtensionProperties> properties(propertyCount);
        vkEnumerateDeviceExtensionProperties(physicalDevice,layerName,propertyCount,properties.data());
        
        return properties;
      }
      
      VkExternalFencePropertiesKHR* getPhysicalDeviceExternalFencePropertiesKHR(const VkPhysicalDeviceExternalFenceInfoKHR* externalFenceInfo){
        VkExternalFencePropertiesKHR* externalFenceProperties;
        vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice,externalFenceInfo,externalFenceProperties);
        
        return externalFenceProperties;
      }
      
      VkSurfaceCapabilities2KHR* getPhysicalDeviceSurfaceCapabilities2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo){
        VkSurfaceCapabilities2KHR* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice,surfaceInfo,surfaceCapabilities);
        
        return surfaceCapabilities;
      }
      
      VkExternalImageFormatPropertiesNV* getPhysicalDeviceExternalImageFormatPropertiesNV(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkExternalMemoryHandleTypeFlagsNV externalHandleType){
        VkExternalImageFormatPropertiesNV* externalImageFormatProperties;
        vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice,format,type,tiling,usage,flags,externalHandleType,externalImageFormatProperties);
        
        return externalImageFormatProperties;
      }
      
      VkExternalBufferPropertiesKHR* getPhysicalDeviceExternalBufferPropertiesKHR(const VkPhysicalDeviceExternalBufferInfoKHR* externalBufferInfo){
        VkExternalBufferPropertiesKHR* externalBufferProperties;
        vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice,externalBufferInfo,externalBufferProperties);
        
        return externalBufferProperties;
      }
      
      std::vector<VkDisplayPlanePropertiesKHR> getPhysicalDeviceDisplayPlanePropertiesKHR(){
        uint32_t* propertyCount;
        vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice,propertyCount,null);
        
        std::vector<VkDisplayPlanePropertiesKHR> properties(propertyCount);
        vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice,propertyCount,properties.data());
        
        return properties;
      }
      
      std::vector<VkDisplayPropertiesKHR> getPhysicalDeviceDisplayPropertiesKHR(){
        uint32_t* propertyCount;
        vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice,propertyCount,null);
        
        std::vector<VkDisplayPropertiesKHR> properties(propertyCount);
        vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice,propertyCount,properties.data());
        
        return properties;
      }
      
      std::vector<VkSparseImageFormatProperties> getPhysicalDeviceSparseImageFormatProperties(VkFormat format,VkImageType type,VkSampleCountFlagBits samples,VkImageUsageFlags usage,VkImageTiling tiling){
        uint32_t* propertyCount;
        vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice,format,type,samples,usage,tiling,propertyCount,null);
        
        std::vector<VkSparseImageFormatProperties> properties(propertyCount);
        vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice,format,type,samples,usage,tiling,propertyCount,properties.data());
        
        return properties;
      }
      
      VkPhysicalDeviceProperties* getPhysicalDeviceProperties(){
        VkPhysicalDeviceProperties* properties;
        vkGetPhysicalDeviceProperties(physicalDevice,properties);
        
        return properties;
      }
      
      std::vector<VkSurfaceFormatKHR> getPhysicalDeviceSurfaceFormatsKHR(SurfaceKHR surface){
        uint32_t* surfaceFormatCount;
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surface,surfaceFormatCount,null);
        
        std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surface,surfaceFormatCount,surfaceFormats.data());
        
        return surfaceFormats;
      }
      
      VkSurfaceCapabilitiesKHR* getPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHR surface){
        VkSurfaceCapabilitiesKHR* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surface,surfaceCapabilities);
        
        return surfaceCapabilities;
      }
      
      MirConnection* getPhysicalDeviceMirPresentationSupportKHR(uint32_t queueFamilyIndex){
        MirConnection* connection;
        vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice,queueFamilyIndex,connection);
        
        return connection;
      }
      
      VkResult releaseDisplayEXT(DisplayKHR display){
        return vkReleaseDisplayEXT(physicalDevice,display);
      }
      
      VkFormatProperties2KHR* getPhysicalDeviceFormatProperties2KHR(VkFormat format){
        VkFormatProperties2KHR* formatProperties;
        vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice,format,formatProperties);
        
        return formatProperties;
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
      
      DisplayModeKHR* createDisplayModeKHR(PhysicalDevice physicalDevice,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        DisplayModeKHR* mode;
        vkCreateDisplayModeKHR(physicalDevice,displayKHR,createInfo,allocator,mode);
        
        return mode;
      }
      
      VkResult displayPowerControlEXT(Device device,const VkDisplayPowerInfoEXT* displayPowerInfo){
        return vkDisplayPowerControlEXT(device,displayKHR,displayPowerInfo);
      }
      
      std::vector<VkDisplayModePropertiesKHR> getDisplayModePropertiesKHR(PhysicalDevice physicalDevice){
        uint32_t* propertyCount;
        vkGetDisplayModePropertiesKHR(physicalDevice,displayKHR,propertyCount,null);
        
        std::vector<VkDisplayModePropertiesKHR> properties(propertyCount);
        vkGetDisplayModePropertiesKHR(physicalDevice,displayKHR,propertyCount,properties.data());
        
        return properties;
      }
      
      Display* acquireXlibDisplayEXT(PhysicalDevice physicalDevice){
        Display* dpy;
        vkAcquireXlibDisplayEXT(physicalDevice,dpy,displayKHR);
        
        return dpy;
      }
      
      Fence* registerDisplayEventEXT(Device device,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator){
        Fence* fence;
        vkRegisterDisplayEventEXT(device,displayKHR,displayEventInfo,allocator,fence);
        
        return fence;
      }
      
      VkResult releaseDisplayEXT(PhysicalDevice physicalDevice){
        return vkReleaseDisplayEXT(physicalDevice,displayKHR);
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
        vkSetHdrMetadataEXT(device,metadata.size(),swapchains.data(),metadata.data());
      }
      
      SamplerYcbcrConversionKHR* createSamplerYcbcrConversionKHR(const VkSamplerYcbcrConversionCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SamplerYcbcrConversionKHR* ycbcrConversion;
        vkCreateSamplerYcbcrConversionKHR(device,createInfo,allocator,ycbcrConversion);
        
        return ycbcrConversion;
      }
      
      void updateDescriptorSets(std::vector<VkWriteDescriptorSet> descriptorWrites,std::vector<VkCopyDescriptorSet> descriptorCopies){
        vkUpdateDescriptorSets(device,descriptorWrites.size(),descriptorWrites.data(),descriptorCopies.size(),descriptorCopies.data());
      }
      
      std::vector<Image> getSwapchainImagesKHR(SwapchainKHR swapchain){
        uint32_t* swapchainImageCount;
        vkGetSwapchainImagesKHR(device,swapchain,swapchainImageCount,null);
        
        std::vector<Image> swapchainImages(swapchainImageCount);
        vkGetSwapchainImagesKHR(device,swapchain,swapchainImageCount,swapchainImages.data());
        
        return swapchainImages;
      }
      
      VkResult importFenceWin32HandleKHR(const VkImportFenceWin32HandleInfoKHR* importFenceWin32HandleInfo){
        return vkImportFenceWin32HandleKHR(device,importFenceWin32HandleInfo);
      }
      
      VkResult debugMarkerSetObjectNameEXT(const VkDebugMarkerObjectNameInfoEXT* nameInfo){
        return vkDebugMarkerSetObjectNameEXT(device,nameInfo);
      }
      
      VkRefreshCycleDurationGOOGLE* getRefreshCycleDurationGOOGLE(SwapchainKHR swapchain){
        VkRefreshCycleDurationGOOGLE* displayTimingProperties;
        vkGetRefreshCycleDurationGOOGLE(device,swapchain,displayTimingProperties);
        
        return displayTimingProperties;
      }
      
      VkResult bindImageMemory2KHR(std::vector<VkBindImageMemoryInfoKHR> bindInfos){
        return vkBindImageMemory2KHR(device,bindInfos.size(),bindInfos.data());
      }
      
      VkResult bindBufferMemory2KHR(std::vector<VkBindBufferMemoryInfoKHR> bindInfos){
        return vkBindBufferMemory2KHR(device,bindInfos.size(),bindInfos.data());
      }
      
      VkResult importSemaphoreWin32HandleKHR(const VkImportSemaphoreWin32HandleInfoKHR* importSemaphoreWin32HandleInfo){
        return vkImportSemaphoreWin32HandleKHR(device,importSemaphoreWin32HandleInfo);
      }
      
      int* getSemaphoreFdKHR(const VkSemaphoreGetFdInfoKHR* getFdInfo){
        int* fd;
        vkGetSemaphoreFdKHR(device,getFdInfo,fd);
        
        return fd;
      }
      
      VkMemoryWin32HandlePropertiesKHR* getMemoryWin32HandlePropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,HANDLE handle){
        VkMemoryWin32HandlePropertiesKHR* memoryWin32HandleProperties;
        vkGetMemoryWin32HandlePropertiesKHR(device,handleType,handle,memoryWin32HandleProperties);
        
        return memoryWin32HandleProperties;
      }
      
      DescriptorUpdateTemplateKHR* createDescriptorUpdateTemplateKHR(const VkDescriptorUpdateTemplateCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        DescriptorUpdateTemplateKHR* descriptorUpdateTemplate;
        vkCreateDescriptorUpdateTemplateKHR(device,createInfo,allocator,descriptorUpdateTemplate);
        
        return descriptorUpdateTemplate;
      }
      
      VkResult flushMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        return vkFlushMappedMemoryRanges(device,memoryRanges.size(),memoryRanges.data());
      }
      
      DescriptorPool* createDescriptorPool(const VkDescriptorPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        DescriptorPool* descriptorPool;
        vkCreateDescriptorPool(device,createInfo,allocator,descriptorPool);
        
        return descriptorPool;
      }
      
      VkResult resetFences(std::vector<Fence> fences){
        return vkResetFences(device,fences.size(),fences.data());
      }
      
      std::vector<VkSparseImageMemoryRequirements2KHR> getImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2KHR* info){
        uint32_t* sparseMemoryRequirementCount;
        vkGetImageSparseMemoryRequirements2KHR(device,info,sparseMemoryRequirementCount,null);
        
        std::vector<VkSparseImageMemoryRequirements2KHR> sparseMemoryRequirements(sparseMemoryRequirementCount);
        vkGetImageSparseMemoryRequirements2KHR(device,info,sparseMemoryRequirementCount,sparseMemoryRequirements.data());
        
        return sparseMemoryRequirements;
      }
      
      Image* createImage(const VkImageCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Image* image;
        vkCreateImage(device,createInfo,allocator,image);
        
        return image;
      }
      
      ShaderModule* createShaderModule(const VkShaderModuleCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        ShaderModule* shaderModule;
        vkCreateShaderModule(device,createInfo,allocator,shaderModule);
        
        return shaderModule;
      }
      
      uint32_t* acquireNextImage2KHX(const VkAcquireNextImageInfoKHX* acquireInfo){
        uint32_t* imageIndex;
        vkAcquireNextImage2KHX(device,acquireInfo,imageIndex);
        
        return imageIndex;
      }
      
      void destroyDevice(const VkAllocationCallbacks* allocator){
        vkDestroyDevice(device,allocator);
      }
      
      VkResult getSwapchainStatusKHR(SwapchainKHR swapchain){
        return vkGetSwapchainStatusKHR(device,swapchain);
      }
      
      Buffer* createBuffer(const VkBufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Buffer* buffer;
        vkCreateBuffer(device,createInfo,allocator,buffer);
        
        return buffer;
      }
      
      VkResult importSemaphoreFdKHR(const VkImportSemaphoreFdInfoKHR* importSemaphoreFdInfo){
        return vkImportSemaphoreFdKHR(device,importSemaphoreFdInfo);
      }
      
      Event* createEvent(const VkEventCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Event* event;
        vkCreateEvent(device,createInfo,allocator,event);
        
        return event;
      }
      
      VkResult displayPowerControlEXT(DisplayKHR display,const VkDisplayPowerInfoEXT* displayPowerInfo){
        return vkDisplayPowerControlEXT(device,display,displayPowerInfo);
      }
      
      IndirectCommandsLayoutNVX* createIndirectCommandsLayoutNVX(const VkIndirectCommandsLayoutCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator){
        IndirectCommandsLayoutNVX* indirectCommandsLayout;
        vkCreateIndirectCommandsLayoutNVX(device,createInfo,allocator,indirectCommandsLayout);
        
        return indirectCommandsLayout;
      }
      
      std::vector<VkPastPresentationTimingGOOGLE> getPastPresentationTimingGOOGLE(SwapchainKHR swapchain){
        uint32_t* presentationTimingCount;
        vkGetPastPresentationTimingGOOGLE(device,swapchain,presentationTimingCount,null);
        
        std::vector<VkPastPresentationTimingGOOGLE> presentationTimings(presentationTimingCount);
        vkGetPastPresentationTimingGOOGLE(device,swapchain,presentationTimingCount,presentationTimings.data());
        
        return presentationTimings;
      }
      
      Fence* createFence(const VkFenceCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Fence* fence;
        vkCreateFence(device,createInfo,allocator,fence);
        
        return fence;
      }
      
      ImageView* createImageView(const VkImageViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        ImageView* view;
        vkCreateImageView(device,createInfo,allocator,view);
        
        return view;
      }
      
      VkDeviceGroupPresentModeFlagsKHX* getDeviceGroupSurfacePresentModesKHX(SurfaceKHR surface){
        VkDeviceGroupPresentModeFlagsKHX* modes;
        vkGetDeviceGroupSurfacePresentModesKHX(device,surface,modes);
        
        return modes;
      }
      
      DescriptorSetLayout* createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        DescriptorSetLayout* setLayout;
        vkCreateDescriptorSetLayout(device,createInfo,allocator,setLayout);
        
        return setLayout;
      }
      
      QueryPool* createQueryPool(const VkQueryPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        QueryPool* queryPool;
        vkCreateQueryPool(device,createInfo,allocator,queryPool);
        
        return queryPool;
      }
      
      RenderPass* createRenderPass(const VkRenderPassCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        RenderPass* renderPass;
        vkCreateRenderPass(device,createInfo,allocator,renderPass);
        
        return renderPass;
      }
      
      VkResult deviceWaitIdle(){
        return vkDeviceWaitIdle(device);
      }
      
      std::vector<CommandBuffer> allocateCommandBuffers(const VkCommandBufferAllocateInfo* allocateInfo){
        std::vector<CommandBuffer> commandBuffers;
        vkAllocateCommandBuffers(device,allocateInfo,commandBuffers);
        
        return commandBuffers;
      }
      
      Queue* getDeviceQueue(uint32_t queueFamilyIndex,uint32_t queueIndex){
        Queue* queue;
        vkGetDeviceQueue(device,queueFamilyIndex,queueIndex,queue);
        
        return queue;
      }
      
      Fence* registerDisplayEventEXT(DisplayKHR display,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator){
        Fence* fence;
        vkRegisterDisplayEventEXT(device,display,displayEventInfo,allocator,fence);
        
        return fence;
      }
      
      PipelineLayout* createPipelineLayout(const VkPipelineLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        PipelineLayout* pipelineLayout;
        vkCreatePipelineLayout(device,createInfo,allocator,pipelineLayout);
        
        return pipelineLayout;
      }
      
      Framebuffer* createFramebuffer(const VkFramebufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Framebuffer* framebuffer;
        vkCreateFramebuffer(device,createInfo,allocator,framebuffer);
        
        return framebuffer;
      }
      
      int* getFenceFdKHR(const VkFenceGetFdInfoKHR* getFdInfo){
        int* fd;
        vkGetFenceFdKHR(device,getFdInfo,fd);
        
        return fd;
      }
      
      VkPeerMemoryFeatureFlagsKHX* getDeviceGroupPeerMemoryFeaturesKHX(uint32_t heapIndex,uint32_t localDeviceIndex,uint32_t remoteDeviceIndex){
        VkPeerMemoryFeatureFlagsKHX* peerMemoryFeatures;
        vkGetDeviceGroupPeerMemoryFeaturesKHX(device,heapIndex,localDeviceIndex,remoteDeviceIndex,peerMemoryFeatures);
        
        return peerMemoryFeatures;
      }
      
      VkMemoryRequirements2KHR* getImageMemoryRequirements2KHR(const VkImageMemoryRequirementsInfo2KHR* info){
        VkMemoryRequirements2KHR* memoryRequirements;
        vkGetImageMemoryRequirements2KHR(device,info,memoryRequirements);
        
        return memoryRequirements;
      }
      
      BufferView* createBufferView(const VkBufferViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        BufferView* view;
        vkCreateBufferView(device,createInfo,allocator,view);
        
        return view;
      }
      
      Semaphore* createSemaphore(const VkSemaphoreCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Semaphore* semaphore;
        vkCreateSemaphore(device,createInfo,allocator,semaphore);
        
        return semaphore;
      }
      
      ObjectTableNVX* createObjectTableNVX(const VkObjectTableCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator){
        ObjectTableNVX* objectTable;
        vkCreateObjectTableNVX(device,createInfo,allocator,objectTable);
        
        return objectTable;
      }
      
      VkResult importFenceFdKHR(const VkImportFenceFdInfoKHR* importFenceFdInfo){
        return vkImportFenceFdKHR(device,importFenceFdInfo);
      }
      
      std::vector<SwapchainKHR> createSharedSwapchainsKHR(std::vector<VkSwapchainCreateInfoKHR> createInfos,const VkAllocationCallbacks* allocator){
        uint32_t swapchainCount;
        vkCreateSharedSwapchainsKHR(device,swapchainCount,createInfos.data(),allocator,null);
        
        std::vector<SwapchainKHR> swapchains(swapchainCount);
        vkCreateSharedSwapchainsKHR(device,swapchainCount,createInfos.data(),allocator,swapchains.data());
        
        return swapchains;
      }
      
      CommandPool* createCommandPool(const VkCommandPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        CommandPool* commandPool;
        vkCreateCommandPool(device,createInfo,allocator,commandPool);
        
        return commandPool;
      }
      
      HANDLE* getSemaphoreWin32HandleKHR(const VkSemaphoreGetWin32HandleInfoKHR* getWin32HandleInfo){
        HANDLE* handle;
        vkGetSemaphoreWin32HandleKHR(device,getWin32HandleInfo,handle);
        
        return handle;
      }
      
      HANDLE* getFenceWin32HandleKHR(const VkFenceGetWin32HandleInfoKHR* getWin32HandleInfo){
        HANDLE* handle;
        vkGetFenceWin32HandleKHR(device,getWin32HandleInfo,handle);
        
        return handle;
      }
      
      VkResult waitForFences(std::vector<Fence> fences,bool waitAll,uint64_t timeout){
        return vkWaitForFences(device,fences.size(),fences.data(),waitAll,timeout);
      }
      
      SwapchainKHR* createSwapchainKHR(const VkSwapchainCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SwapchainKHR* swapchain;
        vkCreateSwapchainKHR(device,createInfo,allocator,swapchain);
        
        return swapchain;
      }
      
      VkMemoryFdPropertiesKHR* getMemoryFdPropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,int fd){
        VkMemoryFdPropertiesKHR* memoryFdProperties;
        vkGetMemoryFdPropertiesKHR(device,handleType,fd,memoryFdProperties);
        
        return memoryFdProperties;
      }
      
      ValidationCacheEXT* createValidationCacheEXT(const VkValidationCacheCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator){
        ValidationCacheEXT* validationCache;
        vkCreateValidationCacheEXT(device,createInfo,allocator,validationCache);
        
        return validationCache;
      }
      
      VkDeviceGroupPresentCapabilitiesKHX* getDeviceGroupPresentCapabilitiesKHX(){
        VkDeviceGroupPresentCapabilitiesKHX* deviceGroupPresentCapabilities;
        vkGetDeviceGroupPresentCapabilitiesKHX(device,deviceGroupPresentCapabilities);
        
        return deviceGroupPresentCapabilities;
      }
      
      void destroySwapchainKHR(SwapchainKHR swapchain,const VkAllocationCallbacks* allocator){
        vkDestroySwapchainKHR(device,swapchain,allocator);
      }
      
      VkResult invalidateMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        return vkInvalidateMappedMemoryRanges(device,memoryRanges.size(),memoryRanges.data());
      }
      
      uint64_t* getSwapchainCounterEXT(SwapchainKHR swapchain,VkSurfaceCounterFlagBitsEXT counter){
        uint64_t* counterValue;
        vkGetSwapchainCounterEXT(device,swapchain,counter,counterValue);
        
        return counterValue;
      }
      
      Sampler* createSampler(const VkSamplerCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Sampler* sampler;
        vkCreateSampler(device,createInfo,allocator,sampler);
        
        return sampler;
      }
      
      PipelineCache* createPipelineCache(const VkPipelineCacheCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        PipelineCache* pipelineCache;
        vkCreatePipelineCache(device,createInfo,allocator,pipelineCache);
        
        return pipelineCache;
      }
      
      int* getMemoryFdKHR(const VkMemoryGetFdInfoKHR* getFdInfo){
        int* fd;
        vkGetMemoryFdKHR(device,getFdInfo,fd);
        
        return fd;
      }
      
      VkResult debugMarkerSetObjectTagEXT(const VkDebugMarkerObjectTagInfoEXT* tagInfo){
        return vkDebugMarkerSetObjectTagEXT(device,tagInfo);
      }
      
      PFN_vkVoidFunction getDeviceProcAddr(std::string name){
        return vkGetDeviceProcAddr(device,name);
      }
      
      HANDLE* getMemoryWin32HandleKHR(const VkMemoryGetWin32HandleInfoKHR* getWin32HandleInfo){
        HANDLE* handle;
        vkGetMemoryWin32HandleKHR(device,getWin32HandleInfo,handle);
        
        return handle;
      }
      
      std::vector<DescriptorSet> allocateDescriptorSets(const VkDescriptorSetAllocateInfo* allocateInfo){
        std::vector<DescriptorSet> descriptorSets;
        vkAllocateDescriptorSets(device,allocateInfo,descriptorSets);
        
        return descriptorSets;
      }
      
      DeviceMemory* allocateMemory(const VkMemoryAllocateInfo* allocateInfo,const VkAllocationCallbacks* allocator){
        DeviceMemory* memory;
        vkAllocateMemory(device,allocateInfo,allocator,memory);
        
        return memory;
      }
      
      VkMemoryRequirements2KHR* getBufferMemoryRequirements2KHR(const VkBufferMemoryRequirementsInfo2KHR* info){
        VkMemoryRequirements2KHR* memoryRequirements;
        vkGetBufferMemoryRequirements2KHR(device,info,memoryRequirements);
        
        return memoryRequirements;
      }
      
      Fence* registerDeviceEventEXT(const VkDeviceEventInfoEXT* deviceEventInfo,const VkAllocationCallbacks* allocator){
        Fence* fence;
        vkRegisterDeviceEventEXT(device,deviceEventInfo,allocator,fence);
        
        return fence;
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
        vkCmdUpdateBuffer(commandBuffer,dstBuffer,dstOffset,data.size(),data.data());
      }
      
      VkResult beginCommandBuffer(const VkCommandBufferBeginInfo* beginInfo){
        return vkBeginCommandBuffer(commandBuffer,beginInfo);
      }
      
      void cmdSetDiscardRectangleEXT(uint32_t firstDiscardRectangle,std::vector<VkRect2D> discardRectangles){
        vkCmdSetDiscardRectangleEXT(commandBuffer,firstDiscardRectangle,discardRectangles.size(),discardRectangles.data());
      }
      
      void cmdSetViewportWScalingNV(uint32_t firstViewport,std::vector<VkViewportWScalingNV> viewportWScalings){
        vkCmdSetViewportWScalingNV(commandBuffer,firstViewport,viewportWScalings.size(),viewportWScalings.data());
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
        vkCmdBindVertexBuffers(commandBuffer,firstBinding,offsets.size(),buffers.data(),offsets.data());
      }
      
      void cmdDispatch(uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        vkCmdDispatch(commandBuffer,groupCountX,groupCountY,groupCountZ);
      }
      
      void cmdNextSubpass(VkSubpassContents contents){
        vkCmdNextSubpass(commandBuffer,contents);
      }
      
      void cmdPushDescriptorSetKHR(VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        vkCmdPushDescriptorSetKHR(commandBuffer,pipelineBindPoint,layout,set,descriptorWrites.size(),descriptorWrites.data());
      }
      
      void cmdSetViewport(uint32_t firstViewport,std::vector<VkViewport> viewports){
        vkCmdSetViewport(commandBuffer,firstViewport,viewports.size(),viewports.data());
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
        vkCmdSetScissor(commandBuffer,firstScissor,scissors.size(),scissors.data());
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
        vkCmdResolveImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regions.size(),regions.data());
      }
      
      void cmdEndRenderPass(){
        vkCmdEndRenderPass(commandBuffer);
      }
      
      void cmdResetQueryPool(QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount){
        vkCmdResetQueryPool(commandBuffer,queryPool,firstQuery,queryCount);
      }
      
      void cmdCopyImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        vkCmdCopyImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regions.size(),regions.data());
      }
      
      void cmdReserveSpaceForCommandsNVX(const VkCmdReserveSpaceForCommandsInfoNVX* reserveSpaceInfo){
        vkCmdReserveSpaceForCommandsNVX(commandBuffer,reserveSpaceInfo);
      }
      
      void cmdBlitImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        vkCmdBlitImage(commandBuffer,srcImage,srcImageLayout,dstImage,dstImageLayout,regions.size(),regions.data(),filter);
      }
      
      void cmdSetStencilWriteMask(VkStencilFaceFlags faceMask,uint32_t writeMask){
        vkCmdSetStencilWriteMask(commandBuffer,faceMask,writeMask);
      }
      
      void cmdExecuteCommands(std::vector<CommandBuffer> commandBuffers){
        vkCmdExecuteCommands(commandBuffer,commandBuffers.size(),commandBuffers.data());
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(DescriptorUpdateTemplateKHR descriptorUpdateTemplate,PipelineLayout layout,uint32_t set,const void* data){
        vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer,descriptorUpdateTemplate,layout,set,data);
      }
      
      void cmdPipelineBarrier(VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,VkDependencyFlags dependencyFlags,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        vkCmdPipelineBarrier(commandBuffer,srcStageMask,dstStageMask,dependencyFlags,memoryBarriers.size(),memoryBarriers.data(),bufferMemoryBarriers.size(),bufferMemoryBarriers.data(),imageMemoryBarriers.size(),imageMemoryBarriers.data());
      }
      
      void cmdWaitEvents(std::vector<Event> events,VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        vkCmdWaitEvents(commandBuffer,events.size(),events.data(),srcStageMask,dstStageMask,memoryBarriers.size(),memoryBarriers.data(),bufferMemoryBarriers.size(),bufferMemoryBarriers.data(),imageMemoryBarriers.size(),imageMemoryBarriers.data());
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
        vkCmdCopyImageToBuffer(commandBuffer,srcImage,srcImageLayout,dstBuffer,regions.size(),regions.data());
      }
      
      void cmdDebugMarkerInsertEXT(const VkDebugMarkerMarkerInfoEXT* markerInfo){
        vkCmdDebugMarkerInsertEXT(commandBuffer,markerInfo);
      }
      
      void cmdSetStencilCompareMask(VkStencilFaceFlags faceMask,uint32_t compareMask){
        vkCmdSetStencilCompareMask(commandBuffer,faceMask,compareMask);
      }
      
      void cmdPushConstants(PipelineLayout layout,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        vkCmdPushConstants(commandBuffer,layout,stageFlags,offset,values.size(),values.data());
      }
      
      void cmdDrawIndirectCountAMD(Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        vkCmdDrawIndirectCountAMD(commandBuffer,buffer,offset,countBuffer,countBufferOffset,maxDrawCount,stride);
      }
      
      void cmdDispatchIndirect(Buffer buffer,std::size_t offset){
        vkCmdDispatchIndirect(commandBuffer,buffer,offset);
      }
      
      void cmdCopyBufferToImage(Buffer srcBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,srcBuffer,dstImage,dstImageLayout,regions.size(),regions.data());
      }
      
      void cmdBindPipeline(VkPipelineBindPoint pipelineBindPoint,Pipeline pipeline){
        vkCmdBindPipeline(commandBuffer,pipelineBindPoint,pipeline);
      }
      
      void cmdDebugMarkerBeginEXT(const VkDebugMarkerMarkerInfoEXT* markerInfo){
        vkCmdDebugMarkerBeginEXT(commandBuffer,markerInfo);
      }
      
      VkResult endCommandBuffer(){
        return vkEndCommandBuffer(commandBuffer);
      }
      
      VkResult resetCommandBuffer(VkCommandBufferResetFlags flags){
        return vkResetCommandBuffer(commandBuffer,flags);
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
        vkCmdClearDepthStencilImage(commandBuffer,image,imageLayout,depthStencil,ranges.size(),ranges.data());
      }
      
      void cmdClearColorImage(Image image,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearColorImage(commandBuffer,image,imageLayout,color,ranges.size(),ranges.data());
      }
      
      void cmdBeginRenderPass(const VkRenderPassBeginInfo* renderPassBegin,VkSubpassContents contents){
        vkCmdBeginRenderPass(commandBuffer,renderPassBegin,contents);
      }
      
      void cmdCopyBuffer(Buffer srcBuffer,Buffer dstBuffer,std::vector<VkBufferCopy> regions){
        vkCmdCopyBuffer(commandBuffer,srcBuffer,dstBuffer,regions.size(),regions.data());
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
        vkCmdBindDescriptorSets(commandBuffer,pipelineBindPoint,layout,firstSet,descriptorSets.size(),descriptorSets.data(),dynamicOffsets.size(),dynamicOffsets.data());
      }
      
      void cmdClearAttachments(std::vector<VkClearAttachment> attachments,std::vector<VkClearRect> rects){
        vkCmdClearAttachments(commandBuffer,attachments.size(),attachments.data(),rects.size(),rects.data());
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
      
      std::vector<Image> getSwapchainImagesKHR(Device device){
        uint32_t* swapchainImageCount;
        vkGetSwapchainImagesKHR(device,swapchainKHR,swapchainImageCount,null);
        
        std::vector<Image> swapchainImages(swapchainImageCount);
        vkGetSwapchainImagesKHR(device,swapchainKHR,swapchainImageCount,swapchainImages.data());
        
        return swapchainImages;
      }
      
      VkRefreshCycleDurationGOOGLE* getRefreshCycleDurationGOOGLE(Device device){
        VkRefreshCycleDurationGOOGLE* displayTimingProperties;
        vkGetRefreshCycleDurationGOOGLE(device,swapchainKHR,displayTimingProperties);
        
        return displayTimingProperties;
      }
      
      VkResult getSwapchainStatusKHR(Device device){
        return vkGetSwapchainStatusKHR(device,swapchainKHR);
      }
      
      uint32_t* acquireNextImageKHR(Device device,uint64_t timeout,Semaphore semaphore,Fence fence){
        uint32_t* imageIndex;
        vkAcquireNextImageKHR(device,swapchainKHR,timeout,semaphore,fence,imageIndex);
        
        return imageIndex;
      }
      
      std::vector<VkPastPresentationTimingGOOGLE> getPastPresentationTimingGOOGLE(Device device){
        uint32_t* presentationTimingCount;
        vkGetPastPresentationTimingGOOGLE(device,swapchainKHR,presentationTimingCount,null);
        
        std::vector<VkPastPresentationTimingGOOGLE> presentationTimings(presentationTimingCount);
        vkGetPastPresentationTimingGOOGLE(device,swapchainKHR,presentationTimingCount,presentationTimings.data());
        
        return presentationTimings;
      }
      
      void destroySwapchainKHR(Device device,const VkAllocationCallbacks* allocator){
        vkDestroySwapchainKHR(device,swapchainKHR,allocator);
      }
      
      uint64_t* getSwapchainCounterEXT(Device device,VkSurfaceCounterFlagBitsEXT counter){
        uint64_t* counterValue;
        vkGetSwapchainCounterEXT(device,swapchainKHR,counter,counterValue);
        
        return counterValue;
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
      
      std::vector<Pipeline> createComputePipelines(std::vector<VkComputePipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator){
        uint32_t createInfoCount;
        vkCreateComputePipelines((VkDevice)device,pipelineCache,createInfoCount,createInfos.data(),allocator,null);
        
        std::vector<Pipeline> pipelines(createInfoCount);
        vkCreateComputePipelines((VkDevice)device,pipelineCache,createInfoCount,createInfos.data(),allocator,pipelines.data());
        
        return pipelines;
      }
      
      std::vector<Pipeline> createGraphicsPipelines(std::vector<VkGraphicsPipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator){
        uint32_t createInfoCount;
        vkCreateGraphicsPipelines((VkDevice)device,pipelineCache,createInfoCount,createInfos.data(),allocator,null);
        
        std::vector<Pipeline> pipelines(createInfoCount);
        vkCreateGraphicsPipelines((VkDevice)device,pipelineCache,createInfoCount,createInfos.data(),allocator,pipelines.data());
        
        return pipelines;
      }
      
      void destroyPipelineCache(const VkAllocationCallbacks* allocator){
        vkDestroyPipelineCache((VkDevice)device,pipelineCache,allocator);
      }
      
      VkResult mergePipelineCaches(std::vector<PipelineCache> srcCaches){
        return vkMergePipelineCaches((VkDevice)device,pipelineCache,srcCaches.size(),srcCaches.data());
      }
      
      std::vector<void> getPipelineCacheData(){
        size_t* dataSize;
        vkGetPipelineCacheData((VkDevice)device,pipelineCache,dataSize,null);
        
        std::vector<void> data(dataSize);
        vkGetPipelineCacheData((VkDevice)device,pipelineCache,dataSize,data.data());
        
        return data;
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
        return vkBindBufferMemory((VkDevice)device,buffer,deviceMemory,memoryOffset);
      }
      
      void freeMemory(const VkAllocationCallbacks* allocator){
        vkFreeMemory((VkDevice)device,deviceMemory,allocator);
      }
      
      void** mapMemory(std::size_t offset,std::size_t size,VkMemoryMapFlags flags){
        void** data;
        vkMapMemory((VkDevice)device,deviceMemory,offset,size,flags,data);
        
        return data;
      }
      
      void unmapMemory(){
        vkUnmapMemory((VkDevice)device,deviceMemory);
      }
      
      HANDLE* getMemoryWin32HandleNV(VkExternalMemoryHandleTypeFlagsNV handleType){
        HANDLE* handle;
        vkGetMemoryWin32HandleNV((VkDevice)device,deviceMemory,handleType,handle);
        
        return handle;
      }
      
      VkResult bindImageMemory(Image image,std::size_t memoryOffset){
        return vkBindImageMemory((VkDevice)device,image,deviceMemory,memoryOffset);
      }
      
      std::size_t* getDeviceMemoryCommitment(){
        std::size_t* committedMemoryInBytes;
        vkGetDeviceMemoryCommitment((VkDevice)device,deviceMemory,committedMemoryInBytes);
        
        return committedMemoryInBytes;
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
        vkCmdUpdateBuffer(commandBuffer,buffer,dstOffset,data.size(),data.data());
      }
      
      VkResult bindBufferMemory(DeviceMemory memory,std::size_t memoryOffset){
        return vkBindBufferMemory((VkDevice)device,buffer,memory,memoryOffset);
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
        vkCmdCopyImageToBuffer(commandBuffer,srcImage,srcImageLayout,buffer,regions.size(),regions.data());
      }
      
      void destroyBuffer(const VkAllocationCallbacks* allocator){
        vkDestroyBuffer((VkDevice)device,buffer,allocator);
      }
      
      void cmdDispatchIndirect(CommandBuffer commandBuffer,std::size_t offset){
        vkCmdDispatchIndirect(commandBuffer,buffer,offset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,buffer,dstImage,dstImageLayout,regions.size(),regions.data());
      }
      
      VkMemoryRequirements* getBufferMemoryRequirements(){
        VkMemoryRequirements* memoryRequirements;
        vkGetBufferMemoryRequirements((VkDevice)device,buffer,memoryRequirements);
        
        return memoryRequirements;
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
        return vkUnregisterObjectsNVX((VkDevice)device,objectTableNVX,objectIndices.size(),objectEntryTypes.data(),objectIndices.data());
      }
      
      VkResult registerObjectsNVX(std::vector<VkObjectTableEntryNVX> objectTableEntries,std::vector<uint32_t> objectIndices){
        return vkRegisterObjectsNVX((VkDevice)device,objectTableNVX,objectIndices.size(),objectTableEntries.data(),objectIndices.data());
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
        return vkQueueSubmit(queue,submits.size(),submits.data(),fence);
      }
      
      void destroyFence(const VkAllocationCallbacks* allocator){
        vkDestroyFence((VkDevice)device,fence,allocator);
      }
      
      uint32_t* acquireNextImageKHR(SwapchainKHR swapchain,uint64_t timeout,Semaphore semaphore){
        uint32_t* imageIndex;
        vkAcquireNextImageKHR((VkDevice)device,swapchain,timeout,semaphore,fence,imageIndex);
        
        return imageIndex;
      }
      
      VkResult queueBindSparse(Queue queue,std::vector<VkBindSparseInfo> bindInfo){
        return vkQueueBindSparse(queue,bindInfo.size(),bindInfo.data(),fence);
      }
      
      VkResult getFenceStatus(){
        return vkGetFenceStatus((VkDevice)device,fence);
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
      
      std::vector<void> getQueryPoolResults(uint32_t firstQuery,uint32_t queryCount,std::size_t stride,VkQueryResultFlags flags){
        size_t dataSize;
        vkGetQueryPoolResults((VkDevice)device,queryPool,firstQuery,queryCount,dataSize,null,stride,flags);
        
        std::vector<void> data(dataSize);
        vkGetQueryPoolResults((VkDevice)device,queryPool,firstQuery,queryCount,dataSize,data.data(),stride,flags);
        
        return data;
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
      
      VkSubresourceLayout* getImageSubresourceLayout(const VkImageSubresource* subresource){
        VkSubresourceLayout* layout;
        vkGetImageSubresourceLayout((VkDevice)device,image,subresource,layout);
        
        return layout;
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyImageToBuffer(commandBuffer,image,srcImageLayout,dstBuffer,regions.size(),regions.data());
      }
      
      void destroyImage(const VkAllocationCallbacks* allocator){
        vkDestroyImage((VkDevice)device,image,allocator);
      }
      
      VkResult bindImageMemory(DeviceMemory memory,std::size_t memoryOffset){
        return vkBindImageMemory((VkDevice)device,image,memory,memoryOffset);
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Buffer srcBuffer,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        vkCmdCopyBufferToImage(commandBuffer,srcBuffer,image,dstImageLayout,regions.size(),regions.data());
      }
      
      std::vector<VkSparseImageMemoryRequirements> getImageSparseMemoryRequirements(){
        uint32_t* sparseMemoryRequirementCount;
        vkGetImageSparseMemoryRequirements((VkDevice)device,image,sparseMemoryRequirementCount,null);
        
        std::vector<VkSparseImageMemoryRequirements> sparseMemoryRequirements(sparseMemoryRequirementCount);
        vkGetImageSparseMemoryRequirements((VkDevice)device,image,sparseMemoryRequirementCount,sparseMemoryRequirements.data());
        
        return sparseMemoryRequirements;
      }
      
      void cmdClearDepthStencilImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearDepthStencilImage(commandBuffer,image,imageLayout,depthStencil,ranges.size(),ranges.data());
      }
      
      void cmdClearColorImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        vkCmdClearColorImage(commandBuffer,image,imageLayout,color,ranges.size(),ranges.data());
      }
      
      VkMemoryRequirements* getImageMemoryRequirements(){
        VkMemoryRequirements* memoryRequirements;
        vkGetImageMemoryRequirements((VkDevice)device,image,memoryRequirements);
        
        return memoryRequirements;
      }
    private:
      VkImage image;
      Device device;
  }