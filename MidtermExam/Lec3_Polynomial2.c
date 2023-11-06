#include <stdio.h>
#define MAX_TERMS 101

// ���׽� ��(term)�� ��Ÿ���� ����ü ����
struct {
    float coef; // ���
    int expon;  // ����
} terms[MAX_TERMS] = { {8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0} };

int avail = 6;

// �� ������ ���ϴ� �Լ�
char compare(int a, int b) {
    if (a > b) return '>';       // a�� b���� ū ���
    else if (a == b) return '='; // a�� b�� ���� ���
    else return '<';            // a�� b���� ���� ���
}

// ���ο� ���� ���׽Ŀ� �߰��ϴ� �Լ�
void attach(float coef, int expon) {
    if (avail > MAX_TERMS) {
        fprintf(stderr, "���� �ʹ� �����ϴ�.\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail++].expon = expon;
}

// ���׽� C = ���׽� A + ���׽� B�� ����ϴ� �Լ�
int poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    float tempcoef;
    avail = *Cs; // ���׽� C�� ���� ����

    // A�� B ���׽��� �պ�
    while (As <= Ae && Bs <= Be) {
        switch (compare(terms[As].expon, terms[Bs].expon)) {
        case '>':
            attach(terms[As].coef, terms[As].expon); // A�� ���� C�� �߰�
            As++;
            break;
        case '=':
            tempcoef = terms[As].coef + terms[Bs].coef;
            if (tempcoef)
                attach(tempcoef, terms[As].expon); // A�� B�� ���� ���ϰ�, ����� 0�� �ƴϸ� C�� �߰�
            As++;
            Bs++;
            break;
        case '<':
            attach(terms[Bs].coef, terms[Bs].expon); // B�� ���� C�� �߰�
            Bs++;
            break;
        }

        // ���� A�� ���� C�� ����
        for (; As <= Ae; As++)
            attach(terms[As].coef, terms[As].expon);
        // ���� B�� ���� C�� ����
        for (; Bs <= Be; Bs++)
            attach(terms[Bs].coef, terms[Bs].expon);

        *Ce = avail - 1; // ���׽� C�� �� ����
    }
}

void main() {
    int Cs, Ce;
    poly_add2(0, 2, 3, 5, &Cs, &Ce); // ���׽� A(0~2)�� B(3~5)�� ���� ����� C�� ����
}
