#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode* rlink;
	struct DlistNode* llink;
}DlistNode;

typedef struct {
	DlistNode* top;
}LinkedStackType;


void init(LinkedStackType* s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

void push(LinkedStackType* s, element data)
{
	DlistNode* temp = (DlistNode*)malloc(sizeof(DlistNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}
	else {
		if (is_empty(s)) {
			temp->data = data;
			temp->rlink = temp->llink = temp;
		}
		else {
			temp->data = data;

			temp->llink = s->top;
			temp->rlink = s->top->rlink;

			s->top->rlink->llink = temp;
			s->top->rlink = temp;
		}
		s->top = temp;
	}

}

element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {

		DlistNode* temp = s->top;
		int item = temp->data;
		if (s->top == s->top->llink) { // s->top ==s->top->rlink ÇØµµ ¹«°ü
			s->top = NULL;
		}
		else {
			temp->llink->rlink = temp->rlink;
			temp->rlink->llink = temp->llink;

			s->top = temp->llink;
		}
		free(temp);
		return item;
	}
}

element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}

void main()
{
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}