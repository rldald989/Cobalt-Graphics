#pragma once

#include <Camera.h>
#include <vector>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

bool CheckCollision(Cobalt::GameObject& a, Cobalt::GameObject& b) {
    bool colX = a.GetPosition().x + a.GetBounds().x >= b.GetPosition().x &&
        b.GetPosition().x + b.GetBounds().x >= a.GetPosition().x;

    bool colY = a.GetPosition().y + a.GetBounds().y >= b.GetPosition().y &&
        b.GetPosition().y + b.GetBounds().y >= a.GetPosition().y;

    return colX && colY;
}

bool CheckRadialCollision(Cobalt::GameObject& a, Cobalt::GameObject& b, float dist)
{
    bool col = glm::abs(glm::distance(a.GetPosition(), b.GetPosition())) <= dist;
    return col;
}

//Entities

struct Entity
{
    Cobalt::GameObject* obj;
    float health;
    glm::vec2 size;
    glm::vec2 position;
    glm::vec2 m_mov;
};

struct Player : public Entity
{
    float runes = 0;
    float speed;
    bool bounce = false;

    Player(Cobalt::GameObject* _obj, float _health, glm::vec2 _size, glm::vec2 _position, glm::vec2 _m_mov) : Entity({ _obj, _health, _size, _position, _m_mov })
    {

    }
    void Init(glm::vec2 pos) 
    {
        position = pos;
        obj->SetX(position.x);
        obj->SetY(position.y);
    }

    void Controls(GLFWwindow* win)
    {
        if (health > 0) {
            if (glfwGetKey(win, GLFW_KEY_W))
            {
                m_mov.y = speed;
            }
            else if (glfwGetKey(win, GLFW_KEY_S))
            {
                m_mov.y = -speed;
            }
            else {
                if (!bounce) {
                    m_mov.y = 0.0f;
                }
            }

            if (glfwGetKey(win, GLFW_KEY_A))
            {
                m_mov.x = -speed;
            }
            else if (glfwGetKey(win, GLFW_KEY_D))
            {
                m_mov.x = speed;
            }
            else {
                if (!bounce) {
                    m_mov.x = 0.0f;
                }
            }
        }
        else {
            m_mov = glm::vec2(0.0f);
        }
    }

    void Update() {
        obj->Move(m_mov.x, m_mov.y);
    }

    void Bounce(Cobalt::GameObject& other, float speedMod) {
        //Gets the x and y distance from one object to the other
        float xDist = obj->GetPosition().x - other.GetPosition().x;
        float yDist = obj->GetPosition().y - other.GetPosition().y;
        
        //Takes that distance and divides it by itself to get either -1 or 1 for x and y
        float xCalc = xDist / xDist;
        float yCalc = yDist / yDist;

        //Multiplies x and y by the speed which is then multiplied by the speedMod to let us bounce off of objects or enemies
        m_mov = glm::vec2( (xDist * speed) * speedMod, (yDist * speed) * speedMod);

        //IDK How tf I got this to work
    }


};