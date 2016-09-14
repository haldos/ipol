#include <stdio.h>
#include <math.h>

float fun(float a, float b)
{
	return sqrt(a*a+b*b);
}

void init(float* array)
{
	float pi=3.14;
	for(int i=0;i<1000;i++)
            array[i]=sin(pi/4*i);

}

void procesar(float* in, float* out)
{
	for(int i=1;i<1000;i++)
           out[i]=fun(in[i],in[i-1]);
}

void mostrar(float* in)
{
	for(int i=0;i<1000;i++)
          printf("in[%d]: %g\n",i,in[i]);
}

int main()
{	
	float v[1000];
	float w[1000];
	
	init(v);
	procesar(v,w);
	mostrar(w);
	return 0;
}


