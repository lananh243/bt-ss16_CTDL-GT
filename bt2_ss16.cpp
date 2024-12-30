#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node* node, int data){
	if(node == NULL){
		node = createNode(data);
	}
	if(data < node->data){
		node->left = insertNode(node->left, data);
	}else if(data > node->data){
		node->right = insertNode(node->right, data);
	}
	return node;
}

void preorderTraversal(Node* node){
	if(node != NULL){
		printf("%d \t", node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
}

void inOrder(Node* node){
	if(node != NULL){
		inOrder(node->left);
		printf("%d \t", node->data);
		inOrder(node->right);
	}
} 

void postOrder(Node* node){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf("%d \t", node->data);
	}
}

int main() {
	Node* tree = NULL;
	int n,value;
	printf("Nhap so luong phan tu : ");
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ",i);
		scanf("%d",&value);
		tree = insertNode(tree, value);
	}
	printf("Duyet theo tien thu tu : ");
	preorderTraversal(tree);
	printf("\n");
	printf("Duyet theo trung thu tu : ");
	inOrder(tree);
	printf("\n");
	printf("Duyet theo hau thu tu : ");
	postOrder(tree);
}

