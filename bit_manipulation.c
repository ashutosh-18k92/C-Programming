#include <stdio.h>

int isPower2(int x)
{
	return (x && !(x & (x - 1)));
}

int isNthBitSet(int m, int x)
{
}
void print(int n)
{
	printf("%d", n);
}

int lonelyNum(int *num)
{
	int i;
	int x = num[0];
	int len = sizeof(num) / sizeof(int);

	for (i = 1; i < len; ++i)
	{
		printf("%d", x);
		x = x ^ num[i];
	}
	return x;
}
int main()
{
	printf("%d\n", isPower2(8));
	int u[] = {1, 2, 1, 2, 3, 3};
	printf("%d", lonelyNum(u));
	int x = 2 ^ 2;
	print(x);
	return 0;
}
