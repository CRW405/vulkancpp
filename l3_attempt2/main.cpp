#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

#include <vulkan/vulkan.h>

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

GLFWwindow *window;

void initWindow(int width, int height, std::string name) {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);               // we don't want OpenGL context
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);                 // we have to handle resizing ourselves for Vulkan
	glfwWindowHintString(GLFW_WAYLAND_APP_ID, "make-me-float"); // for hyprland window rule

	window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
}

VkInstance instance;

void initVulkan() {
	// set up app info
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	// set up instance
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	// set up vulkan to use glfw extensions
	uint32_t glfwExtensionCount = 0;
	const char **glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
	if (result != VK_SUCCESS)
		throw std::runtime_error("Vulkan Error! - Failed to create Vulkan Instance.");
}

void mainLoop() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
}

void cleanup() {
	// vulkan
	vkDestroyInstance(instance, nullptr);
	// glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}

int main() {
	initWindow(500, 500, "Hello Triangle");
	initVulkan();
	mainLoop();
	cleanup();

	return EXIT_SUCCESS;
}
