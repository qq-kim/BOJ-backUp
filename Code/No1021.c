#include<stdio.h>
#define SIZE 56

//deque관련
int deque[SIZE] = {0};
int front, rear, size;
void InitDeque();
void Push_front(int x);
int Pop_front();
void Push_rear(int x);
int Pop_rear();
int Peek_front();
//void PrintDeque();

//문제풀이 관련.
int N=0, M=0, drawVal=0, operationCnt=0;
void Move_left();
void Move_right();
void Draw_first();
int IsValueNearFront(int val); //deque에서 val값이 앞쪽에 가까우면 1, 뒤쪽에 가까우면 0.

//1. 뽑으려는 수가 덱의 앞쪽과 뒤쪽 중 어디에 더 가까운지 판단.
//2. 1.의 결과에 맞게 연산 수행해서 뽑아냄
//3. 반복함.
int main(){
	InitDeque();
	//PrintDeque();
	for(int i=0; i<M; i++){
		scanf("%d", &drawVal);
		//printf("draw %d\n", drawVal);
		if(IsValueNearFront(drawVal)){
			//printf("%d\n", IsValueNearFront(drawVal));
			while(Peek_front() != drawVal){
				Move_left();
				//PrintDeque();
			}
			Draw_first();
			//PrintDeque();
		}else{
			//printf("%d\n", IsValueNearFront(drawVal));
			while(Peek_front() != drawVal){
				Move_right();
				//PrintDeque();
			}
			Draw_first();
			//PrintDeque();
		}
	}
	printf("%d", operationCnt);
	return 0;
}

void InitDeque(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) deque[i] = i+1;
	front = 0;
	rear = N-1;
	size = N;
}

void Push_front(int x){
	front--;
	if(front < 0) front = SIZE-1;
	deque[front] = x;
	if(size==0) rear = front;
	size++;
	
}

int Pop_front(){
	int del = deque[front];
	front = (front+1) % SIZE;
	size--;
	return del;
}

void Push_rear(int x){
	rear = (rear+1) % SIZE;
	deque[rear] = x;
	if(size==0) front = rear;
	size++;
}

int Pop_rear(){
	int del = deque[rear];
	rear--;
	if(rear < 0) rear = SIZE-1;
	size--;
	return del;
}

int Peek_front(){
	return deque[front];
}

void Move_left(){
	int tmp = Pop_front();
	Push_rear(tmp);
	operationCnt++;
}

void Move_right(){
	int tmp = Pop_rear();
	Push_front(tmp);
	operationCnt++;
}

void Draw_first(){
	Pop_front();
}


int IsValueNearFront(int val){
	int half = size / 2;
	int cnt=0;
	//if(val == 6) printf("size:%d, front:%d, rear:%d, half:%d, ", size, front, rear, half);
	for(int i=front; i!=rear+1; i=(i+1)%SIZE){
		if(deque[i] == val) break;
		cnt++;		
	}
	//if(val==6) printf("cnt:%d\n", cnt);
	if(cnt <= half) return 1;
	else return 0;
}
/*
void PrintDeque(){
	int half = size / 2;

	if(size==0) {
		printf("empty\n");
		return;
	}
	
	for(int i=front; i!=rear; i=(i+1)%SIZE){
		printf("%d ", deque[i]);
		if(i == (front+half)%SIZE) printf("half ");
	}
	printf("%d\n", deque[rear]);
}*/