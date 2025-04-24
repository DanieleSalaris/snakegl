#pragma once
#include <GL/glew.h>
#include "VertexBuffer.h"
#include "VertexArrayBuffer.h"
#include "../shader/ShaderProgram.h"
#include "../utility/Array.h"

class VertexDrawer
{
private:
	VertexBuffer vertexBuffer;
	VertexArrayBuffer vertexArrayBuffer;
	ShaderProgram program;

public:
	VertexDrawer(VertexDrawer&& other) noexcept;
	VertexDrawer(ShaderProgram& program, VertexBuffer& vertexBuffer, VertexArrayBuffer& vertexArrayBuffer);
	void setVertices(Array<GLfloat>& vertices);
	void setIndices(Array<GLuint>& indices);
	void draw();
};

