//merge sort

#include<stdio.h>
#include<stdlib.h>

/*void merge(int a[], int start, int mid, int end){

	int i=0,j=0,k;
	int l[mid-start+1],r[end-mid];
	int temp[end-start+1];
	int i=start,s=start,m=mid;
	while((s<=mid) && (m<=end)){
		if(*(a+s) < *(a+m))
			*(temp + i++) = *(a + s++);
		else
			*(temp + i++) = *(a + m++);
	}
	while(s<=mid){

		temp[i] = a[s]; i++; s++;
	}
	while(m<=end){

		temp[i] = a[m]; i++; m++;
	}
	for(i=start;i<=end;i++)	a[i] = temp[i];
		//*(a+i) = *(temp+i);
 
}*/

void merge(int a[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1, n2 =  r - m; 

	int L[n1], R[n2]; 
  
	for (i = 0; i < n1; i++) 
	        L[i] = a[l + i]; 
	for (j = 0; j < n2; j++) 
        	R[j] = a[m + 1+ j]; 
  
	i = 0;     j = 0;    k = l; 

	while (i < n1 && j < n2){ 
	       
		if (L[i] <= R[j]) {
 
        		a[k] = L[i]; 
        		i++; 
        	} 
       		else { 
            		a[k] = R[j]; 
           		j++; 
        	} 
        	k++; 
    	} 
  
	while (i < n1) 
    	{ 
        	a[k] = L[i]; 
        	i++; k++; 
    	} 
  
	while (j < n2) 
    	{ 
        	a[k] = R[j]; 
        	j++; k++; 
    	} 
} 

void mergesort(int* a, int start, int end){

	int mid;
	if(start<end){

		mid= (start+end)/2;
		mergesort(a,0,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
	}
	printf("\nSorted Array: \n");
	for(int i=0; i<=end; i++)
	printf("%d\t",a[i]);
}

int main(){

	int a[] = {9,3,7,2,0,8};
	int n = sizeof(a)/sizeof(a[0]);
	mergesort(a,0,n-1);
	printf("\nSorted Array: \n");
	for(int i=0; i<n; i++)
	printf("%d\t",a[i]);
	return 0;
}
