//partition sort

#include<stdio.h>

int* partition_sort(int* a, int n){

	int i,temp, opcount = 0;
	

	printf("\nSorted Array: \n");
	for(i=0; i<n; i++)
	printf("%d\t",a[i]);
	printf("\nOpcount: %d\n",opcount);
}

int main(){

	int a[] = {9,3,7,2,0,8};
	int n = sizeof(a)/sizeof(a[0]);
	partition_sort(a,n);
	return 0;
}
