#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
// n1
// / |
// n2 n3
void main()
{
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 10; // node n1
	n1->left = n2;
	n1->right = n3;
	n2->data = 20; // node n2
	n2->right = NULL;
	n3->data = 30; // node n3
	n3->right = NULL;