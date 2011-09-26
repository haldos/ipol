#include <stdio.h>
#include "auxiliares.h"

int main(){
	int a = 20;
	int b = 15;
	int c;
	c = maximo(a,b);
	printf("El máximo de a=%d y b=%d es %d.\n",a,b,c);
        
        int d = 23;
        int e = 4;
        int f;
        f = minimo(d,e);
        printf("El mínimo de d=%d y e=%d es %d.\n",d,e,f);
}
