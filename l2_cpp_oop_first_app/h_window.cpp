#include "h_window.hpp"
#include <stdexcept>

h::Window::Window(int w, int h, std::string name) : width(w), height(h), name(name) {
	initWindow();
}

void h::Window::initWindow() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);               // we don't want OpenGL context
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);                 // we have to handle resizing ourselves for Vulkan
	glfwWindowHintString(GLFW_WAYLAND_APP_ID, "make-me-float"); // for hyprland window rule

	window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
}

h::Window::~Window() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void h::Window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
	if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create window surface");
	}
}
