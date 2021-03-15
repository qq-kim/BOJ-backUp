#include <stdio.h>

void Hanoi(int n, int from, int to);
int departures[2000000]={0}, destinations[2000000]={0};
int N, moveCount=0;

int main(){
	scanf("%d", &N);

	Hanoi(N, 1, 3);

	printf("%d\n", moveCount);
	for(int i=0; i<moveCount; i++) printf("%d %d\n", departures[i], destinations[i]);

	return 0;
}


//하노이의 탑 = (n-1 개를 1번->2번 막대기로 옮기기) + (마지막 원판을 1번->3번으로 옮기기) + (n-1 개를 2번->3번으로 옮기기)
void Hanoi(int n, int from, int to){
	if(n<=0) return;

	int emptyRodName = 6 - from - to; // 막대기의 이름을 1, 2, 3이라 했을때 합은 6

	Hanoi(n-1, from, emptyRodName);
	
	departures[moveCount] = from;
	destinations[moveCount] = to;
	moveCount++;

	Hanoi(n-1, emptyRodName, to);
}