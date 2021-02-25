#include <stdio.h>

int main(){
	//초기화
	int input, result=0;
	//입력
	scanf("%d", &input);

	//1. 연도가 4의 배수면 윤년O
	if(input%4 == 0){
		result = 1;
	//2. 연도가 100의 배수면 윤년X
		if(input%100 == 0){
			result = 0;
	//3. 연도가 400의 배수면 윤년O
			if(input%400 == 0) result = 1;
		}
	}
	
	//출력
	printf("%d", result);
	return 0;
}