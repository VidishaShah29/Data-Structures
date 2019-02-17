//insertion sort

#include<stdio.h>

int* insertion_sort(int* a, int n){

	int i,t,key,opcount = 0;
	
	for(i=1; i<n; i++){
		
		t = i - 1; key = a[i];

		while(key<a[t] && t>=0){
			opcount++;
			a[t+1] = a[t];
			t--;			
		}		
		a[t+1] = key;
	}

	printf("\nSorted Array: \n");
	for(i=0; i<n; i++)
		printf("%d\t",a[i]);
	printf("\nOpcount: %d\n",opcount);
}

int main(){

	int a[] = {9,3,7,2,0,8};
	int n = sizeof(a)/sizeof(a[0]);
	insertion_sort(a,n);
	return 0;
}
