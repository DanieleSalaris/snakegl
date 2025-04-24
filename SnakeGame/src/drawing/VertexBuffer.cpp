#include "VertexBuffer.h"
#include "../utility/utility.h"

VertexBuffer::VertexBuffer()
{
	GLCall(glGenBuffers(1, &id));
}
VertexBuffer::VertexBuffer(Array<GLfloat>& data): VertexBuffer()
{
	setData(data);
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &id));
}

void VertexBuffer::setData(Array<GLfloat>& data)
{
	bind();
	GLCall(glBufferData(GL_ARRAY_BUFFER, data.getByteSize(), data, GL_STATIC_DRAW));
}

void VertexBuffer::bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, id));
}

void VertexBuffer::unbind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
} 