#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 10

typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

int compareElements(const void* a, const void* b) {
    element* elementA = (element*)a;
    element* elementB = (element*)b;

    if (elementA->row < elementB->row) {
        return -1;
    }
    else if (elementA->row > elementB->row) {
        return 1;
    }
    else {
        if (elementA->col < elementB->col) {
            return -1;
        }
        else if (elementA->col > elementB->col) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

SparseMatrix matrixInput() {
    SparseMatrix m;
    printf("Input row size: ");
    scanf("%d", &m.rows);
    printf("Input col size: ");
    scanf("%d", &m.cols);
    printf("Input terms(maximum is 10): ");
    scanf("%d", &m.terms);
    for (int i = 0; i < m.terms; i++) {
        printf("Input numbers by format row col value : ");
        scanf("%d %d %d", &m.data[i].row, &m.data[i].col, &m.data[i].value);
    }
    return m;
}

SparseMatrix transposMatrix(SparseMatrix m) {
    SparseMatrix trans;
    int count = 0;

    trans.rows = m.cols;
    trans.cols = m.rows;
    trans.terms = m.terms;

    while (count < m.terms) {
        trans.data[count].col = m.data[count].row;
        trans.data[count].row = m.data[count].col;
        trans.data[count].value = m.data[count].value;
        count++;
    }
    return trans;
}

void printSparseMat(SparseMatrix m) {
    qsort(m.data, m.terms, sizeof(element), compareElements);

    for (int i = 0; i < m.terms; i++) {
        printf("%d %d %d\n", m.data[i].row, m.data[i].col, m.data[i].value);
    }
}

void printFullMat(SparseMatrix m) {
    int r = m.rows;
    int c = m.cols;
    int term = m.terms;

    int** array = (int**)malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++) {
        array[i] = (int*)malloc(sizeof(int) * c);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            array[i][j] = 0;
        }
    }
    for (int i = 0; i < term; i++) {
        array[m.data[i].row][m.data[i].col] = m.data[i].value;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
        free(array[i]);
    }
    free(array);
}

int main() {
    SparseMatrix mat = matrixInput();
    printf("\n");

    SparseMatrix transmat = transposMatrix(mat);

    printf("Input data for Transposed Matrix B^T\n");
    printSparseMat(transmat);

    printf("\nMatrix B\n");
    printFullMat(mat);

    printf("\nMatrix B^T\n");
    printFullMat(transmat);

    return 0;
}