//recursive tower of hanoi

#include<stdio.h>

int opcount = 0;

void toh(int n, char from, char to, char aux){

	opcount++;
	if(n == 1){

		printf("\nMove disk 1 from %c to %c",from, to);
		return;
	}
	
	toh(n-1, from, aux, to);
	printf("\nMove disk %d from rod %c to rod %c",n,from,to);
	toh(n-1, aux, to, from);
}

int main(){

	int n;
	scanf("%d",&n);
	toh(n, 'A','C','B');
	printf("\nOpcount: %d\n",opcount);
	return 0;
}
