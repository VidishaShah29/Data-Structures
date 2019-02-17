//selection sort

#include<stdio.h>

int* select_sort(int* a, int n){

	int i,j,min,temp,opcount = 0;
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			opcount++;
			if(a[j]<a[min])	min = j;
		}
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}

	printf("\nSorted Array: \n");
	for(i=0; i<n; i++)
		printf("%d\t",a[i]);
	printf("\nOpcount: %d\n",opcount);
}

int main(){

	int a[] = {9,3,7,2,0,8};
	int n = sizeof(a)/sizeof(a[0]);
	select_sort(a,n);
	return 0;
}
