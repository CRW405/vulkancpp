CXX      = g++
GLSLC    = glslc

CXXFLAGS = -Wall -Wextra -Wpedantic -Werror
LDLIBS   = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

APP = HelloTriangle

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)

VERT_SHADERS = $(wildcard shaders/*.vert)
FRAG_SHADERS = $(wildcard shaders/*.frag)

VERT_SPV = $(VERT_SHADERS:.vert=.vert.spv)
FRAG_SPV = $(FRAG_SHADERS:.frag=.frag.spv)

SHADER_OUTPUTS = $(VERT_SPV) $(FRAG_SPV)


.PHONY: all run compile-shaders clean test

all: $(APP)


$(APP): $(SOURCES) $(HEADERS) $(SHADER_OUTPUTS)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES) $(LDLIBS)


compile-shaders: $(SHADER_OUTPUTS)


shaders/%.vert.spv: shaders/%.vert
	$(GLSLC) $< -o $@


shaders/%.frag.spv: shaders/%.frag
	$(GLSLC) $< -o $@


run: $(APP)
	./$(APP)


clean:
	rm -f $(APP) $(SHADER_OUTPUTS)


test:
	$(MAKE) clean
	$(MAKE) run
