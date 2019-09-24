#pragma once

#include "vulkan/VulkanDef.h"
#include "vulkan/Instance.h"
#include "GSH_VulkanContext.h"
#include "GSH_VulkanPresent.h"
#include <vector>
#include "../GSHandler.h"
#include "../GsCachedArea.h"
#include "../GsTextureCache.h"

class CGSH_Vulkan : public CGSHandler
{
public:
	CGSH_Vulkan();
	virtual ~CGSH_Vulkan();

	virtual void LoadState(Framework::CZipArchiveReader&) override;

	void ProcessHostToLocalTransfer() override;
	void ProcessLocalToHostTransfer() override;
	void ProcessLocalToLocalTransfer() override;
	void ProcessClutTransfer(uint32, uint32) override;
	void ReadFramebuffer(uint32, uint32, void*) override;

	Framework::CBitmap GetScreenshot() override;

protected:
	void InitializeImpl() override;
	void ReleaseImpl() override;
	void ResetImpl() override;
	void NotifyPreferencesChangedImpl() override;
	void FlipImpl() override;

	Framework::Vulkan::CInstance m_instance;
	GSH_Vulkan::ContextPtr m_context;

private:
	virtual void PresentBackbuffer() = 0;

	std::vector<VkPhysicalDevice> GetPhysicalDevices();
	std::vector<uint32_t> GetRenderQueueFamilies(VkPhysicalDevice);
	std::vector<VkSurfaceFormatKHR> GetDeviceSurfaceFormats(VkPhysicalDevice);

	void CreateDevice(VkPhysicalDevice);
	void CreateDescriptorPool();

	GSH_Vulkan::PresentPtr m_present;
};
