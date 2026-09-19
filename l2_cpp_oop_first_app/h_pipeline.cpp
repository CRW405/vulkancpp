#include "h_pipeline.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<char> h::Pipeline::readFile(const std::string &path) {
	// Open the file in binary mode and move the cursor to the end of the file
	std::ifstream file(path, std::ios::ate | std::ios::binary);

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file: " + path);
	}

	size_t fileSize = static_cast<size_t>(file.tellg()); // Get the size of the file by checking the current position of the cursor (which we sent to the end of the file)
	std::vector<char> buffer(fileSize);

	file.seekg(0);                      // Move the cursor back to the beginning of the file
	file.read(buffer.data(), fileSize); // Read the file contents into the buffer

	file.close();
	return buffer;
}

void h::Pipeline::createGraphicsPipeline(
    const std::string &vertPath,
    const std::string &fragPath,
    [[maybe_unused]] const PipelineConfigInfo &configInfo) {

	std::vector<char> vertCode = readFile(vertPath);
	std::vector<char> fragCode = readFile(fragPath);

	// placeholder, just print the size of the shader code for now
	std::cout << "Vertex shader code size: " << vertCode.size() << " bytes" << std::endl;
	std::cout << "Fragment shader code size: " << fragCode.size() << " bytes" << std::endl;
}

void h::Pipeline::createShaderModule(
    const std::vector<char> &code,
    VkShaderModule *shaderModule) {
	VkShaderModuleCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	createInfo.codeSize = code.size();
	createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

	if (vkCreateShaderModule(device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create shader module");
	}
}

 h::PipelineConfigInfo h::Pipeline::defaultPipelineConfigInfo(
    [[maybe_unused]] uint32_t width,
    [[maybe_unused]] uint32_t height) {
	PipelineConfigInfo configInfo{};
	return configInfo;
}

h::Pipeline::Pipeline(
    Device &device,
    const std::string &vertPath,
    const std::string &fragPath,
    const PipelineConfigInfo &configInfo) : device(device) {

	createGraphicsPipeline(vertPath, fragPath, configInfo);
}

h::Pipeline::~Pipeline() {
	if (graphicsPipeline != VK_NULL_HANDLE) {
		vkDestroyPipeline(device.device(), graphicsPipeline, nullptr);
	}
	if (vertShaderModule != VK_NULL_HANDLE) {
		vkDestroyShaderModule(device.device(), vertShaderModule, nullptr);
	}
	if (fragShaderModule != VK_NULL_HANDLE) {
		vkDestroyShaderModule(device.device(), fragShaderModule, nullptr);
	}
}
