#include <stdio.h>

int main()
{	
	int a = 10;
	int* pa= &a;
	printf("&a: %x\n",&a);
	printf("a: %d pa: %x\n",a,pa);
	printf("*pa: %d \n",*pa);
	*pa=11;
	printf("a: %d pa: %x\n",a,pa);

}


