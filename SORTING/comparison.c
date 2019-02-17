//distribution counting method sort

#include<stdio.h>
#include<string.h>

void comparisoncount_sort(int arr[], int n){

	int count[100],i;
	memset(count, 0, sizeof(count));
	for(i=0; i<n; i++)	++count[arr[i]];

	char out[n]; 
  	for(i=1; i<100; i++)	count[i] += count[i-1];

	for (i = 0; i<n; i++) 
	{ 
		out[count[arr[i]-1]] = arr[i];  
	} 
  
	for (i = 0; i<n; i++) 
       		arr[i] = out[i]; 

	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
}

int main(){

	int arr[] = {94,1,22,39,88,60};
	int n = sizeof(arr)/sizeof(arr[0]);
	comparisoncount_sort(arr,n);

	return 0;
}
