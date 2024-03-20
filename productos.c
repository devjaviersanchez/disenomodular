#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "productos.h"
#include "lectura.h"

void LeerProductos(Productos* productos){

    FILE *fichero;
	fichero=fopen("Productos.txt","r");

    if (fichero == NULL)puts("\nError al abrir Productos.txt");
	else
	{
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[7];//vector de cadenas ,contendra 7 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 7; i++) tokens[i] = strtok(NULL, delim);

			productos[j].id_prod=entero(tokens[0]) ;
			strcpy(productos[j].descripcion,tokens[1]);
			productos[j].id_categoria=entero(tokens[2]) ;
			productos[j].id_gestor=entero(tokens[3]) ;
			productos[j].stock=entero(tokens[4]) ;
			productos[j].entrega=entero(tokens[5]) ;
            productos[j].importe=entero(tokens[6]) ;
			j++;
		}
	}
    fclose(fichero);
}

void MostrarProductos(Productos *productos,int n_productos,AdminProv*adminprov,int posicion_vector){

    int j=n_productos-1;
    int cont=0;

	while(j>=0){
        if(adminprov[posicion_vector].id_empresa == productos[j].id_gestor || strcmp(adminprov[posicion_vector].perfil,"admin") == 0){
            printf("\n");
            printf("Producto: %d\n",productos[j].id_prod);
            printf("Descripcion: %s\n",productos[j].descripcion);
            printf("Categoria: %d\n",productos[j].id_categoria);
            printf("Gestor: %d\n",productos[j].id_gestor);
            printf("Stock: %d\n",productos[j].stock);
            printf("Entrega: %d\n",productos[j].entrega);
            printf("Importe: %d\n",productos[j].importe);
            printf("\n");cont++;
        }

        j--;
    }

	if (cont < 1) printf("Usted no tiene ningun producto dado de alta\n");
}
