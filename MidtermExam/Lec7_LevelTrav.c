#include<stdio.h>

// 15
// 4 20
// 1 16 25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

typedef TreeNode* element;
typedef struct QueueNode {
	element item;
	struct QueueNode* link;
} QueueNode;

typedef struct QueueType {
	QueueNode* front;
	QueueNode* rear;
} QueueType;

void level_order(TreeNode* ptr) {
	QueueType q;
	init(&q);
	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf("%d\n", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}
void main()
{
	printf("level traversal\n");
	level_order(root);
	printf("\n");
}