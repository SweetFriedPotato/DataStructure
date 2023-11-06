#include <stdio.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;


void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}

	else {
		if (p == NULL) {
			printf("The preceding node cannot be NULL.\n");
			exit(1);
		}
		else {
			new_node->link = p->link;
			p->link = new_node;
		}
	}
}

//phead : 헤드 포인터의 포인터
void insert_first(ListNode** phead, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		new_node->link = *phead;
		*phead = new_node;
	}
}

void insert_last(ListNode** phead, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		new_node->link = NULL;
		struct ListNode* last = *phead;
		while (last->link != NULL)
			last = last->link;
		last->link = new_node;
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	if (*pheae == NULL) {
		printf("The list is blank.\n");
	}
	else {
		p->link = removed->link;
		free(removed);
	}
}

void remove_first(ListNode** phead, ListNode* removed) {
	if (*phead == NULL) {
		printf("The list is blank.\n");
	}
	else {
		*phead = (*phead)->link;
		free(removed);
	}
}

//visit operation_iteration
void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

//visit operation_iteration
void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

//visit operation_recursion
void display_recur(ListNode* head) {
	ListNode* p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		display_recur(p->link);
	}
}

ListNode* search(Listnode* head, int x) {
	ListNode* p;
	p = head;
	while (p != NULL) {
		if (p->data == x)return p;
		p = p->link;
	}
	return p;
}

ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL)return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}