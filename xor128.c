#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int s[2];

unsigned long long int xorshift128plus(unsigned long long int spt0, unsigned long long int spt1) {
	s[0] = spt0;
	s[1] = spt1;
	unsigned long long int x = s[0];
	unsigned long long int const y = s[1];
	s[0] = y;
	x ^= x << 23; // a
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26); // b, c
	return s[1] + y;
}

int main()
{
	int num[10] = { 0, };
	int i, j, n;
	unsigned long long int z, y, x;
	printf("몇 번 돌려볼까요? : ");
	scanf("%d", &n);
	y = time(NULL);
	x = clock();
for(j = 0;j < n;j++)
	{
	if((j != 0) && (j % 10000 == 0))
	{
		printf("%d번 돌림...\n", j);
	}
	z = xorshift128plus(y, x);
	y = z;
	x = z + clock() + j;
	num[y % 10]++;
	}
	
	printf("\nxor128plus %d번 돌린결과 :\n", n);
	for(j = 0;j < 10;j++)
	{
		printf("%d의 편차 : %d\n", j, (n / 10) -num[j]);
	}
	return 0;
}
