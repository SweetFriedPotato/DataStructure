#include <stdio.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//phead: pointer of head pointer
//p : preceding node
//node : node to be inserted
void insert_first(ListNode** phead, ListNode* node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}

void insert_last(ListNode** phead, ListNode* node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}