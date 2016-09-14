all: libabc.a

libabc.a: a.o b.o c.o 
	ar -rs libabc.a a.o b.o c.o 

a.o: a.c
	gcc -c a.c -o a.o

b.o: b.c
	gcc -c b.c -o b.o

c.o: c.c
	gcc -c c.c -o c.o
	
clean:
	rm -f *.o prog.exe
