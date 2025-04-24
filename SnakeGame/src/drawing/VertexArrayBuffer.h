#pragma once
#include <GL/glew.h>
class VertexArrayBuffer
{
private:
	GLuint id;
	unsigned int length;
public:
	VertexArrayBuffer(GLuint* data, unsigned int size);
	~VertexArrayBuffer();
	void setData(GLuint* data, unsigned int size);
	void bind();
	void unbind();
	inline unsigned int getLength() { return length; }
};

