//bottom up heap construction

#include<stdio.h>

int opcount = 0;

void heapify(int h[], int n){

	int i,j,val,heap=0;
	for(i=n/2; i>=1; i--){

		j=i; val=h[i]; heap=0;
		while(heap==0 && 2*j<=n){
			opcount++;
			int k=2*j;
			if(k<n)
			 if(h[k]<h[k+1]) k=k+1;
			if(val>=h[k])	heap=1;
			else{
				h[j]=h[k]; j=k;
				}
		}
		h[j]=val;
	}
}

void main(){

	printf("\nEnter number of elements: ");
	int i,n; scanf("%d",&n);
	int h[n+1];

	printf("\nEnter the elements: ");
	for(i=1; i<=n; i++)
		scanf("%d",&h[i]);


	printf("\nHeap Created:\n");
	heapify(h,n);
	for(i=1; i<=n; i++)
		printf("%d  ",h[i]);

	printf("\n\nOpcount = %d\n",opcount);
}
