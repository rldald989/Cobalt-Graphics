#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"
#include "Buffers.h"
#include <vector>

// Avery why did you make me do this

// Contains all of the information needed to render an object
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

		// Sets the X position of the object
		void SetX(float amount);

		// Sets the Y position of the object
		void SetY(float amount);

		void SetTextureScale(float x, float y);

		/// Getter Functions

		// Gets the name of the object
		inline std::string GetName() { return m_name; }

		// Gets the shader
		inline Shader* GetShader();

		// Gets the position of the object
		glm::vec3 GetPosition();

		// Gets the bounds of the object
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

	class ObjectCollection
	{
	public:
		// Initializes the Object Collection
		ObjectCollection(const char* collection_name);
		~ObjectCollection();

		// Adds a game object to the object collection
		void Add(GameObject* object);

		// Returns the size of the Object Collection
		int Size();

		// Gets an object by name search
		GameObject* GetObject(const char* name);

		// Gets an object by index
		GameObject* GetObject(int index);

		// Removes an object by name search
		void RemoveObject(const char* name);

		// Removes an object by index
		void RemoveObject(int index);

		// Updates all of the objects
		void Update();

		// Renders all of the objects
		void Render();

		friend class Camera;

	private:
		std::vector<GameObject*> m_objects;
		const char* m_collection_name;
	};
}