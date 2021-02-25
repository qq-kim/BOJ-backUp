#include<stdio.h>
#include<stdlib.h>

int meeting[100008][2] = {0};//meeting[i][1]: 회의시작시간, meeting[i][2]: 회의종료시간.
int N=0, maxNumOfMeetings=0;

void Input();
void Solve();
void QuickSort(int left, int right, int flag);//meeting을 정렬하는 함수. 기준 index는 flag로 정함.
void Swap(int idx1, int idx2); //meeting[idx1]과 meeting[idx2]안의 값들을 서로 바꿔줌.

int main(){
	Input();
	Solve();
	printf("\n");
	for(int i=0; i<N; i++) printf("%d %d\n", meeting[i][1], meeting[i][2]);
	printf("%d", maxNumOfMeetings);
	return 0;
}

void Input(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d%d", &meeting[i][1], &meeting[i][2]);
}

void Solve(){
	int endTime = 0;//현재 회의가 끝나는 시간.
	int startIdx=0, endIdx=0;//회의 끝나는시간이 같은애들끼리 묶을때 쓰는 변수.

	QuickSort(0, N-1, 2);//회의 끝나는시간 기준으로 오름차순 정렬.

	//회의 끝나는시간이 같은 애들끼리 시작시간 기준으로 오름차순 정렬.
	for(int i=0; i<N; i++){
		if(meeting[startIdx][2] == meeting[i][2]){
			endIdx = i;
		}else{
			QuickSort(startIdx, endIdx, 1);
			startIdx = i+1;
		}
	}
	QuickSort(startIdx, endIdx, 1);

	//회의가 끝난후에 시작하면 카운트++
	for(int i=0; i<N; i++){
		if(meeting[i][1] >= endTime){
			maxNumOfMeetings++;
			endTime = meeting[i][2];
		}
	}
}

//left: 정렬할 구역의 가장 왼쪽 idx, right: 정렬할 구역의 가장 오른쪽 idx
//flag==1: 회의시작시간 기준 정렬, flag==2: 회의종료시간 기준 정렬.
void QuickSort(int left, int right, int flag){
	int pivot, pivotIdx;

	if(left >= right) return; //마지막 재귀(정렬할 구역 안의 원소가 1개임)

	//pivot값을 무작위로 정해서 구역 가장 왼쪽에 배치시킴
	pivotIdx = (rand() % (right-left+1))+ left;
	Swap(left, pivotIdx);
	
	pivotIdx = left;
	pivot = meeting[pivotIdx][flag];

	//pivot값은 그대로 가장 왼쪽에 냅둠
	//구역의 원소를 하나씩 비교, pivot보다 작은건 왼쪽, 큰건 오른쪽으로 몰아넣음.
	//이때 pivotIdx에는 pivot보다 작은값들 중 가장 오른쪽에 있는 값의 index를 저장함.
	for(int i=left+1; i<=right; i++){
		if(meeting[i][flag] < pivot){
			pivotIdx++;
			Swap(pivotIdx, i);
		}
	}
	//제일 왼쪽에 있던 pivot을 정상적인 위치로 넣어줌.
	Swap(pivotIdx, left);
	//재귀
	QuickSort(left, pivotIdx-1, flag);
	QuickSort(pivotIdx+1, right, flag);
}

void Swap(int idx1, int idx2){
	int tmp1=0, tmp2=0;

	tmp1 = meeting[idx1][1];
	tmp2 = meeting[idx1][2];

	meeting[idx1][1] = meeting[idx2][1];
	meeting[idx1][2] = meeting[idx2][2];

	meeting[idx2][1] = tmp1;
	meeting[idx2][2] = tmp2;
}