#include "ShaderProgram.h"
#include <utility>

ShaderProgram::ShaderProgram()
{
    id = GLCall(glCreateProgram());
}

ShaderProgram::ShaderProgram(ShaderProgram&& other) noexcept : id(other.id), shaders(std::move(other.shaders))
{
    other.id = 0;
}

ShaderProgram::~ShaderProgram()
{
    if (id != 0)
    {
        shaders.clear();
        GLCall(glDeleteProgram(id));
    }
}

void ShaderProgram::AddShader(std::string filePath, GLenum type)
{
    shaders.emplace_back(filePath, type, id);
}

void ShaderProgram::Link()
{
    GLCall(glLinkProgram(id));
}

void ShaderProgram::Bind()
{
    GLCall(glUseProgram(id));
}
