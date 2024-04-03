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

void Alta_Transportista(Transportista* transportistas,int *n_transportistas){

    int i=*n_transportistas,id;
    do{
        printf("\n\t Introduzca el id del adminprov: \n");
        printf("\n\t\t Adminprov :\n");
        fflush(stdin);
        scanf("%d",&id);
    }while(Buscar_Transportista(transportistas,*n_transportistas,id)!=0);

    transportistas[i].id_transp=id;
    printf("\n\t Introduzca los siguientes datos: \n");
    printf("\n\t\t Email :\n");
    fflush(stdin);
    gets(transportistas[i].email);
    printf("\n\t\t Password :\n");
    fflush(stdin);
    gets(transportistas[i].contrasena);
    printf("\n\t\t Nombre de la empresa :\n");
    fflush(stdin);
    gets(transportistas[i].nombre_empresa);
    printf("\n\t\t Ciudad :\n");
    fflush(stdin);
    gets(transportistas[i].nombre_ciudad);

    *n_transportistas=i+1;
}

int Buscar_Transportista(Transportista* transportistas, int n_transportistas,int id) {
    int i,cont=0;
    char email[30];

    for (i=0;i<n_transportistas;i++)
        if(transportistas[i].id_transp==id) cont++;

    return cont;
}

void Baja_Transportista(Transportista* transportistas,int *n_transportistas, int pos){

    int i=*n_transportistas,j,cont=1;

    for(j=pos;j<i;j++) {
        transportistas[j].id_transp=transportistas[j+cont].id_transp;
        strcpy(transportistas[j].email,transportistas[j+cont].email);
        strcpy(transportistas[j].contrasena,transportistas[j+cont].contrasena);
        strcpy(transportistas[j].nombre_empresa,transportistas[j+cont].nombre_empresa);
        strcpy(transportistas[j].nombre_ciudad,transportistas[j+cont].nombre_ciudad);
    }

    *n_transportistas=i-1;
}

void Modificar_Transportista(Transportista* transportistas, int pos){

    system("cls");
    int opcion;
    char  aux[50];


    do{
        printf("\n\t\t Que campo desea modificar?. \n");
        printf("\n\t\t 1. Email.\n");
        printf("\n\t\t 2. Password.\n");
        printf("\n\t\t 3. Empresa.\n");
        printf("\n\t\t 4. Ciudad.\n");
        printf("\n\n\n\t\t 5. Salir.\n");

        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo Email:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(transportistas[pos].email,aux);};break;

            case 2: { system("pause");
                      system("cls");
                      printf("\n\t Escriba la nueva Password:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(transportistas[pos].contrasena,aux);};break;

            case 3: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo nombre de la empresa:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(transportistas[pos].nombre_empresa,aux);};break;

            case 4: { system("pause");
                      system("cls");
                      printf("\n\t Escriba la nueva Ciudad:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(transportistas[pos].nombre_ciudad,aux);};break;


        }

    } while(opcion!=5);
}
