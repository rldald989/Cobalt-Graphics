#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Cobalt 
{
	class VAO
	{
	public:
		// Initializes the VAO (Vertex Attribute)
		VAO();
		~VAO();

		// Binds the VAO
		void Bind() const;

		// Unbinds the VAO
		void Unbind() const;

	private:
		unsigned int m_ID;
	};

	class VBO
	{
	public:
		// Initializes the VBO (Vertex Buffer)
		VBO();
		~VBO();

		// Binds the VBO
		void Bind() const;

		// Unbinds the VBO
		void Unbind() const;

	private:
		unsigned int m_ID;
	};

	class IBO
	{
	public:
		// Initializes the IBO (Index Buffer)
		IBO();
		~IBO();

		// Binds the IBO
		void Bind() const;

		// Unbinds the IBO
		void Unbind() const;

	private:
		unsigned int m_ID;
	};
}