#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode (int data){
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

int count(Node* node) {
    if (node == NULL) {
        return 0; 
    }
    if (node->left == NULL && node->right == NULL) {
        return 1; 
    }
    return count(node->left) + count(node->right);
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
	int leafCount = count(tree);
    printf("So la trong cay nhi phan la : %d\n", leafCount);

    return 0;
	
}

