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

Node* insertNode(Node* node,int data){
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

void inorderTraversal(Node* node){
	if(node != NULL) {
		inorderTraversal(node->left);
		printf("%d \t", node->data);
		inorderTraversal(node->right);
	}
} 
int searchNode(Node* node, int key){
	if(node == NULL){
		return 0;
	}
	if(node->data == key){
		return 1;
	}
	if(key < node->data){
		return searchNode(node->left, key);
	}
	return searchNode(node->right, key);
}

int main() {
	Node* tree = NULL;
	int n, value, searchValue;
	printf("Nhap so luong phan tu : ");
	scanf("%d",&n);
	
	for(int i; i < n; i++){
		printf("a[%d] : ", i + 1);
		scanf("%d",&value);
		tree = insertNode(tree, value);
		
	}
	printf("Duyet cay theo thu tu inorder: \n");
    inorderTraversal(tree);
    printf("\n"); 
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);
    if(searchNode(tree, searchValue)){
    	printf("Gia tri %d ton tai trong cay",searchValue); 
	}else{
		printf("Gia tri %d ko ton tai trong cay",searchValue);
	} 

}

