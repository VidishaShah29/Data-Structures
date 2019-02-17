//doubly linked list 
//create, add at front, insert left to a key, delete all key, search, display

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
	if(root == NULL)
		return temp;

	temp->right = root;
	root->left = temp;
	return temp;
}

LIST insertbefore(LIST root, int node, int data){

	LIST temp = create_node(data), start = root;
	while(start != NULL){
		if(start->data == node){
			LIST prev;
			prev = start->left;
			temp->left = prev; temp->right = start;
			prev->right = temp; start->left = temp;
			return root;
		}
		start = start->right;
	}
	printf("Node not found\n");
}

LIST deleteall(LIST root, int data){

	LIST temp = root;
	while(temp != NULL){
		if(temp->data == data){
			LIST prev = temp->left, next = temp->right;
			prev->right = next;
			next->left = prev;
			free(temp);
		}
		temp = temp->right;
	}
	return root;
}

int search(LIST root, int data){

	while(root != NULL){
		if(root->data == data)
			return 1;
		root = root->right;
	}
	return 0;
}

void display(LIST root){
	
	printf("DISPLAY\n");
	while(root != NULL){
		printf("%d\t",root->data);
		root = root->right;
	}
}

void prompt(){

	printf("\n1. CREATE LIST/ ADD AT FRONT               2. INSERT TO LEFT OF A NODE\n");
	printf("3. DELETE ALL OCCURENCES OF A KEY          4. SEARCH FOR A KEY\n");
	printf("5. DISPLAY THE LIST                        6. EXIT\n");
}

int main(){

//create, add at front, insert left to a key, delete all key, search, display
	LIST root = NULL; int ch;
	printf("\nDOUBLY LINKED LIST\n"); int f = 1;
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
				scanf("%d %d",&data, &node);
				root = insertbefore(root, node, data);
				display(root);			
				break;

			case 3: scanf("%d",&data);
				root = deleteall(root, data);
				display(root);
				break;

			case 4: 
				scanf("%d", &data);
				if(search(root, data) == 1)
					printf("Node found\n");
				else printf("Node not found\n");
				break;

			case 5: display(root);
				break;

			case 6: f = 0;
				break;
		}
	}

	return 0;
}

