#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "categorias.h"
#include "lectura.h"

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

void EscribirCategorias(Categorias *categorias,int n_categorias){
    FILE *fichero;
	fichero=fopen("Categorias.txt","w");

    if (fichero == NULL)
		puts("\nError al abrir Categorias.txt");
	else
	{
        rewind(fichero);
		int j=0;
		while (j<n_categorias){
			fprintf(fichero, "%d-%s",categorias[j].id_categoria,categorias[j].descripcion);
            if(j!=n_categorias-1){
                fputc('\n',fichero);
            }
			j++;
        }
        fclose(fichero);
    }
}

void MostrarCategorias(Categorias *categorias,int n_categorias){

    int j=n_categorias - 1;

	while(j>=0){
        printf("\n");
		printf("\n\t\t\tId de la categoria: %d\n",categorias[j].id_categoria);
		printf("\n\t\t\tDescripcion: %s\n",categorias[j].descripcion);
		j--;
		printf("\n");
	}

	system("pause");
}

void Alta_Categoria(Categorias* categorias,int* n_categorias){

    char s[100];
    int i=*n_categorias;

    categorias[i].id_categoria=categorias[i - 1].id_categoria + 1;

    printf("\n\t\t\tIntroduce la descripcion de la categoria :");
    fflush(stdin);
    gets(s);
    strcpy(categorias[i].descripcion,s);

    *n_categorias=i+1;
}

void Baja_Categoria(Categorias*categorias,int*n_categorias,int posicion){

    int i=*n_categorias,j;

    for(j=posicion;j<i;j++) {
        categorias[j].id_categoria=categorias[j+1].id_categoria;
        strcpy(categorias[j].descripcion,categorias[j+1].descripcion);
    }

    *n_categorias=i-1;
}


void Modificacion_Categoria(Categorias* categorias,int pos){

    char aux[50];

    printf("\n\t\t\tIntroduce la nueva descripcion de la categoria: ");
    fflush(stdin);
    gets(aux);

    strcpy(categorias[pos].descripcion,aux);
}

int Busqueda_Categoria(Categorias*categorias,int n_categorias,int id){

    int cont=0,i;
    system("cls");

    for (i=0;i<n_categorias;i++)
        if(categorias[i].id_categoria==id)cont++;

    return cont;
}

void Consultar_Categoria(Categorias*categorias,int posicion){

    printf("\n\t\t\tId de la categoria: %d", categorias[posicion].id_categoria);
    printf("\n\t\t\tDescripcion: %s\n\n", categorias[posicion].descripcion);

    system("pause");
}


