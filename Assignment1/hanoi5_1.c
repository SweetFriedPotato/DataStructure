#include <stdio.h>

// ��ũ�� �̵��ϴ� �Լ�
void moveDisk(char source, char destination, int disk) {
    printf("Move disc %d from %c to %c.\n", disk, source, destination);
}

// �ϳ��� ž �˰����� �ݺ����� ����Ͽ� �����ϴ� �Լ�
void iterativeHanoi(int numDiscs, char source, char auxiliary, char destination) {
    // ��ũ�� �̵��ϱ� ���� ���� �� ���
    int totalMoves = (1 << numDiscs) - 1;

    // ¦�� ��ũ ���� ��, destination�� auxiliary�� ����
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