// tercero.c

#include <stdio.h>

/** @file
 * \brief Tercer ejemplo de programa para introducir el uso del debugger (ddd).
 */

#define TAM 10

int main(){
    int arreglo[TAM];
    int veinte = 20;
    
    int i;
    for(i=0;i<=TAM+1;i++){
        arreglo[i] = i;
    }
    
    printf("veinte -> %d.\n",veinte);
    printf("i -> %d.\n",i);
}