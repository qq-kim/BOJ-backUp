#include<stdio.h>
#include<math.h>

int N, numbers[500008]={0}, aux[500008]={0};
int sum=0;

void Input();//입력받으면서 수들의 합 sum도 같이구함.
void MergeSort(int left, int right);//left: 정렬하려는 범위의 왼쪽 끝 index, right: 오른쪽 끝 index.
int average();//산술평균
int median();//중앙값
int mode();//최빈값
int range();//범위

int main(){
	Input();
	MergeSort(0, N-1);
	printf("%d\n%d\n%d\n%d", average(), median(), mode(), range());
	return 0;
}

void Input(){
	int input;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &input);
		sum += input;
		numbers[i] = input;
	}
	numbers[N] = -4444; //배열의 마지막은 -4444로 표시함.
}

void MergeSort(int left, int right){
	int mid=0, leftIdx=0, rightIdx=0, auxIdx=0;

	if(left >= right) return;//마지막 재귀: 1개의 원소를 정렬할 때.

	//주어진 범위의 배열을 반으로 쪼갠 후 재귀함.
	mid = (left+right)/2;
	MergeSort(left, mid);
	MergeSort(mid+1, right);

	//왼쪽 배열과 오른쪽 배열의 숫자를 앞에서부터 차례로 비교, 작은값부터 aux에 정리해 넣음.
	for(leftIdx=left, rightIdx=mid+1, auxIdx=left; (leftIdx<=mid)&&(rightIdx<=right); ){
		if(numbers[leftIdx] <= numbers[rightIdx]) 
			aux[auxIdx++] = numbers[leftIdx++];
		else 
			aux[auxIdx++] = numbers[rightIdx++];
	}
	while(leftIdx<=mid) aux[auxIdx++] = numbers[leftIdx++];
	while(rightIdx<=right) aux[auxIdx++] = numbers[rightIdx++];

	//aux에 정리된애들을 다시 numbers에 복사함.
	for(int i=left; i<=right; i++) numbers[i] = aux[i];
}

int average(){
	return round((double)sum / N);
}

int median(){
	return numbers[N/2];
}

//1.numbers[0]을 mode_candidate에 저장하고, 거기부터 하나씩 확인해봄.
//2.언제까지? 새로운 숫자가 나올 때까지
//3.새로운 숫자가 나오면 cnt값을 확인해봄 : 이전 숫자가 몇 번 나왔나?(cnt)
//4.만약 이전 숫자가 나온 횟수가 최빈값이 되기에 충분하다면, mode_real에 최빈값을, mode_bestCnt에 그 기록을, mode_sameCnt에는 동일기록 보유자의 수를 저장.
//5.만약 이전 숫자가 나온 횟수가 기존 최빈값과 같다면, 그 기록이 2번째 기록일 경우엔 저장, 그 이후일 경우엔 무시.
//6.새로운 숫자를 mode_candidate로 정하고 반복함.
int mode(){
	int mode_real=numbers[0], mode_candidate=numbers[0], mode_sameCnt=0, mode_bestCnt=1, cnt=1;

	for(int i=1; i<=N; i++){//numbers[N]에는 -4444가 들어가있음.
		if(numbers[i] == mode_candidate) cnt++;
		else{
			if(cnt > mode_bestCnt){ //새로운 최빈값 등장시.
				mode_bestCnt = cnt;
				mode_sameCnt = 1;
				mode_real = mode_candidate;
				//초기화중..
				mode_candidate = numbers[i];
				cnt = 1;
			}
			else if(cnt == mode_bestCnt){//최빈값이 여러개인가???
				if(mode_sameCnt >= 2){//최빈값 중 세 번째~로 작은 값이면 무시함
					mode_candidate = numbers[i];//초기화중..
					cnt = 1;
				}
				else{
					mode_sameCnt++;
					mode_real = mode_candidate;
					mode_candidate = numbers[i];//초기화중..
					cnt = 1;
				}
			}
			else{//최빈값이 아니면 무시함
				mode_candidate = numbers[i];//초기화중..
				cnt = 1;
			}
		}
	}

	return mode_real;
}

int range(){
	return numbers[N-1] - numbers[0];
}