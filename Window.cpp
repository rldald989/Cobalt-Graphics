#include "Window.h"


Window::Window(const char* title, int x, int y)
	:  m_window(glfwCreateWindow(x, y, title, NULL, NULL))
{
	m_size = { x, y };

	if (!m_window) {
		glfwTerminate();
		std::cout << "Failed to Create Window" << std::endl;
	}
	else {
		
	}

	glfwMakeContextCurrent(m_window);
	
}

Window::~Window() { }

Vec2 Window::GetSize()
{
	return m_size;
}

GLFWwindow* Window::GetGLFWwindow() {
	return m_window;
}