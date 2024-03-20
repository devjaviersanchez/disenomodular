#include <stdio.h>
#include <stdlib.h>
#include "lectura.h"

int entero(char* a) {

	int n = 0;
	int c=0;

	while(a[c] != '\0') {
		n = n * 10 + a[c] - '0';
		c++;
	}

	return n;
}

int LineasFichero(char* );

int LineasFichero(char* nombre){

    FILE* fichero;
    int ch, num_lineas=0;

    if ((fichero = fopen(nombre, "r")) == NULL) printf("\nFallo al abrir %s",nombre);
    else {
        num_lineas = 0;

        while ((ch = fgetc(fichero)) != EOF)
            if (ch == '\n') num_lineas++;
   }

   return num_lineas+1;
}
