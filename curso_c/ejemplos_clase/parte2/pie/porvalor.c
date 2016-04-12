#include <stdio.h>

int por2(int a)
{	
	a=a*2;
	printf("adentro a: %d &a: %x\n",a,&a);
	return a;
}

int por2puntero(int* pa)
{
	printf("pa: %x\n",pa);
	*pa=135;
	return 0;
}

int main()
{	
	int a = 2;
	printf("paso 1 a: %d\n",a);
	printf("&a afuera: %x\n",&a);
	int c=por2(a);
	printf("paso 2 a: %d c: %d\n",a,c);

	int d=por2puntero(&a);
	printf("paso 3 a: %d\n",a);
}


