#include <stdio.h>

int restar(int x)
{
	//printf("x: %d\n",x);
if(x>1) restar(x-1);
else return 0;
}


int main()
{
	int a = 1e5;
	//int a = 1e15;
	int b=restar(a);
	//printf("b: %d\n",b);
	return 0;
}


