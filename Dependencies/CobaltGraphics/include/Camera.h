#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GameObject.h"

#include <vector>

// Avery why did you make me do this

namespace Cobalt 
{
	// Vec2 for the size of the app
	struct Vec2 
	{
		int x;
		int y;
	};

	class Camera
	{
	public:
		Camera(GLFWwindow* window, Vec2 size);

		~Camera();

		// Sets the matrix for one object so the object can be rendered to the screen properly
		void SetMatrix(GameObject* object);

		//Sets the matrix for multiple objects so the objects can be rendered to the screen properly
		void SetMatrix(ObjectCollection* objects, Vec2 size);

		// Moves the camera on the x and y axis
		void Move(float x, float y);

		// Sets the position of the camera on the x and y axis (different from the Move impl)
		void SetPosition(float x, float y);

		glm::vec2 GetPosition();
		
		void Update();

		// Allows you to use WASD to control the camera
		void Controls2D(GLFWwindow* window, float speed);
		
		// Gets the Delta Time
		float GetDT();

	private:

		// Stores the aspect ratio for calculating the transformation for the matrix that removes stretching on objects
		float m_aspectRatio;

		// The transform for the camera
		glm::mat4 m_cam;

		// The position of the camera
		glm::vec3 m_camPos;
	};
}