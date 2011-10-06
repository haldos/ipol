// test_flow.c

#include "iio.h"
#include <stdio.h> // only for "fprintf"
#include <stdlib.h> // only for "free"

int main(int argc, char *argv[]){
    
    if (argc!=3){
        printf("Usage: %s input_image_1 input_image_2\n",argv[0]);
    } else {
        int w, h, pixeldim;
        float *im1 = iio_read_image_float_vec(argv[1], &w, &h, &pixeldim);
        float *im2 = iio_read_image_float_vec(argv[2], &w, &h, &pixeldim);
        fprintf(stderr, "Two images were loded:\n        im1: %dx%d image with %d channels\n"
                "        im2: %dx%d image with %d channels\n", w, h, pixeldim, w, h, pixeldim);
        
        // some processing here
        
        float *u = malloc(w*h*sizeof*u);
        float *v = malloc(w*h*sizeof*v);
        // known flow (just for testing)
        int i,j;
        for(i=0;i<w;i++){
            for(j=0;j<h;j++){
                u[w*j+i] = 200;
                v[w*j+i] = -100;
            }
        }

        // here we have flow already calculated and saved in two arrays
        // "u" and "v". now we save it in a two channels tiff file:
        
        float *x = malloc(w*h*2*sizeof*x);
        for(i=0;i<w;i++){
            for(j=0;j<h;j++){
                x[2*(w*j+i)] = u[w*j+i];
                x[2*(w*j+i)+1] = v[w*j+i];
            }
        }
        iio_save_image_float_vec("flow", x, w, h, 2);
        
        // free memory
        free(im1);
        free(im2);
        free(x);
        free(u);
        free(v);
        
        return 0;
    }
    
}