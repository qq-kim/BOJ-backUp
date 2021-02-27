#include<stdio.h>
#define SIZE 10
//문서 구조체: dequeue의 return값을 위해 존재.
typedef struct DOCUMENT{
	int name;
	int importance;
}DOCUMENT;

//queue 관련.
int queue[SIZE][2]={0}; //queue[i][0]: 문서명, queue[i][1]: 중요도.
int front=0, rear=-1;
void InitQueue();//N과 중요도를 입력받아 queue 초기화함.
void Enqueue(int document, int importance);
DOCUMENT Dequeue();
//void PrintQueue();

//문제풀이 관련.
int testCaseNum, N, M, printCnt, lastPrinted;
int IsMostImportant();//queue front가 남아있는 문서중에 가장 중요도 높으면 1 반환.
void ReassignDocument();//queue front의 문서를 맨 뒤로 옮김.
int PrintDocument();//queue front의 문서를 출력하고 그 문서의 이름을 반환.

//1. 인쇄된 문서가 찾는 문서가 아닐 경우 반복.
//2. 다음에 인쇄될 문서 뒤에 그보다 큰 중요도의 문서가 있는지 확인.
//2.1. 있다: 맨 뒤로 보냄.
//2.2. 없다: 인쇄하고 printCnt값을 증가시킴.
//3. 출력
int main(){

	scanf("%d", &testCaseNum);
	for(int i=0; i<testCaseNum; i++){
		//새로운 test case 입력전 초기화.
		lastPrinted=-1;
		printCnt=0;
		InitQueue();
		PrintQueue();
		printf("\n");
		//풀이과정.
		while(lastPrinted != M){//1.
			if(IsMostImportant()){//2.2.
				lastPrinted = PrintDocument();
				printCnt++;
				PrintQueue();
			}else{
				ReassignDocument();
				PrintQueue();
			} //2.1.
		}
		printf("%d\n", printCnt);//3.
	}

	return 0;
}

void InitQueue(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) {
		queue[i][0] = i; //편의상 문서의 이름을 그 문서의 초기 위치로 정함.
		scanf("%d", &queue[i][1]);
	}
	front=0;
	rear=N-1;
}

//문서의 최대 개수가 정해져 있고, 풀이상 enqueue전에 dequeue를 무조건 하기 때문에
//Enqueue/Dequeue 시 queue가 꽉 찼는지/비었는지 검사할필요X.
void Enqueue(int document, int importance){
	rear = (rear + 1) % SIZE;
	queue[rear][0] = document;
	queue[rear][1] = importance;
}

DOCUMENT Dequeue(){
	DOCUMENT del;
	del.name = queue[front][0];
	del.importance = queue[front][1];
	front = (front + 1) % SIZE;
	return del;
}

int IsMostImportant(){
	int frontVal = queue[front][1];
	for(int iterator=(front+1)%SIZE; iterator!=rear; iterator=(iterator+1)%SIZE){
		if(queue[iterator][1] > frontVal) return 0;
	}
	if(queue[rear][1] > frontVal) return 0;
	return 1;
}

void ReassignDocument(){
	DOCUMENT doc = Dequeue();
	Enqueue(doc.name, doc.importance);
}

int PrintDocument(){
	DOCUMENT doc = Dequeue();
	printf("printing %d\n", doc.name);
	return doc.name;
}

/*void PrintQueue(){
	printf("%d ", queue[front][0]);
	for(int iterator=(front+1)%SIZE; iterator!=rear; iterator=(iterator+1)%SIZE)
		printf("%d ", queue[iterator][0]);
	printf("%d ", queue[rear][0]);
	printf("\n");
}*/