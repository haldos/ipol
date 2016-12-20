#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "heap.h"


int number_of_nodes=10;

/*Test code. Tests if a path is correct and it has the given value */
int main()
{
	printf("<heaptest>\n");
	HEAP heap;
	ITEM p[number_of_nodes];
	ITEM *res;

	p[0].v=123;
	p[1].v=23;
	p[2].v=0;
	p[3].v=22;
	p[4].v=255;
	p[5].v=1;
	p[6].v=10;
	p[7].v=3;
	p[8].v=101;
	p[9].v =102;

	heap_init(&heap, number_of_nodes);

	printf("\nAdding nodes to the heap\nLabel\tCost\n");
	for (int i=0;i<number_of_nodes;i++) {
		printf("<iter i=%d>\n");
		p[i].label = i;
		//p[i].v = (int)(rand()/1000000);
		printf("%d\t%.2f\n",p[i].label,p[i].v);
		heap_addItem(&heap,&(p[i]));
		heap_print(&heap);
		printf("</iter>\n");
	}

	heap_print(&heap);

	/*
	printf("\n\nExtracting the nodes from the heap\nLabel\tCost\n");
	while (!heap_isEmpty(&heap)) {
		res = heap_extractMin(&heap);
		printf("%d\t%.2f\n",res->label,res->v);
	}
	*/
	heap_delete(&heap);
	printf("</heaptest>\n");
	return 0;
}



