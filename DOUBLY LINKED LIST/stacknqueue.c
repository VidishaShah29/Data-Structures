#include<stdio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list *left, *right;
};

typedef struct list* LIST;

LIST create_node(int data){

	LIST temp = (LIST)malloc(sizeof(struct list)); temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}

LIST insert_front(LIST root, int data){
	
	LIST temp = create_node(data);
	if(root == NULL){
		temp->right = temp->left = temp;	
		return temp;
	}
	
	LIST last = root->left;
	temp->left = last;	temp->right = root;
	root->left = temp;	last->right = temp;
	return temp;
}

LIST remove_front(LIST root){

	LIST temp = root, last = root->left, next = root->right;
	last->right = next;	next->left = last;
	free(temp);
	return next;	
}

LIST remove_last(LIST root){

	LIST last = root->left, seclast = last->left;
	seclast->right = root;	root->left = seclast;
	free(last);
	return root;
}

void display(LIST root){
	
	printf("DISPLAY\n");
	LIST temp = root;
	while(temp->right != root){
		printf("%d\t",temp->data);
		temp = temp->right;
	}
	printf("%d\t",temp->data);
}

void prompt(){

	printf("\n\n1. FIFO Insert		2. FIFO Remove \n");
	printf("3. LIFO Insert		      4. LIFO Remove \n");
	printf("5. Display		      6. Exit \n");
	
}

int main(){

	LIST root = NULL; int ch;
	int f = 1;
	while(f == 1){
		prompt();
		printf("Enter your Choice: \n");
		scanf("%d",&ch);
		int data, node;
		switch(ch){
			case 1: 
				scanf("%d",&data);
				root = insert_front(root, data);
				display(root);				
				break;

			case 2: 
				root = remove_last(root);
				display(root);			
				break;

			case 3: scanf("%d",&data);
				root = insert_front(root, data);
				display(root);				
				break;

			case 4: 
				root = remove_front(root);
				display(root);			
				break;

			case 5: display(root);
				break;

			case 6: f = 0;
				break;
		}
	}

	return 0;
}

