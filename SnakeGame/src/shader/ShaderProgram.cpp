#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
    id = GLCall(glCreateProgram());
}

void ShaderProgram::AddShader(std::string filePath, GLenum type)
{
    //Shader shader(filePath, type, id);
    //shaders.push_back(Shader (filePath, type, id));
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
