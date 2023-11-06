#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy_s 함수를 사용하기 위해 필요한 헤더 파일 추가

// 구조체 Example 정의
struct Example {
    int number;         // 정수형 변수 number 선언
    char name[10];      // 길이 10인 문자 배열 name 선언
};

// main 함수 시작
int main() {
    struct Example* p;  // 구조체 Example 포인터 p 선언
    p = (struct Example*)malloc(2 * sizeof(struct Example)); // 메모리 할당

    if (p == NULL) { // 메모리 할당 실패 시
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n"); // 에러 메시지 출력
        exit(1); // 프로그램 종료
    }

    p->number = 1; // 첫 번째 Example 구조체의 number 멤버에 1 할당
    strcpy_s(p->name, 10, "Park"); // 첫 번째 Example 구조체의 name 멤버에 "Park" 복사
    // strcpy_s 함수를 사용하여 버퍼 오버플로우 방지 (버퍼 크기를 10으로 지정)

    (p + 1)->number = 2; // 두 번째 Example 구조체의 number 멤버에 2 할당
    strcpy_s((p + 1)->name, 10, "Kim"); // 두 번째 Example 구조체의 name 멤버에 "Kim" 복사

    printf("%d   %s\n", p->number, p->name); // 첫 번째 구조체 내용 출력
    printf("%d   %s\n", (p + 1)->number, (p + 1)->name); // 두 번째 구조체 내용 출력

    free(p); // 동적으로 할당한 메모리 해제

    return 0; // 프로그램 종료
}
