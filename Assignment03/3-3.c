﻿#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

typedef struct {
	ListNode* head; // head pointer
	ListNode* tail; // Tail pointer
	int length; // # of nodes
} ListType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ListType* list) {
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}

int is_empty(ListType* list) {
	if (list->head == NULL) return 1;
	else return 0;
}

int get_length(ListType* list) {
	return list->length;
}

ListNode* get_node_at(ListType* list, int pos) {
	ListNode* tmp_node = list->head;
	if (pos < 0) return NULL;
	for (int i = 0; i < pos; i++) {
		tmp_node = tmp_node->link;
	}
	return tmp_node;
}

void insert_node(ListType* list, ListNode* before, ListNode* new_node) {
	if (list->head == NULL) {
		new_node->link = NULL;
		list->head = new_node;
		list->tail = new_node;
	}
	else {
		if (before == NULL) error("The preceding node cannot be NULL");
		else {
			new_node->link = before->link;
			before->link = new_node;
			if (before == list->tail) list->tail = new_node;
		}
	}
	list->length++;
}

void add_first(ListType* list, element data) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("Memory allocation error");
	new_node->data = data;
	if (list->head == NULL) {
		new_node->link = NULL;
		list->head = list->tail = new_node;
	}
	else {
		new_node->link = list->head;
		list->head = new_node;
	}
	list->length++;
}

void add_last(ListType* list, element data) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("Memory allocation error");
	new_node->data = data;
	new_node->link = NULL;

	if (list->tail == NULL) {
		list->head = list->tail = new_node;
	}
	else {
		ListNode* p = list->tail;
		p->link = new_node;
		list->tail = new_node;
	}
	list->length++;
}

void add(ListType* list, int position, element data) {
	ListNode* p;
	// positon 0ÀÏ ¶§ insert_node¿¡¼­ ¾ÈµÈ´Ù.
	if ((position >= 1) && (position <= list->length - 1)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL) error("Memory allocation error");
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(list, p, node);
	}
	else if (position == 0) {
		add_first(list, data);
	}
	else if (position == list->length) {
		add_last(list, data);
	}
}

void remove_node(ListType* list, ListNode* p, ListNode* removed) {
	if (list->head == NULL) {
		printf("The list is blank.\n");
	}
	else {
		if (p == NULL) printf("The preceding node cannot be NULL.\n");
		else {
			p->link = removed->link;
			free(removed);
			if (removed == list->head) list->head = list->head->link;
			if (removed == list->tail) list->tail = p;
		}
	}
	list->length--;
}

void delete_first(ListType* list) {
	if (!is_empty(list)) {
		ListNode* removed = list->head;
		list->head = removed->link;
		free(removed);
		list->length--;
	}
}

void delete_last(ListType* list) {
	if (!is_empty(list)) {
		ListNode* p = get_node_at(list, list->length - 2);
		if (p != NULL) {
			ListNode* removed = list->tail;
			p->link = NULL;
			list->tail = p;
			free(removed);
			list->length--;
		}
		else {
			// Only one element in the list
			free(list->head);
			init(list);
		}
	}
}

void delete(ListType* list, int pos) {
	if (!is_empty(list) && (pos >= 1) && (pos < list->length - 1)) {
		ListNode* p = get_node_at(list, pos - 1);
		ListNode* removed = get_node_at(list, pos);
		remove_node(list, p, removed);
	}
	else if (!is_empty(list) && pos == 0) {
		delete_first(list);
	}
	else if (!is_empty(list) && pos == list->length - 1) {
		delete_last(list);
	}
}

void display(ListType* list) {
	ListNode* node = list->head;
	printf("(");
	for (int i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf(")\n");
}

int is_in_list(ListType* list, element item) {
	ListNode* p;
	p = list->head;
	while (p != NULL) {
		if (p->data == item)
			break;
		p = p->link;
	}
	if (p == NULL) return false;
	else return true;
}

element get_entry(ListType* list, int pos) {
	ListNode* p;
	if (pos >= list->length) error("Position error");
	p = get_node_at(list, pos);
	return p->data;
}

int main() {
	ListType list1;
	init(&list1);
	add_first(&list1, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 2, 70);
	display(&list1);

	delete(&list1, 2);
	delete_first(&list1);
	delete_last(&list1);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == true ? "TRUE" : "FALSE");
	printf("%d\n", get_entry(&list1, 0));

	return 0;
}