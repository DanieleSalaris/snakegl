#pragma once
#include <string>
#include "../utility/utility.h"

class Shader
{
private:
    GLuint id = 0;
    GLuint programId = 0;
    GLenum type;
    void compile(std::string filePath);
    void clear();

public:
    Shader(std::string filePath, GLenum type, GLuint programId);
    Shader(Shader&& o) noexcept;
    ~Shader();
};

