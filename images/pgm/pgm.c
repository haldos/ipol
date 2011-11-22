#include <stdio.h>
#include <stdlib.h>

// Funciones para abrir y guardar imágenes en formato PGM.

int *load_pgm(const char *filename, int *w, int *h){
    
    // Crea el puntero file y abre el archivo solo para lectura.
    FILE *file = fopen(filename, "r");
    
    // Chequeo de existencia del archivo.
    if (file == NULL){
		printf("Falla al abrir el archivo %s.\n", filename);
		return NULL;
	} else {
		printf("ARCHIVO: %s.\n", filename);
        }
    
    // Se lee la primera línea del archivo para verificar formato P2 (ASCII) ó P5 (binario).
    int linea = 1;
    char valor[64];
    fscanf(file, "%s", valor);
    linea = linea++;
    if (valor[0] == 'P' && valor[1] == '2')
        printf("PGM tipo P2 (ASCII).\n");
    else {
        if (valor[0] == 'P' && valor[1] == '5'){
            printf("PGM tipo P5 (binario).\nError: Esta función solo abre PGM ASCII.");
            return NULL;
        }
        else {
            printf("Error: Tipo de archivo desconocido.\n");
            return NULL;
        }
    }

    // Leo segunda línea (tamaño).
    fscanf(file, "%d", w);
    fscanf(file, "%d", h);
    linea = linea++;
    
    // Tercera línea, máximo valor de nivel de gris en la imagen.
        // to do: agregar caso en que el valor máximo es mayor a 255 (16 bits).
    fscanf(file, "%s", valor);
    int maxvalue = atoi(valor);
    linea = linea++;

    // Reservo memoria para guardar la imagen.
    int *x = (int*)malloc((*w) * (*h) * sizeof (int));
    
    // Leo el resto de la imagen.
    int i, j;
    for (j = 0; j < *h; j++) {
        for (i = 0; i < *w; i++) {
            fscanf(file, "%s", valor);
            x[(*w)*j+i] = atoi(valor);
        }
    }
    
    // Cierro el archivo.
    fclose(file);
    return x;
}

void save_pgm(char *filename, int *image, int w, int h){
    
    // Crea el puntero file y abre el archivo solo para escritura.
    // Se crea un archivo nuevo y se sobreescribe si ya existe.
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error al crear el archivo %s.\n", filename);
        return;
    } else {
        printf("Se crea el archivo: %s.\n", filename);
    }
    
    // Escribo encabezado.
        // to do: agregar caso en que el valor máximo es mayor a 255 (16 bits).
    int maxvalue = 255;
    fprintf(file, "P2\n%d %d\n%d\n", w, h, maxvalue);
    
    // Escribo el resto del archivo.
    int i;
    for (i = 0; i < w * h; i++) {
        fprintf(file, "%d ", image[i]);
        if ((i%20==0)&&(i!=0))
                fprintf(file, "\n");
    }
    
    // Cierro el archivo.
    fclose(file);
}