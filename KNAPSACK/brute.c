//knapsack - brute force

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int powcal(int a, int b){

	int res=1;
	while(b--) res*=a;
	return res;
}

int knapsack(int n,int val[],int wt[],int cap,int set[][n+1],int power){

	int max = -999,wts,vals;
	for(int i=0;i<power;i++){
		wts=0; vals=0;
		for(int j=0; j<=n; j++)
		{
			wts += set[i][j]*wt[j];
			vals += set[i][j]*val[j];
			if(wts<=cap && vals>max){
				max=vals;
			}
		}
	}
	return max;
}

void main(){

	int n,i,j;
	printf("\nEnter number of elements: \n");
	scanf("%d",&n);
	
	int power = powcal(2,n);
	int set[power][n+1];
	memset(set,0,sizeof(set));
	for(i=0; i<power; i++){
		for(j=0; j<n; j++)
			if(i & (1<<j))	set[i][j]=1;
	}

	int wt[n],val[n];
	printf("\nEnter values and weights of items: ");
	for(i=0; i<n; i++){
		scanf("%d%d",&val[i],&wt[i]);
	}
	int cap;
	printf("\nEnter knapsack capacity: ");
	scanf("%d",&cap);

	printf("\nMax Profit: %d\n",knapsack(n,val,wt,cap,set,power));

}
	
