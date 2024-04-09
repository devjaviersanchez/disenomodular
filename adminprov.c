#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "adminprov.h"
#include "lectura.h"

void MostrarAdminProv(AdminProv *adminprov,int n_adminprov){

	int j=n_adminprov - 1;

	printf("\n\t\t\tListado de proveedores:\n");

	while(j>=0){
        if (strcmp(adminprov[j].perfil, "proveedor") == 0) {
            printf("\n");
            printf("\n\t\t\tId: %d\n",adminprov[j].id_empresa);
            printf("\n\t\t\tNombre: %s\n",adminprov[j].nombre);
            printf("\n\t\t\tEmail: %s\n",adminprov[j].email);
            printf("\n\t\t\tContrasena: %s\n",adminprov[j].contrasena);
            printf("\n\t\t\tPerfil: %s\n",adminprov[j].perfil);

        }
        j--;
	}
	printf("\n");

	system("pause");
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

int Buscar_AdminProv(AdminProv* adminyprov, int n_adminprov,int id, char* perfil) {

    int i,cont=0;

    for (i=0;i<n_adminprov;i++)
        if(adminyprov[i].id_empresa==id && strcmp(adminyprov[i].perfil, perfil) == 0) cont++;

    return cont;
}

//Alta administradores y proveedores
void Alta_AdminProv(AdminProv* adminyprov,int *n_adminprov,char* tipo){

    char aux[6];
    int i=*n_adminprov,id;
    strcpy(adminyprov[i].perfil,tipo);

    adminyprov[i].id_empresa=adminyprov[i - 1].id_empresa + 1;

    if(strcmp(tipo, "administrador")==0){
        strcpy(adminyprov[i].nombre,"ESIZON");
        strcpy(adminyprov[i].perfil,"administrador");
    }else{
        printf("\n\t\t\Nombre de la empresa :");
        fflush(stdin);
        gets(adminyprov[i].nombre);
    }

    printf("\n\t\tEmail:");
    fflush(stdin);
    gets(adminyprov[i].email);
    printf("\n\t\tContrasena:");
    fflush(stdin);
    gets(adminyprov[i].contrasena);

    *n_adminprov=i+1;
}

//Baja Administrador o Proveedor
void Baja_AdminProv(AdminProv* adminyprov,int *n_adminprov, int pos,char* tipo){

    // Comprobamos que se esta eliminando un administrador, y no un proveedor
    if (strcmp(adminyprov[pos].perfil,tipo)==0){

        int i = *n_adminprov, j;

        for(j=pos;j<i;j++){
            adminyprov[j].id_empresa=adminyprov[j+1].id_empresa;
            strcpy(adminyprov[j].nombre,adminyprov[j+1].nombre);
            strcpy(adminyprov[j].email,adminyprov[j+1].email);
            strcpy(adminyprov[j].contrasena,adminyprov[j+1].contrasena);
            strcpy(adminyprov[j].perfil,adminyprov[j+1].perfil);
        }

        *n_adminprov=i-1;
    }
}

void Consulta_AdminProv(AdminProv* adminyprov, int pos){

        system("cls");

        printf("\n\t\t\tDatos del perfil:\n");
        printf("\n\t\t\t1. Empresa: %s\n",adminyprov[pos].nombre);
        printf("\n\t\t\t2. Email: %s\n",adminyprov[pos].email);
        printf("\n\t\t\t3. Contrasena: %s\n",adminyprov[pos].contrasena);
        printf("\n\t\t\t3. Perfil: %s\n\n",adminyprov[pos].perfil);

        system("pause");
}

void Modificar_AdminProv(AdminProv* adminyprov, int pos){

    int aux2;
    char opcion, aux[50];

    system("cls");
    printf("\n\t\t\tModificacion de los datos del perfil:\n");

    printf("\n\t\t\tNuevo nombre de la empresa: ");
    fflush(stdin);
    gets(aux);
    strcpy(adminyprov[pos].nombre,aux);

    printf("\n\t\t\tNuevo email: ");
    fflush(stdin);
    gets(aux);
    strcpy(adminyprov[pos].email,aux);


    printf("\n\t\t\tNueva contrasena: ");
    gets(aux);
    fflush(stdin);
    strcpy(adminyprov[pos].contrasena,aux);
}

