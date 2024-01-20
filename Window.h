#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

struct Vec2 {
    int x;
    int y;
};

class Window
{
public:
    Window(const char* title, int x, int y);
    ~Window();

    Vec2 GetSize();

    //virtual void OnUpdate() = 0;
    //virtual unsigned int GetWidth() const = 0;
    //virtual unsigned int GetHeight() const = 0;

    GLFWwindow* GetGLFWwindow();

private:
    GLFWwindow* m_window;
    Vec2 m_size;
};