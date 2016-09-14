// tercero.c

#include <stdio.h>
#include <stdlib.h>

/// Struct de prueba
typedef struct
{
	char *name;
	char sexo;
	int edad;
} persona;

persona* crear_persona(char* name, char sexo, int edad);

/** @file
 * \brief Primer ejemplo de programa para introducir el uso del debugger (ddd).
 */
int main()
{
    /// Puntero a un struct
    persona *p1=crear_persona("Juan",'M',300);
printf("1\n");
	 //uso mediante puntero
	 int edad=p1->edad;
	 printf("edad: %d\n",edad);

    return 0;
}


persona* crear_persona(char* name, char sexo, int edad)
{
	persona *p1=NULL;
	if( (edad>=0) && (edad<100) )
	{
		p1=malloc(sizeof (persona));
    p1->name = name;
    p1->sexo = sexo;
    p1->edad = edad;
	}
	return p1;
}
