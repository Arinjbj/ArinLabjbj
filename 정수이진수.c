#include <stdio.h>
#include <stdint.h>


//���α׷��� ����� �� �� ���� �������� ���
inline void div(){
	printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
};


//(size)byte�� ������ ���������� ������ִ� �Լ� 
void printbit(int64_t num, int size);

int main()
{
	int whatkind, size;
	int64_t num;
	
	retry:	//while�� ��� �ݴ��� ��� ���
		
	printf("�Է��� ������ �ڷ��� ũ���?\n\n1 : 2byte(short)\n2 : 4byte(int)\n3 : 8byte(long long)\n\n0 : ����\n\n��ȣ�Է� : ");
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
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.");
			div();
			goto retry;
	}
	
	printf("%dbyte�� �����Է� : ", size);
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
