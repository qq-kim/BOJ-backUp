#include<stdio.h>

int main(){
	int num, max=-1000000, min=1000000, input;

	scanf("%d", &num);

	for(int i=0; i<num; i++){
		scanf("%d", &input);
		if(max<input) max=input;
		if(min>input) min=input;
	}

	printf("%d %d", min, max);
	return 0;
}