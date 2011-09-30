#include "iio.h"
#include <stdio.h> // only for "fprintf"
#include <stdlib.h> // only for "free"

int main(int c, char *v[]){
    
    if (c!=4){
        printf("Usage: %s threshold input_image output_image\n",v[0]);
    } else {
        int w, h, pixeldim;
        float *x = iio_read_image_float_vec(v[2], &w, &h, &pixeldim);
        fprintf(stderr, "Got a %dx%d image with %d channels\n", w, h, pixeldim);
        int th = atoi(v[1]);
        
        int i;
        for( i=0 ; i<w*h*pixeldim ; i++ ){
            if ( x[i] <= th ){
                x[i] = 0;
            } else {
                x[i] = 255;
            }
        }

        iio_save_image_float_vec(v[3], x, w, h, pixeldim);
        free(x);
        return 0;
    }
    
}