#include <stdio.h>
#include <stdlib.h>

// 이중 연결 리스트의 노드 구조체 정의
typedef struct DlistNode {
    int data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
} DlistNode;

DlistNode* create_new_node(int data) {
    DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->llink = NULL;
        new_node->rlink = NULL;
    }
    return new_node;
}

void dinsert_first_node(DlistNode** head, DlistNode** tail, int data) {
    DlistNode* new_node = create_new_node(data);
    if (new_node != NULL) {
        new_node->rlink = (*head)->rlink;
        new_node->llink = *head;
        (*head)->rlink->llink = new_node;
        (*head)->rlink = new_node;
    }
}

void dinsert_last_node(DlistNode** head, DlistNode** tail, int data) {
    DlistNode* new_node = create_new_node(data);
    if (new_node != NULL) {
        new_node->llink = (*tail)->llink;
        new_node->rlink = *tail;
        (*tail)->llink->rlink = new_node;
        (*tail)->llink = new_node;
    }
}

int main() {
    DlistNode* head = create_new_node(0);
    DlistNode* tail = create_new_node(0);

    dinsert_first_node(&head, &tail, 10);

    dinsert_last_node(&head, &tail, 20);

    DlistNode* current = head->rlink;
    while (current != tail) {
        printf("%d ", current->data);
        current = current->rlink;
    }

    free(head);
    free(tail);

    return 0;
}