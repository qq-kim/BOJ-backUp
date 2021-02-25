#include<stdio.h>

//queue 관련.
int queue[1000000] = {0}; //(1000,1000)-요세푸스 순열 계산시 대략 1000*1000칸 필요함.
int front=0, rear=-1, size=0;
void InitQueue();
void Enqueue(int x);
int Dequeue();

//문제풀이 관련.
int N, K;
int Josephus(int k); //순서대로 k번째 사람을 제거하고 제거된 사람의 번호를 반환.

//1. N값 바탕으로 queue에 사람들을 번호순대로 배치.
//2. K-1회만큼 앞의 사람들을 queue의 뒤로 옮김(dequeue -> enqueue 반복)
//3. 1회 dequeue함. 이때 반환된 값이 요세푸스 순열의 요소.
//4. 2.~4.번을 반복함. 
int main(){

	InitQueue();

	printf("<");
	while(size > 1) printf("%d, ", Josephus(K));//4.
	printf("%d>", Dequeue());

	return 0;
}

//1.
void InitQueue(){
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++) queue[i] = i+1;
	rear = N-1;
	size = N;
}

void Enqueue(int x){
	queue[++rear] = x;
	size++;
}

int Dequeue(){
	int result = queue[front++];
	size--;
	return result;
}

int Josephus(int k){
	int tmp;
	for(int i=1; i<K; i++){//2.
		tmp = Dequeue();
		Enqueue(tmp);
	}
	return Dequeue();//3.
}