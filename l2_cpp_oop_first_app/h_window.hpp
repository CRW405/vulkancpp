#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace h {
class Window {
  public:
	Window(int w, int h, std::string name);
	~Window();

	bool shouldClose() { return glfwWindowShouldClose(window); }

	// disable copy and move constructors and assignment operators to prevent multiple instances of the window
	Window(const Window &) = delete;
	Window &operator=(const Window &) = delete;

	void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

  private:
	void initWindow();

	int width;
	int height;
	std::string name;
	GLFWwindow *window;
};
} // namespace h
