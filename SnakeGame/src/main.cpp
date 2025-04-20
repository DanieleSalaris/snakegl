#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "utility/utility.h"
#include "shader/ShaderProgram.h"
#include "drawing/VertexBuffer.h"
#include "drawing/VertexArrayBuffer.h"



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

    GLenum error = glewInit();
    if (error != GLEW_OK) {
        std::cout << "Unable to initialize glew!" << std::endl;
        return 0;
    }

    GLuint vertexArrayId;
    glGenVertexArrays(1, &vertexArrayId);
    glBindVertexArray(vertexArrayId);

    // static GLfloat g_vertex_buffer_data[] = {
    //      0.4f,  0.5f, 0.0f,
    //      0.5f, -0.5f, 0.0f,
    //     -0.5f, -0.5f, 0.0f,
    //     -0.5f,  0.5f, 0.0f
    // };

    static GLfloat g_vertex_buffer_data[] {
        -0.9f, 0.9f, 0.0f,
        -0.8f, 0.9f, 0.0f,
        -0.9f, 0.8f, 0.0f,
        -0.8f, 0.8f, 0.0f,

         0.3f, 0.9f, 0.0f,
         0.4f, 0.9f, 0.0f,
         0.3f, 0.8f, 0.0f,
         0.4f, 0.8f, 0.0f,
    };

    // unsigned int indices[] = {
    //     0, 1, 3,
    //     1, 2, 3
    // };

    unsigned int indices[] = {
        0, 1, 2,
        1, 2, 3,

        4, 5, 6,
        5, 6, 7
    };

    VertexBuffer vertexBuffer(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
    VertexArrayBuffer vertexArrayBuffer(indices, sizeof(indices));

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);


    std::string vertexShader = readFile("res/shaders/vertex.shader");
    std::string fragmentShader = readFile("res/shaders/fragment.shader");
    
    std::cout << "Vertex Shader: " << vertexShader << "\nFragmentShader: " << fragmentShader << std::endl;

    ShaderProgram program;
    program.AddShader("res/shaders/vertex.shader", GL_VERTEX_SHADER);
    program.AddShader("res/shaders/fragment.shader", GL_FRAGMENT_SHADER);
    program.Link();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glEnableVertexAttribArray(0);
        //glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        vertexBuffer.bind();
        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void*)0
        );

        program.Bind();

        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        glDisableVertexAttribArray(0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}