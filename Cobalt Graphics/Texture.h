#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Buffers.h"
#include "Shader.h"

// Lets you set the filtering mode for the texture
enum FilteringMode
{
	Linear = GL_LINEAR,
	Nearest = GL_NEAREST
};

namespace Cobalt
{
	struct Texture 
	{
		unsigned int texture;

		GLuint LoadTex(const char* filePath, FilteringMode ft);

		void Bind(unsigned int tex);
		void Unbind();
	};
}
