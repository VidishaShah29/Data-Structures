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

TREE SearchElseInsert(TREE root, int data){

	if(root == NULL){
		TREE temp = (TREE)malloc(sizeof(struct tree));
		temp->lchild = temp->rchild = NULL;
		temp->data = data;
		return temp;
	}
	if(root->data == data)
		printf("Node found\n");
	else if(data < root->data){
		root->lchild = SearchElseInsert(root->lchild, data);
	}	
	else if(data > root->data){
		root->rchild= SearchElseInsert(root->rchild, data);
	}	
	return root;
}

void inorder(TREE root){
	if(root == NULL) return;
	inorder(root->lchild);
	printf("%d\t",root->data);
	inorder(root->rchild);
}

void preorder(TREE root){
	if(root == NULL) return;
	printf("%d\t",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

void postorder(TREE root){
	if(root == NULL) return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\t",root->data);
}

void prompt(){

	printf("\n1. INSERT                2. SEARCH ELSE INSERT\n");
	printf("3. PREORDER              4. INORDER\n");
	printf("5. POSTORDER             6. EXIT\n");
}

int main(){

	int ch, data;
	printf("\nBINARY TREE\n"); int f = 1;
	while(f == 1){
		prompt();
		printf("Enter your Choice: \n");
		scanf("%d",&ch);
		
		switch(ch){
			case 1: 
				scanf("%d",&data);
				root = insert(root, data);			
				break;

			case 2: 
				scanf("%d",&data);
				root = SearchElseInsert(root, data);			
				break;

			case 3: printf("PREORDER\n");
				preorder(root);
				break;

			case 4: printf("INORDER\n");
				inorder(root);
				break;

			case 5: printf("POSTORDER\n");
				postorder(root);
				break;

			case 6: f = 0;
				break;
		}
	}

	return 0;
}
