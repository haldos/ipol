#include <stdio.h>


int main()
{	
	char saludo[10]={'h','o','l','a','\0','j'};
	char saludo2[]="hola juan como andas?";
	printf("saludo : %s\n",saludo);
	printf("saludo2: %s\n",saludo2);

	for(int i=0;i<10;i++)
	{
		printf("saludo[%d]: %c\n",i,saludo[i]);
	}
	
	printf("saludo: ");
	for(int i=0;i<10;i++)
	{
		printf("%c",saludo[i]);
	}
	printf("\n");
}


