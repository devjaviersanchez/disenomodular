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

void Listar_Transportitsta (Transportista* transportista, int posicion) {

    system("cls");

    printf("\n\t\t\tId del transportista: %d\n",transportista[posicion].id_transp);
    printf("\n\t\t\tNombre: %s\n",transportista[posicion].nombre);
    printf("\n\t\t\tEmail: %s\n",transportista[posicion].email);
    printf("\n\t\t\tContrasena: %s\n",transportista[posicion].contrasena);
    printf("\n\t\t\tEmpresa: %s\n",transportista[posicion].nombre_empresa);
    printf("\n\t\t\tCiudad: %s\n\n",transportista[posicion].nombre_ciudad);

    system("pause");
}

void MostrarTransportistas(Transportista *transportista,int n_transportista){

	int j=n_transportista - 1;

	system("cls");
	printf("\n\t\t\tLista de transportistas:\n");

	while(j>=0){
        printf("\n");
        printf("\n\t\t\tId del transportista: %d\n",transportista[j].id_transp);
        printf("\n\t\t\tNombre: %s\n",transportista[j].nombre);
		printf("\n\t\t\tEmail: %s\n",transportista[j].email);
		printf("\n\t\t\tContrasena: %s\n",transportista[j].contrasena);
		printf("\n\t\t\tEmpresa: %s\n",transportista[j].nombre_empresa);
		printf("\n\t\t\tCiudad: %s\n",transportista[j].nombre_ciudad);

		j--;
		printf("\n");
	}

	system("pause");
}

void Alta_Transportista(Transportista* transportistas,int *n_transportistas){

    int i=*n_transportistas;
    char aux[50];

    system("cls");

    transportistas[i].id_transp= transportistas[i - 1].id_transp + 1;

    printf("\n\t\t\tNombre del transportista:");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[i].nombre , aux);

    printf("\n\t\t\tEmail:");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[i].email, aux);

    printf("\n\t\t\tContrasena:");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[i].contrasena, aux);

    printf("\n\t\t\tNombre de la empresa:");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[i].nombre_empresa, aux);

    printf("\n\t\t\tCiudad:");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[i].nombre_ciudad, aux);

    *n_transportistas=i+1;
}

int Buscar_Transportista(Transportista* transportistas, int n_transportistas,int id) {

    int i,cont=0;

    for (i=0;i<n_transportistas;i++)
        if(transportistas[i].id_transp==id) cont++;

    return cont;
}

void Baja_Transportista(Transportista* transportistas,int *n_transportistas, int pos){

    int i=*n_transportistas,j;

    for(j=pos;j<i;j++) {
        transportistas[j].id_transp=transportistas[j+1].id_transp;
        strcpy(transportistas[j].email,transportistas[j+1].email);
        strcpy(transportistas[j].contrasena,transportistas[j+1].contrasena);
        strcpy(transportistas[j].nombre_empresa,transportistas[j+1].nombre_empresa);
        strcpy(transportistas[j].nombre_ciudad,transportistas[j+1].nombre_ciudad);
    }

    *n_transportistas=i-1;
}

void Modificar_Transportista(Transportista* transportistas, int pos){

    char aux[50];

    system("cls");

    printf("\n\t\t\tIntroduce los nuevos datos del transportista:\n");

    printf("\n\t\t\tNombre del transportista: ");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[pos].nombre , aux);

    printf("\n\t\t\tEmail: ");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[pos].email, aux);

    printf("\n\t\t\tContrasena: ");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[pos].contrasena, aux);

    printf("\n\t\t\tNombre de la empresa: ");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[pos].nombre_empresa, aux);

    printf("\n\t\t\tCiudad: ");
    fflush(stdin);
    gets(aux);
    strcpy(transportistas[pos].nombre_ciudad, aux);
}
