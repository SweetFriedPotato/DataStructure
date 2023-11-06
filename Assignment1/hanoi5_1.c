#include <stdio.h>

// 디스크를 이동하는 함수
void moveDisk(char source, char destination, int disk) {
    printf("Move disc %d from %c to %c.\n", disk, source, destination);
}

// 하노이 탑 알고리즘을 반복문을 사용하여 구현하는 함수
void iterativeHanoi(int numDiscs, char source, char auxiliary, char destination) {
    // 디스크를 이동하기 위한 스텝 수 계산
    int totalMoves = (1 << numDiscs) - 1;

    // 짝수 디스크 수일 때, destination과 auxiliary를 스왑
    if (numDiscs % 2 == 0) {
        char temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    for (int step = 1; step <= totalMoves; ++step) {
        if (step % 3 == 1) {
            moveDisk(source, destination, 1);
        }
        else if (step % 3 == 2) {
            moveDisk(source, auxiliary, 2);
        }
        else {
            moveDisk(auxiliary, destination, 1);
        }
    }
}

int main() {
    iterativeHanoi(3, 'A', 'B', 'C');
    return 0;
}