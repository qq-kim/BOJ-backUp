#include<stdio.h>
#include<string.h>
#define SIZE 10001 //명령의 수가 최대 1만개임.

//deque 관련.
int deque[SIZE] = {0};
int front=1, rear=-1, size=0;

void Push_front(int x);
void Push_back(int x);
int Pop_front();
int Pop_back();
int IsEmpty();
int Peek_front();
int Peek_back();

int main(){
	int N, cmdVal;
	char command[16]={0};

	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", command);
		if(strcmp(command, "push_front")==0){
			scanf("%d", &cmdVal);
			Push_front(cmdVal);
		}
		else if(strcmp(command, "push_back")==0){
			scanf("%d", &cmdVal);
			Push_back(cmdVal);
		}
		else if(strcmp(command, "pop_front")==0)
			printf("%d\n", Pop_front());
		else if(strcmp(command, "pop_back")==0)
			printf("%d\n", Pop_back());
		else if(strcmp(command, "size")==0)
			printf("%d\n", size);
		else if(strcmp(command, "empty")==0)
			printf("%d\n", IsEmpty());
		else if(strcmp(command, "front")==0)
			printf("%d\n", Peek_front());
		else{//command == "back"
			printf("%d\n", Peek_back());
		}
	}

	return 0;
}

void Push_front(int x){
	front--;
	if(front<0) front = SIZE-1;
	deque[front] = x;
	if(IsEmpty()) rear = front;
	size++;
}

void Push_back(int x){
	rear++;
	if(rear>=SIZE) rear = 0;
	deque[rear] = x;
	if(IsEmpty()) front = rear;
	size++;
}

int Pop_front(){
	if(IsEmpty()) return -1;
	int del = deque[front];
	front++;
	if(front>=SIZE) front = 0;
	size--;
	return del;
}

int Pop_back(){
	if(IsEmpty()) return -1;
	int del = deque[rear];
	rear--;
	if(rear<0) rear = SIZE-1;
	size--;
	return del;
}

int IsEmpty(){
	return size == 0;
}

int Peek_front(){
	if(IsEmpty()) return -1;
	return deque[front];
}

int Peek_back(){
	if(IsEmpty()) return -1;
	return deque[rear];
}