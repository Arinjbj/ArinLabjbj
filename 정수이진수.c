#include <stdio.h>
#include <stdint.h>


//프로그램이 재시작 될 때 영역 구분으로 사용
inline void div(){
	printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
};


//(size)byte의 정수를 이진법으로 출력해주는 함수 
void printbit(int64_t num, int size);

int main()
{
	int whatkind, size;
	int64_t num;
	
	retry:	//while문 대신 금단의 비기 사용
		
	printf("입력할 정수의 자료형 크기는?\n\n1 : 2byte(short)\n2 : 4byte(int)\n3 : 8byte(long long)\n\n0 : 종료\n\n번호입력 : ");
	scanf("%d", &whatkind);
	switch(whatkind)
	{
		case 0:
			return 0;
		case 1:
		{
			size = 2;
			break;
		}
		case 2:
		{
			size = 4;
			break;
		}
		case 3:
		{
			size = 8;
			break;
		}
		default :
			printf("잘못된 입력입니다. 다시 입력하세요.");
			div();
			goto retry;
	}
	
	printf("%dbyte의 정수입력 : ", size);
	scanf("%lld", &num);
	printbit(num, size);
	div();
	goto retry;
}

void printbit(int64_t num, int size)
{
	int i, temp[size * 8];
	for(i = size * 8 - 1; i >= 0; i--)
	{
		temp[i] = num & 0x0000000000000001;
		num >>= 1;
	}
	for(i = 0; i <= size * 8 - 1; i++)
	{
		printf("%d", temp[i]);
		if((i + 1) % 8 == 0) printf(" ");
	}
}
