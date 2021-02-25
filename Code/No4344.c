#include<stdio.h>

int main(){
	int testNum, stuNum, scores[1000], sum, aboveAvg;

	//테스트 케이스의 수 testNum 입력
	scanf("%d", &testNum);
	//테스트 케이스의 수만큼 반복
	for(int i=0; i<testNum; i++){
		sum = aboveAvg = 0; // sum, aboveAvg 값 초기화
	//학생의 수 stuNum 입력
		scanf("%d", &stuNum);
	//점수들을 scores 입력 및 점수의 총합 sum 계산
		for(int j=0; j<stuNum; j++){
			scanf("%d", &scores[j]);
			sum += scores[j];
		}
	//평균보다 높은 학생의 수 aboveAvg 계산
		for(int j=0; j<stuNum; j++){
			if(scores[j]*stuNum > sum) aboveAvg++;
		}
	//출력
		printf("%.3f%%\n", (double) aboveAvg*100 / stuNum);
	}
	return 0;
}