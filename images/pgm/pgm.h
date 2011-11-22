// Funciones para abrir y guardar imágenes en formato PGM.

int *load_pgm(const char *filename, int *w, int *h);

void save_pgm(char *filename, int *image, int w, int h);