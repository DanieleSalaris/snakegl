#include "VertexArrayBuffer.h"
#include "../utility/utility.h"

VertexArrayBuffer::VertexArrayBuffer(): length(0)
{
	GLCall(glGenBuffers(1, &id));
}

VertexArrayBuffer::VertexArrayBuffer(Array<GLuint>& data): VertexArrayBuffer()
{
	setData(data);
}

VertexArrayBuffer::~VertexArrayBuffer()
{
	GLCall(glDeleteBuffers(1, &id));
}

void VertexArrayBuffer::setData(Array<GLuint>& data)
{
	bind();
	length = data.getSize();
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.getByteSize(), data, GL_DYNAMIC_DRAW));
}

void VertexArrayBuffer::bind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
}

void VertexArrayBuffer::unbind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

