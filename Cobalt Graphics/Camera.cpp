#include "Camera.h"
#include "pch.h"

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

Cobalt::Camera::Camera(GLFWwindow* window, Vec2 size) : m_cam(1.0f), m_camPos(glm::vec3(0.f, 0.f, 0.0f))
{
	// Gets the framebuffer size from the window and size of the window
	glfwGetFramebufferSize(window, &size.x, &size.y);
	
	// Calculates the aspect ratio of the window, needed for part of the transformation that keeps an object from stretching
	m_aspectRatio = static_cast<float>(size.x) / static_cast<float>(size.y);
}

Cobalt::Camera::~Camera()
{
	// Does nothing
}

void Cobalt::Camera::SetMatrix(GameObject* object)
{
	// The matrix/transformation needed to remove object stretching
	glm::mat4 projection = glm::ortho(-m_aspectRatio, m_aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);

	//Sets the matrix transformations for one object
	object->m_shader->SetMat4("ortho", projection);
}

void Cobalt::Camera::SetMatrix(ObjectCollection* objects, Vec2 size)
{
	float aspectRatio = static_cast<float>(size.x) / static_cast<float>(size.y);
	// The matrix/transformation needed to remove object stretching
	glm::mat4 projection = glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);

	// Sets the matrix transformations for multiple objects
	for (int i = 0; i < objects->m_objects.size(); i++)
	{
		objects->m_objects[i]->m_shader->SetMat4("ortho", projection);
		objects->m_objects[i]->m_shader->SetMat4("cam", m_cam);
	}
}

void Cobalt::Camera::Move(float x, float y)
{
	m_cam = glm::translate(m_cam, glm::vec3(x, y, 0.0f));
}

void Cobalt::Camera::SetPosition(float x, float y)
{
	m_cam[3][0] = x;
	m_cam[3][1] = y;
}

glm::vec2 Cobalt::Camera::GetPosition()
{
	return glm::vec2(m_cam[3][0], m_cam[3][1]);
}

void Cobalt::Camera::Update()
{
	// Updates the delta time
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

}

void Cobalt::Camera::Controls2D(GLFWwindow* window, float speed)
{
	// Sets the y position if you press w or s
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) 
	{
		m_camPos.y = -speed * deltaTime;
	}
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_camPos.y = speed * deltaTime;
	}
	else
	{
		m_camPos.y = 0;
	}

	// Sets the x position if you press a or d
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_camPos.x = -speed * deltaTime;
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_camPos.x = speed * deltaTime;
	}
	else
	{
		m_camPos.x = 0;
	}

	// Moves the "Camera"
	m_cam = glm::translate(m_cam, glm::vec3(m_camPos.x, m_camPos.y, 0.0f));
}

float Cobalt::Camera::GetDT()
{
	return deltaTime;
}
