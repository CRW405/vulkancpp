#version 450

// output variable
// can output to multiple locations, but just outputting to location 0 for now
layout(location = 0) out vec4 outColor;

void main() {
    outColor = vec4(1.0, 0.0, 1.0, 1.0); // rgba
}
