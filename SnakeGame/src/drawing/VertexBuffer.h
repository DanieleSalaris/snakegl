#pragma once
#include <GL/glew.h>
#include <memory>
#include "../utility/Array.h"

class VertexBuffer
{
private:
	GLuint id;

public:
	VertexBuffer();
	VertexBuffer(Array<GLfloat>& data);
	~VertexBuffer();
	void setData(Array<GLfloat>& data);
	void bind();
	void unbind();
};

