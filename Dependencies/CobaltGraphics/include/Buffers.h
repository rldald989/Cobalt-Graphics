#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Cobalt 
{
	class VAO
	{
	public:
		VAO();
		~VAO();

		void Bind() const;
		void Unbind() const;

	private:
		unsigned int m_ID;
	};

	class VBO
	{
	public:
		VBO();
		~VBO();

		void Bind() const;
		void Unbind() const;

	private:
		unsigned int m_ID;
	};

	class IBO
	{
	public:
		IBO();
		~IBO();

		void Bind() const;
		void Unbind() const;

	private:
		unsigned int m_ID;
	};
}