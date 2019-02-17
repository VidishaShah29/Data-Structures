//brute foce string matching

#include<stdio.h>
#include<string.h>

int string_matching(char str[],int n, char substr[], int m){

	for(int i=0; i<n-m; i++){
		int c = 0;
		for(int j=0; j<m; j++){
			if(str[i+j]!=substr[j])	break;
			else c++;
		}
	if(c == m) return i;
	}
	return -1;

}

int main(){

	char str[50],substr[50];

	scanf("%[^\n]%*c",str);
	scanf("%[^\n]%*c",substr);

	int i = string_matching(str,strlen(str),substr,strlen(substr));
	if(i == -1)
		printf("\nSubstring not found in main string\n");
	else printf("\nSubstring found at index %d\n",i+1);
}
