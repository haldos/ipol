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
        unsigned char byte : 8;
    } registro;
    
    // Utilice el tipo registro creado anteriormente para modificar una posición 
    // de memoria dada. Para ello siga los siguientes pasos:
    //          1. defina una variable entera inicializada en cero.
    //          2. imprima su valor en hexadecimal.
    
    typedef struct {
        registro byte1,byte2,byte3,byte4;
    } cuatro_bytes;
    typedef union {
        cuatro_bytes bytes;
        unsigned int valor;
    } entero;
    entero num;
    num.valor = 0;
    printf("Inicial:\n");
    printf("Valor (dec): %d \n", num.valor);
    printf("Valor (hex): %#x \n", num.valor);
    // Intento modificar <valor> usando los structs definidos antes:
    num.bytes.byte1.bits.bit0 = 1;
    num.bytes.byte1.bits.bit7 = 1;
    num.bytes.byte2.bits.bit0 = 1;
    printf("Final:\n");
    printf("Valor (dec): %d \n", num.valor);
    printf("Valor (hex): %#x \n", num.valor);
    
    printf("\n");
    
    int byte_to_mod = 0;
    int bit_to_mod = 0;
    int value = 0;
    num.valor = 0;
    printf("Se asignó nuevamente valor 0.\n");
    while (byte_to_mod!=-1){
        
        switch (byte_to_mod) {
            case 1:
                switch (bit_to_mod) {
                    case 0: num.bytes.byte1.bits.bit0 = value; break;
                    case 1: num.bytes.byte1.bits.bit1 = value; break;
                    case 2: num.bytes.byte1.bits.bit2 = value; break;
                    case 3: num.bytes.byte1.bits.bit3 = value; break;
                    case 4: num.bytes.byte1.bits.bit4 = value; break;
                    case 5: num.bytes.byte1.bits.bit5 = value; break;
                    case 6: num.bytes.byte1.bits.bit6 = value; break;
                    case 7: num.bytes.byte1.bits.bit7 = value; break;
                    default: break;
                }
                break;
            case 2:
                switch (bit_to_mod) {
                    case 0: num.bytes.byte2.bits.bit0 = value; break;
                    case 1: num.bytes.byte2.bits.bit1 = value; break;
                    case 2: num.bytes.byte2.bits.bit2 = value; break;
                    case 3: num.bytes.byte2.bits.bit3 = value; break;
                    case 4: num.bytes.byte2.bits.bit4 = value; break;
                    case 5: num.bytes.byte2.bits.bit5 = value; break;
                    case 6: num.bytes.byte2.bits.bit6 = value; break;
                    case 7: num.bytes.byte2.bits.bit7 = value; break;
                    default: break;
                }
                break;
            case 3:
                switch (bit_to_mod) {
                    case 0: num.bytes.byte3.bits.bit0 = value; break;
                    case 1: num.bytes.byte3.bits.bit1 = value; break;
                    case 2: num.bytes.byte3.bits.bit2 = value; break;
                    case 3: num.bytes.byte3.bits.bit3 = value; break;
                    case 4: num.bytes.byte3.bits.bit4 = value; break;
                    case 5: num.bytes.byte3.bits.bit5 = value; break;
                    case 6: num.bytes.byte3.bits.bit6 = value; break;
                    case 7: num.bytes.byte3.bits.bit7 = value; break;
                    default: break;
                }
                break;
            case 4:
                switch (bit_to_mod) {
                    case 0: num.bytes.byte4.bits.bit0 = value; break;
                    case 1: num.bytes.byte4.bits.bit1 = value; break;
                    case 2: num.bytes.byte4.bits.bit2 = value; break;
                    case 3: num.bytes.byte4.bits.bit3 = value; break;
                    case 4: num.bytes.byte4.bits.bit4 = value; break;
                    case 5: num.bytes.byte4.bits.bit5 = value; break;
                    case 6: num.bytes.byte4.bits.bit6 = value; break;
                    case 7: num.bytes.byte4.bits.bit7 = value; break;
                    default: break;
                }
                break;
            default:
                break;
                
        }
        
        printf("num:\n");
        printf("%x%x%x%x%x%x%x%x %x%x%x%x%x%x%x%x %x%x%x%x%x%x%x%x %x%x%x%x%x%x%x%x = %d\n",
            num.bytes.byte4.bits.bit7,num.bytes.byte4.bits.bit6,num.bytes.byte4.bits.bit5,
            num.bytes.byte4.bits.bit4,num.bytes.byte4.bits.bit3,num.bytes.byte4.bits.bit2,
            num.bytes.byte4.bits.bit1,num.bytes.byte4.bits.bit0,num.bytes.byte3.bits.bit7,
            num.bytes.byte3.bits.bit6,num.bytes.byte3.bits.bit5,num.bytes.byte3.bits.bit4,
            num.bytes.byte3.bits.bit3,num.bytes.byte3.bits.bit2,num.bytes.byte3.bits.bit1,
            num.bytes.byte3.bits.bit0,num.bytes.byte2.bits.bit7,num.bytes.byte2.bits.bit6,
            num.bytes.byte2.bits.bit5,num.bytes.byte2.bits.bit4,num.bytes.byte2.bits.bit3,
            num.bytes.byte2.bits.bit2,num.bytes.byte2.bits.bit1,num.bytes.byte2.bits.bit0,
            num.bytes.byte1.bits.bit7,num.bytes.byte1.bits.bit6,num.bytes.byte1.bits.bit5,
            num.bytes.byte1.bits.bit4,num.bytes.byte1.bits.bit3,num.bytes.byte1.bits.bit2,
            num.bytes.byte1.bits.bit1,num.bytes.byte1.bits.bit0,num.valor);
        
        printf("\n");
        printf("Byte a modificar:");
        scanf("%d",&byte_to_mod);
        printf("Bit a modificar:");
        scanf("%d",&bit_to_mod);
        printf("Valor para el bit a modificar:");
        scanf("%d",&value);
        
    }
} 