#include<stdio.h>
#include<stdlib.h>

char equation[101]={0};
int val=0, answer=0;//수식의 숫자, 정답
char* bookmark = equation;//equation[]의 어디까지 읽었는지 주소를 저장.
char sign='+';//방금 막 읽은 기호가 +인지 -인지 저장함.

void Solve();//답을 answer에 저장.
//void Read();//bookmark지점부터 숫자 1개와 기호 1개를 읽고 숫자는 val에, 기호는 sign에 저장함.
void ReadVal();//bookmark지점부터 숫자 1개를 읽어 val에 저장.
void ReadSign();//bookmark지점부터 기호 1개를 읽어 sign에 저장.

int main(){
	scanf("%s", equation);
	Solve();
	printf("%d", answer);
	return 0;
}

/*void Read(){
	int cnt = 0;
	char ch;
	//부호가 나올때까지 읽음. 숫자의 시작주소는 bookmark이고 숫자의 길이는 cnt임.
	for(ch=*(bookmark+cnt); (ch!='+')||(ch!='-')||(ch!='\0'); cnt++);
	//숫자 및 부호 저장
	val = atoi(bookmark);
	sign = ch;
	//다음 숫자의 시작주소 저장.
	bookmark += cnt+1;
	//만약 수식이 끝난거면 sigh = e 
	if(*bookmark == '\0' && ch == '\0') sign = 'e';
}*/

//수식에서 -와 - 사이의 +들을 전부 괄호처리해서 -값을 극대화하는 방법.
//1. 첫 '-' 등장 이전(flag:1): 전부 answer에 더함.
//2. '-' 등장(flag:-1): 다음 '-' 또는 '\0'전까지 tmp에 더함
//3. answer-=tmp, tmp초기화후 2.부터 반복.
void Solve(){
	int tmp=0, flag=1;

	while(sign != '\0'){
		ReadVal();
		switch(flag){
			case 1:
				answer += val; break;
			case -1:
				tmp += val; break;
		}
		ReadSign();
		switch(sign){
			case '+': break;
			case '-':
			case '\0':
				flag = -1;
				answer -= tmp;
				tmp = 0;
				break;
		}
	}
}

void ReadVal(){
	int cnt=0;
	char ch;
	//부호가 나올때까지 읽음. 숫자의 시작주소는 bookmark이고 숫자의 길이는 cnt임.
	for(ch=*(bookmark+cnt); (ch!='+')&&(ch!='-')&&(ch!='\0'); ch=*(bookmark+cnt)) cnt++;
	val = atoi(bookmark);
	//bookmark에 다음에 읽을 기호의 주소 저장.
	bookmark += cnt;
}

void ReadSign(){
	sign = *bookmark;//부호의 시작주소는 bookmark임.
	bookmark += 1;//다음에 읽을 숫자의 주소 저장.
}