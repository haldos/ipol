typedef struct
{
	int label;
	float v;
}ITEM;

typedef struct
{
	int n_max;
	int n;
	ITEM **data;
}HEAP;

ITEM* heap_extractMin(HEAP* h);
void  heap_init(HEAP* h, int n_max);
int   heap_isEmpty(HEAP* h);
void  heap_addItem(HEAP* h, ITEM* it);
void  heap_free(HEAP* h);
void heap_moveDown(HEAP* h, int i);
void heap_moveUp(HEAP* h, int i);

void heap_print(HEAP* h);