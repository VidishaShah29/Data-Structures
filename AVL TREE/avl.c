//create avl tree by iterative insertion

#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *lchild, *rchild;
};

typedef struct tree* TREE;

TREE root = NULL;

int max(int a, int b){

	if(a>b) return a;
	else return b;
}

int height(TREE root){

	if(root == NULL) return 0;
	return 1+max(height(root->lchild),height(root->rchild));
}

int balance_factor(TREE root){

	return height(root->lchild)-height(root->rchild);
}

TREE leftRotate(TREE root){

	TREE child = root->rchild, temp = child->lchild;
	child->lchild = root;
	root->rchild = temp;

	return child;
}

TREE rightRotate(TREE root){

	TREE child = root->lchild, temp = child->rchild;
	child->rchild = root;
	root->lchild = temp;

	return child;
}

TREE insert(TREE root, int data){
	
	if(root == NULL){
		TREE temp = (TREE)malloc(sizeof(struct tree));
		temp->lchild = temp->rchild = NULL;
		temp->data = data;
		return temp;
	}
	if(data<root->data){
		root->lchild = insert(root->lchild, data);
	}
	if(data>root->data){
		root->rchild = insert(root->rchild, data);
	}

	int bal = balance_factor(root);
	if(bal<-1 && data>root->rchild->data)	return leftRotate(root);
	//left case

	if(bal<-1 && data<root->rchild->data)
	//lr case
	{
		root->rchild = rightRotate(root->rchild);
		return leftRotate(root);
	}

	if(bal>1 && data<root->lchild->data)	return rightRotate(root);
	//right case

	if(bal>1 && data>root->lchild->data)
	//rl case
	{
		root->lchild = leftRotate(root->lchild);
		return rightRotate(root);
	}
	return root;
}

void preorder(TREE root){

	if(root == NULL) return;
	printf("%d ",root->data);
	preorder(root->lchild);	
	preorder(root->rchild);	
}

int main(){

	int f=1, node;
	printf("\nEnter node then 1 to continue, 0 to exit\n");
	while(f==1){
		scanf("%d%d",&node,&f);
		root= insert(root,node);
	}
	printf("\nPREORDER\n");
	preorder(root);
	return 0;
}
