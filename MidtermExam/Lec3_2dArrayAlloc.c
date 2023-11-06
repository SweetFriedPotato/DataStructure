#include <stdio.h>
#include <stdlib.h>

void main() {
	// 3x3 ũ���� 2���� �迭�� �������� �Ҵ��մϴ�.
	int row = 3; // ���� ����
	int col = 3; // ���� ����

	// m2�� int�� �������� �����ͷ� 2���� �迭�� ��Ÿ�½��ϴ�.
	int** m2 = (int**)malloc(sizeof(int*) * row); // �� �����͸� �Ҵ�
	for (int i = 0; i < row; i++) {
		m2[i] = (int*)malloc(sizeof(int) * col); // �� �迭�� �Ҵ�
	}

	int count = 0; // �迭�� ���� ���� �ʱⰪ�Դϴ�.

	// �迭�� �ʱ�ȭ�ϰ� ����մϴ�.
	for (int i = 0; i < row; i++) { // �� �ݺ�
		for (int j = 0; j < col; j++) { // �� �ݺ�
			m2[i][j] = ++count; // count ���� �迭 ��ҿ� �Ҵ��ϰ� ������ŵ�ϴ�.
			printf_s("%d\n", m2[i][j]); // �迭 ��Ҹ� ����մϴ�.
		}
	}

	// �Ҵ��� �޸𸮸� �����մϴ�.
	for (int i = 0; i < row; i++) {
		free(m2[i]); // �� �迭 �޸� ����
	}
	free(m2); // �� ������ �޸� ����
}
