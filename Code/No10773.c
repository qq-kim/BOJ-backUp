#include <stdio.h>

int main(){
	int k, input, topIdx=-1, sum=0;
	int stack[100000]; // K는 최대 100,000까지임.

	//정수 k = for루프 몇번 돌릴지
	scanf("%d", &k);

	for(int i=0; i<k; i++){
		scanf("%d", &input);
		//입력값 양수일때 stack의 top에 숫자 삽입후 top index를 +1만큼 조정.
		if(input > 0) {
			topIdx++;
			stack[topIdx] = input;
		}
		//입력값 0일때 stack의 top index를 -1만큼 조정(따로 숫자를 빼내는 작업X).
		else topIdx--;
	}
	//최종적으로 stack의 값들을 더함.
	if(topIdx == -1) sum=0; //stack empty 일 때.
	else{
		for(int i=0; i<topIdx+1; i++) sum+=stack[i];
	}
	//출력.
	printf("%d", sum);
	return 0;
}