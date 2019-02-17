//0-1 knapsack - dp

#include<stdio.h>

int max(int a, int b){
	return a>b?a:b;
}

int knapsackdp(int n,int val[],int wt[],int cap){

	int K[n+1][cap+1];
	for (int i = 0; i <= n; i++) { 
       		for (int w = 0; w <= cap; w++){ 
	           	if (i==0 || w==0)  K[i][w] = 0; 

           		else if (wt[i-1] <= w) 
                 	  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 

           		else K[i][w] = K[i-1][w]; 
   		} 
   	} 
  
   return K[n][cap]; 
}

int main(){

	int n,i,cap;
	printf("\nEnter number of items: ");
	scanf("%d",&n);
	int wt[n],val[n];
	printf("\nEnter values and weights of items: ");
	for(i=0; i<n; i++){
		scanf("%d%d",&val[i],&wt[i]);
	}

	printf("\nEnter knapsack capacity: ");
	scanf("%d",&cap);

	printf("\nMax Profit: %d\n",knapsackdp(n,val,wt,cap));
	return 0;
}
