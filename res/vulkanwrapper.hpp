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
      
      std::tuple<uint32_t*,VkResult> acquireNextImageKHR(SwapchainKHR swapchain,uint64_t timeout,Fence fence){
        
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
      
      std::tuple<std::vector<void>,VkResult> getValidationCacheDataEXT(){
        
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
      
      std::tuple<VkDisplayPlaneCapabilitiesKHR*,VkResult> getDisplayPlaneCapabilitiesKHR(uint32_t planeIndex){
        
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
      
      std::tuple<std::vector<VkRect2D>,VkResult> getPhysicalDevicePresentRectanglesKHX(PhysicalDevice physicalDevice){
        
      }
      
      void destroySurfaceKHR(const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<std::vector<VkPresentModeKHR>,VkResult> getPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice physicalDevice){
        
      }
      
      std::tuple<VkDeviceGroupPresentModeFlagsKHX*,VkResult> getDeviceGroupSurfacePresentModesKHX(Device device){
        
      }
      
      std::tuple<VkSurfaceCapabilities2EXT*,VkResult> getPhysicalDeviceSurfaceCapabilities2EXT(PhysicalDevice physicalDevice){
        
      }
      
      std::tuple<bool*,VkResult> getPhysicalDeviceSurfaceSupportKHR(PhysicalDevice physicalDevice,uint32_t queueFamilyIndex){
        
      }
      
      std::tuple<std::vector<VkSurfaceFormatKHR>,VkResult> getPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice physicalDevice){
        
      }
      
      std::tuple<VkSurfaceCapabilitiesKHR*,VkResult> getPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice physicalDevice){
        
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
      
      std::tuple<SurfaceKHR,VkResult> createXlibSurfaceKHR(const VkXlibSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createWin32SurfaceKHR(const VkWin32SurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      PFN_vkVoidFunction getInstanceProcAddr(std::string name){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createWaylandSurfaceKHR(const VkWaylandSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createIOSSurfaceMVK(const VkIOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createAndroidSurfaceKHR(const VkAndroidSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<DebugReportCallbackEXT,VkResult> createDebugReportCallbackEXT(const VkDebugReportCallbackCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createViSurfaceNN(const VkViSurfaceCreateInfoNN* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<std::vector<PhysicalDevice>,VkResult> enumeratePhysicalDevices(){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createMacOSSurfaceMVK(const VkMacOSSurfaceCreateInfoMVK* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createXcbSurfaceKHR(const VkXcbSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      void destroyInstance(const VkAllocationCallbacks* allocator){
        
      }
      
      void debugReportMessageEXT(VkDebugReportFlagsEXT flags,VkDebugReportObjectTypeEXT objectType,uint64_t object,size_t location,int32_t messageCode,std::string layerPrefix,std::string message){
        
      }
      
      std::tuple<std::vector<VkPhysicalDeviceGroupPropertiesKHX>,VkResult> enumeratePhysicalDeviceGroupsKHX(){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createMirSurfaceKHR(const VkMirSurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<SurfaceKHR,VkResult> createDisplayPlaneSurfaceKHR(const VkDisplaySurfaceCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
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
        
      }
      
      std::vector<VkSparseImageFormatProperties2KHR> getPhysicalDeviceSparseImageFormatProperties2KHR(const VkPhysicalDeviceSparseImageFormatInfo2KHR* formatInfo){
        
      }
      
      std::tuple<VkDeviceGeneratedCommandsFeaturesNVX*,VkDeviceGeneratedCommandsLimitsNVX*> getPhysicalDeviceGeneratedCommandsPropertiesNVX(){
        
      }
      
      std::tuple<std::vector<VkSurfaceFormat2KHR>,VkResult> getPhysicalDeviceSurfaceFormats2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo){
        
      }
      
      std::tuple<std::vector<VkRect2D>,VkResult> getPhysicalDevicePresentRectanglesKHX(SurfaceKHR surface){
        
      }
      
      VkBool32 getPhysicalDeviceWaylandPresentationSupportKHR(uint32_t queueFamilyIndex,struct wl_display* display){
        
      }
      
      std::tuple<Device,VkResult> createDevice(const VkDeviceCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<DisplayModeKHR,VkResult> createDisplayModeKHR(DisplayKHR display,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<std::vector<VkLayerProperties>,VkResult> enumerateDeviceLayerProperties(){
        
      }
      
      VkPhysicalDeviceFeatures* getPhysicalDeviceFeatures(){
        
      }
      
      std::vector<VkQueueFamilyProperties2KHR> getPhysicalDeviceQueueFamilyProperties2KHR(){
        
      }
      
      VkExternalSemaphorePropertiesKHR* getPhysicalDeviceExternalSemaphorePropertiesKHR(const VkPhysicalDeviceExternalSemaphoreInfoKHR* externalSemaphoreInfo){
        
      }
      
      VkPhysicalDeviceFeatures2KHR* getPhysicalDeviceFeatures2KHR(){
        
      }
      
      VkMultisamplePropertiesEXT* getPhysicalDeviceMultisamplePropertiesEXT(VkSampleCountFlagBits samples){
        
      }
      
      VkPhysicalDeviceMemoryProperties* getPhysicalDeviceMemoryProperties(){
        
      }
      
      std::tuple<std::vector<VkDisplayModePropertiesKHR>,VkResult> getDisplayModePropertiesKHR(DisplayKHR display){
        
      }
      
      std::tuple<std::vector<VkPresentModeKHR>,VkResult> getPhysicalDeviceSurfacePresentModesKHR(SurfaceKHR surface){
        
      }
      
      std::tuple<Display*,VkResult> acquireXlibDisplayEXT(DisplayKHR display){
        
      }
      
      VkPhysicalDeviceProperties2KHR* getPhysicalDeviceProperties2KHR(){
        
      }
      
      std::tuple<std::vector<DisplayKHR>,VkResult> getDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex){
        
      }
      
      VkPhysicalDeviceMemoryProperties2KHR* getPhysicalDeviceMemoryProperties2KHR(){
        
      }
      
      std::tuple<xcb_connection_t*,VkBool32> getPhysicalDeviceXcbPresentationSupportKHR(uint32_t queueFamilyIndex,xcb_visualid_t visual_id){
        
      }
      
      std::tuple<Display*,DisplayKHR,VkResult> getRandROutputDisplayEXT(RROutput rrOutput){
        
      }
      
      VkFormatProperties* getPhysicalDeviceFormatProperties(VkFormat format){
        
      }
      
      std::tuple<VkSurfaceCapabilities2EXT*,VkResult> getPhysicalDeviceSurfaceCapabilities2EXT(SurfaceKHR surface){
        
      }
      
      std::tuple<bool*,VkResult> getPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex,SurfaceKHR surface){
        
      }
      
      std::tuple<VkImageFormatProperties2KHR*,VkResult> getPhysicalDeviceImageFormatProperties2KHR(const VkPhysicalDeviceImageFormatInfo2KHR* imageFormatInfo){
        
      }
      
      VkBool32 getPhysicalDeviceWin32PresentationSupportKHR(uint32_t queueFamilyIndex){
        
      }
      
      std::tuple<Display*,VkBool32> getPhysicalDeviceXlibPresentationSupportKHR(uint32_t queueFamilyIndex,VisualID visualID){
        
      }
      
      std::tuple<VkImageFormatProperties*,VkResult> getPhysicalDeviceImageFormatProperties(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags){
        
      }
      
      std::tuple<std::vector<VkExtensionProperties>,VkResult> enumerateDeviceExtensionProperties(std::string layerName){
        
      }
      
      VkExternalFencePropertiesKHR* getPhysicalDeviceExternalFencePropertiesKHR(const VkPhysicalDeviceExternalFenceInfoKHR* externalFenceInfo){
        
      }
      
      std::tuple<VkSurfaceCapabilities2KHR*,VkResult> getPhysicalDeviceSurfaceCapabilities2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* surfaceInfo){
        
      }
      
      std::tuple<VkExternalImageFormatPropertiesNV*,VkResult> getPhysicalDeviceExternalImageFormatPropertiesNV(VkFormat format,VkImageType type,VkImageTiling tiling,VkImageUsageFlags usage,VkImageCreateFlags flags,VkExternalMemoryHandleTypeFlagsNV externalHandleType){
        
      }
      
      VkExternalBufferPropertiesKHR* getPhysicalDeviceExternalBufferPropertiesKHR(const VkPhysicalDeviceExternalBufferInfoKHR* externalBufferInfo){
        
      }
      
      std::tuple<std::vector<VkDisplayPlanePropertiesKHR>,VkResult> getPhysicalDeviceDisplayPlanePropertiesKHR(){
        
      }
      
      std::tuple<std::vector<VkDisplayPropertiesKHR>,VkResult> getPhysicalDeviceDisplayPropertiesKHR(){
        
      }
      
      std::vector<VkSparseImageFormatProperties> getPhysicalDeviceSparseImageFormatProperties(VkFormat format,VkImageType type,VkSampleCountFlagBits samples,VkImageUsageFlags usage,VkImageTiling tiling){
        
      }
      
      VkPhysicalDeviceProperties* getPhysicalDeviceProperties(){
        
      }
      
      std::tuple<std::vector<VkSurfaceFormatKHR>,VkResult> getPhysicalDeviceSurfaceFormatsKHR(SurfaceKHR surface){
        
      }
      
      std::tuple<VkSurfaceCapabilitiesKHR*,VkResult> getPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHR surface){
        
      }
      
      std::tuple<MirConnection*,VkBool32> getPhysicalDeviceMirPresentationSupportKHR(uint32_t queueFamilyIndex){
        
      }
      
      VkResult releaseDisplayEXT(DisplayKHR display){
        
      }
      
      VkFormatProperties2KHR* getPhysicalDeviceFormatProperties2KHR(VkFormat format){
        
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
      
      std::tuple<DisplayModeKHR,VkResult> createDisplayModeKHR(PhysicalDevice physicalDevice,const VkDisplayModeCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult displayPowerControlEXT(Device device,const VkDisplayPowerInfoEXT* displayPowerInfo){
        
      }
      
      std::tuple<std::vector<VkDisplayModePropertiesKHR>,VkResult> getDisplayModePropertiesKHR(PhysicalDevice physicalDevice){
        
      }
      
      std::tuple<Display*,VkResult> acquireXlibDisplayEXT(PhysicalDevice physicalDevice){
        
      }
      
      std::tuple<Fence,VkResult> registerDisplayEventEXT(Device device,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator){
        
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
      
      std::tuple<SamplerYcbcrConversionKHR,VkResult> createSamplerYcbcrConversionKHR(const VkSamplerYcbcrConversionCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      void updateDescriptorSets(std::vector<VkWriteDescriptorSet> descriptorWrites,std::vector<VkCopyDescriptorSet> descriptorCopies){
        
      }
      
      std::tuple<std::vector<Image>,VkResult> getSwapchainImagesKHR(SwapchainKHR swapchain){
        
      }
      
      VkResult importFenceWin32HandleKHR(const VkImportFenceWin32HandleInfoKHR* importFenceWin32HandleInfo){
        
      }
      
      VkResult debugMarkerSetObjectNameEXT(const VkDebugMarkerObjectNameInfoEXT* nameInfo){
        
      }
      
      std::tuple<VkRefreshCycleDurationGOOGLE*,VkResult> getRefreshCycleDurationGOOGLE(SwapchainKHR swapchain){
        
      }
      
      VkResult bindImageMemory2KHR(std::vector<VkBindImageMemoryInfoKHR> bindInfos){
        
      }
      
      VkResult bindBufferMemory2KHR(std::vector<VkBindBufferMemoryInfoKHR> bindInfos){
        
      }
      
      VkResult importSemaphoreWin32HandleKHR(const VkImportSemaphoreWin32HandleInfoKHR* importSemaphoreWin32HandleInfo){
        
      }
      
      std::tuple<int*,VkResult> getSemaphoreFdKHR(const VkSemaphoreGetFdInfoKHR* getFdInfo){
        
      }
      
      std::tuple<VkMemoryWin32HandlePropertiesKHR*,VkResult> getMemoryWin32HandlePropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,HANDLE handle){
        
      }
      
      std::tuple<DescriptorUpdateTemplateKHR,VkResult> createDescriptorUpdateTemplateKHR(const VkDescriptorUpdateTemplateCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult flushMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        
      }
      
      std::tuple<DescriptorPool,VkResult> createDescriptorPool(const VkDescriptorPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult resetFences(std::vector<Fence> fences){
        
      }
      
      std::vector<VkSparseImageMemoryRequirements2KHR> getImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2KHR* info){
        
      }
      
      std::tuple<Image,VkResult> createImage(const VkImageCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<ShaderModule,VkResult> createShaderModule(const VkShaderModuleCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<uint32_t*,VkResult> acquireNextImage2KHX(const VkAcquireNextImageInfoKHX* acquireInfo){
        
      }
      
      void destroyDevice(const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult getSwapchainStatusKHR(SwapchainKHR swapchain){
        
      }
      
      std::tuple<Buffer,VkResult> createBuffer(const VkBufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult importSemaphoreFdKHR(const VkImportSemaphoreFdInfoKHR* importSemaphoreFdInfo){
        
      }
      
      std::tuple<Event,VkResult> createEvent(const VkEventCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult displayPowerControlEXT(DisplayKHR display,const VkDisplayPowerInfoEXT* displayPowerInfo){
        
      }
      
      std::tuple<IndirectCommandsLayoutNVX,VkResult> createIndirectCommandsLayoutNVX(const VkIndirectCommandsLayoutCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<std::vector<VkPastPresentationTimingGOOGLE>,VkResult> getPastPresentationTimingGOOGLE(SwapchainKHR swapchain){
        
      }
      
      std::tuple<Fence,VkResult> createFence(const VkFenceCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<ImageView,VkResult> createImageView(const VkImageViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<VkDeviceGroupPresentModeFlagsKHX*,VkResult> getDeviceGroupSurfacePresentModesKHX(SurfaceKHR surface){
        
      }
      
      std::tuple<DescriptorSetLayout,VkResult> createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<QueryPool,VkResult> createQueryPool(const VkQueryPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<RenderPass,VkResult> createRenderPass(const VkRenderPassCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult deviceWaitIdle(){
        
      }
      
      std::tuple<std::vector<CommandBuffer>,VkResult> allocateCommandBuffers(const VkCommandBufferAllocateInfo* allocateInfo){
        
      }
      
      Queue getDeviceQueue(uint32_t queueFamilyIndex,uint32_t queueIndex){
        
      }
      
      std::tuple<Fence,VkResult> registerDisplayEventEXT(DisplayKHR display,const VkDisplayEventInfoEXT* displayEventInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<PipelineLayout,VkResult> createPipelineLayout(const VkPipelineLayoutCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<Framebuffer,VkResult> createFramebuffer(const VkFramebufferCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<int*,VkResult> getFenceFdKHR(const VkFenceGetFdInfoKHR* getFdInfo){
        
      }
      
      VkPeerMemoryFeatureFlagsKHX* getDeviceGroupPeerMemoryFeaturesKHX(uint32_t heapIndex,uint32_t localDeviceIndex,uint32_t remoteDeviceIndex){
        
      }
      
      VkMemoryRequirements2KHR* getImageMemoryRequirements2KHR(const VkImageMemoryRequirementsInfo2KHR* info){
        
      }
      
      std::tuple<BufferView,VkResult> createBufferView(const VkBufferViewCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<Semaphore,VkResult> createSemaphore(const VkSemaphoreCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<ObjectTableNVX,VkResult> createObjectTableNVX(const VkObjectTableCreateInfoNVX* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult importFenceFdKHR(const VkImportFenceFdInfoKHR* importFenceFdInfo){
        
      }
      
      std::tuple<std::vector<SwapchainKHR>,VkResult> createSharedSwapchainsKHR(std::vector<VkSwapchainCreateInfoKHR> createInfos,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<CommandPool,VkResult> createCommandPool(const VkCommandPoolCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<HANDLE*,VkResult> getSemaphoreWin32HandleKHR(const VkSemaphoreGetWin32HandleInfoKHR* getWin32HandleInfo){
        
      }
      
      std::tuple<HANDLE*,VkResult> getFenceWin32HandleKHR(const VkFenceGetWin32HandleInfoKHR* getWin32HandleInfo){
        
      }
      
      VkResult waitForFences(std::vector<Fence> fences,bool waitAll,uint64_t timeout){
        
      }
      
      std::tuple<SwapchainKHR,VkResult> createSwapchainKHR(const VkSwapchainCreateInfoKHR* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<VkMemoryFdPropertiesKHR*,VkResult> getMemoryFdPropertiesKHR(VkExternalMemoryHandleTypeFlagBitsKHR handleType,int fd){
        
      }
      
      std::tuple<ValidationCacheEXT,VkResult> createValidationCacheEXT(const VkValidationCacheCreateInfoEXT* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<VkDeviceGroupPresentCapabilitiesKHX*,VkResult> getDeviceGroupPresentCapabilitiesKHX(){
        
      }
      
      void destroySwapchainKHR(SwapchainKHR swapchain,const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult invalidateMappedMemoryRanges(std::vector<VkMappedMemoryRange> memoryRanges){
        
      }
      
      std::tuple<uint64_t*,VkResult> getSwapchainCounterEXT(SwapchainKHR swapchain,VkSurfaceCounterFlagBitsEXT counter){
        
      }
      
      std::tuple<Sampler,VkResult> createSampler(const VkSamplerCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<PipelineCache,VkResult> createPipelineCache(const VkPipelineCacheCreateInfo* createInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<int*,VkResult> getMemoryFdKHR(const VkMemoryGetFdInfoKHR* getFdInfo){
        
      }
      
      VkResult debugMarkerSetObjectTagEXT(const VkDebugMarkerObjectTagInfoEXT* tagInfo){
        
      }
      
      PFN_vkVoidFunction getDeviceProcAddr(std::string name){
        
      }
      
      std::tuple<HANDLE*,VkResult> getMemoryWin32HandleKHR(const VkMemoryGetWin32HandleInfoKHR* getWin32HandleInfo){
        
      }
      
      std::tuple<std::vector<DescriptorSet>,VkResult> allocateDescriptorSets(const VkDescriptorSetAllocateInfo* allocateInfo){
        
      }
      
      std::tuple<DeviceMemory,VkResult> allocateMemory(const VkMemoryAllocateInfo* allocateInfo,const VkAllocationCallbacks* allocator){
        
      }
      
      VkMemoryRequirements2KHR* getBufferMemoryRequirements2KHR(const VkBufferMemoryRequirementsInfo2KHR* info){
        
      }
      
      std::tuple<Fence,VkResult> registerDeviceEventEXT(const VkDeviceEventInfoEXT* deviceEventInfo,const VkAllocationCallbacks* allocator){
        
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
      
      std::tuple<std::vector<Image>,VkResult> getSwapchainImagesKHR(Device device){
        
      }
      
      std::tuple<VkRefreshCycleDurationGOOGLE*,VkResult> getRefreshCycleDurationGOOGLE(Device device){
        
      }
      
      VkResult getSwapchainStatusKHR(Device device){
        
      }
      
      std::tuple<uint32_t*,VkResult> acquireNextImageKHR(Device device,uint64_t timeout,Semaphore semaphore,Fence fence){
        
      }
      
      std::tuple<std::vector<VkPastPresentationTimingGOOGLE>,VkResult> getPastPresentationTimingGOOGLE(Device device){
        
      }
      
      void destroySwapchainKHR(Device device,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<uint64_t*,VkResult> getSwapchainCounterEXT(Device device,VkSurfaceCounterFlagBitsEXT counter){
        
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
      
      std::tuple<std::vector<Pipeline>,VkResult> createComputePipelines(std::vector<VkComputePipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator){
        
      }
      
      std::tuple<std::vector<Pipeline>,VkResult> createGraphicsPipelines(std::vector<VkGraphicsPipelineCreateInfo> createInfos,const VkAllocationCallbacks* allocator){
        
      }
      
      void destroyPipelineCache(const VkAllocationCallbacks* allocator){
        
      }
      
      VkResult mergePipelineCaches(std::vector<PipelineCache> srcCaches){
        
      }
      
      std::tuple<std::vector<void>,VkResult> getPipelineCacheData(){
        
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
      
      std::tuple<void**,VkResult> mapMemory(std::size_t offset,std::size_t size,VkMemoryMapFlags flags){
        
      }
      
      void unmapMemory(){
        
      }
      
      std::tuple<HANDLE*,VkResult> getMemoryWin32HandleNV(VkExternalMemoryHandleTypeFlagsNV handleType){
        
      }
      
      VkResult bindImageMemory(Image image,std::size_t memoryOffset){
        
      }
      
      std::size_t* getDeviceMemoryCommitment(){
        
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
      
      std::tuple<uint32_t*,VkResult> acquireNextImageKHR(SwapchainKHR swapchain,uint64_t timeout,Semaphore semaphore){
        
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
      
      std::tuple<std::vector<void>,VkResult> getQueryPoolResults(uint32_t firstQuery,uint32_t queryCount,std::size_t stride,VkQueryResultFlags flags){
        
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
        
      }
      
      void cmdClearDepthStencilImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearDepthStencilValue* depthStencil,std::vector<VkImageSubresourceRange> ranges){
        
      }
      
      void cmdClearColorImage(CommandBuffer commandBuffer,VkImageLayout imageLayout,const VkClearColorValue* color,std::vector<VkImageSubresourceRange> ranges){
        
      }
      
      VkMemoryRequirements* getImageMemoryRequirements(){
        
      }
    private:
      VkImage image;
      Device device;
  }