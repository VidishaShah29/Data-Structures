//quick sort

#include<stdio.h>

int opcount = 0;

void swap(int *a,int *b){

	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int* a,int start,int end){
	opcount++;
	int p=a[end],i=start,j;
	for(j=start;j<end;j++){

		if(a[j]<=p){
			
			swap(&a[i],&a[j]); i++;
		}
	}
	swap(&a[i],&a[end]);
	return i;
}

void quickSort(int a[], int start, int end){
	
	if(start<=end){

		int p = partition(a,start,end);
		quickSort(a,start,p-1);
		quickSort(a,p+1,end);	
	}	
}

int main(){

	int a[] = {9,3,7,2,0,8};
	int n = sizeof(a)/sizeof(a[0]);
	quickSort(a,0,n-1);

	printf("\nSorted Array: \n");
	for(int i=0; i<n; i++)
		printf("%d ",a[i]);
	printf("\nOpcount: %d\n",opcount);

	return 0;
}
