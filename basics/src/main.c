#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "loadShaders.h"

int application_cleanup()
{
    glfwTerminate();
    return 0;
}

static const GLfloat g_vertex_buffer_data[] = {
    -1.0,   -1.0,   0.0,
     1.0,   -1.0,   0.0,
     0.0,    1.0,   0.0,
};

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, 1);
    }
}

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        fprintf(stderr, "Could not initialize glfw\n");
        return -1;
    }

    GLFWwindow *window;
    window = glfwCreateWindow(500, 500, "Hello OpenGL!", NULL, NULL);
    if (window == NULL)
    {
        fprintf(stderr, "Could not create window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Could not initialize glew\n");
        return -1;
    }

    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    printf("Got here\n");
    glBindVertexArray(vertexArrayID);

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do
    {
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT);

        // 1st attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(
            0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,        // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0,        // stride
            (void *)0 // array buffer offset
        );
        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window));

    glfwTerminate();
    return 0;
}