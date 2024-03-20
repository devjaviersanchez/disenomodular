#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "transportistas.h"
#include "lectura.h"

void LeerTransportistas(Transportista* transportista){

    FILE *fichero;
	fichero=fopen("Transportistas.txt","r");

    if (fichero == NULL) puts("\nError al abrir Transportistas.txt");
	else
	{
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[6];//vector de cadenas ,contendra 6 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for (i = 1; i < 6; i++) tokens[i] = strtok(NULL, delim);

			transportista[j].id_transp=entero(tokens[0]) ;
			strcpy(transportista[j].nombre,tokens[1]);
			strcpy(transportista[j].email,tokens[2]);
			strcpy(transportista[j].contrasena,tokens[3]);
			strcpy(transportista[j].nombre_empresa,tokens[4]);
			strcpy(transportista[j].nombre_ciudad,tokens[5]);

			j++;
		}
	}
	fclose(fichero);
}

void MostrarTransportistas(Transportista *transportista,int n_transportista){

	int j=n_transportista - 1;

	while(j>=0){
        printf("\n");
        printf("Id: %d\n",transportista[j].id_transp);
        printf("Nombre: %s\n",transportista[j].nombre);
		printf("Email: %s\n",transportista[j].email);
		printf("Contrasena: %s\n",transportista[j].contrasena);
		printf("Empresa: %s\n",transportista[j].nombre_empresa);
		printf("Ciudad: %s\n",transportista[j].nombre_ciudad);

		j--;
		printf("\n");
	}
}
