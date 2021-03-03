#include<stdio.h>

int getFibonacci(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return getFibonacci(n-1) + getFibonacci(n-2);
}

int main(){
	int val;
	scanf("%d", &val);
	printf("%d", getFibonacci(val));
	return 0;
}