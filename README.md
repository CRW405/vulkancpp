
# Vulkan CPP

Learning vulkan + cpp

## Notes

### Bookmark

- [Video](www.youtube.com/watch?v=ecMcXW6MSYU&list=PL8327DO66nu9qYVKLDmdLW_84-yE4auCR&index=5)
- [Guide](https://vulkan-tutorial.com/Drawing_a_triangle/Setup/Validation_layers)

### Engine Code

- See [Vulkan_Trianle_Tutorial/Setup/Instance](https://vulkan-tutorial.com/Drawing_a_triangle/Setup/Instance)
- Through [Vulkan_Trianle_Tutorial/Setup/Logical_Devices_and_Queues](https://vulkan-tutorial.com/Drawing_a_triangle/Setup/Logical_device_and_queues)

### (Simplified) Graphics Pipeline

- Shaders are programs that run on the GPU. They are written in GLSL or HLSL, C like languages. They are compiled into SPIR-V and then run on the GPU.
- The non shader parts of the pipeline are handled by the GPU driver and are not programmable. They are fixed function but can be configured.

#### Vertex / Index Buffer // Input

- Contain input data such point positons, colors, normals, texture data, etc.
- Basic example could be a list of points. (x_1, y_1), (x_2, y_2), ...
- Think OBJ files.

#### Input Assembler

- Takes our input's vertices and assembles them into primitives (usually a triangle).

#### Vertex Shader

- Runs once per vertex.
- Performs transformations on our vertices. Ex: 3d to 2d projection.
- Can operate on multiple spaces such as world space, model space, view space, clip space.
- Can pass other data such as color or texture data.

#### Rasterization

- Turns primitives into fragments.
- A fragment is used to represent and create a pixel. Doesnt necessarily mean it will be a pixel, but it is a candidate for one.
- Other operations can take place in order to figure out what frasgments turn into what pixels.
- Like coloring in a triangle.

#### Fragment Shader

- Runs once per fragment.
- Takes things like lighting, textures, etc and figures out what color those pixels should be.
- This is where things become pretty.

#### Color Blending

- Self explanatory.
- Think transparency.

#### Frame Buffer / Image

- In actual Vulkan, a frame buffer and image are two seperate things.
- Turn our final fragments into pixels and (possibly) display them.
