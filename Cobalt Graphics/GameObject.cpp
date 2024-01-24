#include "GameObject.h"
#include "pch.h"

// Vertices
Vert vertices[] =
{
    glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.f, 1.f),
    glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.f, 0.f),
    glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(1.f, 0.f),
    glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(1.f, 1.f)
};

// Number of vertices
unsigned nrOfVertices = sizeof(vertices) / sizeof(Vert); 

// Indices
GLuint indices[] =
{
    0, 1, 2,
    2, 3, 0
};

// Number of indices
unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

Cobalt::GameObject::GameObject(std::string name, const char* texFilePath, FilteringMode ft) : m_shader(new Shader("Shaders/vert.glsl", "Shaders/frag.glsl")), m_projection(1.0f), m_transform(1.0f), tex_scale(1.0f, 1.0f), m_name(name)
{
    // Binds the Vertex Array Buffer(VAO), Vertex Buffer(VBO), and the Index Buffer(IBO)
    m_vao.Bind();
    m_vbo.Bind();
    m_ibo.Bind();

    // Pushes the vertex and index data into opengl's buffers
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Sets up position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), (void*)0);
    glEnableVertexAttribArray(0);

    // Sets up the color and texture coordinates
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Loads the texture into a variable i.e. m_texID, which is an unsigned int, this method here allows us to change the texture later on
    m_texID = new unsigned int(m_texture.LoadTex(texFilePath, ft));

    // Unbinds the Vertex Array Buffer(VAO), Vertex Buffer(VBO), and the Index Buffer(IBO)
    m_ibo.Unbind();
    m_vbo.Unbind();
    m_vao.Unbind();

    m_shader->SetVec2("tex_scale", tex_scale);
}

// Delete anything that is loaded into memory
Cobalt::GameObject::~GameObject()
{
    //delete m_shader;
    delete m_texID;
}

void Cobalt::GameObject::Update()
{
    m_shader->SetMat4("transform", m_transform);
}

void Cobalt::GameObject::Render()
{
    // Uses the shader
    m_shader->Use();

    // Binds the texture for use so it can be seen on an object
    m_texture.Bind(*m_texID);

    // Binds the VAO so the object's vertex data can be cycled through the buffer
    m_vao.Bind();

    // Does the actual rendering of the object
    m_shader->Draw(nrOfIndices, indices);

    // Unbinds the texture
    m_texture.Unbind();

    // Unuses the shader
    m_shader->Unuse();
}

void Cobalt::GameObject::Move(float x, float y) 
{
    m_transform = glm::translate(m_transform, glm::vec3(x, y, 0.0f));
}

void Cobalt::GameObject::Rotate(float amount, glm::vec3 rot)
{
    m_transform = glm::rotate(m_transform, glm::radians(amount), rot);
}

void Cobalt::GameObject::Scale(float x, float y)
{
    m_transform = glm::scale(m_transform, glm::vec3(x, y, 0.0f));
}

void Cobalt::GameObject::SetBounds(glm::vec2 value)
{
    m_bounds.x = m_bounds.x + value.x;
    m_bounds.y = m_bounds.y + value.y;
}

void Cobalt::GameObject::SetX(float amount)
{
    m_transform[3][0] = amount;
}

void Cobalt::GameObject::SetY(float amount)
{
    m_transform[3][1] = amount;
}

void Cobalt::GameObject::SetTextureScale(float x, float y)
{
    tex_scale = glm::vec2(x, y);
    m_shader->SetVec2("tex_scale", tex_scale);
}

inline Cobalt::Shader* Cobalt::GameObject::GetShader()
{
    // Returns the shader to be gotten and used
    return m_shader;
}

glm::vec3 Cobalt::GameObject::GetPosition()
{
    return glm::vec3(m_transform[3].x, m_transform[3].y, m_transform[3].z);
}

glm::vec3 Cobalt::GameObject::GetBounds()
{
    return m_bounds;
}

Cobalt::ObjectCollection::ObjectCollection(const char* collection_name) : m_collection_name(collection_name)
{
}

Cobalt::ObjectCollection::~ObjectCollection()
{
    for (int i = 0; i < Size(); i++) {
        delete m_objects[i];
    }
}

void Cobalt::ObjectCollection::Add(GameObject* object)
{
    m_objects.push_back(object);
    std::cout << "Object " << object->GetName() << " added to " << m_collection_name << std::endl;
}

Cobalt::GameObject* Cobalt::ObjectCollection::GetObject(const char* name)
{
    for (int i = 0; i < Size(); i++) {
        if (m_objects[i]->GetName() == name) {
            return m_objects[i];
        }
    }
}

Cobalt::GameObject* Cobalt::ObjectCollection::GetObject(int index)
{
    return m_objects[index];
}

void Cobalt::ObjectCollection::RemoveObject(const char* name)
{
    for (int i = 0; i < Size(); i++) {
        if (m_objects[i]->GetName() == name) {
            m_objects.erase(m_objects.begin() + i);
        }
    }
}

void Cobalt::ObjectCollection::RemoveObject(int index)
{
    m_objects.erase(m_objects.begin() + index);
}

void Cobalt::ObjectCollection::Update()
{
    for (int i = 0; i < Size(); i++) {
        m_objects[i]->Update();
    }
}

void Cobalt::ObjectCollection::Render()
{
    for (int i = 0; i < Size(); i++) {
        m_objects[i]->Render();
    }
}

int Cobalt::ObjectCollection::Size()
{
    return m_objects.size();
}
