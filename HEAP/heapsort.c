//heap sort - bottom up max heap construction

#include<stdio.h>

void swap(int* a,int* b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int i,int h[],int n){

	int k=i, val=h[i], heap=0;
	while(heap==0 && 2*k<=n){

		int j=2*k;
		if(j<n){
			if(h[j]<h[j+1]) j=j+1;
		}	
		if(val>=h[j])	heap=1;
		else{
			h[k]=h[j]; k=j;
		}
	}
	h[k]=val;	
}

void heapsort(int h[],int n){

	while(n>1){

		swap(&h[n],&h[1]);
		n--;
		heapify(1,h,n);
	}
}

int main(){

	int a[] = {-99,6,5,4,3,2,1};
	int n = sizeof(a)/sizeof(a[0]);

	for(int i=n/2; i>=1; i--)
		heapify(i,a,n);
	heapsort(a,n);

	printf("\nSortedArray:\n");
	for(int i=1;i<n;i++) printf("%d ",a[i]);
	return 0;
}
