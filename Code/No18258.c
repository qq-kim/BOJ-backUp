#include<stdio.h>
#include<string.h>

//큐 관련
int queue[2000000]={0};
int front=0, rear=-1, size=0;

void Push(int x);
void Pop();
void Size();
int IsEmpty();
void Front();
void Back();


int main(){
	int N=0, x=0;
	char command[6]={0};

	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%s", command);
		if(strcmp(command, "push") == 0){
			scanf("%d", &x);
			Push(x);
		}
		else if(strcmp(command, "pop") == 0) Pop();
		else if(strcmp(command, "size") == 0) Size();
		else if(strcmp(command, "empty") == 0) printf("%d\n", IsEmpty());
		else if(strcmp(command, "front") == 0) Front();
		else if(strcmp(command, "back") == 0) Back();
	}

	return 0;
}

void Push(int x){
	queue[++rear] = x;
	size++;
}

void Pop(){
	if(IsEmpty()){
		printf("-1\n");
		return;
	}
	printf("%d\n", queue[front]);
	front++;
	size--;
}

void Size(){
	printf("%d\n", size);
}

int IsEmpty(){
	return (size == 0);
}

void Front(){
	if(IsEmpty()){
		printf("-1\n");
		return;
	}
	printf("%d\n", queue[front]);
}

void Back(){
	if(IsEmpty()){
		printf("-1\n");
		return;
	}
	printf("%d\n", queue[rear]);
}