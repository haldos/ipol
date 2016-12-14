#include "heap.h"
#include <stdlib.h>
#include <stdio.h>


#define PARENT(i) (i-1)/2
#define RIGHT(i) (i-1)/2
#define LEFT(i) (i-1)/2

ITEM* heap_extractMin(HEAP* h)
{}

void heap_init(HEAP* h, int n_max)
{
	h->n_max=n_max;
	h->n=0;
	h->data=malloc(n_max*sizeof(*(h->data)));
}

int heap_isEmpty(HEAP* h)
{
	return (h->n==0);
}

void heap_addItem(HEAP* h, ITEM* it)
{
	if(h->n>=h->n_max)
	{
		printf("heap full\n");
		return;
	}
		h->data[h->n]=it;
		heap_moveUp(h,h->n++);
}

void heap_delete(HEAP* h)
{
	h->n_max=0;
	h->n=0;
	if(h->data) free(h->data);
}

void heap_moveDown(HEAP* h, int i)
{}

#define H_V(i) h->data[i]->v
void swap(HEAP* h, int i, int j)
{
	ITEM* tmp=h->data[i];
	h->data[i]=h->data[j];
	h->data[j]=tmp;
	//reset labels
	h->data[i]->label=i;
	h->data[j]->label=j;
}

void heap_moveUp(HEAP* h, int i)
{
	while(i!=0)
	{
		int j=PARENT(i);
		if(H_V(i)<H_V(j))

			swap(h,i,j);
		else
			break;
		i=j;
	}
}

void heap_print(HEAP* h)
{
	ITEM* res;
	printf("\n\nPrint array of the heap\nLabel\tCost\n");
	for (int i = 0; i < h->n; i++)
	{
		res = h->data[i];
		printf("%d\t%.2f\n",res->label,res->v);
	}
}
