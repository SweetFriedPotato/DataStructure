#include <stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct StackNode {
	element item;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory Allocation Error\n");
		exit(1);
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
	}
	else {
		StackNode* temp = s->top;
		int item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}