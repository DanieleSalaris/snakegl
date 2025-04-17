#include "Shader.h"
#include "../utility/utility.h"

Shader::Shader(const std::string filePath, GLenum type, GLuint programId) :
    type(type), programId(programId)
{
    compile(filePath);
}

Shader::Shader(Shader&& o) noexcept
{
    id = o.id;
    type = o.id;
    programId = o.id;
    o.id = 0;
}

Shader::~Shader()
{
    clear();
}

void Shader::compile(const std::string filePath)
{
    if (id != 0) return;
    const std::string source = readFile(filePath);
    const char* sourceCStr = source.c_str();
    id = glCreateShader(type);
    GLCall(glShaderSource(id, 1, &sourceCStr, NULL));
    GLCall(glCompileShader(id));
    GLCall(glAttachShader(programId, id));
}

void Shader::clear()
{
    if (id == 0) return;
    GLCall(glDetachShader(programId, id));
    GLCall(glDeleteShader(id));
    id = 0;
}
