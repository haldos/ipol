#include <stdio.h>
#include "genera_senales.h" // Ya incluye al fir.h.

void print_signal(sample_t *signal, int n){
    sample_t *pf = signal;
    int index;
    for (index=0;index<n;index++){
        printf("%1.3f ",*pf);
        pf++;
    }
    printf("\n");
}
#define DEBUG 1

void init_array(sample_t *signal, int n, sample_t value){
    sample_t *pf = signal;
    int index;
    for (index=0;index<n;index++){
		  *pf++=value;
    }
    printf("\n");
}

int main(){
    
    // Señales de entrada y salida:
    sample_t entrada[SIGNAL_LENGTH];
    sample_t salida[SIGNAL_LENGTH];
    
    // Coeficientes del FIR:
    sample_t coefs[TAP_LENGTH];
	 init_array(coefs, TAP_LENGTH, 1.0/TAP_LENGTH); 
#if DEBUG   
    print_signal(coefs,TAP_LENGTH);
#endif
	 // Inicializo entrada:
    step(entrada,SIGNAL_LENGTH,SIGNAL_LENGTH/2,1);
    //impulse(entrada,SIGNAL_LENGTH);
#if DEBUG
    printf("Entrada: \n");
    print_signal(entrada,SIGNAL_LENGTH);
    //print_signal(entrada);
#endif    
    // Inicializo FIR:
    ini_fir(coefs);
    
    int i;
    for(i=0;i<SIGNAL_LENGTH;i++){
        salida[i] = fir(entrada[i]);
    }
#if DEBUG    
    printf("Salida: \n");
    print_signal(salida,SIGNAL_LENGTH);
#endif
}
