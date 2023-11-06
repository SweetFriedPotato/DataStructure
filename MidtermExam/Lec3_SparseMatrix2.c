#include <stdio.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

// 희소 행렬의 각 원소를 나타내는 구조체
typedef struct {
    int row;
    int col;
    int value;
} element;

// 희소 행렬 구조체 정의
typedef struct SparseMatrix {
    element data[MAX_TERMS]; // 데이터 배열 (희소 행렬 원소)
    int rows;               // 행 수
    int cols;               // 열 수
    int terms;              // 0이 아닌 원소의 수
} SparseMatrix;

// 희소 행렬 덧셈 함수
SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b) {
    SparseMatrix c;
    int ca = 0, cb = 0, cc = 0;

    // 입력 행렬 a와 b의 행 및 열 크기가 일치하지 않으면 오류 메시지 출력
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "희소 행렬의 크기 오류\n");
        exit(1);
    }

    c.rows = a.rows;
    c.cols = a.cols;
    c.terms = 0;

    // 행렬 a와 b를 합병
    while (ca < a.terms && cb < b.terms) {
        int inda = a.data[ca].row * a.cols + a.data[ca].col;
        int indb = b.data[cb].row * b.cols + b.data[cb].col;

        if (inda < indb) {
            // a의 항을 c에 추가
            c.data[cc++] = a.data[ca++];
        }
        else if (inda == indb) {
            if ((a.data[ca].value + b.data[cb].value) != 0) {
                // a와 b의 항을 더하고 결과가 0이 아니면 c에 추가
                c.data[cc].row = a.data[ca].row;
                c.data[cc].col = a.data[ca].col;
                c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
            }
            else
                ca++; cb++;
        }
        else
            // b의 항을 c에 추가
            c.data[cc++] = b.data[cb++];
    }

    // 남은 a의 항을 c에 복사
    for (; ca < a.terms;)
        c.data[cc++] = a.data[ca++];

    // 남은 b의 항을 c에 복사
    for (; cb < b.terms;)
        c.data[cc++] = b.data[cb++];

    c.terms = cc; // 결과 희소 행렬 c의 0이 아닌 항의 수를 업데이트
    return c;
}

main() {
    // 희소 행렬 m1과 m2를 정의 및 초기화
    SparseMatrix m1 = { { {1, 1, 5}, {2, 2, 9} }, 3, 3, 2 };
    SparseMatrix m2 = { { {0, 0, 5}, {2, 2, 9} }, 3, 3, 2 };

    SparseMatrix m3; // 결과를 저장할 희소 행렬
    m3 = sparse_matrix_add2(m1, m2); // 두 희소 행렬을 더하고 결과를 m3에 저장
}