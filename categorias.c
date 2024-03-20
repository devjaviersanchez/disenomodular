#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "categorias.h"
#include "lectura.h"

void MostrarCategorias(Categorias *categorias,int n_categorias){

    int j=n_categorias - 1;

	while(j>=0){
        printf("\n");
		printf("Id de categoria: %d\n",categorias[j].id_categoria);
		printf("Descripcion: %s\n",categorias[j].descripcion);

		j--;
		printf("\n");
	}
}


void LeerCategorias(Categorias* categorias){

    FILE *fichero;
	fichero=fopen("Categorias.txt","r");

    if (fichero == NULL) puts("\nError al abrir Categorias.txt");
	else {
		int j=0;
		const char delim[2]="-";
		char* tokens[2];//vector de cadenas ,contendra 2 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);
			tokens[1] = strtok(NULL, delim);

			categorias[j].id_categoria=entero(tokens[0]) ;
			strcpy(categorias[j].descripcion,tokens[1]);
			j++;
		}
	}
    fclose(fichero);
}

