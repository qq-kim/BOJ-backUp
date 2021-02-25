#include <stdio.h>

int main(){
	int input;
	
	//입력
	scanf("%d", &input);
	//출력
	for(int i=1; i<=9; i++) printf("%d * %d = %d\n", input, i, input*i);
	
	return 0;
}