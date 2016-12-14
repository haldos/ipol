typedef struct
{
	///variable auxiliar que guarda la posicion actual en el array interno
	int idx;
	///nombre de elemento
	int label;
	///prioridad del elemento
	float v;
}ITEM;

typedef struct
{
	///tamaño del array
	int n_max;
	///cantidad de elementos no vacios del array
	int n;
	///array de punteros a ITEM
	ITEM **data;
}HEAP;

/** Obtiene el mínimo elemento del heap y lo elimina del mismo*/
ITEM* heap_extractMin(HEAP* h);
/** Reserva la memoria para almacenar los punteros e inicializa los atributos del heap*/
void  heap_init(HEAP* h, int n_max);
/** Verifica si el heap esta vacio*/
int   heap_isEmpty(HEAP* h);
/** agrega el elemento it al heap h*/
void  heap_addItem(HEAP* h, ITEM* it);
/** libera la memoria reservada por el heap y deja sus atributos con valores coherentes. Por ejemplo tamaño =0 */
void  heap_delete(HEAP* h);
/** Realiza la operacion move down del heap. Compara con lo elementos hijos y si es mas grande que alguno de ellos realiza el swap de los elementos*/
void  heap_moveDown(HEAP* h, int i);
/** Realiza la operacion move up del heap. Compara con el elemento superior y si es mas pequeño que este realiza el swap de los elementos*/
void  heap_moveUp(HEAP* h, int i);
/** Imprime el contenido del heap */
void heap_print(HEAP* h);
