#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "utility/utility.h"
#include "utility/Array.h"
#include "drawing/VertexDrawer.h"
#include "drawing/GridVertexMapper.h"
#include "drawing/BoardGridVertexMapper.h"
#include "snake/Board.h"


VertexDrawer createVertexDrawer() {
		std::string vertexShader = readFile("res/shaders/vertex.shader");
		std::string fragmentShader = readFile("res/shaders/fragment.shader");
		

		ShaderProgram program;
		program.AddShader("res/shaders/vertex.shader", GL_VERTEX_SHADER);
		program.AddShader("res/shaders/fragment.shader", GL_FRAGMENT_SHADER);
		program.Link();
		
		VertexBuffer vertexBuffer;
		VertexArrayBuffer vertexArrayBuffer;

		return VertexDrawer(program, vertexBuffer, vertexArrayBuffer);
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    {
		GLenum error = glewInit();
		if (error != GLEW_OK) {
			std::cout << "Unable to initialize glew!" << std::endl;
			return 0;
		}

		GLuint vertexArrayId;
		glGenVertexArrays(1, &vertexArrayId);
		glBindVertexArray(vertexArrayId);

		Array<GLfloat> g_vertex_buffer_data {
			-0.9f, 0.9f, 0.0f,
			-0.8f, 0.9f, 0.0f,
			-0.9f, 0.8f, 0.0f,
			-0.8f, 0.8f, 0.0f,

			 0.3f, 0.9f, 0.0f,
			 0.4f, 0.9f, 0.0f,
			 0.3f, 0.8f, 0.0f,
			 0.4f, 0.8f, 0.0f,
		};

		Array<GLuint> indices {
			0, 1, 2,
			1, 2, 3,

			4, 5, 6,
			5, 6, 7
		};


		GridVertexMapper mapper(32, 24);

		Positions cell1 = mapper.getCellPosition(1, 2);
		Positions cell2 = mapper.getCellPosition(12, 7);
		Positions cell3 = mapper.getCellPosition(3, 17);
		Positions positions = cell2 + cell1 + cell3;

		VertexDrawer vertexDrawer = createVertexDrawer();
		// vertexDrawer.setVertices(g_vertex_buffer_data);
		// vertexDrawer.setIndices(indices);

		vertexDrawer.setPositions(positions);

		
		Board board(new RandomImpl(), new SnakeFactoryImpl());
		GridVertexMapper gridVertexMapper;
		SnakePositionToGridVertexSerializer snakeSerializer(&gridVertexMapper, &board.GetSnake());
		BoardGridVertexMapper boardGridVertexMapper(&board, &snakeSerializer);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

			vertexDrawer.draw();

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}