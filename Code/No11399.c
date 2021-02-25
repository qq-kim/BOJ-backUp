#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int atmTime[1000]={0};//각 사람이 돈을 인출하는데 걸리는 시간.
int N, answer=0;//사람의 수, 시간의 합의 최솟값.

void Input();//N과 P_i를 입력받아 각각 N과 atmTime[i-1]에 저장.
void Solve();//정렬된 atmTime을 바탕으로 답 게산.
void PrintResult();//답 출력.
void QuickSort(int left, int right);//재귀적으로 atmTime을 정렬. left는 정렬할 배열의 첫번째 index, right는 마지막 index.

//첫번째 사람이 P_1분 걸린다 하면 각 사람들이 기다리는 시간의 합은 P_1 * N분만큼 늘어남.
//두번째 사람이 P_2분 걸린다 하면 P_2 * (N-1)분만큼 늘어남.
//결국 시간이 적게걸리는 사람을 앞에 배치해야 정답을 구할 수 있음(30분걸리는사람*30명보다 1분걸리는사람*30명이 훨씬이득).
int main(){
	Input();
	QuickSort(0, N-1);
	Solve();
	PrintResult();
	return 0;
}

void Input(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &atmTime[i]);
}

void Solve(){
	int time=0;
	for(int i=0; i<N; i++){
		time += atmTime[i];
		answer += time;
	}
}

void PrintResult(){
	printf("%d", answer);
}

void QuickSort(int left, int right){//left는 배열에서 정렬할 구역의 가장 왼쪽 index, righ는 그 구역의 가장 오른쪽 index.
	int pivot, tmp;
	int pivotIdx; //처음에 pivot의 index, 정렬중에는 pivot보다 작은값들 중 마지막 값의 index.

	if(left>=right) return; //재귀적으로 배열을 절반으로 쪼개서 계산하는데 마지막에는 결국 1칸을 정렬하게 됨. 이때는 그냥 리턴.

	//pivot값을 무작위로 정하고, 정렬하려는 배열의 가장 왼쪽부분으로 이동시킴.
	srand(time(NULL));
	pivotIdx = (rand() % (right-left+1)) + left;
	tmp = atmTime[pivotIdx];
	atmTime[pivotIdx] = atmTime[left];
	atmTime[left] = tmp;
	pivot = atmTime[left];

	//pivot보다 작은놈은 왼쪽, pivot 이상인 놈은 오른쪽으로 몰아넣음. pivot값은 아직 왼쪽에 있음.
	pivotIdx = left;
	for(int i=left+1; i<=right; i++){
		if(atmTime[i] < pivot){
			pivotIdx++;
			tmp = atmTime[i];
			atmTime[i] = atmTime[pivotIdx];
			atmTime[pivotIdx] = tmp;
		}
	}

	//맨 왼쪽에 있는 pivot과 pivot보다 작은값들 중 마지막값의 위치 교환.
	//pivot-작은값-큰값 => 작은값-pivot-큰값.
	tmp = atmTime[left];
	atmTime[left] = atmTime[pivotIdx];
	atmTime[pivotIdx] = tmp;

	//재귀적으로 pivot보다 작은값들 모임, 이상인 값들 모임을 따로따로 정리.
	QuickSort(left, pivotIdx-1);
	QuickSort(pivotIdx+1, right);
}