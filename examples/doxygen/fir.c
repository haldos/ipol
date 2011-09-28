// fir.c

/** @file
 * \brief Implementa las funciones de inicialización del filtro, actualización del
 * índice del buffer circular y la función de filtrado propiamente dicha.
*/

#include "fir.h"

/// Coeficientes del filtro.
sample_t a[TAP_LENGTH]; 
/// Entrada al filtro, del mismo tamaño que a[].
sample_t buff_in[TAP_LENGTH];
/// Puntero a una muestra, siempre apunta a la ultima muestra ingresada (circular).
int p; 

/** \fn ini_fir(sample_t coefs[])
 * \brief Inicializa el filtro.
 * \param coefs[] Coeficientes del filtro (array de elementos tipo sample_t).
 * @return No tiene salida.
*/
void ini_fir(sample_t coefs[]){
    int index;
    for (index=0;index<TAP_LENGTH;index++){
        a[index] = coefs[index];
        buff_in[index] = 0;
    }
    p = 0;
}

/** \fn update_p(int paso)
 * \brief Actualiza el índice que apunta a la última muestra ingresada en el
 * buffer circular de entrada.
 * \param paso Cantidad a incrementar/decrementar el índice (entero).
 * @return No tiene salida.
*/
void update_p(int paso){
    if (p+paso<0){
        p = TAP_LENGTH + p + paso;
    } else if (p+paso>TAP_LENGTH-1){
        p = p + paso - TAP_LENGTH;
    } else {
        p = p + paso;
    }
}

/** \fn fir(sample_t muestra)
 * \brief Aplica el filtro FIR a la muestra de entrada.
 * \param muestra Muestra de la señal de entrada (tipo sample_t).
 * @return Devuelve la muestra de la señal de salida del filtro.
*/
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
