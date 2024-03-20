#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"
#include "lectura.h"

void LeerClientes(Cliente *clientes){

    FILE *fichero;
	fichero=fopen("Clientes.txt","r");

    if (fichero == NULL) puts("\nError al abrir Clientes.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[8];//vector de cadenas ,contendra 8 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 8; i++)tokens[i] = strtok(NULL, delim);

			clientes[j].id_cliente=entero(tokens[0]) ;
			strcpy(clientes[j].nomb_cliente,tokens[1]) ;
			strcpy(clientes[j].dir_cliente,tokens[2]);
			strcpy(clientes[j].localidad,tokens[3]);
			strcpy(clientes[j].provincia,tokens[4]);
			strcpy(clientes[j].email,tokens[5]);
			strcpy(clientes[j].contrasena,tokens[6]);
			clientes[j].cartera=entero(tokens[7]);

			j++;
		}
	}
	fclose(fichero);
}

void MostrarClientes(Cliente *clientes,int n_clientes){

	int j=n_clientes - 1;

	while(j>=0){
        printf("\n");
		printf("Id de cliente: %d\n",clientes[j].id_cliente);
		printf("Nombre: %s\n",clientes[j].nomb_cliente);
		printf("Direccion: %s\n",clientes[j].dir_cliente);
		printf("Localidad: %s\n",clientes[j].localidad);
		printf("Provincia: %s\n",clientes[j].provincia);
		printf("Email: %s\n",clientes[j].email);
		printf("Contrasena: %s\n",clientes[j].contrasena);
		printf("Cartera: %d\n",clientes[j].cartera);

		j--;
		printf("\n");
	}
}

void Alta_Cliente(Cliente*clientes,int *n_clientes){

    int i=*n_clientes,id;

    printf("\n\t Introduzca los siguientes datos: \n");

    // Con la funcion Buscar_Cliente comprobamos que el id es válido
    //do{
        printf("\n\t\t Introduzca el id del cliente: ");
        fflush(stdin);
        scanf("%d",&id);
    //} while(Buscar_Cliente(clientes,*n_clientes,id) != 0);

    clientes[i].id_cliente = id;

    printf("\n\t\t Nombre: ");
    fflush(stdin);
    gets(clientes[i].nomb_cliente);

    printf("\n\t\t Direccion: ");
    fflush(stdin);
    gets(clientes[i].dir_cliente);

    printf("\n\t\t Localidad: ");
    fflush(stdin);
    gets(clientes[i].localidad);

    printf("\n\t\t Provincia: ");
    fflush(stdin);
    gets(clientes[i].provincia);

    printf("\n\t\t Email: ");
    fflush(stdin);
    gets(clientes[i].email);

    printf("\n\t\t Password: ");
    fflush(stdin);
    gets(clientes[i].contrasena);

    clientes[i].cartera=0;

    *n_clientes=i+1;

    system("cls");
}
