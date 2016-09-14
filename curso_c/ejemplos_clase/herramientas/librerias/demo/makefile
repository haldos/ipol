all: demo.exe

demo.exe: demo.o
	gcc  demo.o -o demo.exe -L../library -labc

demo.o: demo.c
	gcc -I../library -c demo.c

clean:
	rm -f *.o demo.exe
