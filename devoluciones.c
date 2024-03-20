#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "devoluciones.h"
#include "lectura.h"

void LeerDevoluciones(Devoluciones* devoluciones){

    FILE *fichero;
	fichero=fopen("Devoluciones.txt","r");

    if (fichero == NULL) puts("\nError al abrir Devoluciones.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[7];//vector de cadenas ,contendra 9 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 7; i++) tokens[i] = strtok(NULL, delim);

            devoluciones[j].id_pedido=entero(tokens[0]);
            devoluciones[j].id_prod=entero(tokens[1]);
            strcpy(devoluciones[j].fecha_devolucion,tokens[2]);
            strcpy(devoluciones[j].motivo,tokens[3]);
            strcpy(devoluciones[j].estado,tokens[4]);
			strcpy(devoluciones[j].fecha_aceptacion,tokens[5]) ;
			strcpy(devoluciones[j].fecha_caducidad,tokens[6]) ;
			j++;
		}
	}
}

void MostrarDevoluciones(Devoluciones* devoluciones,int n_devoluciones){

    int j=n_devoluciones - 1;

	while(j>=0){
        printf("\n");
        printf("Id del pedido: %d\n",devoluciones[j].id_pedido);
		printf("Id del producto: %d\n",devoluciones[j].id_prod);
		printf("Fecha de devolucion: %s\n",devoluciones[j].fecha_devolucion);
		printf("Motivo: %s\n",devoluciones[j].motivo);
		printf("Estado: %s\n",devoluciones[j].estado);
		printf("Fecha de aceptacion: %s\n",devoluciones[j].fecha_aceptacion);
		printf("Fecha de caducidad: %s\n",devoluciones[j].fecha_caducidad);

		j--;
		printf("\n");
	}
}
