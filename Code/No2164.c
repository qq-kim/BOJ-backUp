#include<stdio.h>

int queue[1000000]={0};
int N, front=0, rear=-1, cardsLeft=0;
void InitQueue();
int Dequeue();
void Enqueue(int x);
void PrintQueue();

int main(){
	int tmp;

	InitQueue();
	PrintQueue();

	while(cardsLeft > 1){
		Dequeue(); // 제일 위에 있는 카드 버리기
		tmp = Dequeue(); // 제일 위의 카드를 맨 아래로 옮기기
		Enqueue(tmp);
		PrintQueue();
	}

	printf("%d", Dequeue());

	return 0;
}

void InitQueue(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) queue[i] = i+1;
	cardsLeft = N;
	rear = N-1;
}

int Dequeue(){
	int dequeueVal;

	if((rear-front) == -1) return -1;

	dequeueVal = queue[front++];
	cardsLeft--;
	
	return dequeueVal;
}

void Enqueue(int x){
	queue[++rear] = x;
	cardsLeft++;
}

void PrintQueue(){
	for(int i=front; i<=rear; i++) printf("%d ", queue[i]);
	printf("\n");
}