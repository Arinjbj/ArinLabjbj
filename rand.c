#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int num[10] = { 0, };
	int i, j, n, y;
	unsigned long long int x;
	printf("몇 번 돌려볼까요? : ");
	scanf("%d", &n);
	y = time(NULL);
for(j = 0;j < n;j++)
	{
	if((j != 0) && (j % 10000 == 0))
	{
		printf("%d번 돌림...\n", j);
	}
	srand(y + clock());
	y = rand();
	num[y % 10]++;
	}
	
	printf("\nrand() %d번 돌린결과 :\n", n);
	for(j = 0;j < 10;j++)
	{
		printf("%d의 편차 : %d\n", j, (n / 10) -num[j]);
	}
	return 0;
}
