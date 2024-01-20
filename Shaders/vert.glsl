#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec2 aColor;
layout (location = 2) in vec2 aTexcoord;

out vec4 vertexColor; // specify a color output to the fragment shader

uniform mat4 transform;
uniform mat4 ortho;
uniform mat4 cam;
uniform vec2 tex_scale;

out vec2 tex_coord;

void main()
{
    gl_Position = cam * transform * ortho * vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
    tex_coord = aTexcoord * tex_scale;
}
