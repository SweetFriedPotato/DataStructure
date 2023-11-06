#include <stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct QueueNode {
    element item;
    struct QueueNode* link;
}QueueNode;

typedef struct QueueType {
    QueueNode* front;
    QueueNode* rear;
}QueueType;

void error(char* message) {
    fprintf(stderr, "%s\n", message); 
    exit(1);
}

int is_empty(QueueType* q) {
    return (q->front == NULL);
}

void init(QueueType* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(QueueType* q, element item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if (temp == NULL)
        printf("Memory cannot be allocated.\n");
    else {
        temp->item = item;
        temp->link = NULL;
        if (is_empty(q)) {
            q->front = temp;
            q->rear = temp;
        }
        else {
            q->rear->link = temp;
            q->rear = temp;
        }
    }
}


element dequeue(QueueType* q) {
    QueueNode* temp = q->front;
    element item;
    if (is_empty(q)) {
        error("Queue is empty.");
    }

    else {
        item = temp->item;
        q->front = q->front->link;
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);

        return item;
    }
}

element peek(QueueType* q) {
    if (is_empty(q)) 
        error("Queue is empty."); 
    else { return (q->front->item); }
}
void main() {
    QueueType q;

    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("dequeue()=%d\n", dequeue(&q)); 
    printf("dequeue()=%d\n", dequeue(&q)); 
    printf("dequeue()=%d\n", dequeue(&q));
}

