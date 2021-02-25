#include<stdio.h>

int sequence[1000001]={0}; //처음엔 수열을 저장하고 이후 NGE값으로 덮어씌움.
int N=0; //수열의 길이.
void Input(); //N값과 수열의 항들을 입력받음.
void PrintSeq(); //sequence배열의 값을 출력함.
int GetNGE(int idx); //sequence[idx]의 NGE값을 계산해 반환함.

//스택관련.
int stack[1000001]={0};
int topIdx=-1;
void Push(int val);
void Pop();
int Peek(); //Top of stack의 값 반환. stack empty하면 2147483647반환.


int main(){
	int nge = 0;
	Input();

	for(int i=N-1; i>=0; i--){ //수열을 역순으로 스택에 넣음.
		nge = GetNGE(i);
		sequence[i] = nge;
	}

	PrintSeq();
	return 0;
}


void Input(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &sequence[i]);
}

void PrintSeq(){
	for(int i=0; i<N; i++) printf("%d ", sequence[i]);
}

int GetNGE(int idx){
	int value = sequence[idx], nge = -1;
	if(Peek()==2147483647) nge = -1;//만약 stack empty하면 NGE=-1
	else{
		while(Peek() <= value) Pop(); //TOS가 push하려는 값 이하면 계속 Pop(NGE를 찾는과정)
		nge = Peek(); //TOS가 push하려는 값보다 크면 TOS가 곧 NGE라는 소리.
		if(Peek()==2147483647) nge = -1;//근데 만약 전부 Pop해서 stack empty하면 NGE=-1
	}
	Push(value);//이후 push

	return nge;
}

void Push(int val){
	if(topIdx >= 1000000) return;//stack full
	topIdx++;
	stack[topIdx] = val;
}

void Pop(){
	if(Peek()==-1) return;//stack empty
	topIdx--;
	return;
}

int Peek(){
	if(topIdx==-1) return 2147483647;//stack empty
	return stack[topIdx];
}