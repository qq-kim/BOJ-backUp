#include<stdio.h>

int distance[1000008]={0}, price[1000008]={0};
int cityNum=0;
long long totalPrice=0LL;

void Input();
void Solve();

int main(){
	Input();
	Solve();
	printf("%lld", totalPrice);
	return 0;
}

void Input(){
	scanf("%d", &cityNum);
	for(int i=0; i<cityNum-1; i++) scanf("%d", &distance[i]);
	for(int i=0; i<cityNum; i++) scanf("%d", &price[i]);
}


//1.첫 번째 도시에서 출발하면서 다음 도시에 계속 물어봄. "너 나보다 싸냐?"
//2. "ㅇㅇ." 대답이 나오면 스탑, 그 전까지는 계속 첫 번째 도시(기준도시)의 가격으로 기름 채움.
//3. 이후 멈춘 도시를 다시 새로운 기준으로 잡고 1.부터 반복.
void Solve(){
	int cheapGasPrice = price[0];
	//totalPrice = 1LL * price[0] * distance[0];

	for(int i=0; i<cityNum-1; i++){
		if(cheapGasPrice <= price[i]){//1.
			totalPrice += 1LL * cheapGasPrice * distance[i];
			//printf("%d %d\n", i, totalPrice);
		}
		else{//2.
			cheapGasPrice = price[i];//3.
			totalPrice += 1LL * cheapGasPrice * distance[i];;
			//printf("%d %d\n", i, totalPrice);
		}
	}
}