#include "VertexArrayBuffer.h"
#include "../utility/utility.h"

VertexArrayBuffer::VertexArrayBuffer(GLuint* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &id));
	setData(data, size);
}

VertexArrayBuffer::~VertexArrayBuffer()
{
	GLCall(glDeleteBuffers(1, &id));
}

void VertexArrayBuffer::setData(GLuint* data, unsigned int size)
{
	bind();
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
}

void VertexArrayBuffer::bind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
}

void VertexArrayBuffer::unbind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
