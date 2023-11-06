#include <stdio.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

// ��� ����� �� ���Ҹ� ��Ÿ���� ����ü
typedef struct {
    int row;
    int col;
    int value;
} element;

// ��� ��� ����ü ����
typedef struct SparseMatrix {
    element data[MAX_TERMS]; // ������ �迭 (��� ��� ����)
    int rows;               // �� ��
    int cols;               // �� ��
    int terms;              // 0�� �ƴ� ������ ��
} SparseMatrix;

// ��� ��� ���� �Լ�
SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b) {
    SparseMatrix c;
    int ca = 0, cb = 0, cc = 0;

    // �Է� ��� a�� b�� �� �� �� ũ�Ⱑ ��ġ���� ������ ���� �޽��� ���
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "��� ����� ũ�� ����\n");
        exit(1);
    }

    c.rows = a.rows;
    c.cols = a.cols;
    c.terms = 0;

    // ��� a�� b�� �պ�
    while (ca < a.terms && cb < b.terms) {
        int inda = a.data[ca].row * a.cols + a.data[ca].col;
        int indb = b.data[cb].row * b.cols + b.data[cb].col;

        if (inda < indb) {
            // a�� ���� c�� �߰�
            c.data[cc++] = a.data[ca++];
        }
        else if (inda == indb) {
            if ((a.data[ca].value + b.data[cb].value) != 0) {
                // a�� b�� ���� ���ϰ� ����� 0�� �ƴϸ� c�� �߰�
                c.data[cc].row = a.data[ca].row;
                c.data[cc].col = a.data[ca].col;
                c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
            }
            else
                ca++; cb++;
        }
        else
            // b�� ���� c�� �߰�
            c.data[cc++] = b.data[cb++];
    }

    // ���� a�� ���� c�� ����
    for (; ca < a.terms;)
        c.data[cc++] = a.data[ca++];

    // ���� b�� ���� c�� ����
    for (; cb < b.terms;)
        c.data[cc++] = b.data[cb++];

    c.terms = cc; // ��� ��� ��� c�� 0�� �ƴ� ���� ���� ������Ʈ
    return c;
}

main() {
    // ��� ��� m1�� m2�� ���� �� �ʱ�ȭ
    SparseMatrix m1 = { { {1, 1, 5}, {2, 2, 9} }, 3, 3, 2 };
    SparseMatrix m2 = { { {0, 0, 5}, {2, 2, 9} }, 3, 3, 2 };

    SparseMatrix m3; // ����� ������ ��� ���
    m3 = sparse_matrix_add2(m1, m2); // �� ��� ����� ���ϰ� ����� m3�� ����
}