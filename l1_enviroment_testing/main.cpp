#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

#include <iostream>

int main() {
	glfwInit();

	// glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // glfw assumes OpenGL so we tell it to not use any client API // disabled for the wayland workaround

	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE); // this does not actually work for hyprland but it may on other platforms

	// hyprland window rule floating workaround
	glfwWindowHintString(GLFW_WAYLAND_APP_ID, "make-me-float"); // we can use this for a window rule;

	GLFWwindow *window = glfwCreateWindow(200, 200, "Hello GLFW", nullptr, nullptr);

	// test vulkan
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::cout << "Available Vulkan extensions: " << extensionCount << std::endl;

	// test glm
	glm::mat4 matrix;
	glm::vec4 vector;
	auto test = matrix * vector;
	(void)test;

	// Wayland wants the window to (try to) display something before it allows the window to exist so swap some empty openGL buffers
	glfwMakeContextCurrent(window);
	glfwSwapBuffers(window);

	// main glfw loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
