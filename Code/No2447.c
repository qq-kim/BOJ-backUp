#include <stdio.h>

//화면 좌상단을 원점으로 하는 좌표계에 별을 찍음. 3^7 = 2187.
int coordinates[2222][2222] = {0};
int N;

void star(int startCoord_x, int startCoord_y, int size);
void printCoordinate(int x, int y);

int main(){
	scanf("%d", &N);

	star(0, 0, N);

	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++) printCoordinate(x, y);
		printf("\n");
	}
	return 0;
}

// 가로 size, 세로 size 크기의 정사각형을 9개로 쪼갠 후, 가운데 사각형을 제외한 사각형들에 대해 재귀.
void star(int startCoord_x, int startCoord_y, int size){
	if(size == 3){ // 마지막 재귀
		for(int addx=0; addx<3; addx++){
			for(int addy=0; addy<3; addy++){
				if(addx==1 && addy==1) continue;
				coordinates[startCoord_x + addx][startCoord_y + addy] = 1;
			}
		}
		return;
	}

	for(int addx=0; addx<3; addx++){
		for(int addy=0; addy<3; addy++){
			if(addx==1 && addy==1) continue; // 가운데 사각형은 비움.
			//printf("star(%d, %d, %d)\n", size/3 * addx, size/3 * addy, size/3);
			star(startCoord_x + size/3 * addx, startCoord_y + size/3 * addy, size/3);
		}
	}
}

void printCoordinate(int x, int y){
	if(coordinates[x][y] == 1) printf("*");
	else printf(" ");
}