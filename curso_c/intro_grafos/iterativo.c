#include <stdio.h>

int restar(x)
{
	while(x>1)
	{
		printf("x: %d\n",x);
		x=x-1;
	}
	return x;
}

int main()
{
	int a = 3e5;
	//int a = 1e15;
	int b=restar(a);
	printf("b: %d\n",b);
	return 0;
}
