#include<stdio.h>
//한무재귀를 쉽게하는법: 범위가 작다면 table을 만들자!!
int a, b, c;
int w_table[21][21][21] = {0};

int w(int a, int b, int c);//w(a,b,c)값을 w_table에서 찾아서 반환함.
void w_calculate(int a, int b, int c);//w(a,b,c)를 계산해서 w_table[a][b][c]에 추가함.

int main(){
	scanf("%d%d%d", &a, &b, &c);

	while(!(a==-1 && b==-1 && c==-1)){
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));
		scanf("%d%d%d", &a, &b, &c);
	}

	return 0;
}

int w(int a, int b, int c){
	if(a<=0 || b<=0 || c<=0) return 1;
	if(a>20 || b>20 || c>20) return w(20,20,20);

	if(w_table[a][b][c] == 0) w_calculate(a,b,c);
	return w_table[a][b][c];
}

void w_calculate(int a, int b, int c){
	if(a<b && b<c) w_table[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else w_table[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

