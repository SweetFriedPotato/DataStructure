#include <stdio.h>
#include <stdlib.h>

void main() {
	// 3x3 크기의 2차원 배열을 동적으로 할당합니다.
	int row = 3; // 행의 개수
	int col = 3; // 열의 개수

	// m2는 int형 포인터의 포인터로 2차원 배열을 나타냈습니다.
	int** m2 = (int**)malloc(sizeof(int*) * row); // 행 포인터를 할당
	for (int i = 0; i < row; i++) {
		m2[i] = (int*)malloc(sizeof(int) * col); // 열 배열을 할당
	}

	int count = 0; // 배열에 넣을 값의 초기값입니다.

	// 배열을 초기화하고 출력합니다.
	for (int i = 0; i < row; i++) { // 행 반복
		for (int j = 0; j < col; j++) { // 열 반복
			m2[i][j] = ++count; // count 값을 배열 요소에 할당하고 증가시킵니다.
			printf_s("%d\n", m2[i][j]); // 배열 요소를 출력합니다.
		}
	}

	// 할당한 메모리를 해제합니다.
	for (int i = 0; i < row; i++) {
		free(m2[i]); // 열 배열 메모리 해제
	}
	free(m2); // 행 포인터 메모리 해제
}
