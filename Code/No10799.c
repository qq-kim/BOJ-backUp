#include<stdio.h>

//1. 입력값 '(' : 쇠막대기일 수도 있고(잠재적 막대기++), 레이저일 수도 있음(잠재적 레이저 ON).
//2. 입력값 ')' : 잠재적 레이저가 ON일때 >> 레이저란 뜻.
//2.1. 잠재적 막대기--(막대기인 줄 알았는데 아니었음), 막대기조각+=잠재적막대기(레이저가 조각을 잘라냄), 잠재적레이저 OFF.
//3. 입력값 ')' : 잠재적 레이저가 OFF일때 >> 쇠막대기의 끝이란 뜻.
//3.1. 잠재적 막대기--, 막대기조각++
int main(){
	char input = '\0';
	int laserFlag=0;//잠재적 레이저 flag: 1이면 레이저 ON, 0이면 레이저 OFF.
	int pipeCnt=0;//잠재적 쇠막대기의 개수
	int pieceCnt=0;//잘려진 쇠막대기 조각의 총 개수

	while((input = getchar()) == '(' || input == ')'){
		if(input == '('){ //1.
			pipeCnt++;
			laserFlag = 1;
		}else{
			if(laserFlag == 1){//2.
				pieceCnt += --pipeCnt;
				laserFlag = 0;
			}else{ //3.
				pipeCnt--;
				pieceCnt++;
			}
		}
	}

	//출력.
	printf("%d",pieceCnt);
	return 0;
}