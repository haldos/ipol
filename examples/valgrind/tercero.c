#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

	int *a = malloc(sizeof(int) * 100);
	int *b = malloc(sizeof(int) * 100);

	free(a);

	return 0;
}
