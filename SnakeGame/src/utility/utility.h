#pragma once

#include <GL/glew.h>
#include <assert.h>
#include <string>

#define GLCall(glFunction) \
    glFunction;\
    assert(GLLogErrors() != true)

std::string readFile(const std::string filePath);
bool GLLogErrors();
