#pragma once
#include "../utility/Array.h"
#include <memory>

class Positions
{
public:
	Array<GLfloat> vertices;
	Array<GLuint> indices;

	Positions() {}
	
	Positions(Array<GLfloat> vertices, Array<GLuint> indices): vertices(vertices), indices(indices) {}

	Positions(const Positions& other) {
		vertices = other.vertices;
		indices = other.indices;
	}

	Positions operator+(const Positions& other) {
		Positions result{
			vertices + other.vertices,
			indices + other.indices
		};
		unsigned int otherStart = indices.getSize();
		unsigned int otherVertexStart = vertices.getSize() / 3;
		for (unsigned int i = otherStart; i < result.indices.getSize(); i++) {
			result.indices[i] += otherVertexStart;
		}
		return result;
	}

	Positions operator=(const Positions& other) {
		vertices = other.vertices;
		indices = other.indices;
		return *this;
	}

	Positions operator=(Positions&& other) noexcept {
		vertices = std::move(other.vertices);
		indices = std::move(other.indices);
		return *this;
	}
};
