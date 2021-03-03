#include<stdio.h>

int getFactorial(int n){
	if(n == 0) return 1;
	return n * getFactorial(n-1);
}

int main(){
	int val;
	scanf("%d", &val);
	printf("%d", getFactorial(val));
	return 0;
}