#include<stdio.h>

int gcdEuclid(int a, int b){
	if(b<a) gcdEuclid(b,a);
	int t, opcount = 0;
	while(a != 0){
		opcount++;
		t = b % a;
		b = a;
		a = t;
	}
	printf("\nOpcount: %d",opcount);
	return b;
}

int gcdcons(int a, int b){

	if(b<a) gcdcons(b,a);
	int t = a, opcount = 0;
	while(t--){
		opcount++;
		if(a%t ==0 && b%t ==0)	
			break;
	}
	printf("\nOpcount: %d",opcount);
	return t;
}

int minimum(int a, int b){
	return (a<b)?a:b;
}

int gcdMiddleSchool(int a, int b){
	int opcount=0;
	if(b<a) gcdMiddleSchool(b,a);
	int m,n=a,gcd=1,k=0;
	
	int factors[50];
	for(int i=2;i<=a/2;i++)
	if(a%i==0){
		factors[k]=i;k++;a=a%i;
	}

	for(int j=0;j<=k;j++){
		opcount++;
		m=factors[j];
		if(b%m!=0){}
		else{
			gcd=gcd*minimum(b/m,a/m); b=b/m; printf("yo");
		}
	}
	printf("\nOpcount: %d",opcount);
	return gcd;
}

int main(){

	int a,b;
	scanf("%d%d",&a,&b);
	printf("\nGCD using Euclidean method: %d\n",gcdEuclid(a,b));
	printf("\nGCD using consecutive integer checking method: %d\n",gcdcons(a,b));
	printf("\nGCD using Middle School method: %d\n",gcdMiddleSchool(a,b));
	printf("\nDone");
	return 0;
}
