#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Buffers.h"
#include "Shader.h"

// Avery why did you make me do this

// Lets you set the filtering mode for teh texture
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

		// Loads the texture through a file path and sets the filtering mode of the texture
		GLuint LoadTex(const char* filePath, FilteringMode ft);

		// Binds the texture
		void Bind(unsigned int tex);

		// Unbinds the texture
		void Unbind();
	};
}
