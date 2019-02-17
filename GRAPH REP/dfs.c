//dfs 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void dfs(int n, int graph[n][n], int visited[n], int vertex){

	printf("%d\t",(vertex));
	visited[vertex-1] = 1;

	for(int i=0; i<n; i++){
		if(graph[vertex-1][i] && !visited[i] && i!=vertex)
			dfs(n,graph,visited,i+1);
	}
}

int main(){

	printf("\nEnter the number of nodes: ");
	int n,a,b,vertex, f=1;
	scanf("%d",&n);
	int graph[n][n],visited[n];
	memset(graph,0,sizeof(graph[0][0])*n*n);
	memset(visited,0,sizeof(visited));
	while(f==1){
		printf("\nEnter directed edge i->j: ");
		scanf("%d%d",&a,&b);
		graph[a-1][b-1] = 1;
		printf("\nEnter 1 to continue, 0 to exit: ");
		scanf("%d",&f);	
	}

	printf("\nAdjacency Matrix: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}

	printf("\nEnter starting vertex: ");
	scanf("%d",&vertex);
	dfs(n,graph,visited,vertex);
	return 0;	
}
