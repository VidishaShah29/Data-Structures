//recursive nth fibonacci

#include<stdio.h>

int opcount = 0;

int fib(int n){

	opcount++;
	if(n<2) return n;
	return fib(n-1) + fib(n-2);
}

int main(){

	int n;
	scanf("%d",&n);
	printf("\nFibonaaci number(%d): %d\n",n,fib(n));
	printf("\nOpcount: %d\n",opcount);
	return 0;
}
