#include<stdio.h>

int N=0, coordinate[100000][2]={0}, aux[1000000][2]={0};

void Input();
void Arrange();
//left: 정렬하려는 구역의 왼쪽 끝 index, right: 오른쪽 끝 index, axis=0: x축기준, axis=1: y축기준.
void MergeSort(int left, int right, int axis);
//direction=0: coordinate[corIdx]를 aux[auxIdx]로 복사, direction=1: 반대.
void Copy(int corIdx, int auxIdx, int direction);

int main(){
	Input();
	Arrange();
	//printf("\n");
	for(int i=0; i<N; i++) printf("%d %d\n", coordinate[i][0], coordinate[i][1]);
	return 0;
}

void Input(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d%d", &coordinate[i][0], &coordinate[i][1]);
}

void Arrange(){
	int startIdx=0, endIdx=0, y_axis;//y축 값이 y_axis로 동일한 애들은 startIdx와 endIdx 사이에 위치함.

	//y축 기준으로 오름차순 정렬.
	MergeSort(0, N-1, 1); //<<<<<<<<<외않댐????????????????????????

	/*printf("\n");
	for(int i=0; i<N; i++) printf("%d %d\n", coordinate[i][0], coordinate[i][1]);
	printf("\n");
	for(int i=0; i<N; i++) printf("%d %d\n", aux[i][0], aux[i][1]);*/

	//y축이 같은 애들끼리 x축기준 오름차순 정렬.
	y_axis = coordinate[0][1];//기준 y축 값 초기 설정.
	for(int i=1; i<N; i++){
		if(coordinate[i][1] == y_axis) endIdx = i;//y값이 같으면 같은애들 범위만 설정해줌.
		else{//y값이 바뀌면 startIdx~endIdx를 정렬한 후에 기준y값 재설정.
			MergeSort(startIdx, endIdx, 0);
			startIdx = i;
			y_axis = coordinate[i][1];
		}
	}
	MergeSort(startIdx, endIdx, 0);
}

void MergeSort(int left, int right, int axis){
	int mid=0, leftIdx=0, rightIdx=0, auxIdx=0;

	if(left>=right) return; //마지막 재귀: 1개의 원소를 정렬할 때.

	//mid값 설정 후 그걸 기준으로 배열을 반으로 쪼개서 재귀.
	mid = (left+right)/2;
	MergeSort(left, mid, axis);
	MergeSort(mid+1, right, axis);

	//왼쪽 배열과 오른쪽 배열의 원소를 하나씩 차례로 비교, 작은놈부터 aux에 순서대로 채움.
	for(leftIdx=left, rightIdx=mid+1, auxIdx=left; (leftIdx<=mid)&&(rightIdx<=right); ){
		if(coordinate[leftIdx][axis] <= coordinate[rightIdx][axis]){
			Copy(leftIdx, auxIdx, 0);
			leftIdx++;
			auxIdx++;
		}else{
			Copy(rightIdx, auxIdx, 0);
			rightIdx++;
			auxIdx++;
		}
	}

	while(leftIdx<=mid){
		Copy(leftIdx, auxIdx, 0);
		leftIdx++;
		auxIdx++;
	}
	while(rightIdx<=right){
		Copy(rightIdx, auxIdx, 0);
		rightIdx++;
		auxIdx++;
	}

	//aux의 내용을 원본 coordinate에 옮김.
	for(int i=left; i<=right; i++) Copy(i, i, 1);
}

void Copy(int corIdx, int auxIdx, int direction){
	if(direction==0){
		aux[auxIdx][0] = coordinate[corIdx][0];
		aux[auxIdx][1] = coordinate[corIdx][1];
	}else{
		coordinate[corIdx][0] = aux[auxIdx][0];
		coordinate[corIdx][1] = aux[auxIdx][1];
	}
}