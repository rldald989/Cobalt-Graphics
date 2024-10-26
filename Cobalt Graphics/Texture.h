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
	enum ActiveTextureSlot
	{
		AT_ONE = 1,
		AT_TWO = 2,
		AT_THREE = 3,
		AT_FOUR = 4,
		AT_FIVE = 5,
		AT_SIX = 6,
		AT_SEVEN = 7,
		AT_EIGHT = 8,
		AT_NINE = 9,
		AT_TEN = 10,
		AT_ELEVEN = 11,
		AT_TWELVE = 12,
		AT_THIRTEEN = 13,
		AT_FOURTEEN = 14,
		AT_FIFTEEN = 15
	};

	struct Texture 
	{
		// Is returned, do not use for actual texture 
		unsigned int texture;

		GLuint LoadTex(const char* filePath, FilteringMode ft);

		void Bind(unsigned int tex);
		void Unbind();
	};

	struct DynamicTexture : Texture 
	{
		// Is not returned, use for actual texture
		unsigned int* texID;

		ActiveTextureSlot activeTextureSlot;

		const char* name;
	};
}
