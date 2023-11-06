#include <stdio.h>

// 디스크 이동 함수
void moveDisk(char from, char to, int disk) {
    printf("Move disc %d from %c to %c.\n", disk, from, to);
}

// 하노이 탑 알고리즘 함수
void iterativeHanoi(int n, char source, char auxiliary, char target) {
    int totalMoves = (1 << n) - 1;
    int isEven = n % 2 == 0;

    for (int move = 1; move <= totalMoves; move++) {
        int disk = (move & (move - 1)) % 3 + 1;
        char from, to;

        if (move % 3 == 1) {
            from = source;
            to = target;
        }
        else if (move % 3 == 2) {
            from = source;
            to = auxiliary;
        }
        else {
            from = auxiliary;
            to = target;
        }

        if (isEven) {
            char temp = from;
            from = auxiliary;
            auxiliary = temp;
        }

        moveDisk(from, to, disk);
    }
}

int main() {
    iterativeHanoi(5, 'A', 'B', 'C');
    return 0;
}
