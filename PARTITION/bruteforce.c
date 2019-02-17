//partition problem - brute force

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int powcal(int a, int b){

	int res=1;
	while(b--) res*=a;
	return res;
}

int main(){

	int n,i,j;
	printf("\nEnter number of elements followed by the set: \n");
	scanf("%d",&n);
	
	int power = powcal(2,n);
	int set[power][n+1];
	memset(set,0,sizeof(set));
	for(i=0; i<power; i++){
		for(j=0; j<n; j++)
			if(i & (1<<j))	set[i][j]=1;
	}

	int arr[n];
	for(i=0; i<n; i++)	scanf("%d",&arr[i]);

	int sum = 0;
	for(i=0; i<n; i++) sum += arr[i];
	if(sum%2 != 0){

		printf("\nNO PARTITION POSSIBLE\n");
		exit(1);
	}

	for(i=0; i<power; i++)
		for(j=0; j<n; j++)
			set[i][n] += set[i][j]*arr[j];

	for(i=0; i<power; i++){
		for(j=0; j<=n; j++)	printf("%d ",set[i][j]);
	printf("\n");
	}

	for(i=0; i<power-1; i++)
	{

		for(j=i+1; j<power; j++)
			if(set[i][n] == set[j][n]){

				printf("\nPARTITION POSSIBLE\n");
				exit(1);
			}
	}	
		
	printf("\nNO PARTITION POSSIBLE\n");
	return 0;
}
