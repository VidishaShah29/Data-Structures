//generate power set

#include<stdio.h>
#include<math.h>
#include<string.h>

int powcal(int a, int b){

	int res=1;
	while(b--) res*=a;
	return res;
}

void generate_powset(int n){

	int power = powcal(2,n);
	int i,j;
	int set[power][n];
	memset(set,0,sizeof(set));
	for(i=0; i<power; i++){
		for(j=0; j<n; j++)
			if(i & (1<<j))	set[i][j]=1;
	}

	for(i=0; i<power; i++){
		for(j=0; j<n; j++){
			printf("%d ",set[i][j]);
		}
		printf("\n");
	}
		
}

int main(){

	generate_powset(3);
	return 0;
}
