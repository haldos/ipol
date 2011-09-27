#include <stdio.h>
#include "genera_senales.h" // Ya incluye al fir.h.

void print_signal(sample_t *signal){
    sample_t *pf = signal;
    int index;
    for (index=0;index<SIGNAL_LENGTH;index++){
        printf("%1.3f ",*pf);
        pf++;
    }
    printf("\n");
}

int main(){
    
    // Señales de entrada y salida:
    sample_t entrada[SIGNAL_LENGTH];
    sample_t salida[SIGNAL_LENGTH];
    
    // Coeficientes del FIR:
    sample_t coefs[TAP_LENGTH];
        coefs[0] = 0.25;
        coefs[1] = 0.25;
        coefs[2] = 0.25;
        coefs[3] = 0.25;
    
    // Inicializo entrada:
    //step(entrada,SIGNAL_LENGTH,SIGNAL_LENGTH/2,1);
    impulse(entrada,SIGNAL_LENGTH);
    printf("Entrada: \n");
    print_signal(entrada);
    //print_signal(entrada);
    
    // Inicializo FIR:
    ini_fir(coefs);
    
    int i;
    for(i=0;i<SIGNAL_LENGTH;i++){
        salida[i] = fir(entrada[i]);
    }
    
    printf("Salida: \n");
    print_signal(salida);
}
