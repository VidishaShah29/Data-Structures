//comparison counting algorithm

#include<stdio.h>

void counting_sort(int arr[], int n){

	int count[n],res[n];
	int i,j;
	for(i=0; i<n; i++)	count[i]=0;

	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(arr[i]<arr[j])
				count[j]++;
			else count[i]++;

	for(i=0; i<n; i++)
		res[count[i]] = arr[i];
	for(int i=0; i<n; i++)
		printf("%d ",res[i]);
}

int main(){

	int arr[] = {98,1,22,39,88,60};
	int n = sizeof(arr)/sizeof(arr[0]);
	counting_sort(arr,n);

	return 0;
}
