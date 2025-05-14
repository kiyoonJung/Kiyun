
#include <windows.h>
#include <stdio.h>

int main() {
    char letter = 'O';  // ���ĺ� 'O' ����
    POINT mousePos;     // ���콺 ��ġ
    int isDragging = 0;  // �巡�� ���� (0: �巡�� �� �ƴ�, 1: �巡�� ��)
    int letterX = 10;    // ���ĺ� 'O'�� �ʱ� X ��ǥ
    int letterY = 5;     // ���ĺ� 'O'�� �ʱ� Y ��ǥ

    // �ܼ� ȭ�� �ʱ�ȭ
    system("cls");

    while (1) {
        // ���콺 ��ġ ���
        GetCursorPos(&mousePos);

        // ���콺 �巡�� ������ Ȯ��
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            isDragging = 1;
            letterX = mousePos.x / 9;
            letterY = mousePos.y / 19;
        }
        else {
            isDragging = 0;
        }

        // ȭ�� ����
        system("cls");
        printf("���ĺ� '%c'�� ���콺�� �巡���ϼ���.\n", letter);
        printf("���� ���ĺ� '%c'�� ��ġ: (%d, %d)\n", letter, letterX, letterY);

        // ���ĺ� O ���
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        // ���� ����: ESC Ű�� ������ ���α׷� ����
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("\n���α׷� ����\n");
            break;
        }

        // ��� ��� (CPU ��� ����ȭ)
        Sleep(10);
    }

    return 0;
}
