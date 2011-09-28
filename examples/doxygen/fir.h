// fir.h

/** @file
 * \brief Implementa las funciones de inicialización del filtro, actualización del
 * índice del buffer circular y la función de filtrado propiamente dicha.
*/

/// Cantidad de coeficientes del filtro.
#define TAP_LENGTH 4 
/// Cantidad de muestras.
#define SIGNAL_LENGTH 10 

/// Tipo definido para manejar las muestras de la señal.
typedef float sample_t;

/** \fn ini_fir(sample_t coefs[])
 * \brief Inicializa el filtro.
 * \param coefs[] Coeficientes del filtro (array de elementos de tipo sample_t).
 * @return No tiene salida.
*/
void ini_fir(sample_t coefs[]);

/** \fn fir(sample_t muestra)
 * \brief Aplica el filtro FIR a la muestra de entrada.
 * \param muestra Muestra de la señal de entrada (tipo sample_t).
 * @return Devuelve la muestra de la señal de salida del filtro.
*/
sample_t fir(sample_t muestra);

/** \fn update_p(int paso)
 * \brief Actualiza el índice que apunta a la última muestra ingresada en el
 * buffer circular de entrada.
 * \param paso Cantidad a incrementar/decrementar el índice (entero).
 * @return No tiene salida.
*/
void update_p(int paso);