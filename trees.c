#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};	

struct node* create() {
	int x;
	struct node* newnode;
	newnode = (struct node*) malloc (sizeof(struct node*));
	printf("Enter data (-1 for no node): ");
	scanf("%d",&x);
	if(x == -1) {
		return NULL;
	}
	newnode->data = x;
	printf("Enter for left child of %d\n",x);
	newnode->left = create();
	printf("Enter for right child of %d\n",x);
	newnode->right = create();
	return newnode;
}

void Preorder(struct node *root) {
	if(root == 0) {
		return;
	}
	printf("%d ",root->data);
	Preorder(root->left);
	Preorder(root->right);
}

int main() {
	struct node* root;
	root = create();
	printf("%d",root->data);
	printf("Preorder Traversal is: ");
	Preorder(root);
}
