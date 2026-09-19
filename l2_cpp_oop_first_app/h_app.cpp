#include "h_app.hpp"
#include "h_window.hpp"

namespace h {
void App::run() {
	while (!window.shouldClose()) {
		glfwPollEvents();
	}
}
} // namespace h
