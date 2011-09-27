#!/bin/bash

OBJ = fir.o genera_señales.o test_fir.o


test_fir : $(OBJ)
	gcc $(OBJ) -o $@

%.o: %.c
	gcc -c $^