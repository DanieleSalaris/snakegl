#pragma once
#include "Shader.h"
#include "../utility/utility.h"
#include <vector>
#include <string>

class ShaderProgram
{
private:
    GLuint id;
    std::vector<Shader> shaders;
public:
    ShaderProgram();
    void AddShader(std::string filePath, GLenum type);
    void Link();
    void Bind();
};

