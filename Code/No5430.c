#include<stdio.h>
//#include<string.h>

int T, n, arr[100000]={0};
int reverseFlag=1, left, right, size, errorFlag=1;//reverseFlag 1: 왼>오, -1:오>왼; errorFlag 1:에러없음, -1:있음
char p[100001]={0};
void InitArr(); //배열을 입력받아 arr에, 그 크기는 size에 저장함.
void R();
void D();
void Execute(); // p를 수행함.
void PrintArr(); //arr을 출력함.

int main(){
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%s", p);
		InitArr();
		Execute();
		PrintArr();		
	}
	return 0;
}

void InitArr(){
	scanf("%d%*c", &n); // '숫자\n'

	if(n == 0) scanf("%*c%*c"); // 수열이 []일때.
	else{
		for(int i=0; i<n; i++) scanf("%*c%d", &arr[i]); // '[숫자' 또는 ',숫자'
		if(n > 0) scanf("%*c"); // ']'
	}
	
	/*
	printf("arr: ");
	for(int i=0; i<n; i++) printf("%d ", arr[i]);
	printf("\n");
	*/
	size = n;
	left = 0;
	right = n-1;
	reverseFlag = errorFlag = 1;
}

void R(){
	reverseFlag = -reverseFlag;
}

void D(){
	if(size == 0){
		errorFlag = -1;
		return;
	}
	if(reverseFlag == 1) left++;
	else right--;
	size--;
}

void Execute(){
	int i=0;
	char command;
	while(p[i] != '\0'){
		command = p[i];
		switch(command){
			case 'R':
				//printf("do R\n");
				R();
				//PrintArr();
				break;
			case 'D':
				//printf("do D\n");
				D();
				//PrintArr();
				break;
		}
		i++;
		if(errorFlag == -1) break;
	}
}

void PrintArr(){
	if(errorFlag == -1){
		printf("error\n");
		return;
	}else if(size == 0){
		printf("[]\n");
		return;
	}

	//printf("ans: ");
	printf("[");
	if(reverseFlag == 1){
		for(int i=left; i<right; i++) printf("%d,", arr[i]);
		printf("%d]\n", arr[right]);
	}else{
		for(int i=right; i>left; i--) printf("%d,", arr[i]);
		printf("%d]\n", arr[left]);		
	}

	
}