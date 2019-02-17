//bfs 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int q[100],f=-1,r=-1;

void enqueue(int q[],int vertex){

	if(r == -1)	f=0;
	q[++r]=vertex;
}

void dequeue(){
	f++;
}

int isempty(){

	if(r-f<0) return 1;
	return 0;
}

void bfs(int n, int graph[n][n], int visited[n], int vertex){

	enqueue(q,vertex);
	visited[vertex] = 1;
	int front,i;
	while(!isempty()){
		front = q[f];
		printf("%d->",front+1);
		dequeue();

		for(i=0; i<n; i++){
			if(graph[front][i] && !visited[i]){
				visited[i]=1; enqueue(q,i);
			}
		}
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
	bfs(n,graph,visited,vertex-1);
	return 0;	
}
