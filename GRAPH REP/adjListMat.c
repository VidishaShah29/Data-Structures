//Implementing Adjacency lists and matrices

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

LIST insert_last(LIST root, int data){
	
	LIST temp = create_node(data), curr= root;
	if(root == NULL)
		return temp;
	
	while(curr->next!=NULL)	curr = curr->next;
	curr->next = temp;
	return root;
}

void display_adjMat(int adjMat[][10],int n){

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d\t",adjMat[i][j]);
		}
		printf("\n");
	}
}

void display_adjList(LIST root){

	LIST temp = root;
	while(temp != NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
}

int main(){

	printf("\nEnter the number of nodes and edges: ");
	int n,e,i,j,a,b;
	scanf("%d%d",&n,&e);

	int adjMat[n][10];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			adjMat[i][j] = 0;
		}
	}
	
	LIST adjList[n];
	for(i=0; i<n; i++)	adjList[i] = NULL;

	printf("\nEnter the edges(if edge is directed from i to j, enter i j): \n");
	for(i=0; i<e; i++){
	
		scanf("%d%d",&a,&b);
		adjMat[a-1][b-1] = 1;
		adjList[a-1] = insert_last(adjList[a-1],b);
	}

	printf("\nAdjacency List Representation\n");	
	for(i=0; i<n; i++){
		printf("%d\t",i+1);
		display_adjList(adjList[i]);
		printf("\n");
	}

	printf("\nAdjacency Matrix Representation\n");	
	display_adjMat(adjMat,n);

	return 0;
}
