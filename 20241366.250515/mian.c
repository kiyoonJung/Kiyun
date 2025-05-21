#include <GLFW/glfw3.h>
#include <math.h>

#pragma comment(lib, "opengl32.lib")

#define PI 3.1415926535

const int WIDTH = 537;
const int HEIGHT = 445;

void draw_circle(float cx, float cy, float rx, float ry, int segments, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float x = cx + rx * cosf(angle);
        float y = cy + ry * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

float to_gl_x(float x) {
    return x / (WIDTH / 2) - 1.0f;
}
float to_gl_y(float y) {
    return 1.0f - y / (HEIGHT / 2);
}

// ✅ 수정된 위쪽 아치형 흰 호 함수
void draw_upper_white_arc_fixed() {
    float cx1 = 240.0f;
    float cx2 = 283.0f;
    float cy = 287.0f;
    float rx = 22.5f;
    float ry = 19.5f;

    glColor3f(1.0f, 1.0f, 1.0f);  // 흰색

    glBegin(GL_TRIANGLE_FAN);

    // 중앙 꼭짓점은 위쪽에 위치
    float centerX = (cx1 + cx2) / 2.0f;
    float centerY = cy - ry - 0.65f;  // 좀 더 위쪽
    glVertex2f(to_gl_x(centerX), to_gl_y(centerY));

    // 왼쪽 원의 위쪽 외곽
    for (int i = 0; i >= -90; i--) {
        float angle = PI * i / 180.0f;
        float x = cx1 + rx * cosf(angle);
        float y = cy + ry * sinf(angle);
        if (x > cx2) break;
        glVertex2f(to_gl_x(x), to_gl_y(y));
    }

    // 오른쪽 원의 위쪽 외곽
    for (int i = 0; i <= 320; i++) {
        float angle = PI * i / 180.0f;
        float x = cx2 - rx * cosf(angle);
        float y = cy + ry * sinf(angle);
        if (x < cx1) break;
        glVertex2f(to_gl_x(x), to_gl_y(y));
    }

    glEnd();
}

void draw_whiskers() {
    glColor3f(0.0f, 0.0f, 0.0f); // 검정색 수염
    glLineWidth(3.0f);

    glBegin(GL_LINES);

    // 왼쪽 수염 기준점: (240, 287)
    float x0 = 240, y0 = 287;
    glVertex2f(to_gl_x(x0 - 10), to_gl_y(y0 - 10));
    glVertex2f(to_gl_x(x0 - 60), to_gl_y(y0 - 20));

    glVertex2f(to_gl_x(x0 - 10), to_gl_y(y0));
    glVertex2f(to_gl_x(x0 - 60), to_gl_y(y0));

    glVertex2f(to_gl_x(x0 - 10), to_gl_y(y0 + 10));
    glVertex2f(to_gl_x(x0 - 60), to_gl_y(y0 + 20));

    // 오른쪽 수염 기준점: (283, 287)
    x0 = 283;
    glVertex2f(to_gl_x(x0 + 10), to_gl_y(y0 - 10));
    glVertex2f(to_gl_x(x0 + 60), to_gl_y(y0 - 20));

    glVertex2f(to_gl_x(x0 + 10), to_gl_y(y0));
    glVertex2f(to_gl_x(x0 + 60), to_gl_y(y0));

    glVertex2f(to_gl_x(x0 + 10), to_gl_y(y0 + 10));
    glVertex2f(to_gl_x(x0 + 60), to_gl_y(y0 + 20));

    glEnd();
}



int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "겹치는 흰색 원 + 위쪽 호", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // 파란 큰 원
        float cx1 = to_gl_x(265);
        float cy1 = to_gl_y(223);
        float rx1 = 214.5f / (WIDTH / 2);
        float ry1 = 192.0f / (HEIGHT / 2);
        draw_circle(cx1, cy1, rx1, ry1, 100, 0.0f, 0.0f, 1.0f);

        // 좌측 검은 눈
        float cx_eye_left = to_gl_x(88.5);
        float cy_eye = to_gl_y(177);
        float rx_eye = 15.5f / (WIDTH / 2);
        float ry_eye = 15.0f / (HEIGHT / 2);
        draw_circle(cx_eye_left, cy_eye, rx_eye, ry_eye, 100, 0.0f, 0.0f, 0.0f);

        // 우측 검은 눈
        float dx = 265 - 88.5;
        float cx_eye_right = to_gl_x(265 + dx - 10);
        draw_circle(cx_eye_right, cy_eye, rx_eye, ry_eye, 100, 0.0f, 0.0f, 0.0f);
         
        // 흰색 원 1
        float cx_white1 = to_gl_x(230);
        float cy_white1 = to_gl_y(287);
        float rx_white1 = 32.0f / (WIDTH / 2);
        float ry_white1 = 30.0f / (HEIGHT / 2);
        draw_circle(cx_white1, cy_white1, rx_white1, ry_white1, 100, 1.0f, 1.0f, 1.0f);

        // 흰색 원 2
        float cx_white2 = to_gl_x(293);
        float cy_white2 = to_gl_y(287);
        float rx_white2 = 32.0f / (WIDTH / 2);
        float ry_white2 = 30.0f / (HEIGHT / 2);
        draw_circle(cx_white2, cy_white2, rx_white2, ry_white2, 100, 1.0f, 1.0f, 1.0f);


        // ✅ 위쪽 호 추가
        draw_upper_white_arc_fixed();
 
        // 코
	    float nose_cx = to_gl_x(261.5);
        float nose_cy = to_gl_y(255);
        float nose_rx = 21.0f / (WIDTH / 2);
        float nose_ry = 19.0f / (HEIGHT / 2);
        draw_circle(nose_cx, nose_cy, nose_rx, nose_ry, 100, 0.0f, 0.0f, 0.0f);
        
        draw_whiskers();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
