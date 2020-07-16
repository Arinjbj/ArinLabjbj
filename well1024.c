/* ***************************************************************************** */
/* Copyright:      Francois Panneton and Pierre L'Ecuyer, University of Montreal */
/*                 Makoto Matsumoto, Hiroshima University                        */
/* Notice:         This code can be used freely for personal, academic,          */
/*                 or non-commercial purposes. For commercial purposes,          */
/*                 please contact P. L'Ecuyer at: lecuyer@iro.UMontreal.ca       */
/* ***************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define W 32
#define R 32
#define M1 3
#define M2 24
#define M3 10

#define MAT0POS(t,v) (v^(v>>t))
#define MAT0NEG(t,v) (v^(v<<(-(t))))
#define Identity(v) (v)

#define V0            STATE[state_i                   ]
#define VM1           STATE[(state_i+M1) & 0x0000001fU]
#define VM2           STATE[(state_i+M2) & 0x0000001fU]
#define VM3           STATE[(state_i+M3) & 0x0000001fU]
#define VRm1          STATE[(state_i+31) & 0x0000001fU]
#define newV0         STATE[(state_i+31) & 0x0000001fU]
#define newV1         STATE[state_i                   ]

#define FACT 2.32830643653869628906e-10

static unsigned int state_i = 0;
static unsigned int STATE[R];
static unsigned int z0, z1, z2;


void InitWELLRNG1024a (unsigned int *init);
double WELLRNG1024a (void);

union num{
	uint64_t l;
	double d;
};

int main()
{
	union num number;
	unsigned int *init, *temp;
	unsigned int i, x[R], n, p, leng, get = 1;
	unsigned int want;
	char * c;
	init = x;
	
	c = (char *)malloc(40);
	
	printf("0 ~ n 까지의 갯수를 입력하세요.\nn입력 : ");
	scanf("%d", &want);
	sprintf(c, "%d", want);
	leng = strlen(c);
	for(i = 0; i < leng; i++)
	{
		get *= 10;
	}
	free(c);
	
	temp = (int *)malloc(sizeof(int) * want);
	
	printf("몇 번 돌려볼까요? : ");
	scanf("%u", &n);
	for(i = 0; i < R; i++)
	{
		x[i] = time(NULL) + clock() + i;
	}
	InitWELLRNG1024a(init);
	printf("%u번 돌립니다...", n);
	for(i = 0; i < n; i++)
	{
		p = 0;
		if(i % 10000 == 0 && i != 0) printf("%u번 돌림...\n", i);
		p = WELLRNG1024a() * get;
		p %= want;
		temp[p]++;
	}
	
	printf("\n\n%d번 돌린 결과 : \n", i);
	for(i = 0; i < want; i++)
	{
		printf("%u의 횟수 : %u\n", i, temp[i]);
	}
	printf("\n");
	for(i = 0; i < want; i++)
	{
		printf("%d의 평균과의 대략적인 편차 : %d\n", i, (n / want) - temp[i]);
	}
	free(temp);
	return 0;
}



void InitWELLRNG1024a (unsigned int *init){
   int j;
   state_i = 0;
   for (j = 0; j < R; j++)
     STATE[j] = init[j];
}

double WELLRNG1024a (void){
  z0    = VRm1;
  z1    = Identity(V0)       ^ MAT0POS (8, VM1);
  z2    = MAT0NEG (-19, VM2) ^ MAT0NEG(-14,VM3);
  newV1 = z1                 ^ z2; 
  newV0 = MAT0NEG (-11,z0)   ^ MAT0NEG(-7,z1)    ^ MAT0NEG(-13,z2) ;
  state_i = (state_i + 31) & 0x0000001fU;
  return ((double) STATE[state_i]  * FACT);
}
