#include <stdio.h>
//stack
char stack[101] = {0};
int topIdx=-1;
void stack_Init(); //stack을 초기화하는 함수.
void push(char ch);
char pop();
int isStackEmpty(); //stack이 비어있으면 1, 그렇지 않으면 0을 출력.

//void printStack();

//1.'.'이 들어올 때까지 입력을 받음.
//2.입력받은 어떤 char가 ( 또는 [ 이면 stack에 push
//3.입력받은 어떤 char가 ) 또는 ] 이면 stach에서 pop
//4.이때 pop된 char가 ) 또는 ]와 알맞게 세트를 이루면 통과, 아니면 균형X.
//5.'.'을 받아 한 문장이 끝났을 때 stack이 empty하면 균형O, 아니면 균형X.
//6. 입력 완전 종료(변수 length를 사용해 문장의 길이를 측정).
int main(){
	char ch;
	int isBalanced=1; //0이면 균형잡히지 않음, 1이면 균형잡힘.
	int length = 0; //문장의 길이.
	stack_Init();

	while(1){
		ch = getchar();
		length++;
		//printf("%c ", ch );
		//printStack();
		if(ch != '.'){ //1.
			switch(ch){
				case '(':
				case '[':
					push(ch); break;
				case ')':
					if(pop() != '(') isBalanced=0; break;
				case ']':
					if(pop() != '[') isBalanced=0; break;
				default:
					break;
			}
		}else{
			if(length > 2){ //5. 문장은 최소 3글자임: "\n어쩌구저쩌구."
				//출력
				if(isBalanced == 0) printf("no\n");
				else if(isStackEmpty()) printf("yes\n");
				else printf("no\n");
				//다시 초기화
				stack_Init();
				isBalanced=1;
				length=0;
			}else break; //6. 종료선언문은 두 글자로 이루어짐: "\n."
		}		
	}
	return 0;
}

//stack
void stack_Init(){
	for(int i=0; i<101; i++){
		stack[i] = '\0';
	}
	topIdx = -1;
}

void push(char ch){
	if(topIdx < 100){ 
		topIdx++;
		stack[topIdx] = ch;
	}else{}//stack이 꽉찼으면 아무것도 안함
}
	
char pop(){
	char poppedChar;
	if(topIdx>-1){
		poppedChar = stack[topIdx];
		//stack[topIdx] = '\0';
		topIdx--;
	}else poppedChar = 'e'; //for error, 스택이 비어있을때 pop했다는 뜻.
	return poppedChar;
}

int isStackEmpty(){
	if(topIdx == -1) return 1;
	else return 0;
}

/*void printStack(){
	for(int i=0; i<20; i++){
		printf("%c", stack[i]);
	}
	printf("\n");
}*/