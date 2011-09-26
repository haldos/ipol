EXES=prueba
OBJS=fun_strings
SRCS=$(addsuffix .c , $(OBJS) $(EXES))
OBJS_EXT=$(addsuffix .o , $(OBJS) )
EXES_EXT=$(addsuffix .bin , $(EXES) )
LIBNAME=prueba
CFLAGS=-Wall #-std=c99
all: $(EXES_EXT)

echo:
	echo $(EXES_EXT)

.SECONDARY:

%.bin:%.o lib
	gcc $(CFLAGS) $< -std=c99 -L. -l$(LIBNAME) -o $@ 

%.o: %.c
	gcc -MMD $(CFLAGS) -I.  -c $^
	@cp $*.d $*.P #; \
    #sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
                #-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P #; \
            #rm -f $*.d

lib: lib$(LIBNAME).a


lib$(LIBNAME).a: $(OBJS_EXT)
	ar -rcs lib$(LIBNAME).a $^

clean:
	-rm -f *.o
	-rm -f *.a
	-rm -f *.bin
	-rm -f *.P
	-rm -f *.d
	-rm -f *.gch
	
-include $(SRCS:.c=.P)	
