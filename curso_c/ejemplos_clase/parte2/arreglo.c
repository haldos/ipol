#include <stdio.h>

int main()
{	
	int v[]={10,20,30,40,50};
	int a=-100;

	for(int i=-5;i<6;i++)
		printf("i: %d v: %d &v[]: %x\n",i,v[i],&v[i]);
	
	int* pv=&v[0];

	printf("pv: %x *pv: %d\n",pv,*pv);
	pv++;
	printf("pv: %x *pv: %d\n",pv,*pv);
	pv=&v[4];
	printf("pv: %x *pv: %d\n",pv,*pv);
	
	printf("&a: %x\n",&a);

	printf("tamaño del entero: %d\n",sizeof(int));
}


