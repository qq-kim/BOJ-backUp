#include<stdio.h>
// '('는 스택에 push하란 뜻이고 ')'는 스택에서 pop하란뜻.
// 모든 입력이 끝났을 때 스택이 비어있다면 YES.
// 입력도중 stack이 비었는데 pop지시가 나오거나, 입력이 끝났는데 stack이 차있으면 NO.
int main(){
	int T, topIdx=-1;
	char stack[51]={0}, inputStr[51]={0};

	//테스트 데이터의 개수 T만큼 반복.
	scanf("%d", &T);

	for(int i=0; i<T; i++){
		//이전까지의 값들을 초기화
		topIdx=-1;
		char inputStr[51]={0}, stack[51]={0};
		//한 줄을 입력받아 inputStr에 저장.
		scanf("%s", &inputStr);

		//for(int j=0;j<51;j++) printf("%c, ", inputStr[j]);

		//inputStr을 앞에서부터 훑으면서 '('는 stack에 push, ')'나오면 pop
		for(int j=0; inputStr[j]!='\0'; j++){
			//printf("%d\n", topIdx);
			
			if(inputStr[j] == '('){
				topIdx++;
				stack[topIdx] = '(';
			}else topIdx--;

			
			//stack이 비었는데 pop지시가 나오면 NO
			if(topIdx<-1) break;		
		}
		//출력 : stack이 비어있다 == topIdx가 -1이다 == VPS이다.
		if(topIdx == -1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}