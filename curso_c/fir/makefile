#!/bin/bash

OBJ = fir.o genera_senales.o test_fir.o


test_fir : $(OBJ)
	gcc -g $(OBJ) -o $@

%.o: %.c
	gcc -Ofast -fPIC -c -g $^

clean:
	rm -f *.o test_fir

