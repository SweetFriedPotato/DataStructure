#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy_s �Լ��� ����ϱ� ���� �ʿ��� ��� ���� �߰�

// ����ü Example ����
struct Example {
    int number;         // ������ ���� number ����
    char name[10];      // ���� 10�� ���� �迭 name ����
};

// main �Լ� ����
int main() {
    struct Example* p;  // ����ü Example ������ p ����
    p = (struct Example*)malloc(2 * sizeof(struct Example)); // �޸� �Ҵ�

    if (p == NULL) { // �޸� �Ҵ� ���� ��
        fprintf(stderr, "�޸𸮸� �Ҵ��� �� �����ϴ�.\n"); // ���� �޽��� ���
        exit(1); // ���α׷� ����
    }

    p->number = 1; // ù ��° Example ����ü�� number ����� 1 �Ҵ�
    strcpy_s(p->name, 10, "Park"); // ù ��° Example ����ü�� name ����� "Park" ����
    // strcpy_s �Լ��� ����Ͽ� ���� �����÷ο� ���� (���� ũ�⸦ 10���� ����)

    (p + 1)->number = 2; // �� ��° Example ����ü�� number ����� 2 �Ҵ�
    strcpy_s((p + 1)->name, 10, "Kim"); // �� ��° Example ����ü�� name ����� "Kim" ����

    printf("%d   %s\n", p->number, p->name); // ù ��° ����ü ���� ���
    printf("%d   %s\n", (p + 1)->number, (p + 1)->name); // �� ��° ����ü ���� ���

    free(p); // �������� �Ҵ��� �޸� ����

    return 0; // ���α׷� ����
}
