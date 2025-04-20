#pragma once
#include <GL/glew.h>
#include <memory>

class VertexBuffer
{
private:
	GLuint id;

public:
	VertexBuffer(GLfloat* data, unsigned int size);
	~VertexBuffer();
	void setData(GLfloat* data, unsigned int size);
	void bind();
	void unbind();
};

