#pragma once
#include <GL/glew.h>
#include "VertexBuffer.h"
#include "VertexArrayBuffer.h"
#include "../shader/ShaderProgram.h"

class VertexDrawer
{
private:
	VertexBuffer vertexBuffer;
	VertexArrayBuffer vertexArrayBuffer;
	ShaderProgram program;

public:
	VertexDrawer(VertexDrawer&& other) noexcept;
	VertexDrawer(ShaderProgram& program, VertexBuffer& vertexBuffer, VertexArrayBuffer& vertexArrayBuffer);
	void setVertices(GLfloat* vertices, GLuint size);
	void setIndices(GLuint* indices, GLuint size);
	void draw();
};

