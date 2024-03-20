#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "adminprov.h"
#include "lectura.h"

void MostrarAdminProv(AdminProv *adminprov,int n_adminprov){

	int j=n_adminprov - 1;

	while(j>=0){
        printf("\n");
        printf("Id: %d\n",adminprov[j].id_empresa);
		printf("Nombre: %s\n",adminprov[j].nombre);
		printf("Email: %s\n",adminprov[j].email);
		printf("Contrasena: %s\n",adminprov[j].contrasena);
		printf("Perfil: %s\n",adminprov[j].perfil);

		j--;
		printf("\n");
	}
}

void LeerAdminProv(AdminProv * adminprov){

    FILE *fichero;
	fichero=fopen("AdminProv.txt","r");

    if (fichero == NULL) puts("\nError al abrir AdminProv.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[5];//vector de cadenas ,contendra 5 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 5; i++) tokens[i] = strtok(NULL, delim);

			adminprov[j].id_empresa=entero(tokens[0]);
			strcpy(adminprov[j].nombre,tokens[1]);
			strcpy(adminprov[j].email,tokens[2]);
			strcpy(adminprov[j].contrasena,tokens[3]);
			strcpy(adminprov[j].perfil,tokens[4]);

			j++;
		}
	}
	fclose(fichero);
}

