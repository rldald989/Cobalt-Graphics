#include "Buffers.h"
#include "pch.h"

///VAO

//Gens the vertex arrays
Cobalt::VAO::VAO()
{
	glGenVertexArrays(1, &m_ID);
}

//Deletes the vertex arrays
Cobalt::VAO::~VAO()
{
	glDeleteVertexArrays(1, &m_ID);
}

//Binds the vertex arrays
void Cobalt::VAO::Bind() const
{
	glBindVertexArray(m_ID);
}

//Unbinds the vertex arrays
void Cobalt::VAO::Unbind() const
{
	glBindVertexArray(0);
}

/// VBO

//Gens the buffers
Cobalt::VBO::VBO()
{
	glGenBuffers(1, &m_ID);
}

//Deletes the buffers
Cobalt::VBO::~VBO()
{
	glDeleteBuffers(1, &m_ID);
}

//Binds the buffers
void Cobalt::VBO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

//Unbinds the buffers
void Cobalt::VBO::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/// IBO

//Gens the buffers
Cobalt::IBO::IBO()
{
	glGenBuffers(1, &m_ID);
}

//Deletes the buffers
Cobalt::IBO::~IBO()
{
	glDeleteBuffers(1, &m_ID);
}

//Binds the buffers
void Cobalt::IBO::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

//Unbinds the buffers
void Cobalt::IBO::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
