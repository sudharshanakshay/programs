#include<stdio.h>

void main(){

int n;
scanf("%d", &n);

for(int i=1; i<=n; i++){
	for(int j=0; j<n-i; j++){
		printf(" ");
	}
	for(int j=1; j<=i; j++){
		printf("%d",j);
	}
	for(int j=i-1; j>=1; j--){
		printf("%d",j);
	}
	printf("\n");
}

for(int i=n-1; i>=1; i--){
	for(int j=0; j<n-i; j++)
	{
		printf(" ");
	}
	for(int j=1; j<=i; j++)
	{
		printf("%d", j);
	}
	for(int j=i-1; j>=1; j--)
	{
		printf("%d", j);
	}
	printf("\n");
}
}
