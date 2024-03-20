#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "descuentos.h"
#include "lectura.h"

void LeerDescuentos(Descuentos* descuentos){

    FILE *fichero;
	fichero=fopen("Descuentos.txt","r");

    if (fichero == NULL) puts("\nError al abrir Descuentos.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[6];//vector de cadenas ,contendra 6 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 6; i++) tokens[i] = strtok(NULL, delim);

            strcpy(descuentos[j].id_cod,tokens[0]);
            strcpy(descuentos[j].descripcion,tokens[1]);
            strcpy(descuentos[j].tipo,tokens[2]);
			strcpy(descuentos[j].estado,tokens[3]);
			descuentos[j].importe=entero(tokens[4]) ;
			strcpy(descuentos[j].aplicabilidad,tokens[5]);

			j++;
		}
	}
    fclose(fichero);
}

void LeerDescuentosClientes(DescuentosClientes* descuentosclientes){

    FILE *fichero;
	fichero=fopen("DescuentosClientes.txt","r");

    if (fichero == NULL) puts("\nError al abrir DescuentosClientes.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[5];//vector de cadenas ,contendra 5 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 5; i++)tokens[i] = strtok(NULL, delim);

            descuentosclientes[j].id_cliente=entero(tokens[0]);
            strcpy(descuentosclientes[j].id_cod,tokens[1]);
			strcpy(descuentosclientes[j].fecha_asignacion,tokens[2]) ;
			strcpy(descuentosclientes[j].fecha_caducidad,tokens[3]) ;
			descuentosclientes[j].estado=entero(tokens[4]) ;

			j++;
		}
	}
}

void MostrarDescuentos(Descuentos* descuentos,int n_descuentos){

    int j=n_descuentos - 1;

	while(j>=0){
        printf("\n");
		printf("Id: %s\n",descuentos[j].id_cod);
		printf("Descripcion: %s\n",descuentos[j].descripcion);
		printf("Tipo: %s\n",descuentos[j].tipo);
		printf("Estado: %s\n",descuentos[j].estado);
		printf("Importe: %d\n",descuentos[j].importe);
		printf("Aplicabilidad: %s\n",descuentos[j].aplicabilidad);

		j--;
		printf("\n");
	}
}

void MostrarDescuentosClientes(DescuentosClientes* descuentosclientes,int n_descuentosclientes){

    int j=n_descuentosclientes - 1;

	while(j>=0){
        printf("\n");
		printf("Id del cliente%d\n",descuentosclientes[j].id_cliente);
		printf("Id del codigo promocional: %s\n",descuentosclientes[j].id_cod);
		printf("Fecha de asignacion: %s\n",descuentosclientes[j].fecha_asignacion);
		printf("Fecha de caducidad: %s\n",descuentosclientes[j].fecha_caducidad);
		printf("Estado: %d\n",descuentosclientes[j].estado);

        j--;
		printf("\n");
	}
}
