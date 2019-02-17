#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *lchild, *rchild;
};

typedef struct tree* TREE;

TREE root = NULL;

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
	return root;
}

int max(int a, int b){

	if(a>b) return a;
	else return b;
}

int height(TREE root){

	if(root == NULL) return 0;
	return 1+max(height(root->lchild),height(root->rchild));
}

int dia(TREE root){

	if(root == NULL) return 0;
	int ld = dia(root->lchild);
	int rd = dia(root->rchild);
	int d = max(ld,rd);
	int ht = height(root->lchild) + height(root->rchild) + 1;
	return max(ht,d);
}

int totnodes(TREE root){

	if(root == NULL) return 0;
	return 1+ totnodes(root->lchild)+totnodes(root->rchild);
}

int main(){

	int f=1, node;
	printf("\nEnter node then 1 to continue, 0 to exit\n");
	while(f==1){
		scanf("%d%d",&node,&f);
		root= insert(root,node);
	}
	printf("Height of the Tree: %d\n",height(root));
	printf("Diameter of the Tree: %d\n",dia(root));
	printf("Total number of nodes in the Tree: %d\n",totnodes(root));
	return 0;
}
