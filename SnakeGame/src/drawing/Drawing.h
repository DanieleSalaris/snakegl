#pragma once
#include "../utility/Array.h"

class Positions
{
public:
	Array<GLfloat> vertices;
	Array<GLuint> indices;

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
};
