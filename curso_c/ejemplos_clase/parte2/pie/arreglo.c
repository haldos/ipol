#include <stdio.h>


int main()
{	
	int ai[]={1,2,3,4,5};
	int b=-9;
	int* pi;

	pi=ai;

	printf("ai[0]: %d\n",ai[0]);
	printf("ai: %x\n",ai);
	printf("&ai[0]: %x\n",&ai[0]);
	printf("&ai[1]: %x\n",&ai[1]);
	
	printf("pi: %x *pi: %d\n",pi,*pi);
	pi++;
	printf("pi: %x *pi: %d\n",pi,*pi);
	pi++;
	printf("pi: %x *pi: %d\n",pi,*pi);

	printf("tamaño entero: %d\n", sizeof(int));
	printf("tamaño float : %d\n", sizeof(float));
	printf("tamaño double: %d\n", sizeof(double));
	//empiezo en el cuarto elemento
	pi=&ai[3];
	printf("pi: %x *pi: %d\n",pi,*pi);
	pi=ai[3];
	printf("pi: %x\n",pi);
	//printf("*pi: %d\n",*pi);
	//printf("pi: %x *pi: %d\n",pi,*pi);
	//printf("ai[6]: %d\n",ai[6]);

	printf("b: %d &b: %x\n",b,&b);
	printf("ai[-1]: %d\n",ai[-1]);
	ai[-1]=23;
	printf("b: %d &b: %x\n",b,&b);
}


