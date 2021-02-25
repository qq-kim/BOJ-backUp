#include<stdio.h>
#include<stdlib.h>

int N=0, coordinate[100000][2]={0};

void Input();
//left: 정렬하려는 구역의 왼쪽 끝 index, right: 오른쪽 끝 index, axis=0: x축 기준 오름차순정렬, axis=1: y축 기준.
void QuickSort(int left, int right, int axis);
void Arrange();//좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬
void Swap(int idx1, int idx2); //coordinate[idx1]과 coordinate[idx2]의 자리를 바꿈.

int main(){

	Input();
	Arrange();
	for(int i=0; i<N; i++) printf("%d %d\n", coordinate[i][0], coordinate[i][1]);

	return 0;
}

void Input(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d%d", &coordinate[i][0], &coordinate[i][1]);
}

void Arrange(){
	int startIdx=0, endIdx=0, x_axis=0;//같은 x좌표를 가진놈들의 시작 index, 끝 index, 기준 x좌표

	QuickSort(0, N-1, 0);//x좌표 기준으로 정렬함.

	//x좌표가 같은애들은 y좌표 기준으로 정렬함.
	x_axis = coordinate[0][0];//기준 x좌표 설정.
	for(int i=1; i<N; i++){
		if(coordinate[i][0] == x_axis) endIdx = i;//x좌표가 같다면 그녀석도 startIdx~endIdx 그룹에 포함시킴.
		else{//만약 x좌표가 다른게 나왔다면
			QuickSort(startIdx, endIdx, 1);//startIdx~endIdx 그룹을 정렬.
			startIdx = i;//새로운 x좌표가 나왔으므로 startIdx 및 기준 x좌표 값 변경.
			x_axis = coordinate[i][0];
		}
	}
	QuickSort(startIdx, endIdx, 1);
}

void QuickSort(int left, int right, int axis){
	int pivot=0, pivotIdx=0;
	
	if(left>=right) return;//마지막 재귀: 1개의 원소를 정렬할 때.
	
	//pivot 무작위로 정하고 정렬하려는 구역의 가장 왼쪽으로 치움.
	pivotIdx = (rand() % (right-left+1)) + left;
	Swap(pivotIdx, left);
	pivot = coordinate[left][axis];
	pivotIdx = left;

	//pivot 미만의 값은 왼쪽, 이상의 값은 오른쪽으로 몰아넣음.
	//pivot은 가장 왼쪽 고정, pivotIdx는 pivot 미만의 값중 가장 오른쪽 값의 index.
	for(int i=left+1; i<=right; i++){
		if(coordinate[i][axis] < pivot){
			pivotIdx++;
			Swap(pivotIdx, i);
		}
	}

	//가장 왼쪽에 있던 pivot을 pivot 미만인 값들과 pivot 이상인 값들 사이로 옮김.
	Swap(pivotIdx, left);

	//재귀
	QuickSort(left, pivotIdx-1, axis);
	QuickSort(pivotIdx+1, right , axis);
}

void Swap(int idx1, int idx2){
	int tmp0, tmp1;

	tmp0 = coordinate[idx1][0];
	tmp1 = coordinate[idx1][1];

	coordinate[idx1][0] = coordinate[idx2][0];
	coordinate[idx1][1] = coordinate[idx2][1];

	coordinate[idx2][0] = tmp0;
	coordinate[idx2][1] = tmp1;
}