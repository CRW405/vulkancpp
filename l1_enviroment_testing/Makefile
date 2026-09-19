LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
CFLAGS = -Wall -Wextra -Wpedantic -Werror

VulkanTest: main.cpp
	g++ $(CFLAGS) main.cpp -o VulkanTest $(LDFLAGS)

.PHONY: run clean

run: VulkanTest
	./VulkanTest

clean:
	rm -f VulkanTest

test:
	make clean
	make run
