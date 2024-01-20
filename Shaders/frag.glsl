#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  

in vec2 tex_coord;
uniform sampler2D texture1;

void main()
{
    vec4 tex = texture2D(texture1, tex_coord);
    FragColor = tex;
} 