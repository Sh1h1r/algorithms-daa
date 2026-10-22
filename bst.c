#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}node;

node* create(int value){
	node* new_node = malloc(sizeof(node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = value;
	return new_node;
}

node* insert(node* root,int value){
	if(root == NULL) return create(value);
	if(value < root->data){
		root->left = insert(root->left,value);
	}

	else if(value > root->data){
		root->right = insert(root->right,value);
	}

	return root;
}

void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

int main(){
	node* root = NULL;
	int arr[] = {50,20,30,70,80,40,10};
	int n = 7;
	for(int i = 0; i < n; i++){
		root = insert(root,arr[i]);
	}

	printf("inorder:");
	inorder(root);
	return 0;
}
