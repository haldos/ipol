test_fir : fir.o genera_señales.o test_fir.o
	gcc -g -c fir.c
	gcc -g -c genera_señales.c
	gcc -g -c test_fir.c
	gcc -g fir.o genera_señales.o test_fir.o -o test_fir