#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"
#include "Buffers.h"

struct Vert {
	glm::vec3 positions;
	glm::vec3 color;
	glm::vec2 tex_coords;
};

namespace Cobalt
{
	class GameObject
	{
	public:
		// Constructor/Destructor
		GameObject(std::string name, const char* texFilePath, FilteringMode ft);
		~GameObject();

		// Updates the object
		void Update();

		// Renders the object
		void Render();

		// Moves the object
		void Move(float x, float y);

		// Rotates the object
		void Rotate(float amount, glm::vec3 rot);

		// Scales the object
		void Scale(float x, float y);

		/// Setter Functions
		void SetBounds(glm::vec2 value);

		void SetX(float amount);

		void SetY(float amount);

		void SetTextureScale(float x, float y);

		/// Getter Functions

		inline std::string GetName() { return m_name; }

		// Gets the shader
		inline Shader* GetShader();

		glm::vec3 GetPosition();

		glm::vec3 GetBounds();

		friend class Camera;

	private:
		// Shader (Important)
		Shader* m_shader;

		// Buffers (Important)
		VAO m_vao;
		VBO m_vbo;
		IBO m_ibo;

		//Texture (Medium-Importance)
		Texture m_texture;
		unsigned int* m_texID;

		glm::mat4 m_projection;
		glm::mat4 m_transform;
		glm::vec3 m_bounds;
		glm::vec2 tex_scale;

		std::string m_name;
	};
}