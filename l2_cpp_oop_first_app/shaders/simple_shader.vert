#version 450

// triangle
vec2 pos[3] = vec2[](
    vec2(0, .5),
    vec2(-.5, -.5),
    vec2(.5, -.5)
);
// in a real shader, you would get your vertices / primitives from a buffer or other source

void main() {
    // gl_VertexIndex is a built-in variable that gives you the index of the vertex being processed
    // x,y,z,and w which in future stages can be used to divide ther other companents by w to get normalized device coordinates for perspective projection
    gl_Position = vec4(pos[gl_VertexIndex], 0, 1);
}
