#include "fir.h"

sample_t a[TAP_LENGTH]; // Coeficientes del filtro.
sample_t buff_in[TAP_LENGTH]; //Entrada al filtro, del mismo tamaño que a[].
int p; // Puntero a una muestra, siempre apunta a la ultima muestra 
       // ingresada (circular).

void ini_fir(sample_t coefs[]){
    int index;
    for (index=0;index<TAP_LENGTH;index++){
        a[index] = coefs[index];
        buff_in[index] = 0;
    }
    p = 0;
}

void update_p(int paso){
    if (p+paso<0){
        p = TAP_LENGTH + p + paso;
    } else if (p+paso>TAP_LENGTH-1){
        p = p + paso - TAP_LENGTH;
    } else {
        p = p + paso;
    }
}

sample_t fir(sample_t muestra){
    buff_in[p] = muestra;
    int i;
    sample_t muestra_out = 0;
    for(i=0;i<TAP_LENGTH;i++){
        muestra_out = muestra_out + a[TAP_LENGTH-i-1]*buff_in[p];
        update_p(1);
    }
    update_p(1);
    return muestra_out;
}
