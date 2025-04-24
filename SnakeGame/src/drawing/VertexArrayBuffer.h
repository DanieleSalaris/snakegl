#pragma once
#include <GL/glew.h>
#include "../utility/Array.h"
class VertexArrayBuffer
{
private:
	GLuint id;
	unsigned int length;
public:
	VertexArrayBuffer();
	VertexArrayBuffer(Array<GLuint>& data);
	~VertexArrayBuffer();
	void setData(Array<GLuint>& data);
	void bind();
	void unbind();
	inline unsigned int getLength() { return length; }
};

