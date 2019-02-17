//WARSHALL'S ALGO

#include<stdio.h>
#include<stdlib.h>

void print_graph(int n,int arr[n][n]){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}

int main(){

	printf("\nEnter the number of nodes: ");
	int n;
	scanf("%d",&n);

	int arr[n][n];

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			arr[i][j] = 0;
		
	printf("\nEnter the directed edges, then 1 to continue else 0: \n");
	int a,b,y=1;
	while(y==1){

		scanf("%d%d%d",&a,&b,&y);
		arr[a-1][b-1] = 1;
	}

	printf("\nAdjacency Matrix Representation\n");	
	print_graph(n,arr);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j] == 1){

				for(int k=0; k<n; k++)
					if(arr[k][i] == 1)	arr[k][j] = 1;
			}
		}
	}

	printf("\nWarshall Matrix Representation\n");	
	print_graph(n,arr);
	return 0;
}
