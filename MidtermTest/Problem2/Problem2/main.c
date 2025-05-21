#include <stdio.h>
#include <string.h>

void drawConsoleWindow(int width, int height, const char* title) {
    int title_len = strlen(title);
    int startX = 0;

    // 상단 경계
    printf("┌");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┐\n");

    // 제목 줄
    printf("│");
    printf(" %s", title);
    for (int i = 0; i < width - 3 - title_len; i++) printf(" ");
    printf("X│\n");

    // 중간 내용 영역
    for (int i = 0; i < height - 3; i++) {
        printf("│");
        for (int j = 0; j < width - 2; j++) printf(" ");
        printf("│\n");
    }

    // 하단 경계
    printf("└");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┘\n");
}

int main() {
    drawConsoleWindow(35, 12, "나의 멋진 윈도우");
    return 0;
}
