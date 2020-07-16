#include <stdio.h>
#define BIT 64


union number{
	long long i;
	double d;
};



void convert(union number n);		//실수를 이진수로 출력


int main()
{
	union number n;
	n.i = n.d = 0;
	scanf("%lf", &n.d);
	convert(n);
	return 0;
}


void convert(union number n)
{
	int x, temp[BIT];
	for(x = 0; x < BIT; x++)
	{
		temp[x] = n.i & 1;
		n.i >>= 1;
	}
	for(x = BIT - 1; x >= 0; x--)
	{
		printf("%d", temp[x]);
		if(BIT - x == 1) //1번째 자리일때(64비트 부호부)
		{
			printf("   ");
		}
		else if(BIT - x == 12) //2~12자리까지(64비트 지수부)
		{
			printf("   ");
		}
		else if(((BIT - 12 - x) % 4 == 0) & (BIT - 12 - x) >= 0) //13~64자리(64비트 가수부)
		{
			printf(" ");
		}
	}
	printf("\n");
}
