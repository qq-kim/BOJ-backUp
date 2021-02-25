#include<stdio.h>

int num[1000000] = {0}, aux[1000000] = {0};
int N = 0;

void MergeSort(int left, int right);

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &num[i]);

	MergeSort(0, N-1);

	for(int i=0; i<N; i++) printf("%d\n", num[i]);
	return 0;
}

void MergeSort(int left, int right){
	int mid, i, j, k;

	if(left >= right) return; //마지막 재귀: 1개의 원소를 정렬할 때.

	mid = (left+right)/2;

	//재귀: 배열을 절반으로 계속 쪼개는 중..
	MergeSort(left, mid);
	MergeSort(mid+1, right);

	//mid를 기준으로 왼쪽(mid포함), 오른쪽으로 배열을 나눔.
	//왼쪽배열과 오른쪽배열의 원소를 앞에서부터 순서대로 뽑음(왼쪽과 오른쪽은 위의 재귀과정에서 이미 정렬됨)
	//두 원소중에 작은놈부터 순서대로 aux배열에 넣어서 배열을 완성함.
	//다 했으면 aux배열의 정돈된 값들을 원래의 num배열로 복사함.
	for(i=left, j=mid+1, k=left; (i<=mid)&&(j<=right); ){
		if(num[i] <= num[j]){
			aux[k++] = num[i++];
			//k++;
			//i++;
		}else{
			aux[k++] = num[j++];
			//k++;
			//j++;
		}
	}

	//남은 값들을 처리하는 과정
	//(홀수였거나, 어느 한쪽 배열에 큰 숫자들이 편중된것 등..)
	while(i <= mid){
		aux[k] = num[i];
		k++;
		i++;
	}
	while(j <= right){
		aux[k] = num[j];
		k++;
		j++;
	}

	//복사하는 과정.
	for(i=left; i<=right; i++) num[i] = aux[i];

}