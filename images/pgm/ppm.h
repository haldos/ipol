// Funciones para abrir y guardar imágenes en formato PPM.

int *load_ppm(const char *filename, int *w, int *h);

void save_ppm(char *filename, int *image, int w, int h);