#include "utility.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string readFile(const std::string filePath) {
    std::fstream file(filePath);
    std::string line = "";
    std::stringstream result;
    if (!file.is_open()) {
        return "";
    }
    while (getline(file, line)) {
        result << line << "\n";
    }
    return result.str();
}

bool GLLogErrors() {
    GLenum err;
    std::stringstream ss;
    bool isFirst = true;
    while ((err = glGetError()) != GL_NO_ERROR) {
        if (!isFirst) {
            ss << ", ";
        }
        ss << "0x" << std::hex << err;
        isFirst = false;
    }
    std::string errors = ss.str();
    if (errors.length() == 0) {
        return false;
    }
    std::cout << "GL Error: " << errors << "." << std::endl;
    return true;
}
