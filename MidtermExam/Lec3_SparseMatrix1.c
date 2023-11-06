//Sparse matrix - store all elements

#include <stdio.h>
#define ROWS 3
#define COLS 3

// 희소 행렬 덧셈 함수
void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
    int r, c;
    // 모든 행(r)과 열(c)에 대해 루프 실행
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            // 행렬 C의 해당 위치에 행렬 A와 행렬 B의 값을 더함
            C[r][c] = A[r][c] + B[r][c];
        }
    }
}

int main() {
    // 3x3 배열 정의와 초기화
    int array1[ROWS][COLS] = { {2, 3, 0}, {8, 9, 1}, {7, 0, 5} };
    int array2[ROWS][COLS] = { {1, 0, 0}, {1, 0, 0}, {1, 0, 0} };
    int array3[ROWS][COLS]; // 결과를 저장할 배열

    // sparse_matrix_add1 함수를 호출하여 두 행렬을 더하고 결과를 array3에 저장

    // 행렬 A:
    //  2  3  0
    //  8  9  1
    //  7  0  5

    // 행렬 B:
    //  1  0  0
    //  1  0  0
    //  1  0  0

    // 덧셈 후 행렬 C (결과):
    //  3  3  0
    //  9  9  1
    //  8  0  5
}
