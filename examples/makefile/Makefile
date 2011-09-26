EXES=prueba
OBJS=fun_strings
OBJS_EXT=$(addsuffix .o , $(OBJS) )
EXES_EXT=$(addsuffix .bin , $(EXES) )
LIBNAME=prueba
CFLAGS=-Wall -Wextra -Wno-unused -Werror -pedantic-errors -g -rdynamic -O3

all: $(EXES_EXT)

echo:
	echo $(EXES_EXT)

.SECONDARY:

%.bin:%.o lib
	gcc $(CFLAGS) $< -std=c99 -L. -l$(LIBNAME) -o $@ 

%.o: %.c
	gcc $(CFLAGS) -I. -std=c99 -c $^

lib: lib$(LIBNAME).a


lib$(LIBNAME).a: $(OBJS_EXT)
	ar -rcs lib$(LIBNAME).a $^

clean:
	-rm -f *.o
	-rm -f *.a
	-rm -f *.bin
