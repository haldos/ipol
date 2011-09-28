// segundo.c

#include <stdio.h>

/** @file
 * \brief Segundo ejemplo de programa para introducir el uso del debugger (ddd).
 */

/// Ejemplo de lista encadenada
struct elemento{
    int valor;
    struct elemento * next;
};

typedef struct elemento item;

int main(){
    
    item item1, item2, item3;
    item1.next = &item2; item1.valor = 10;
    item2.next = &item3; item2.valor = 20;
    item3.next = &item1; item3.valor = 25;
    
    /// Recorro una lista encadenada
    int i;
    item * actual = &item1;
    for ( i=0 ; i<10 ; i++){
        printf("Valor del elemento: %d.\n",actual->valor);
        actual = actual->next;
    }
}