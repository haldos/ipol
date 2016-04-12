#include <stdio.h>


int main()
{	
	int a[]={1,2,3,4,5};
	int b=-9;
	
	for(int i=0;i<6;i++)
		printf("a[%d]: %d\n",i,a[i]);

	for(int i=0;i<6;i++)
		a[i]=2*a[i];
	
	for(int i=0;i<6;i++)
		printf("a[%d]: %d\n",i,a[i]);
}


