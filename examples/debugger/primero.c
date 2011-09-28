// primero.c

#include <stdio.h>

/** @file
 * \brief Primer ejemplo de programa para introducir el uso del debugger (ddd).
 */

int main(){
    
    /// Struct de prueba
    typedef struct {
        char *name;
        char sexo;
        int edad;
    } persona;
    
    persona p1;
    p1.name = "Juan";
    p1.sexo = 'M';
    p1.edad = 30;
        
    /// Puntero a un struct
    persona *pp1;
    pp1 = &p1;
    
    return 0;
}