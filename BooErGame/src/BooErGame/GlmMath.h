#pragma once
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
//#include <glm/ext/constants.hpp> // glm::pi

class GlmMath
{
public:
    GlmMath();
    ~GlmMath();

    void Init();
    void Setup();

    glm::mat4 Camera(float Translate, glm::vec2 const& Rotate);

};

