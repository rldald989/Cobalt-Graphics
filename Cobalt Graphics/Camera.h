#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GameObject.h"

#include <vector>

namespace Cobalt 
{
	struct Vec2 
	{
		int x;
		int y;
	};

	class Camera
	{
	public:
		// Camera constructor
		Camera(GLFWwindow* window, Vec2 size);

		// Camera destructor
		~Camera();

		// Sets the matrix for one object
		void SetMatrix(GameObject* object);

		//Sets the matrix for multiple objects
		void SetMatrix(std::vector<GameObject*> objects, Vec2 size);

		void Move(float x, float y);

		void SetPosition(float x, float y);

		void Update();

		void Controls2D(GLFWwindow* window, float speed);

		float GetDT();

	private:

		// Stores the aspect ratio for calculating the transformation for the matrix that removes stretching on objects
		float m_aspectRatio;

		std::vector<GameObject*> m_objs;

		glm::mat4 m_cam;
		glm::vec3 m_camPos;
	};
}