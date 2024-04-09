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

    printf("\n\t\t\tLista de clientes:\n");

	while(j>=0){
        printf("\n");
		printf("\n\t\t\tId de cliente: %d\n",clientes[j].id_cliente);
		printf("\n\t\t\tNombre: %s\n",clientes[j].nomb_cliente);
		printf("\n\t\t\tDireccion: %s\n",clientes[j].dir_cliente);
		printf("\n\t\t\tLocalidad: %s\n",clientes[j].localidad);
		printf("\n\t\t\tProvincia: %s\n",clientes[j].provincia);
		printf("\n\t\t\tEmail: %s\n",clientes[j].email);
		printf("\n\t\t\tContrasena: %s\n",clientes[j].contrasena);
		printf("\n\t\t\tCartera: %d\n",clientes[j].cartera);

		j--;
		printf("\n");
	}

	system("pause");
}

void Alta_Cliente(Cliente* clientes,int *n_clientes){

    int i = *n_clientes;
    int cartera;

    if (i == 0) clientes[i].id_cliente = 1;
    else clientes[i].id_cliente = clientes[i - 1].id_cliente + 1;

    printf("\n\t\tNombre: ");
    fflush(stdin);
    gets(clientes[i].nomb_cliente);

    printf("\n\t\tDireccion: ");
    fflush(stdin);
    gets(clientes[i].dir_cliente);

    printf("\n\t\tLocalidad: ");
    fflush(stdin);
    gets(clientes[i].localidad);

    printf("\n\t\tContrasena: ");
    fflush(stdin);
    gets(clientes[i].provincia);

    printf("\n\t\tEmail: ");
    fflush(stdin);
    gets(clientes[i].email);

    printf("\n\t\tPassword: ");
    fflush(stdin);
    gets(clientes[i].contrasena);

    printf("\n\t\tCartera: ");
    fflush(stdin);
    scanf("%d", &cartera);
    clientes[i].cartera=cartera;

    *n_clientes = i+1;

    system("cls");
}

int Buscar_Cliente(Cliente* clientes, int n_clientes,int id) {

    int i,cont=0;

    for (i=0;i<n_clientes;i++)
        if(clientes[i].id_cliente==id)cont++;

    return cont;
}

void Listar_Cliente(Cliente* clientes, int n_clientes,int id) {

    int i;

    for (i=0;i<n_clientes;i++)
        if(clientes[i].id_cliente==id){
            printf("\n");
            printf("\n\t\t\tId de cliente: %d\n",clientes[i].id_cliente);
            printf("\n\t\t\tNombre: %s\n",clientes[i].nomb_cliente);
            printf("\n\t\t\tDireccion: %s\n",clientes[i].dir_cliente);
            printf("\n\t\t\tLocalidad: %s\n",clientes[i].localidad);
            printf("\n\t\t\tProvincia: %s\n",clientes[i].provincia);
            printf("\n\t\t\tEmail: %s\n",clientes[i].email);
            printf("\n\t\t\tContrasena: %s\n",clientes[i].contrasena);
            printf("\n\t\t\tCartera: %d\n\n",clientes[i].cartera);
        }

    system("pause");
}

void Baja_Cliente(Cliente* clientes,int *n_clientes, int pos) {

    int i = *n_clientes, j;

    for(j=pos;j<i;j++) {
        clientes[j].id_cliente=clientes[j+1].id_cliente;
        strcpy(clientes[j].nomb_cliente,clientes[j+1].nomb_cliente);
        strcpy(clientes[j].dir_cliente,clientes[j+1].dir_cliente);
        strcpy(clientes[j].localidad,clientes[j+1].localidad);
        strcpy(clientes[j].provincia,clientes[j+1].provincia);
        strcpy(clientes[j].email,clientes[j+1].email);
        strcpy(clientes[j].contrasena,clientes[j+1].contrasena);
        clientes[j].cartera=clientes[j+1].cartera;
    }

    *n_clientes=i-1;
}

void Modificar_Cliente(Cliente* clientes, int pos){

    char aux[50];
    int cartera;

    system("cls");

    printf("\n\t\t\tIntroduce los nuevos datos del cliente:\n");

    printf("\n\t\t\t1. Nombre:");
    fflush(stdin);
    gets(aux);
    strcpy(clientes[pos].nomb_cliente,aux);

    printf("\n\t\t\t2. Direccion: ");
    fflush(stdin);
    gets(aux);
    strcpy(clientes[pos].dir_cliente,aux);

    printf("\n\t\t\t3. Localidad: ");
    fflush(stdin);
    gets(aux);
    strcpy(clientes[pos].localidad,aux);

    printf("\n\t\t\t4. Provincia: ");
    fflush(stdin);
    gets(aux);
    strcpy(clientes[pos].provincia,aux);

    printf("\n\t\t\t5. Email: ");
    fflush(stdin);
    gets(aux);
    strcpy(clientes[pos].email,aux);

    printf("\n\t\t\t6. Contrasena: ");
    fflush(stdin);
    gets(aux);
    strcpy(clientes[pos].contrasena,aux);

    printf("\n\t\t\t7. Cartera: ");
    fflush(stdin);
    scanf("%d", &cartera);
    clientes[pos].cartera=cartera;
}
