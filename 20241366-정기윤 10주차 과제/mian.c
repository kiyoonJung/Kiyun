#pragma comment(lib, "opengl32.lib")

#include <GLFW/glfw3.h>
#include <math.h>

#define PI 3.14159265f

void draw_circle(float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.6f, 1.0f);
   
    for (int i = 0; i < segments; ++i) { 
        float angle = 2.0f * PI * i / segments;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(500, 500, "OpenGL Circle", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        draw_circle(0.5f, 100);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
