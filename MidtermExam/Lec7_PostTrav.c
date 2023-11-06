#include<stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
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
preorder(TreeNode* root) {
	if (root) {
		printf("%d\n", root->data); // Visit root node
		preorder(root->left); // Left subtree
		preorder(root->right); // Right subtree
	}
}
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // Left subtree
		printf("%d\n", root->data); // Visit root node
		inorder(root->right);// Right subtree
	}
}
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left); // Left subtree
		postorder(root->right); // Right subtree
		printf("%d\n", root->data); // Visit root node
	}
}
void main(){
	inorder(root);
	preorder(root);
	postorder(root);
}