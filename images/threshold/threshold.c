#include "iio.h"
#include <stdio.h> // only for "fprintf"
#include <stdlib.h> // only for "free"

int main(int c, char *v[]){
    
    if (c!=3){
        printf("Usage: %s threshold input_image output_image\n",v[0]);
    } else {
        int w, h, pixeldim;
        float *x = iio_read_image_float_vec(v[2], &w, &h, &pixeldim);
        fprintf(stderr, "Got a %dx%d image with %d channels\n", w, h, pixeldim);

        printf("w = %d\n",w);
        printf("h = %d\n",h);
        printf("pixeldim = %d\n",pixeldim);

        iio_save_image_float_vec(v[3], x, w, h, pixeldim);
        free(x);
        return 0;
    }
    
}