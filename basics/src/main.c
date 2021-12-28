#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int application_cleanup()
{
    glfwTerminate();
    return 0;
}

int main(int argc, char **argv)
{
    glewExperimental = 1;
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
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    do
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);

    glfwTerminate();
    return 0;
}