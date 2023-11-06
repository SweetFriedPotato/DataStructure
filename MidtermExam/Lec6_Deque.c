#include <stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

typedef struct DequeType {
	DlistNode* head; 
	DlistNode* tail;
} DequeType;

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) {
	DlistNode* node = (DlistNode*)malloc(sizeof(DlistNode)); 
	if (node == NULL) error("Memory allocation error"); 
	node->llink = llink;
	node->data = item;
	node->rlink = rlink; 
	return node;
}

void add_rear(DequeType* dq, element item) {
	DlistNode* new_node = create_node(dq->tail, item, NULL); 
	if (is_empty(dq))
		dq->head = new_node;
	else
		dq->tail->rlink = new_node; 
	dq->tail = new_node;
}

void add_front(DequeType* dq, element item) {
	DlistNode* new_node = create_node(NULL, item, dq->head); 
	if (is_empty(dq))
		dq->tail = new_node;
	else
		dq->head->llink = new_node; 
	dq->head = new_node;
}

element delete_rear(DequeType* dq) {
	element item;
	DlistNode* removed_node;

	if (is_empty(dq))
		printf(¡°Deque is empty\n¡±);
	else {
		removed_node = dq->tail;
		item = removed_node->data;
		dq->tail = dq->tail->llink;
		if (dq->tail == NULL)
			dq->head = NULL;
		else
			dq->tail->rlink = NULL;
	}
	return item;
}

element delete_front(DequeType* dq) {
	element item;
	DlistNode* removed_node;
	if (is_empty(dq))  
		printf(¡°Deque is empty\n¡±);
	else {
		removed_node = dq->head; // Node to be deleted 
		item = removed_node->data;
		dq->head = dq->head->rlink; // Change head pointer 
		free(removed_node);
		if (dq->head == NULL) // If empty, after removing the node 
			dq->tail = NULL;
		else
			dq->head->llink = NULL;
	}
	return item;		
}
