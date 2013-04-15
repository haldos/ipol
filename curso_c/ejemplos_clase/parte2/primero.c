#include <stdio.h>

int por2b(int *a)
{
   (*a)*=2;
	int b = *a;
	return b;
}

int por2a(int a)
{	
	int b = 2*a;
	return b;
}

int main()
{	
	int a = 10;
	
	printf("POR VALOR:\n");
	printf("---------------\n");
	printf("Antes de intercambiar: a = %d.\n",a);
   int b1 = por2a(a);
 
	printf("Después de intercambiar: a = %d y b1 = %d.\n",a,b1);
	printf("\n");
   int b2 = por2b(&a);

	printf("POR REFERENCIA:\n");
	printf("----------\n");
	printf("Antes de intercambiar: a = %d y b = %d.\n",a,b2);

}


