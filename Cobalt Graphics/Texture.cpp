#include "Texture.h"
#include "pch.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint Cobalt::Texture::LoadTex(const char* filePath, FilteringMode ft)
{
	stbi_set_flip_vertically_on_load(true);
	// Initializes the texture into memory(fills it with information needed for a texture)
	glGenTextures(1, &texture);
	// Binds the texture so it can be shown
	glBindTexture(GL_TEXTURE_2D, texture);
	// Sets the texture wrapping and filtering options for the current texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	if (ft == Nearest) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
	else if (ft == Linear) {
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	// For textures with an alpha background
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.5f);

	// Load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);
	if (data) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else 
	{
		std::cout << "Failed Texture Loading" << std::endl;
	}
	
	// Releasing the data
	stbi_image_free(data);

	return texture;
}

void Cobalt::Texture::Bind(unsigned int tex)
{
	glBindTexture(GL_TEXTURE_2D, tex);
}

void Cobalt::Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
