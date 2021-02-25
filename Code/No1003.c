#include<stdio.h>

//배열 index 신경쓰기!!!!!!!!!!!!!!!!!!!!!!!!!!
int T, N, cnt_0_table[41]={0}, cnt_1_table[41]={0};

void InitTable();
int Print_0_cnt(int n);//fibonacci(n)을 호출했을 때 출력되는 0의 개수(==cnt_0_table[n])를 반환.
int Print_1_cnt(int n);//fibonacci(n)을 호출했을 때 출력되는 1의 개수(==cnt_1_table[n])를 반환.
void Set_0_cnt(int n);
void Set_1_cnt(int n);

int main(){
	InitTable();
	scanf("%d", &T);

	for(int i=0; i<T; i++){
		scanf("%d", &N);
		printf("%d %d\n", Print_0_cnt(N), Print_1_cnt(N));
	}

	printf("\n");
	for(int i=0; i<10; i++){
		printf("fibo(%d): %d %d\n", i, cnt_0_table[i], cnt_1_table[i]); 
	}
	return 0;
}

void InitTable(){
	for(int i=0; i<=40; i++){
		cnt_0_table[i] = -1;
		cnt_1_table[i] = -1;
	}
	cnt_0_table[0] = 1;
	cnt_0_table[1] = 0;
	cnt_1_table[0] = 0;
	cnt_1_table[1] = 1;
}

int Print_0_cnt(int n){
	if(cnt_0_table[n] == -1) Set_0_cnt(n);//
	return cnt_0_table[n];
}

int Print_1_cnt(int n){
	if(cnt_1_table[n] == -1) Set_1_cnt(n);//
	return cnt_1_table[n];
}

void Set_0_cnt(int n){
	cnt_0_table[n] = Print_0_cnt(n-1) + Print_0_cnt(n-2);
}
void Set_1_cnt(int n){
	cnt_1_table[n] = Print_1_cnt(n-1) + Print_1_cnt(n-2);
}