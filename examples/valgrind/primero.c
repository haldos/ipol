#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

  int i;
  int *a = malloc(sizeof(int) * 10);

  if (!a) return -1; /*malloc failed*/

int c;
  for (i = 0; i < 10; i++){
    c=a[i];
  }

  free(a);

  return 0;

}
