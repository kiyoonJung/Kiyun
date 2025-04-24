#include <stdio.h>
#include <string.h>

void drawConsoleWindow(int width, int height, const char* title) {
    int title_len = strlen(title);
    int startX = 0;

    // ��� ���
    printf("��");
    for (int i = 0; i < width - 2; i++) printf("��");
    printf("��\n");

    // ���� ��
    printf("��");
    printf(" %s", title);
    for (int i = 0; i < width - 3 - title_len; i++) printf(" ");
    printf("X��\n");

    // �߰� ���� ����
    for (int i = 0; i < height - 3; i++) {
        printf("��");
        for (int j = 0; j < width - 2; j++) printf(" ");
        printf("��\n");
    }

    // �ϴ� ���
    printf("��");
    for (int i = 0; i < width - 2; i++) printf("��");
    printf("��\n");
}

int main() {
    drawConsoleWindow(35, 12, "���� ���� ������");
    return 0;
}
