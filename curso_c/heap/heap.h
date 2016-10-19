typedef struct
{
	int label;
	float v;
}ITEM;

typedef struct
{
	int n_max;
	int n;
	///array de punteros a ITEM
	ITEM **data;
}HEAP;

/** Obtiene el mínimo elemento del heap y lo elimina del mismo*/
ITEM* heap_extractMin(HEAP* h);
/** Reserva la memoria para almacenar los punteros e inicializa los atributos del heap*/
void  heap_init(HEAP* h, int n_max);
int   heap_isEmpty(HEAP* h);
void  heap_addItem(HEAP* h, ITEM* it);
void  heap_free(HEAP* h);
void  heap_moveDown(HEAP* h, int i);
void  heap_moveUp(HEAP* h, int i);

void heap_print(HEAP* h);
