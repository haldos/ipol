#include "iio.h"
#include <stdio.h> // only for "fprintf"
#include <stdlib.h> // only for "free"

int main(int c, char *v[])
{
	int w, h, pixeldim;
	float *x = iio_read_image_float_vec(v[1], &w, &h, &pixeldim);
	fprintf(stderr, "got a %dx%d image with %d channels\n", w, h, pixeldim);
        
        // some processing here...
        
	iio_save_image_float_vec(v[2], x, w, h, pixeldim);
	free(x);
	return 0;
}