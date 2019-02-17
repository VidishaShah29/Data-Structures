//FLOYD'S ALGO - all pairs shortest path

#include<stdio.h>
#include<stdlib.h>

void print_graph(int n,int arr[n][n]){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}

int min(int a, int b){

	if(a<0) return b;
	if(b<0) return a;
	return (a<b)?a:b;
}

int main(){

	printf("\nEnter the number of nodes: ");
	int n,i,j,k;
	scanf("%d",&n);

	int arr[n][n];

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(i == j)	arr[i][j] = 0;
			else arr[i][j] = -1;
		
	printf("\nEnter the edges and their distances, then 1 to continue else 0: \n");
	int a,b,d,y=1;
	while(y==1){

		scanf("%d%d%d%d",&a,&b,&d,&y);
		arr[a-1][b-1] = d;
	}

	printf("\nAdjacency Matrix Representation\n");	
	print_graph(n,arr);

	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if(arr[i][k]==-1 || arr[k][j]==-1) continue;
				else
				arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);

	printf("\nFloyd's Matrix Representation\n");	
	print_graph(n,arr);
	return 0;
}
