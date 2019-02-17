//singly linked list 
//create, add at front, insert left to a key, delete all key, search, display

#include<stdio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list *next;
};

typedef struct list* LIST;

LIST create_node(int data){

	LIST temp = (LIST)malloc(sizeof(struct list)); temp->next = NULL;
	temp->data = data;
	return temp;
}

LIST insert_front(LIST root, int data){
	
	LIST temp = create_node(data);
	if(root == NULL)
		return temp;

	temp->next = root;
	return temp;
}

LIST insertbefore(LIST root, int node, int data){

	LIST temp = create_node(data), start = root, prev;
	if(start->data == node){
		temp->next = start;
		return temp;
	}
	while(start != NULL){
		if(start->data == node){
			temp->next = start;
			prev->next = temp;
			return root;
		}
		prev = start;
		start = start->next;
	}
	printf("Node not found\n");
}

LIST deleteall(LIST root, int data){

	while(root->data == data)	root = root->next;
	LIST temp = root, prev;
	
	while(temp != NULL){
		if(temp->data == data){
			prev->next = temp->next;
			temp = prev;
		}
		prev = temp;
		temp = temp->next;
	}
	return root;
}

int search(LIST root, int data){

	while(root != NULL){
		if(root->data == data)
			return 1;
		root = root->next;
	}
	return 0;
}

void display(LIST root){
	
	printf("\nDISPLAY\n");
	while(root != NULL){
		printf("%d\t",root->data);
		root = root->next;
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
	printf("\nSINGLY LINKED LIST\n"); int f = 1;
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
