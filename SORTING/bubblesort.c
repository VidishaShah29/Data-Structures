//bubble sort

#include<stdio.h>

int* bubblesort(int* a, int n){

	int i,temp, opcount = 0;
	for(i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			opcount++;
			if(a[j] > a[j+1]){
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("\nSorted Array: \n");
	for(i=0; i<n; i++)
	printf("%d\t",a[i]);
	printf("\nOpcount: %d\n",opcount);
}

int main(){

	int a[] = {9,3,7,2,0,8};
	int n = sizeof(a)/sizeof(a[0]);
	bubblesort(a,n);
	return 0;
}
