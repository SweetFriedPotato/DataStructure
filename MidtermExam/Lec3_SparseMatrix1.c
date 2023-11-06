//Sparse matrix - store all elements

#include <stdio.h>
#define ROWS 3
#define COLS 3

// ��� ��� ���� �Լ�
void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
    int r, c;
    // ��� ��(r)�� ��(c)�� ���� ���� ����
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            // ��� C�� �ش� ��ġ�� ��� A�� ��� B�� ���� ����
            C[r][c] = A[r][c] + B[r][c];
        }
    }
}

int main() {
    // 3x3 �迭 ���ǿ� �ʱ�ȭ
    int array1[ROWS][COLS] = { {2, 3, 0}, {8, 9, 1}, {7, 0, 5} };
    int array2[ROWS][COLS] = { {1, 0, 0}, {1, 0, 0}, {1, 0, 0} };
    int array3[ROWS][COLS]; // ����� ������ �迭

    // sparse_matrix_add1 �Լ��� ȣ���Ͽ� �� ����� ���ϰ� ����� array3�� ����

    // ��� A:
    //  2  3  0
    //  8  9  1
    //  7  0  5

    // ��� B:
    //  1  0  0
    //  1  0  0
    //  1  0  0

    // ���� �� ��� C (���):
    //  3  3  0
    //  9  9  1
    //  8  0  5
}
