#include "VertexBuffer.h"
#include "../utility/utility.h"

VertexBuffer::VertexBuffer(GLfloat* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &id));
	setData(data, size);
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &id));
}

void VertexBuffer::setData(GLfloat* data, unsigned int size)
{
	bind();
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

void VertexBuffer::bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, id));
}

void VertexBuffer::unbind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
} 