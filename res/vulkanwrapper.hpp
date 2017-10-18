namespace vk{
  class DescriptorPool{
    public:
      DescriptorPool(VkDescriptorPool descriptorPool_,Device device_)
        : descriptorPool(descriptorPool_),
          device(device_){
      }
      
      VkResult freeDescriptorSets(std::vector<DescriptorSet> descriptorSets){
        
      }
      
      VkResult resetDescriptorPool(VkDescriptorPoolResetFlags flags){
        
      }
      
      void destroyDescriptorPool(const VkAllocationCallbacks* allocator){
        
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
      }
      
      void destroySemaphore(const VkAllocationCallbacks* allocator){
        
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
      }
      
      VkResult mergeValidationCachesEXT(std::vector<ValidationCacheEXT> srcCaches){
        
      }
      
      void destroyValidationCacheEXT(const VkAllocationCallbacks* allocator){
        
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
        
      }
      
      VkExtent2D* getRenderAreaGranularity(){
        VkExtent2D* granularity;
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
      
      VkDisplayPlaneCapabilitiesKHR* getDisplayPlaneCapabilitiesKHR(uint32_t planeIndex){
        VkDisplayPlaneCapabilitiesKHR* capabilities;
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
        
      }
      
      VkResult queueSubmit(std::vector<VkSubmitInfo> submits,Fence fence){
        
      }
      
      VkResult queueBindSparse(std::vector<VkBindSparseInfo> bindInfo,Fence fence){
        
      }
      
      VkResult queuePresentKHR(const VkPresentInfoKHR* presentInfo){
        
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
        
      }
      
      VkResult resetCommandPool(VkCommandPoolResetFlags flags){
        
      }
      
      void destroyCommandPool(const VkAllocationCallbacks* allocator){
        
      }
      
      void freeCommandBuffers(std::vector<CommandBuffer> commandBuffers){
        
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
      }
      
      void destroySurfaceKHR(const VkAllocationCallbacks* allocator){
        
      }
      
      std::vector<VkPresentModeKHR> getPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice physicalDevice){
        uint32_t* presentModeCount;
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surfaceKHR,presentModeCount,null);
        
        std::vector<VkPresentModeKHR> presentModes(presentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surfaceKHR,presentModeCount,presentModes.data());
      }
      
      VkDeviceGroupPresentModeFlagsKHX* getDeviceGroupSurfacePresentModesKHX(Device device){
        VkDeviceGroupPresentModeFlagsKHX* modes;
        vkGetDeviceGroupSurfacePresentModesKHX(device,surfaceKHR,modes);
      }
      
      VkSurfaceCapabilities2EXT* getPhysicalDeviceSurfaceCapabilities2EXT(PhysicalDevice physicalDevice){
        VkSurfaceCapabilities2EXT* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surfaceKHR,surfaceCapabilities);
      }
      
      bool* getPhysicalDeviceSurfaceSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex){
        bool* supported;
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,surfaceKHR,supported);
      }
      
      std::vector<VkSurfaceFormatKHR> getPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice physicalDevice){
        uint32_t* surfaceFormatCount;
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surfaceKHR,surfaceFormatCount,null);
        
        std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surfaceKHR,surfaceFormatCount,surfaceFormats.data());
      }
      
      VkSurfaceCapabilitiesKHR* getPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice physicalDevice){
        VkSurfaceCapabilitiesKHR* surfaceCapabilities;
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
        
      }
      
      void destroyEvent(const VkAllocationCallbacks* allocator){
        
      }
      
      void cmdSetEvent(CommandBuffer commandBuffer,VkPipelineStageFlags stageMask){
        
      }
      
      VkResult resetEvent(){
        
      }
      
      VkResult setEvent(){
        
      }
      
      VkResult getEventStatus(){
        
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
        
      }
      
      void cmdPushDescriptorSetKHR(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,DescriptorUpdateTemplateKHR descriptorUpdateTemplate,uint32_t set,const void* data){
        
      }
      
      void cmdPushConstants(CommandBuffer commandBuffer,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        
      }
      
      void cmdBindDescriptorSets(CommandBuffer commandBuffer,VkPipelineBindPoint pipelineBindPoint,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        
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
      }
      
      SurfaceKHR* createWin32SurfaceKHR(const VkWin32SurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateWin32SurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      PFN_vkVoidFunction getInstanceProcAddr(std::string name){
        
      }
      
      SurfaceKHR* createWaylandSurfaceKHR(const VkWaylandSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateWaylandSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      SurfaceKHR* createIOSSurfaceMVK(const VkIOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateIOSSurfaceMVK(instance,createInfo,allocator,surface);
      }
      
      SurfaceKHR* createAndroidSurfaceKHR(const VkAndroidSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateAndroidSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      DebugReportCallbackEXT* createDebugReportCallbackEXT(const VkDebugReportCallbackCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator){
        DebugReportCallbackEXT* callback;
        vkCreateDebugReportCallbackEXT(instance,createInfo,allocator,callback);
      }
      
      SurfaceKHR* createViSurfaceNN(const VkViSurfaceCreateInfoNN* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateViSurfaceNN(instance,createInfo,allocator,surface);
      }
      
      std::vector<PhysicalDevice> enumeratePhysicalDevices(){
        uint32_t* physicalDeviceCount;
        vkEnumeratePhysicalDevices(instance,physicalDeviceCount,null);
        
        std::vector<PhysicalDevice> physicalDevices(physicalDeviceCount);
        vkEnumeratePhysicalDevices(instance,physicalDeviceCount,physicalDevices.data());
      }
      
      SurfaceKHR* createMacOSSurfaceMVK(const VkMacOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateMacOSSurfaceMVK(instance,createInfo,allocator,surface);
      }
      
      SurfaceKHR* createXcbSurfaceKHR(const VkXcbSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateXcbSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      void destroyInstance(const VkAllocationCallbacks* allocator){
        
      }
      
      void debugReportMessageEXT(VkDebugReportFlagsEXT flags,VkDebugReportObjectTypeEXT objectType,uint64_t object,size_t location,int32_t messageCode,std::string layerPrefix,std::string message){
        
      }
      
      std::vector<VkPhysicalDeviceGroupPropertiesKHX> enumeratePhysicalDeviceGroupsKHX(){
        uint32_t* physicalDeviceGroupCount;
        vkEnumeratePhysicalDeviceGroupsKHX(instance,physicalDeviceGroupCount,null);
        
        std::vector<VkPhysicalDeviceGroupPropertiesKHX> physicalDeviceGroupProperties(physicalDeviceGroupCount);
        vkEnumeratePhysicalDeviceGroupsKHX(instance,physicalDeviceGroupCount,physicalDeviceGroupProperties.data());
      }
      
      SurfaceKHR* createMirSurfaceKHR(const VkMirSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
        vkCreateMirSurfaceKHR(instance,createInfo,allocator,surface);
      }
      
      SurfaceKHR* createDisplayPlaneSurfaceKHR(const VkDisplaySurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SurfaceKHR* surface;
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
      
      std::vector<VkQueueFamilyProperties> getPhysicalDeviceQueueFamilyProperties(){
        uint32_t* queueFamilyPropertyCount;
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice,queueFamilyPropertyCount,null);
        
        std::vector<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyPropertyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice,queueFamilyPropertyCount,queueFamilyProperties.data());
      }
      
      std::vector<VkSparseImageFormatProperties2KHR> getPhysicalDeviceSparseImageFormatProperties2KHR(const VkPhysicalDeviceSparseImageFormatInfo2KHR* formatInfo){
        uint32_t* propertyCount;
        vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice,formatInfo,propertyCount,null);
        
        std::vector<VkSparseImageFormatProperties2KHR> properties(propertyCount);
        vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice,formatInfo,propertyCount,properties.data());
      }
      
      VkDeviceGeneratedCommandsLimitsNVX* getPhysicalDeviceGeneratedCommandsPropertiesNVX(){
        VkDeviceGeneratedCommandsFeaturesNVX* features;
        vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice,features,null);
        
        VkDeviceGeneratedCommandsLimitsNVX* limits;
        vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice,features,limits);
      }
      
      std::vector<VkSurfaceFormat2KHR> getPhysicalDeviceSurfaceFormats2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo){
        uint32_t* surfaceFormatCount;
        vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice,surfaceInfo,surfaceFormatCount,null);
        
        std::vector<VkSurfaceFormat2KHR> surfaceFormats(surfaceFormatCount);
        vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice,surfaceInfo,surfaceFormatCount,surfaceFormats.data());
      }
      
      std::vector<VkRect2D> getPhysicalDevicePresentRectanglesKHX(SurfaceKHR surface){
        uint32_t* rectCount;
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surface,rectCount,null);
        
        std::vector<VkRect2D> rects(rectCount);
        vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice,surface,rectCount,rects.data());
      }
      
      VkBool32 getPhysicalDeviceWaylandPresentationSupportKHR(uint32_t queueFamilyIndex,struct wl_display* display){
        
      }
      
      Device* createDevice(const VkDeviceCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Device* device;
        vkCreateDevice(physicalDevice,createInfo,allocator,device);
      }
      
      DisplayModeKHR* createDisplayModeKHR(DisplayKHR display,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        DisplayModeKHR* mode;
        vkCreateDisplayModeKHR(physicalDevice,display,createInfo,allocator,mode);
      }
      
      std::vector<VkLayerProperties> enumerateDeviceLayerProperties(){
        uint32_t* propertyCount;
        vkEnumerateDeviceLayerProperties(physicalDevice,propertyCount,null);
        
        std::vector<VkLayerProperties> properties(propertyCount);
        vkEnumerateDeviceLayerProperties(physicalDevice,propertyCount,properties.data());
      }
      
      VkPhysicalDeviceFeatures* getPhysicalDeviceFeatures(){
        VkPhysicalDeviceFeatures* features;
        vkGetPhysicalDeviceFeatures(physicalDevice,features);
      }
      
      std::vector<VkQueueFamilyProperties2KHR> getPhysicalDeviceQueueFamilyProperties2KHR(){
        uint32_t* queueFamilyPropertyCount;
        vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice,queueFamilyPropertyCount,null);
        
        std::vector<VkQueueFamilyProperties2KHR> queueFamilyProperties(queueFamilyPropertyCount);
        vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice,queueFamilyPropertyCount,queueFamilyProperties.data());
      }
      
      VkExternalSemaphorePropertiesKHR* getPhysicalDeviceExternalSemaphorePropertiesKHR(const VkPhysicalDeviceExternalSemaphoreInfoKHR* externalSemaphoreInfo){
        VkExternalSemaphorePropertiesKHR* externalSemaphoreProperties;
        vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice,externalSemaphoreInfo,externalSemaphoreProperties);
      }
      
      VkPhysicalDeviceFeatures2KHR* getPhysicalDeviceFeatures2KHR(){
        VkPhysicalDeviceFeatures2KHR* features;
        vkGetPhysicalDeviceFeatures2KHR(physicalDevice,features);
      }
      
      VkMultisamplePropertiesEXT* getPhysicalDeviceMultisamplePropertiesEXT(VkSampleCountFlagBits samples){
        VkMultisamplePropertiesEXT* multisampleProperties;
        vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice,samples,multisampleProperties);
      }
      
      VkPhysicalDeviceMemoryProperties* getPhysicalDeviceMemoryProperties(){
        VkPhysicalDeviceMemoryProperties* memoryProperties;
        vkGetPhysicalDeviceMemoryProperties(physicalDevice,memoryProperties);
      }
      
      std::vector<VkDisplayModePropertiesKHR> getDisplayModePropertiesKHR(DisplayKHR display){
        uint32_t* propertyCount;
        vkGetDisplayModePropertiesKHR(physicalDevice,display,propertyCount,null);
        
        std::vector<VkDisplayModePropertiesKHR> properties(propertyCount);
        vkGetDisplayModePropertiesKHR(physicalDevice,display,propertyCount,properties.data());
      }
      
      std::vector<VkPresentModeKHR> getPhysicalDeviceSurfacePresentModesKHR(SurfaceKHR surface){
        uint32_t* presentModeCount;
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surface,presentModeCount,null);
        
        std::vector<VkPresentModeKHR> presentModes(presentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,surface,presentModeCount,presentModes.data());
      }
      
      Display* acquireXlibDisplayEXT(DisplayKHR display){
        Display* dpy;
        vkAcquireXlibDisplayEXT(physicalDevice,dpy,display);
      }
      
      VkPhysicalDeviceProperties2KHR* getPhysicalDeviceProperties2KHR(){
        VkPhysicalDeviceProperties2KHR* properties;
        vkGetPhysicalDeviceProperties2KHR(physicalDevice,properties);
      }
      
      std::vector<DisplayKHR> getDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex){
        uint32_t* displayCount;
        vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice,planeIndex,displayCount,null);
        
        std::vector<DisplayKHR> displays(displayCount);
        vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice,planeIndex,displayCount,displays.data());
      }
      
      VkPhysicalDeviceMemoryProperties2KHR* getPhysicalDeviceMemoryProperties2KHR(){
        VkPhysicalDeviceMemoryProperties2KHR* memoryProperties;
        vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice,memoryProperties);
      }
      
      xcb_connection_t* getPhysicalDeviceXcbPresentationSupportKHR(uint32_t queueFamilyIndex,xcb_visualid_t visual_id){
        xcb_connection_t* connection;
        vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice,queueFamilyIndex,connection,visual_id);
      }
      
      DisplayKHR* getRandROutputDisplayEXT(RROutput rrOutput){
        Display* dpy;
        vkGetRandROutputDisplayEXT(physicalDevice,dpy,rrOutput,null);
        
        DisplayKHR* display;
        vkGetRandROutputDisplayEXT(physicalDevice,dpy,rrOutput,display);
      }
      
      VkFormatProperties* getPhysicalDeviceFormatProperties(VkFormat format){
        VkFormatProperties* formatProperties;
        vkGetPhysicalDeviceFormatProperties(physicalDevice,format,formatProperties);
      }
      
      VkSurfaceCapabilities2EXT* getPhysicalDeviceSurfaceCapabilities2EXT(SurfaceKHR surface){
        VkSurfaceCapabilities2EXT* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice,surface,surfaceCapabilities);
      }
      
      bool* getPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex,SurfaceKHR surface){
        bool* supported;
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,queueFamilyIndex,surface,supported);
      }
      
      VkImageFormatProperties2KHR* getPhysicalDeviceImageFormatProperties2KHR(const VkPhysicalDeviceImageFormatInfo2KHR* imageFormatInfo){
        VkImageFormatProperties2KHR* imageFormatProperties;
        vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice,imageFormatInfo,imageFormatProperties);
      }
      
      VkBool32 getPhysicalDeviceWin32PresentationSupportKHR(uint32_t queueFamilyIndex){
        
      }
      
      Display* getPhysicalDeviceXlibPresentationSupportKHR(uint32_t queueFamilyIndex,VisualID visualID){
        Display* dpy;
        vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice,queueFamilyIndex,dpy,visualID);
      }
      
      VkImageFormatProperties* getPhysicalDeviceImageFormatProperties(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags){
        VkImageFormatProperties* imageFormatProperties;
        vkGetPhysicalDeviceImageFormatProperties(physicalDevice,format,type,tiling,usage,flags,imageFormatProperties);
      }
      
      std::vector<VkExtensionProperties> enumerateDeviceExtensionProperties(std::string layerName){
        uint32_t* propertyCount;
        vkEnumerateDeviceExtensionProperties(physicalDevice,layerName,propertyCount,null);
        
        std::vector<VkExtensionProperties> properties(propertyCount);
        vkEnumerateDeviceExtensionProperties(physicalDevice,layerName,propertyCount,properties.data());
      }
      
      VkExternalFencePropertiesKHR* getPhysicalDeviceExternalFencePropertiesKHR(const VkPhysicalDeviceExternalFenceInfoKHR* externalFenceInfo){
        VkExternalFencePropertiesKHR* externalFenceProperties;
        vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice,externalFenceInfo,externalFenceProperties);
      }
      
      VkSurfaceCapabilities2KHR* getPhysicalDeviceSurfaceCapabilities2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo){
        VkSurfaceCapabilities2KHR* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice,surfaceInfo,surfaceCapabilities);
      }
      
      VkExternalImageFormatPropertiesNV* getPhysicalDeviceExternalImageFormatPropertiesNV(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkExternalMemoryHandleTypeFlagsNV externalHandleType){
        VkExternalImageFormatPropertiesNV* externalImageFormatProperties;
        vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice,format,type,tiling,usage,flags,externalHandleType,externalImageFormatProperties);
      }
      
      VkExternalBufferPropertiesKHR* getPhysicalDeviceExternalBufferPropertiesKHR(const VkPhysicalDeviceExternalBufferInfoKHR* externalBufferInfo){
        VkExternalBufferPropertiesKHR* externalBufferProperties;
        vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice,externalBufferInfo,externalBufferProperties);
      }
      
      std::vector<VkDisplayPlanePropertiesKHR> getPhysicalDeviceDisplayPlanePropertiesKHR(){
        uint32_t* propertyCount;
        vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice,propertyCount,null);
        
        std::vector<VkDisplayPlanePropertiesKHR> properties(propertyCount);
        vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice,propertyCount,properties.data());
      }
      
      std::vector<VkDisplayPropertiesKHR> getPhysicalDeviceDisplayPropertiesKHR(){
        uint32_t* propertyCount;
        vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice,propertyCount,null);
        
        std::vector<VkDisplayPropertiesKHR> properties(propertyCount);
        vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice,propertyCount,properties.data());
      }
      
      std::vector<VkSparseImageFormatProperties> getPhysicalDeviceSparseImageFormatProperties(VkFormat format,VkImageType type,VkSampleCountFlagBits samples,VkImageUsageFlags usage,VkImageTiling tiling){
        uint32_t* propertyCount;
        vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice,format,type,samples,usage,tiling,propertyCount,null);
        
        std::vector<VkSparseImageFormatProperties> properties(propertyCount);
        vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice,format,type,samples,usage,tiling,propertyCount,properties.data());
      }
      
      VkPhysicalDeviceProperties* getPhysicalDeviceProperties(){
        VkPhysicalDeviceProperties* properties;
        vkGetPhysicalDeviceProperties(physicalDevice,properties);
      }
      
      std::vector<VkSurfaceFormatKHR> getPhysicalDeviceSurfaceFormatsKHR(SurfaceKHR surface){
        uint32_t* surfaceFormatCount;
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surface,surfaceFormatCount,null);
        
        std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surface,surfaceFormatCount,surfaceFormats.data());
      }
      
      VkSurfaceCapabilitiesKHR* getPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHR surface){
        VkSurfaceCapabilitiesKHR* surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surface,surfaceCapabilities);
      }
      
      MirConnection* getPhysicalDeviceMirPresentationSupportKHR(uint32_t queueFamilyIndex){
        MirConnection* connection;
        vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice,queueFamilyIndex,connection);
      }
      
      VkResult releaseDisplayEXT(DisplayKHR display){
        
      }
      
      VkFormatProperties2KHR* getPhysicalDeviceFormatProperties2KHR(VkFormat format){
        VkFormatProperties2KHR* formatProperties;
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
      
      DisplayModeKHR* createDisplayModeKHR(PhysicalDevice physicalDevice,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        DisplayModeKHR* mode;
        vkCreateDisplayModeKHR(physicalDevice,displayKHR,createInfo,allocator,mode);
      }
      
      VkResult displayPowerControlEXT(Device device,const VkDisplayPowerInfoEXT* displayPowerInfo){
        
      }
      
      std::vector<VkDisplayModePropertiesKHR> getDisplayModePropertiesKHR(PhysicalDevice physicalDevice){
        uint32_t* propertyCount;
        vkGetDisplayModePropertiesKHR(physicalDevice,displayKHR,propertyCount,null);
        
        std::vector<VkDisplayModePropertiesKHR> properties(propertyCount);
        vkGetDisplayModePropertiesKHR(physicalDevice,displayKHR,propertyCount,properties.data());
      }
      
      Display* acquireXlibDisplayEXT(PhysicalDevice physicalDevice){
        Display* dpy;
        vkAcquireXlibDisplayEXT(physicalDevice,dpy,displayKHR);
      }
      
      Fence* registerDisplayEventEXT(Device device,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator){
        Fence* fence;
        vkRegisterDisplayEventEXT(device,displayKHR,displayEventInfo,allocator,fence);
      }
      
      VkResult releaseDisplayEXT(PhysicalDevice physicalDevice){
        
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
        
      }
      
      SamplerYcbcrConversionKHR* createSamplerYcbcrConversionKHR(const VkSamplerYcbcrConversionCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SamplerYcbcrConversionKHR* ycbcrConversion;
        vkCreateSamplerYcbcrConversionKHR(device,createInfo,allocator,ycbcrConversion);
      }
      
      void updateDescriptorSets(std::vector<VkWriteDescriptorSet> descriptorWrites,std::vector<VkCopyDescriptorSet> descriptorCopies){
        
      }
      
      std::vector<Image> getSwapchainImagesKHR(SwapchainKHR swapchain){
        uint32_t* swapchainImageCount;
        vkGetSwapchainImagesKHR(device,swapchain,swapchainImageCount,null);
        
        std::vector<Image> swapchainImages(swapchainImageCount);
        vkGetSwapchainImagesKHR(device,swapchain,swapchainImageCount,swapchainImages.data());
      }
      
      VkResult importFenceWin32HandleKHR(const VkImportFenceWin32HandleInfoKHR* importFenceWin32HandleInfo){
        
      }
      
      VkResult debugMarkerSetObjectNameEXT(const VkDebugMarkerObjectNameInfoEXT* nameInfo){
        
      }
      
      VkRefreshCycleDurationGOOGLE* getRefreshCycleDurationGOOGLE(SwapchainKHR swapchain){
        VkRefreshCycleDurationGOOGLE* displayTimingProperties;
        vkGetRefreshCycleDurationGOOGLE(device,swapchain,displayTimingProperties);
      }
      
      VkResult bindImageMemory2KHR(std::vector<VkBindImageMemoryInfoKHR> bindInfos){
        
      }
      
      VkResult bindBufferMemory2KHR(std::vector<VkBindBufferMemoryInfoKHR> bindInfos){
        
      }
      
      VkResult importSemaphoreWin32HandleKHR(const VkImportSemaphoreWin32HandleInfoKHR* importSemaphoreWin32HandleInfo){
        
      }
      
      int* getSemaphoreFdKHR(const VkSemaphoreGetFdInfoKHR* getFdInfo){
        int* fd;
        vkGetSemaphoreFdKHR(device,getFdInfo,fd);
      }
      
      VkMemoryWin32HandlePropertiesKHR* getMemoryWin32HandlePropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,HANDLE handle){
        VkMemoryWin32HandlePropertiesKHR* memoryWin32HandleProperties;
        vkGetMemoryWin32HandlePropertiesKHR(device,handleType,handle,memoryWin32HandleProperties);
      }
      
      DescriptorUpdateTemplateKHR* createDescriptorUpdateTemplateKHR(const VkDescriptorUpdateTemplateCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        DescriptorUpdateTemplateKHR* descriptorUpdateTemplate;
        vkCreateDescriptorUpdateTemplateKHR(device,createInfo,allocator,descriptorUpdateTemplate);
      }
      
      VkResult flushMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        
      }
      
      DescriptorPool* createDescriptorPool(const VkDescriptorPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        DescriptorPool* descriptorPool;
        vkCreateDescriptorPool(device,createInfo,allocator,descriptorPool);
      }
      
      VkResult resetFences(std::vector<Fence> fences){
        
      }
      
      std::vector<VkSparseImageMemoryRequirements2KHR> getImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2KHR* info){
        uint32_t* sparseMemoryRequirementCount;
        vkGetImageSparseMemoryRequirements2KHR(device,info,sparseMemoryRequirementCount,null);
        
        std::vector<VkSparseImageMemoryRequirements2KHR> sparseMemoryRequirements(sparseMemoryRequirementCount);
        vkGetImageSparseMemoryRequirements2KHR(device,info,sparseMemoryRequirementCount,sparseMemoryRequirements.data());
      }
      
      Image* createImage(const VkImageCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Image* image;
        vkCreateImage(device,createInfo,allocator,image);
      }
      
      ShaderModule* createShaderModule(const VkShaderModuleCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        ShaderModule* shaderModule;
        vkCreateShaderModule(device,createInfo,allocator,shaderModule);
      }
      
      uint32_t* acquireNextImage2KHX(const VkAcquireNextImageInfoKHX* acquireInfo){
        uint32_t* imageIndex;
        vkAcquireNextImage2KHX(device,acquireInfo,imageIndex);
      }
      
      void destroyDevice(const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult getSwapchainStatusKHR(SwapchainKHR swapchain){
        
      }
      
      Buffer* createBuffer(const VkBufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Buffer* buffer;
        vkCreateBuffer(device,createInfo,allocator,buffer);
      }
      
      VkResult importSemaphoreFdKHR(const VkImportSemaphoreFdInfoKHR* importSemaphoreFdInfo){
        
      }
      
      Event* createEvent(const VkEventCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Event* event;
        vkCreateEvent(device,createInfo,allocator,event);
      }
      
      VkResult displayPowerControlEXT(DisplayKHR display,const VkDisplayPowerInfoEXT* displayPowerInfo){
        
      }
      
      IndirectCommandsLayoutNVX* createIndirectCommandsLayoutNVX(const VkIndirectCommandsLayoutCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator){
        IndirectCommandsLayoutNVX* indirectCommandsLayout;
        vkCreateIndirectCommandsLayoutNVX(device,createInfo,allocator,indirectCommandsLayout);
      }
      
      std::vector<VkPastPresentationTimingGOOGLE> getPastPresentationTimingGOOGLE(SwapchainKHR swapchain){
        uint32_t* presentationTimingCount;
        vkGetPastPresentationTimingGOOGLE(device,swapchain,presentationTimingCount,null);
        
        std::vector<VkPastPresentationTimingGOOGLE> presentationTimings(presentationTimingCount);
        vkGetPastPresentationTimingGOOGLE(device,swapchain,presentationTimingCount,presentationTimings.data());
      }
      
      Fence* createFence(const VkFenceCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Fence* fence;
        vkCreateFence(device,createInfo,allocator,fence);
      }
      
      ImageView* createImageView(const VkImageViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        ImageView* view;
        vkCreateImageView(device,createInfo,allocator,view);
      }
      
      VkDeviceGroupPresentModeFlagsKHX* getDeviceGroupSurfacePresentModesKHX(SurfaceKHR surface){
        VkDeviceGroupPresentModeFlagsKHX* modes;
        vkGetDeviceGroupSurfacePresentModesKHX(device,surface,modes);
      }
      
      DescriptorSetLayout* createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        DescriptorSetLayout* setLayout;
        vkCreateDescriptorSetLayout(device,createInfo,allocator,setLayout);
      }
      
      QueryPool* createQueryPool(const VkQueryPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        QueryPool* queryPool;
        vkCreateQueryPool(device,createInfo,allocator,queryPool);
      }
      
      RenderPass* createRenderPass(const VkRenderPassCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        RenderPass* renderPass;
        vkCreateRenderPass(device,createInfo,allocator,renderPass);
      }
      
      VkResult deviceWaitIdle(){
        
      }
      
      std::vector<CommandBuffer> allocateCommandBuffers(const VkCommandBufferAllocateInfo* allocateInfo){
        std::vector<CommandBuffer> commandBuffers;
        vkAllocateCommandBuffers(device,allocateInfo,commandBuffers);
      }
      
      Queue* getDeviceQueue(uint32_t queueFamilyIndex,uint32_t queueIndex){
        Queue* queue;
        vkGetDeviceQueue(device,queueFamilyIndex,queueIndex,queue);
      }
      
      Fence* registerDisplayEventEXT(DisplayKHR display,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator){
        Fence* fence;
        vkRegisterDisplayEventEXT(device,display,displayEventInfo,allocator,fence);
      }
      
      PipelineLayout* createPipelineLayout(const VkPipelineLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        PipelineLayout* pipelineLayout;
        vkCreatePipelineLayout(device,createInfo,allocator,pipelineLayout);
      }
      
      Framebuffer* createFramebuffer(const VkFramebufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Framebuffer* framebuffer;
        vkCreateFramebuffer(device,createInfo,allocator,framebuffer);
      }
      
      int* getFenceFdKHR(const VkFenceGetFdInfoKHR* getFdInfo){
        int* fd;
        vkGetFenceFdKHR(device,getFdInfo,fd);
      }
      
      VkPeerMemoryFeatureFlagsKHX* getDeviceGroupPeerMemoryFeaturesKHX(uint32_t heapIndex,uint32_t localDeviceIndex,uint32_t remoteDeviceIndex){
        VkPeerMemoryFeatureFlagsKHX* peerMemoryFeatures;
        vkGetDeviceGroupPeerMemoryFeaturesKHX(device,heapIndex,localDeviceIndex,remoteDeviceIndex,peerMemoryFeatures);
      }
      
      VkMemoryRequirements2KHR* getImageMemoryRequirements2KHR(const VkImageMemoryRequirementsInfo2KHR* info){
        VkMemoryRequirements2KHR* memoryRequirements;
        vkGetImageMemoryRequirements2KHR(device,info,memoryRequirements);
      }
      
      BufferView* createBufferView(const VkBufferViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        BufferView* view;
        vkCreateBufferView(device,createInfo,allocator,view);
      }
      
      Semaphore* createSemaphore(const VkSemaphoreCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Semaphore* semaphore;
        vkCreateSemaphore(device,createInfo,allocator,semaphore);
      }
      
      ObjectTableNVX* createObjectTableNVX(const VkObjectTableCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator){
        ObjectTableNVX* objectTable;
        vkCreateObjectTableNVX(device,createInfo,allocator,objectTable);
      }
      
      VkResult importFenceFdKHR(const VkImportFenceFdInfoKHR* importFenceFdInfo){
        
      }
      
      std::vector<SwapchainKHR> createSharedSwapchainsKHR(std::vector<VkSwapchainCreateInfoKHR> createInfos,const VkAllocationCallbacks* allocator){
        uint32_t swapchainCount;
        vkCreateSharedSwapchainsKHR(device,swapchainCount,createInfos.data(),allocator,null);
        
        std::vector<SwapchainKHR> swapchains(swapchainCount);
        vkCreateSharedSwapchainsKHR(device,swapchainCount,createInfos.data(),allocator,swapchains.data());
      }
      
      CommandPool* createCommandPool(const VkCommandPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        CommandPool* commandPool;
        vkCreateCommandPool(device,createInfo,allocator,commandPool);
      }
      
      HANDLE* getSemaphoreWin32HandleKHR(const VkSemaphoreGetWin32HandleInfoKHR* getWin32HandleInfo){
        HANDLE* handle;
        vkGetSemaphoreWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      HANDLE* getFenceWin32HandleKHR(const VkFenceGetWin32HandleInfoKHR* getWin32HandleInfo){
        HANDLE* handle;
        vkGetFenceWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      VkResult waitForFences(std::vector<Fence> fences,bool waitAll,uint64_t timeout){
        
      }
      
      SwapchainKHR* createSwapchainKHR(const VkSwapchainCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        SwapchainKHR* swapchain;
        vkCreateSwapchainKHR(device,createInfo,allocator,swapchain);
      }
      
      VkMemoryFdPropertiesKHR* getMemoryFdPropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,int fd){
        VkMemoryFdPropertiesKHR* memoryFdProperties;
        vkGetMemoryFdPropertiesKHR(device,handleType,fd,memoryFdProperties);
      }
      
      ValidationCacheEXT* createValidationCacheEXT(const VkValidationCacheCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator){
        ValidationCacheEXT* validationCache;
        vkCreateValidationCacheEXT(device,createInfo,allocator,validationCache);
      }
      
      VkDeviceGroupPresentCapabilitiesKHX* getDeviceGroupPresentCapabilitiesKHX(){
        VkDeviceGroupPresentCapabilitiesKHX* deviceGroupPresentCapabilities;
        vkGetDeviceGroupPresentCapabilitiesKHX(device,deviceGroupPresentCapabilities);
      }
      
      void destroySwapchainKHR(SwapchainKHR swapchain,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult invalidateMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        
      }
      
      uint64_t* getSwapchainCounterEXT(SwapchainKHR swapchain,VkSurfaceCounterFlagBitsEXT counter){
        uint64_t* counterValue;
        vkGetSwapchainCounterEXT(device,swapchain,counter,counterValue);
      }
      
      Sampler* createSampler(const VkSamplerCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        Sampler* sampler;
        vkCreateSampler(device,createInfo,allocator,sampler);
      }
      
      PipelineCache* createPipelineCache(const VkPipelineCacheCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        PipelineCache* pipelineCache;
        vkCreatePipelineCache(device,createInfo,allocator,pipelineCache);
      }
      
      int* getMemoryFdKHR(const VkMemoryGetFdInfoKHR* getFdInfo){
        int* fd;
        vkGetMemoryFdKHR(device,getFdInfo,fd);
      }
      
      VkResult debugMarkerSetObjectTagEXT(const VkDebugMarkerObjectTagInfoEXT* tagInfo){
        
      }
      
      PFN_vkVoidFunction getDeviceProcAddr(std::string name){
        
      }
      
      HANDLE* getMemoryWin32HandleKHR(const VkMemoryGetWin32HandleInfoKHR* getWin32HandleInfo){
        HANDLE* handle;
        vkGetMemoryWin32HandleKHR(device,getWin32HandleInfo,handle);
      }
      
      std::vector<DescriptorSet> allocateDescriptorSets(const VkDescriptorSetAllocateInfo* allocateInfo){
        std::vector<DescriptorSet> descriptorSets;
        vkAllocateDescriptorSets(device,allocateInfo,descriptorSets);
      }
      
      DeviceMemory* allocateMemory(const VkMemoryAllocateInfo* allocateInfo,const VkAllocationCallbacks* allocator){
        DeviceMemory* memory;
        vkAllocateMemory(device,allocateInfo,allocator,memory);
      }
      
      VkMemoryRequirements2KHR* getBufferMemoryRequirements2KHR(const VkBufferMemoryRequirementsInfo2KHR* info){
        VkMemoryRequirements2KHR* memoryRequirements;
        vkGetBufferMemoryRequirements2KHR(device,info,memoryRequirements);
      }
      
      Fence* registerDeviceEventEXT(const VkDeviceEventInfoEXT* deviceEventInfo,const VkAllocationCallbacks* allocator){
        Fence* fence;
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
        
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer,PipelineLayout layout,uint32_t set,const void* data){
        
      }
      
      void updateDescriptorSetWithTemplateKHR(DescriptorSet descriptorSet,const void* data){
        
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
        
      }
      
      VkResult beginCommandBuffer(const VkCommandBufferBeginInfo* beginInfo){
        
      }
      
      void cmdSetDiscardRectangleEXT(uint32_t firstDiscardRectangle,std::vector<VkRect2D> discardRectangles){
        
      }
      
      void cmdSetViewportWScalingNV(uint32_t firstViewport,std::vector<VkViewportWScalingNV> viewportWScalings){
        
      }
      
      void cmdProcessCommandsNVX(const VkCmdProcessCommandsInfoNVX* processCommandsInfo){
        
      }
      
      void cmdDispatchBaseKHX(uint32_t baseGroupX,uint32_t baseGroupY,uint32_t baseGroupZ,uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        
      }
      
      void cmdResetEvent(Event event,VkPipelineStageFlags stageMask){
        
      }
      
      void cmdBindVertexBuffers(uint32_t firstBinding,std::vector<Buffer> buffers,std::vector<std::size_t> offsets){
        
      }
      
      void cmdDispatch(uint32_t groupCountX,uint32_t groupCountY,uint32_t groupCountZ){
        
      }
      
      void cmdNextSubpass(VkSubpassContents contents){
        
      }
      
      void cmdPushDescriptorSetKHR(VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t set,std::vector<VkWriteDescriptorSet> descriptorWrites){
        
      }
      
      void cmdSetViewport(uint32_t firstViewport,std::vector<VkViewport> viewports){
        
      }
      
      void cmdCopyQueryPoolResults(QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,Buffer dstBuffer,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        
      }
      
      void cmdDrawIndexed(uint32_t indexCount,uint32_t instanceCount,uint32_t firstIndex,int32_t vertexOffset,uint32_t firstInstance){
        
      }
      
      void cmdSetEvent(Event event,VkPipelineStageFlags stageMask){
        
      }
      
      void cmdSetSampleLocationsEXT(const VkSampleLocationsInfoEXT* sampleLocationsInfo){
        
      }
      
      void cmdSetScissor(uint32_t firstScissor,std::vector<VkRect2D> scissors){
        
      }
      
      void cmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage,QueryPool queryPool,uint32_t query){
        
      }
      
      void cmdSetLineWidth(float lineWidth){
        
      }
      
      void cmdDrawIndirect(Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        
      }
      
      void cmdDebugMarkerEndEXT(){
        
      }
      
      void cmdResolveImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageResolve> regions){
        
      }
      
      void cmdEndRenderPass(){
        
      }
      
      void cmdResetQueryPool(QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount){
        
      }
      
      void cmdCopyImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageCopy> regions){
        
      }
      
      void cmdReserveSpaceForCommandsNVX(const VkCmdReserveSpaceForCommandsInfoNVX* reserveSpaceInfo){
        
      }
      
      void cmdBlitImage(Image srcImage,VkImageLayout srcImageLayout,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkImageBlit> regions,VkFilter filter){
        
      }
      
      void cmdSetStencilWriteMask(VkStencilFaceFlags faceMask,uint32_t writeMask){
        
      }
      
      void cmdExecuteCommands(std::vector<CommandBuffer> commandBuffers){
        
      }
      
      void cmdPushDescriptorSetWithTemplateKHR(DescriptorUpdateTemplateKHR descriptorUpdateTemplate,PipelineLayout layout,uint32_t set,const void* data){
        
      }
      
      void cmdPipelineBarrier(VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,VkDependencyFlags dependencyFlags,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        
      }
      
      void cmdWaitEvents(std::vector<Event> events,VkPipelineStageFlags srcStageMask,VkPipelineStageFlags dstStageMask,std::vector<VkMemoryBarrier> memoryBarriers,std::vector<VkBufferMemoryBarrier> bufferMemoryBarriers,std::vector<VkImageMemoryBarrier> imageMemoryBarriers){
        
      }
      
      void cmdDrawIndexedIndirectCountAMD(Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        
      }
      
      void cmdDraw(uint32_t vertexCount,uint32_t instanceCount,uint32_t firstVertex,uint32_t firstInstance){
        
      }
      
      void cmdDrawIndexedIndirect(Buffer buffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        
      }
      
      void cmdCopyImageToBuffer(Image srcImage,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        
      }
      
      void cmdDebugMarkerInsertEXT(const VkDebugMarkerMarkerInfoEXT* markerInfo){
        
      }
      
      void cmdSetStencilCompareMask(VkStencilFaceFlags faceMask,uint32_t compareMask){
        
      }
      
      void cmdPushConstants(PipelineLayout layout,VkShaderStageFlags stageFlags,uint32_t offset,std::vector<void> values){
        
      }
      
      void cmdDrawIndirectCountAMD(Buffer buffer,std::size_t offset,Buffer countBuffer,std::size_t countBufferOffset,uint32_t maxDrawCount,uint32_t stride){
        
      }
      
      void cmdDispatchIndirect(Buffer buffer,std::size_t offset){
        
      }
      
      void cmdCopyBufferToImage(Buffer srcBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        
      }
      
      void cmdBindPipeline(VkPipelineBindPoint pipelineBindPoint,Pipeline pipeline){
        
      }
      
      void cmdDebugMarkerBeginEXT(const VkDebugMarkerMarkerInfoEXT* markerInfo){
        
      }
      
      VkResult endCommandBuffer(){
        
      }
      
      VkResult resetCommandBuffer(VkCommandBufferResetFlags flags){
        
      }
      
      void cmdSetStencilReference(VkStencilFaceFlags faceMask,uint32_t reference){
        
      }
      
      void cmdEndQuery(QueryPool queryPool,uint32_t query){
        
      }
      
      void cmdBindIndexBuffer(Buffer buffer,std::size_t offset,VkIndexType indexType){
        
      }
      
      void cmdSetDeviceMaskKHX(uint32_t deviceMask){
        
      }
      
      void cmdSetDepthBias(float depthBiasConstantFactor,float depthBiasClamp,float depthBiasSlopeFactor){
        
      }
      
      void cmdSetDepthBounds(float minDepthBounds,float maxDepthBounds){
        
      }
      
      void cmdClearDepthStencilImage(Image image,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        
      }
      
      void cmdClearColorImage(Image image,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        
      }
      
      void cmdBeginRenderPass(const VkRenderPassBeginInfo* renderPassBegin,VkSubpassContents contents){
        
      }
      
      void cmdCopyBuffer(Buffer srcBuffer,Buffer dstBuffer,std::vector<VkBufferCopy> regions){
        
      }
      
      void cmdSetBlendConstants(const float blendConstants){
        
      }
      
      void cmdFillBuffer(Buffer dstBuffer,std::size_t dstOffset,std::size_t size,uint32_t data){
        
      }
      
      void cmdBeginQuery(QueryPool queryPool,uint32_t query,VkQueryControlFlags flags){
        
      }
      
      void cmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint,PipelineLayout layout,uint32_t firstSet,std::vector<DescriptorSet> descriptorSets,std::vector<uint32_t> dynamicOffsets){
        
      }
      
      void cmdClearAttachments(std::vector<VkClearAttachment> attachments,std::vector<VkClearRect> rects){
        
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
      }
      
      VkRefreshCycleDurationGOOGLE* getRefreshCycleDurationGOOGLE(Device device){
        VkRefreshCycleDurationGOOGLE* displayTimingProperties;
        vkGetRefreshCycleDurationGOOGLE(device,swapchainKHR,displayTimingProperties);
      }
      
      VkResult getSwapchainStatusKHR(Device device){
        
      }
      
      uint32_t* acquireNextImageKHR(Device device,uint64_t timeout,Semaphore semaphore,Fence fence){
        uint32_t* imageIndex;
        vkAcquireNextImageKHR(device,swapchainKHR,timeout,semaphore,fence,imageIndex);
      }
      
      std::vector<VkPastPresentationTimingGOOGLE> getPastPresentationTimingGOOGLE(Device device){
        uint32_t* presentationTimingCount;
        vkGetPastPresentationTimingGOOGLE(device,swapchainKHR,presentationTimingCount,null);
        
        std::vector<VkPastPresentationTimingGOOGLE> presentationTimings(presentationTimingCount);
        vkGetPastPresentationTimingGOOGLE(device,swapchainKHR,presentationTimingCount,presentationTimings.data());
      }
      
      void destroySwapchainKHR(Device device,const VkAllocationCallbacks* allocator){
        
      }
      
      uint64_t* getSwapchainCounterEXT(Device device,VkSurfaceCounterFlagBitsEXT counter){
        uint64_t* counterValue;
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
        
      }
      
      void destroyPipeline(const VkAllocationCallbacks* allocator){
        
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
      }
      
      std::vector<Pipeline> createGraphicsPipelines(std::vector<VkGraphicsPipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator){
        uint32_t createInfoCount;
        vkCreateGraphicsPipelines((VkDevice)device,pipelineCache,createInfoCount,createInfos.data(),allocator,null);
        
        std::vector<Pipeline> pipelines(createInfoCount);
        vkCreateGraphicsPipelines((VkDevice)device,pipelineCache,createInfoCount,createInfos.data(),allocator,pipelines.data());
      }
      
      void destroyPipelineCache(const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult mergePipelineCaches(std::vector<PipelineCache> srcCaches){
        
      }
      
      std::vector<void> getPipelineCacheData(){
        size_t* dataSize;
        vkGetPipelineCacheData((VkDevice)device,pipelineCache,dataSize,null);
        
        std::vector<void> data(dataSize);
        vkGetPipelineCacheData((VkDevice)device,pipelineCache,dataSize,data.data());
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
        
      }
      
      void freeMemory(const VkAllocationCallbacks* allocator){
        
      }
      
      void** mapMemory(std::size_t offset,std::size_t size,VkMemoryMapFlags flags){
        void** data;
        vkMapMemory((VkDevice)device,deviceMemory,offset,size,flags,data);
      }
      
      void unmapMemory(){
        
      }
      
      HANDLE* getMemoryWin32HandleNV(VkExternalMemoryHandleTypeFlagsNV handleType){
        HANDLE* handle;
        vkGetMemoryWin32HandleNV((VkDevice)device,deviceMemory,handleType,handle);
      }
      
      VkResult bindImageMemory(Image image,std::size_t memoryOffset){
        
      }
      
      std::size_t* getDeviceMemoryCommitment(){
        std::size_t* committedMemoryInBytes;
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
        
      }
      
      VkResult bindBufferMemory(DeviceMemory memory,std::size_t memoryOffset){
        
      }
      
      void cmdCopyQueryPoolResults(CommandBuffer commandBuffer,QueryPool queryPool,uint32_t firstQuery,uint32_t queryCount,std::size_t dstOffset,std::size_t stride,VkQueryResultFlags flags){
        
      }
      
      void cmdDrawIndirect(CommandBuffer commandBuffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        
      }
      
      void cmdDrawIndexedIndirect(CommandBuffer commandBuffer,std::size_t offset,uint32_t drawCount,uint32_t stride){
        
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,Image srcImage,VkImageLayout srcImageLayout,std::vector<VkBufferImageCopy> regions){
        
      }
      
      void destroyBuffer(const VkAllocationCallbacks* allocator){
        
      }
      
      void cmdDispatchIndirect(CommandBuffer commandBuffer,std::size_t offset){
        
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Image dstImage,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        
      }
      
      VkMemoryRequirements* getBufferMemoryRequirements(){
        VkMemoryRequirements* memoryRequirements;
        vkGetBufferMemoryRequirements((VkDevice)device,buffer,memoryRequirements);
      }
      
      void cmdBindIndexBuffer(CommandBuffer commandBuffer,std::size_t offset,VkIndexType indexType){
        
      }
      
      void cmdFillBuffer(CommandBuffer commandBuffer,std::size_t dstOffset,std::size_t size,uint32_t data){
        
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
        
      }
      
      VkResult unregisterObjectsNVX(std::vector<VkObjectEntryTypeNVX> objectEntryTypes,std::vector<uint32_t> objectIndices){
        
      }
      
      VkResult registerObjectsNVX(std::vector<VkObjectTableEntryNVX> objectTableEntries,std::vector<uint32_t> objectIndices){
        
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
        
      }
      
      void destroyFence(const VkAllocationCallbacks* allocator){
        
      }
      
      uint32_t* acquireNextImageKHR(SwapchainKHR swapchain,uint64_t timeout,Semaphore semaphore){
        uint32_t* imageIndex;
        vkAcquireNextImageKHR((VkDevice)device,swapchain,timeout,semaphore,fence,imageIndex);
      }
      
      VkResult queueBindSparse(Queue queue,std::vector<VkBindSparseInfo> bindInfo){
        
      }
      
      VkResult getFenceStatus(){
        
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
        
      }
      
      void cmdWriteTimestamp(CommandBuffer commandBuffer,VkPipelineStageFlagBits pipelineStage,uint32_t query){
        
      }
      
      void cmdResetQueryPool(CommandBuffer commandBuffer,uint32_t firstQuery,uint32_t queryCount){
        
      }
      
      void destroyQueryPool(const VkAllocationCallbacks* allocator){
        
      }
      
      void cmdEndQuery(CommandBuffer commandBuffer,uint32_t query){
        
      }
      
      std::vector<void> getQueryPoolResults(uint32_t firstQuery,uint32_t queryCount,std::size_t stride,VkQueryResultFlags flags){
        size_t dataSize;
        vkGetQueryPoolResults((VkDevice)device,queryPool,firstQuery,queryCount,dataSize,null,stride,flags);
        
        std::vector<void> data(dataSize);
        vkGetQueryPoolResults((VkDevice)device,queryPool,firstQuery,queryCount,dataSize,data.data(),stride,flags);
      }
      
      void cmdBeginQuery(CommandBuffer commandBuffer,uint32_t query,VkQueryControlFlags flags){
        
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
      }
      
      void cmdCopyImageToBuffer(CommandBuffer commandBuffer,VkImageLayout srcImageLayout,Buffer dstBuffer,std::vector<VkBufferImageCopy> regions){
        
      }
      
      void destroyImage(const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult bindImageMemory(DeviceMemory memory,std::size_t memoryOffset){
        
      }
      
      void cmdCopyBufferToImage(CommandBuffer commandBuffer,Buffer srcBuffer,VkImageLayout dstImageLayout,std::vector<VkBufferImageCopy> regions){
        
      }
      
      std::vector<VkSparseImageMemoryRequirements> getImageSparseMemoryRequirements(){
        uint32_t* sparseMemoryRequirementCount;
        vkGetImageSparseMemoryRequirements((VkDevice)device,image,sparseMemoryRequirementCount,null);
        
        std::vector<VkSparseImageMemoryRequirements> sparseMemoryRequirements(sparseMemoryRequirementCount);
        vkGetImageSparseMemoryRequirements((VkDevice)device,image,sparseMemoryRequirementCount,sparseMemoryRequirements.data());
      }
      
      void cmdClearDepthStencilImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        
      }
      
      void cmdClearColorImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        
      }
      
      VkMemoryRequirements* getImageMemoryRequirements(){
        VkMemoryRequirements* memoryRequirements;
        vkGetImageMemoryRequirements((VkDevice)device,image,memoryRequirements);
      }
    private:
      VkImage image;
      Device device;
  }