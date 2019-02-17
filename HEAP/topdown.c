//top down heap construction


#include<stdio.h>

int opcount = 0;

int swap(int *a, int *b){

	int temp=*a; *a=*b; *b=temp;
}

void heapify(int h[], int n){

	int i,j,k,val,heap=0;
	for(i=1; i<=n/2; i++){
		j=i; heap=0; val=h[i];
		while(heap==0 && 2*j<=n){	
			opcount++;
			k=2*i;
			if(k<n)
				if(h[k]<h[k+1])	k++;
			if(val>=h[k])	heap=1;
			
			else{
				swap(&h[j],&h[k]); j=k;
			} 
		}
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
