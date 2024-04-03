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

int Buscar_AdminProv(AdminProv* adminyprov, int n_adminprov,int id) {

    int i,cont=0;

    for (i=0;i<n_adminprov;i++)
        if(adminyprov[i].id_empresa==id) cont++;

    return cont;
}

//Alta administradores y proveedores
void Alta_AdminProv(AdminProv* adminyprov,int *n_adminprov,char* tipo){

    char aux[6];
    int i=*n_adminprov,id;
    strcpy(adminyprov[i].perfil,tipo);

    do{
        printf("\n\t\t\Introduzca un id valido para el nuevo usuario:");
        fflush(stdin);
        scanf("%d",&id);
    }while(Buscar_AdminProv(adminyprov,*n_adminprov,id)!=0); // Si el id esta en uso se repite el buclue

    adminyprov[i].id_empresa=id;

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

        int i = *n_adminprov, j, cont=1;

        for(j=pos;j<i;j++){
            adminyprov[j].id_empresa=adminyprov[j+cont].id_empresa;
            strcpy(adminyprov[j].nombre,adminyprov[j+cont].nombre);
            strcpy(adminyprov[j].email,adminyprov[j+cont].email);
            strcpy(adminyprov[j].contrasena,adminyprov[j+cont].contrasena);
            strcpy(adminyprov[j].perfil,adminyprov[j+cont].perfil);

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

