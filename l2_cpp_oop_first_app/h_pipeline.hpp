#pragma once

#include "h_device.hpp"

#include <string>
#include <vector>

namespace h {

struct PipelineConfigInfo {
};

class Pipeline {
  public:
	Pipeline(
	    Device &device,
	    const std::string &vertPath,
	    const std::string &fragPath,
	    const PipelineConfigInfo &configInfo);

	~Pipeline();

	Pipeline(const Pipeline &) = delete;
	void operator=(const Pipeline &) = delete;

	static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

  private:
	static std::vector<char> readFile(const std::string &path);

	void createGraphicsPipeline(
	    const std::string &vertPath,
	    const std::string &fragPath,
	    const PipelineConfigInfo &configInfo);

	void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

	Device &device; // reference to the device object, could be unsafe if the device is destroyed before the pipeline
	VkPipeline graphicsPipeline = VK_NULL_HANDLE;
	VkShaderModule vertShaderModule = VK_NULL_HANDLE;
	VkShaderModule fragShaderModule = VK_NULL_HANDLE;
};
} // namespace h
