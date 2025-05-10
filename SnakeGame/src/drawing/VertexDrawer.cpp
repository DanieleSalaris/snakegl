#include "VertexDrawer.h"
#include "../utility/utility.h"
#include "../shader/ShaderProgram.h"

VertexDrawer::VertexDrawer(VertexDrawer&& other) noexcept
	: VertexDrawer(other.program, other.vertexBuffer, other.vertexArrayBuffer) { }

VertexDrawer::VertexDrawer(ShaderProgram& program, VertexBuffer& vertexBuffer, VertexArrayBuffer& vertexArrayBuffer)
	: program(std::move(program)), vertexBuffer(vertexBuffer), vertexArrayBuffer(vertexArrayBuffer) { }

void VertexDrawer::setVertices(Array<GLfloat>& vertices)
{
	vertexBuffer.setData(vertices);
}

void VertexDrawer::setIndices(Array<GLuint>& indices)
{
	vertexArrayBuffer.setData(indices);
}

void VertexDrawer::setPositions(Positions& positions)
{
	setVertices(positions.vertices);
	setIndices(positions.indices);
}

void VertexDrawer::draw()
{
	//GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0));
	GLCall(glEnableVertexAttribArray(0));
	vertexBuffer.bind();
	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0));
	program.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, vertexArrayBuffer.getLength(), GL_UNSIGNED_INT, 0));
	GLCall(glDisableVertexAttribArray(0));
}
