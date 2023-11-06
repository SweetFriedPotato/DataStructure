#include <stdio.h>
#define MAX_TERMS 101

// 다항식 항(term)을 나타내는 구조체 정의
struct {
    float coef; // 계수
    int expon;  // 지수
} terms[MAX_TERMS] = { {8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0} };

int avail = 6;

// 두 정수를 비교하는 함수
char compare(int a, int b) {
    if (a > b) return '>';       // a가 b보다 큰 경우
    else if (a == b) return '='; // a와 b가 같은 경우
    else return '<';            // a가 b보다 작은 경우
}

// 새로운 항을 다항식에 추가하는 함수
void attach(float coef, int expon) {
    if (avail > MAX_TERMS) {
        fprintf(stderr, "항이 너무 많습니다.\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail++].expon = expon;
}

// 다항식 C = 다항식 A + 다항식 B를 계산하는 함수
int poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    float tempcoef;
    avail = *Cs; // 다항식 C의 시작 지수

    // A와 B 다항식을 합병
    while (As <= Ae && Bs <= Be) {
        switch (compare(terms[As].expon, terms[Bs].expon)) {
        case '>':
            attach(terms[As].coef, terms[As].expon); // A의 항을 C에 추가
            As++;
            break;
        case '=':
            tempcoef = terms[As].coef + terms[Bs].coef;
            if (tempcoef)
                attach(tempcoef, terms[As].expon); // A와 B의 항을 더하고, 결과가 0이 아니면 C에 추가
            As++;
            Bs++;
            break;
        case '<':
            attach(terms[Bs].coef, terms[Bs].expon); // B의 항을 C에 추가
            Bs++;
            break;
        }

        // 남은 A의 항을 C에 복사
        for (; As <= Ae; As++)
            attach(terms[As].coef, terms[As].expon);
        // 남은 B의 항을 C에 복사
        for (; Bs <= Be; Bs++)
            attach(terms[Bs].coef, terms[Bs].expon);

        *Ce = avail - 1; // 다항식 C의 끝 지수
    }
}

void main() {
    int Cs, Ce;
    poly_add2(0, 2, 3, 5, &Cs, &Ce); // 다항식 A(0~2)와 B(3~5)를 더한 결과를 C에 저장
}
