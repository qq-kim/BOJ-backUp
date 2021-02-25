#include <stdio.h>
//stack
int stack[100000]={0};
int topIdx=-1;
void Push(int x);
int Pop();
int Peek(); //top of stack의 integer값을 알려만 줌.
//void PrintStack();


//1. 수열의 i번째 수가 stack의 top에 있는가?
//2. 네: pop.
//3. 아니오: 그럼 i번째 수가 대기열에 있는가?
//4. 		네: i번째 수까지 push후 한번 pop.
//5.		아니오: 수열 못만든다는 뜻.
int main(){
	int n=0, num=0, waiting=1, operCnt=0, canMake=1, pushCnt=0;
	char operation[200001] = {0};
	
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &num);
		//printf("Bef - num: %d, waiting: %d, peek: %d\n",num, waiting, Peek());

		if(num == Peek()){ //1.
			Pop(); //2.
			operation[operCnt] = '-';
			operCnt++;

		}else if(num>=waiting){//3. 대기열 따로 구현X, 어차피 오름차순으로 정렬되어있는 대기열이므로 대기열 첫값만 waiting으로 파악.
			pushCnt = num-waiting+1; // 4.에서 i번째 수까지 몇번 push가 필요한지 계산.
			for(int j=0; j<pushCnt; j++){ //4.
				Push(waiting++);
				operation[operCnt] = '+';
				operCnt++;
				//printf("j: %d, waiting: %d\n",j, waiting);
			}
			Pop();
			operation[operCnt] = '-';
			operCnt++;

		}else{ //5.
			canMake = 0;
			break;
		}

		//printf("Aft - num: %d, waiting: %d\n",num, waiting);
		//PrintStack();
	}

	//출력.
	if(canMake == 0) printf("NO");
	else{
		for(int i=0; i<operCnt; i++) printf("%c\n", operation[i]);
	}

	return 0;
}

void Push(int x){
	if(topIdx>100000) return; //stack full일때 Push할 시 아무것도 안함.
	topIdx++;
	stack[topIdx] = x;
	return;
}

int Pop(){
	if(topIdx<0) return -1; //stack empty일때 Pop 할 시 -1 반환.
	int popInt = stack[topIdx];
	//stack[topIdx]=0;
	topIdx--;
	return popInt;
}

int Peek(){
	if(topIdx<0) return -1; // stack empty일때 peek하면 -1 반환.
	return stack[topIdx];
}

/*void PrintStack(){
	printf("Stack: ");
	for(int i=0; i<topIdx+1; i++) printf("%d ", stack[i]);
	printf("\n");
}*/