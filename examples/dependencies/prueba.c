#include "fun_strings.h"
#include <stdio.h>

#include <string.h>

int main(int argc, char** argv)
{

	char *s1=argv[1];
	char s2[64];

	strcpy(s2,s1);
	printf("string: %s\n",s2);

	fun_strings();
	return 0;
}


