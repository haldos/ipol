#include "pgm.h"
#include <stdio.h> // only for "fprintf"
#include <stdlib.h> // only for "free"

int main(int c, char *v[]){

    if (c != 3) {
        printf("Usage: %s input_image output_image\n", v[0]);
    } else {
        int w, h;
        int *x = load_pgm(v[1], &w, &h);
        fprintf(stderr, "Got a %dx%d image.\n", w, h);

        // some processing here...

        // Umbralizado.
        int th = 100;
        int i;
        for (i = 0; i < w * h; i++) {
            if (x[i] <= th) {
                x[i] = 0;
            } else {
                x[i] = 255;
            }
        }

        save_pgm(v[2], x, w, h);
        free(x);
        return 0;
    }
    
}