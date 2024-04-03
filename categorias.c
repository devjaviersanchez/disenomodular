#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "categorias.h"
#include "lectura.h"

void MostrarCategorias(Categorias *categorias,int n_categorias){

    int j=n_categorias - 1;

	while(j>=0){
        printf("\n");
		printf("Id de categoria: %d\n",categorias[j].id_categoria);
		printf("Descripcion: %s\n",categorias[j].descripcion);

		j--;
		printf("\n");
	}
}


void LeerCategorias(Categorias* categorias){

    FILE *fichero;
	fichero=fopen("Categorias.txt","r");

    if (fichero == NULL) puts("\nError al abrir Categorias.txt");
	else {
		int j=0;
		const char delim[2]="-";
		char* tokens[2];//vector de cadenas ,contendra 2 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);
			tokens[1] = strtok(NULL, delim);

			categorias[j].id_categoria=entero(tokens[0]) ;
			strcpy(categorias[j].descripcion,tokens[1]);
			j++;
		}
	}
    fclose(fichero);
}

void Alta_Categoria(Categorias* categorias,int* n_categorias){

    char s[100];
    int i=*n_categorias;

    categorias[i].id_categoria=*n_categorias+1;

    printf("Introduce la descripcion de la categoria :");
    fflush(stdin);
    gets(s);
    strcpy(categorias[i].descripcion,s);

    *n_categorias=i+1;

    return categorias;
}

void Baja_Categoria(Categorias*categorias,int*n_categorias){

    int i=*n_categorias,j,cont=1,x;

    MostrarCategorias(categorias,*n_categorias);

    fflush(stdin);
    printf("Categoria: ");
    scanf("%i",&x);

    for(j=x-1;j<i;j++) {
        categorias[j].id_categoria=categorias[j+cont].id_categoria;
        strcpy(categorias[j].descripcion,categorias[j+cont].descripcion);
    }

    *n_categorias=i-1;
}


void Modificacion_Categoria(Categorias* categorias,int n_categorias){
    int x;
    system("cls");
    MostrarCategorias(categorias,n_categorias);
        fflush(stdin);
        printf("categoria: ");
        scanf("%i",&x);

    int opcion;
        do{


    printf("Elija la opcion que desea hacer en el menu de descuentos: \n\n");
        printf("-> 1. modificar descripcion de la categoria\n\n");
        printf("-> 2. Atras\n\n");

    fflush(stdin);
    scanf("%d", &opcion);
    if(opcion==1){
                    printf("\n\t\tIntroduce la descripcion: ");
                    fflush(stdin);
                    gets(categorias[x-1].descripcion);break;

    }

}while(opcion!=2);
return categorias;
}

int Busqueda_Categoria(Categorias*categorias,int n_categorias,int id){

    int cont=0,i;
    system("cls");

    for (i=0;i<n_categorias;i++)
        if(categorias[i].id_categoria==id)cont++;

    return cont;
}

int Busqueda_Categoria_nombre(Categorias*categorias,int n_categorias,char*nombre){

    int cont=0,i;
    system("cls");

    for (i=0;i<n_categorias;i++)
        if(strcmp(categorias[i].descripcion,nombre)==0)cont=i;

    return cont;
}


