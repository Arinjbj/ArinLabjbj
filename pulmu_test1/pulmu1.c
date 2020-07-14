#include <stdio.h>

int main()
{
	int howmany;

	printf("밑변의 길이가 5인 작은 피라미드로 큰 피라미드를 쌓습니다.\n작은 피라미드의 갯수를 입력해주세요.(단, 입력 값 = 1 + 2 + ... + n )\n");
	scanf("%d", &howmany);

	

	//입력 값이 1 + 2 .. 의 형태인지 판별
	
	int sum = 0, n, tf = 0;

	for(n = 0;sum <= howmany;n++)
	{
		sum += n;

		if(sum != 0 && sum == howmany)
		{
			tf = 1;
			break;
		}
	}
	
	if(tf != 1)
	{
		printf("잘못된 입력입니다.");
		return 0;
	}

	

	//피라미드 공사 n == 큰 피라미드 층, stack == 작은 피라미드 층
	
	int stack = n * 3;		//작은 층으로 센 총 층 수입니다. for문에서 한 층씩 쌓으면서 값이 줄어듭니다.
	int stackplan = n * 3;		//작은 층으로 센 총 층 수입니다. 값이 변하지 않습니다.
	int nlocation = 0;		//맨 윗층을 1층으로 센 큰 층수입니다. for문이 진행될 때 현재 몇 번째 큰 층인지 알려줍니다.
	int stacklocation;		//맨 윗층을 1층으로 센 작은 층수입니다. for문이 진행될 때 현재 몇 번째 작은 층인지 알려줍니다.
	int L;				//한 층의 길이입니다. for문에서 길이를 하나씩 늘려주면서 값이 줄어듭니다.
	int length = 5 * n + (n - 1);	//한 층의 길이입니다. 값이 변하지 않아 for문이 반복될 때 L의 값을 초기화 시켜줍니다.

	printf("n = %d\n", n);
	for(stack = stack;stack > 0;stack--)
	{
		stacklocation = stackplan + 1 - stack;

		(stacklocation % 3 == 0) ? (nlocation = stacklocation / 3) : (nlocation = stacklocation / 3 + 1);

		for(L = length;L > 0;L--)
		{
			if(stacklocation % 3 == 1)
			{
				if((L == stack) || (((L - stack) % 6 == 0) && (L <= (stack + (6 * (nlocation - 1)))) && (L >= stack)))
					//L이 stack과 같거나 L - stack이 6의 배수이면서 stack <= L <= stack + 6(현재큰층-1) 을 만족할 때
				{
					printf("^");
				}
				else
				{
					printf(" ");
				}
			}

			else if(stacklocation % 3 == 2)
			{
				if((L == stack) || ((((L - stack) % 6 <= 2) && (L <= (stack + (6 * (nlocation - 1))) + 2) && (L >= stack))))
				{
					printf("^");
				}
				else
				{
					printf(" ");
				}
			}

			else if(stacklocation % 3 == 0)
			{
				if((L == stack) || ((((L - stack) % 6 <= 4) && (L <= (stack + (6 * (nlocation - 1))) + 4) && (L >= stack))))
				{
					printf("^");
				}
				else
				{
					printf(" ");
				}
			}
			

		}

		printf("\n");
	}

	return 0;
}
