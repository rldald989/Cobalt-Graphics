#include "Shader.h"
#include "pch.h"

Cobalt::Shader::Shader(const char* vFile, const char* fFile)
{
	// The data for the vertex and fragment shaders
	unsigned int vShader = 0;
	unsigned int fShader = 0;

	// Processes the shaders (the ones that were inputed in the vFile and fFile parameters)
	vShader = Process(GL_VERTEX_SHADER, (char*)vFile);
	fShader = Process(GL_FRAGMENT_SHADER, (char*)fFile);

	// Links the shader
	Link(vShader, fShader);
}

Cobalt::Shader::~Shader()
{
}

void Cobalt::Shader::Use()
{
	// Uses the shader program
	glUseProgram(m_ID);
}

void Cobalt::Shader::Unuse()
{
	// Unuses the shader program
	glUseProgram(0);
}

void Cobalt::Shader::Delete()
{
	// Deletes the shader program
	glDeleteProgram(m_ID);
}

unsigned int Cobalt::Shader::GetProgram()
{
	// Gets the shader program
	return m_ID;
}

void Cobalt::Shader::Draw(unsigned int nrOfIndices, unsigned int* indices)
{
	// Renders the object (one part of rendering an object)
	glDrawElements(GL_TRIANGLES, nrOfIndices, GL_UNSIGNED_INT, indices);
}

// Sets an integer in the shader
void Cobalt::Shader::SetInt(const char* name, int value)
{
	Use();

	glUniform1i(glGetUniformLocation(value, name), value);

	Unuse();
}

// Sets an float in the shader
void Cobalt::Shader::SetFloat(const char* name, float value)
{
	Use();

	glUniform1f(glGetUniformLocation(m_ID, name), value);

	Unuse();
}

// Sets an Vector 2 in the shader
void Cobalt::Shader::SetVec2(const char* name, glm::fvec2 value)
{
	Use();

	glUniform2fv(glGetUniformLocation(m_ID, name), 1, glm::value_ptr(value));

	Unuse();
}

// Sets an Vector 3 in the shader
void Cobalt::Shader::SetVec3(const char* name, glm::fvec3 value)
{
	Use();

	glUniform3fv(glGetUniformLocation(m_ID, name), 1, glm::value_ptr(value));

	Unuse();
}

// Sets an Vector 4 in the shader
void Cobalt::Shader::SetVec4(const char* name, glm::fvec4 value)
{
	Use();

	glUniform4fv(glGetUniformLocation(m_ID, name), 1, glm::value_ptr(value));

	Unuse();
}

// Sets an Matrix 3 in the shader
void Cobalt::Shader::SetMat3(const char* name, glm::mat3 value, bool transpose)
{
	Use();

	glUniformMatrix3fv(glGetUniformLocation(m_ID, name), 1, transpose, glm::value_ptr(value));

	Unuse();
}

// Sets an Matrix 4 in the shader
void Cobalt::Shader::SetMat4(const char* name, glm::mat4 value, bool transpose)
{
	Use();

	glUniformMatrix4fv(glGetUniformLocation(m_ID, name), 1, transpose, glm::value_ptr(value));

	Unuse();
}

// Sets the view for 3D
void Cobalt::Shader::SetView(const char* name, glm::mat3 value, bool transpose)
{
	Use();

	glUniformMatrix4fv(glGetUniformLocation(m_ID, name), 1, transpose, &value[0][0]);

	Unuse();
}
