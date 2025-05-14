#include <stdio.h>

int PassOrFail(int score) {
    if (score >= 50) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int myScore = 50;  

    int result = PassOrFail(myScore);

    if (result == 1) {
        printf("우리는 합격이다.\n");
    }
    else {
        printf("재시험이다. 재시험이다. 재시험이다.\n");
    }

    return 0;
}
