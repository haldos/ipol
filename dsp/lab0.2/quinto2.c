#include <stdio.h>

int main() {
    
    // Implementar un tipo de datos registro que permita acceder y modificar los
    // datos de 3 formas: byte, nibble y bit.

     typedef struct {
        unsigned char bit0 : 1;
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
    } tipo_bit;
    
    typedef struct{
        unsigned char nibble1 : 4;
        unsigned char nibble2 : 4;
    } tipo_nibbles;
    
    typedef union {
        tipo_bit bits;
        tipo_nibbles nibbles;
        unsigned char byte;
    } registro;
    
    // Utilice el tipo registro creado anteriormente para modificar una posición 
    // de memoria dada. Para ello siga los siguientes pasos:
    //          1. defina una variable entera inicializada en cero.
    //          2. imprima su valor en hexadecimal.
    
    typedef union{
        registro byte1;
        int valor;
    } entero;
    entero num;
    num.valor = 0;
    printf("Inicial:\n");
    printf("Valor (dec): %d \n", num.valor);
    printf("Valor (hex): %#x \n", num.valor);
    // Intento modificar <valor> usando los structs definidos antes:
    num.byte1.bits.bit0 = 1;
    num.byte1.byte = '8'; // '8' = 56 en ASCII.
    printf("Final:\n");
    printf("Valor (dec): %d \n", num.valor);
    printf("Valor (hex): %#x \n", num.valor);
} 