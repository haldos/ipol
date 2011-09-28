// test_fir.c

/** @file
 * \brief Función para probar el módulo FIR implementado. Se crea una señal de
 * entrada, utilizando las funciones implementadas en \p genera_senales, y se
 * utiliza las funciones implementadas en \p fir para filtrar la señal. 
*/

#include <stdio.h>
#include "genera_senales.h"

/** \fn print_signal(sample_t *signal)
 * \brief Imprime en la salida estándar la señal de entrada.
 * \param *signal Puntero a un array de elementos de tipo sample_t, donde se
 * guarda la señal a imprimir.
 * @return No tiene salida.
*/
void print_signal(sample_t *signal){
    sample_t *pf = signal;
    int index;
    for (index=0;index<SIGNAL_LENGTH;index++){
        printf("%1.3f ",*pf);
        pf++;
    }
    printf("\n");
}

/** \fn main()
 * \brief Prueba de los módulos implementados.
 * @return No tiene salida.
*/
int main(){
    
    /// Señal de entrada.
    sample_t entrada[SIGNAL_LENGTH];
    /// Señal de salida.
    sample_t salida[SIGNAL_LENGTH];
    
    /// Coeficientes del FIR.
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