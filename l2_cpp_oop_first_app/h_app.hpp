#pragma once

#include "h_device.hpp"
#include "h_pipeline.hpp"
#include "h_window.hpp"

namespace h {
class App {
  public:
	static constexpr int width = 500;
	static constexpr int height = 500;

	void run();

  private:
	Window window{ width, height, "Hello Vulkan" };
	Device device{ window };
	Pipeline pipeline{ device,
		               "./shaders/simple_shader.vert.spv",
		               "./shaders/simple_shader.frag.spv",
		               Pipeline::defaultPipelineConfigInfo(width, height) };
};
} // namespace h
