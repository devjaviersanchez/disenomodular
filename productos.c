#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "productos.h"
#include "lectura.h"

void LeerProductos(Productos* productos){

    FILE *fichero;
	fichero=fopen("Productos.txt","r");

    if (fichero == NULL)puts("\nError al abrir Productos.txt");
	else
	{
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[7];//vector de cadenas ,contendra 7 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 7; i++) tokens[i] = strtok(NULL, delim);

			productos[j].id_prod=entero(tokens[0]) ;
			strcpy(productos[j].descripcion,tokens[1]);
			productos[j].id_categoria=entero(tokens[2]) ;
			productos[j].id_gestor=entero(tokens[3]) ;
			productos[j].stock=entero(tokens[4]) ;
			productos[j].entrega=entero(tokens[5]) ;
            productos[j].importe=entero(tokens[6]) ;
			j++;
		}
	}
    fclose(fichero);
}

void MostrarProductos(Productos *productos,int n_productos,AdminProv*adminprov,int posicion_vector){

    int j=n_productos-1;
    int cont=0;

    printf("\n\t\t\tLista de productos: \n");

	while(j>=0){
        if(adminprov[posicion_vector].id_empresa == productos[j].id_gestor || strcmp(adminprov[posicion_vector].perfil,"administrador") == 0){
            printf("\n");
            printf("\n\t\t\tId del producto: %d\n",productos[j].id_prod);
            printf("\n\t\t\tDescripcion: %s\n",productos[j].descripcion);
            printf("\n\t\t\tCategoria: %d\n",productos[j].id_categoria);
            printf("\n\t\t\tGestor: %d\n",productos[j].id_gestor);
            printf("\n\t\t\tStock: %d\n",productos[j].stock);
            printf("\n\t\t\tEntrega: %d\n",productos[j].entrega);
            printf("\n\t\t\tImporte: %d\n",productos[j].importe);
            printf("\n");cont++;
        }
        j--;
    }

	if (cont < 1) printf("\n\n\t\t\tUsted no tiene ningun producto dado de alta\n");

	system("pause");
}

void Alta_Producto(Productos* productos,AdminProv* adminprov,Categorias*categorias,int posicion_vector,int n_categorias,int n_adminprov,int* n_productos){

    char s[100];
    int i=*n_productos;
    int id,cat;

    productos[i].id_prod=productos[i-1].id_prod + 1;

    printf("\n\t\t\tIntroduce la descripcion del nuevo producto: ");
    fflush(stdin);
    gets(s);
    strcpy(productos[i].descripcion,s);

    do{
        printf("\n\t\t\tIntroduce un id de categoria valido: ");
        fflush(stdin);
        scanf("%i",&cat);
    }while(Busqueda_Categoria(categorias,n_categorias,cat)==0);

    productos[i].id_categoria=cat;

    productos[i].id_gestor=adminprov[posicion_vector].id_empresa;

    printf("\n\t\t\tIntroduce el stock :");
    fflush(stdin);
    gets(s);
    productos[i].stock=entero(s);

    printf("\n\t\t\tIntroduce el compromiso de entrega: ");
    fflush(stdin);
    gets(s);
    productos[i].entrega=entero(s);

    printf("\n\t\t\tIntroduce el importe: ");
    fflush(stdin);
    gets(s);
    productos[i].importe=entero(s);

    *n_productos=i+1;
}

void Baja_Producto(Productos*productos,int*n_productos,AdminProv*adminprov,int posicion_vector){

    int j;

    for(j=posicion_vector;j<*n_productos;j++) {
        productos[j].id_prod=productos[j+1].id_prod;
        strcpy(productos[j].descripcion,productos[j+1].descripcion);
        productos[j].id_categoria=productos[j+1].id_categoria;
        productos[j].id_gestor=productos[j+1].id_gestor;
        productos[j].stock=productos[j+1].stock;
        productos[j].entrega=productos[j+1].entrega;
        productos[j].importe=productos[j+1].importe;
    }

    *n_productos=*n_productos-1;
}


int Buscar_Producto(Productos* productos,int n_productos,int id){

    int i,cont=0;

    for (i=0;i<n_productos;i++){
        if(productos[i].id_prod==id) cont++;
    }

    return cont;
}

void Modificacion_Producto(Productos* productos,AdminProv* adminprov,int n_categorias,int n_productos,int posicion_vector){

    char aux[50];
    int auxEntero;

    printf("\n\t\t\tIntroduce los nuevos datos del producto:\n");

    printf("\n\t\t\tDescripcion del producto: ");
    fflush(stdin);
    gets(aux);
    strcpy(productos[posicion_vector].descripcion,aux);

    printf("\n\t\t\tId de la categoria: ");
    scanf("%d", &auxEntero);
    productos[posicion_vector].id_categoria = auxEntero;

    printf("\n\t\t\tId del gestor:");
    scanf("%d", &auxEntero);
    productos[posicion_vector].id_gestor = auxEntero;

    printf("\n\t\t\tStock: ");
    scanf("%d", &auxEntero);
    productos[posicion_vector].stock = auxEntero;

    printf("\n\t\t\tCompromiso de entrega (numero de dias):");
    scanf("%d", &auxEntero);
    productos[posicion_vector].entrega = auxEntero;

    printf("\n\t\t\tImporte:");
    scanf("%d", &auxEntero);
    productos[posicion_vector].importe = auxEntero;
}

void Consultar_Producto(Productos*productos,int x){

        printf("\n");
		printf("\n\t\t\tProducto: %d\n",productos[x].id_prod);
		printf("\n\t\t\tDescripcion: %s\n",productos[x].descripcion);
		printf("\n\t\t\tCategoria: %d\n",productos[x].id_categoria);
		printf("\n\t\t\tGestor: %d\n",productos[x].id_gestor);
		printf("\n\t\t\tStock: %d\n",productos[x].stock);
		printf("\n\t\t\tCompromiso: %d\n",productos[x].entrega);
		printf("\n\t\t\tImporte: %d\n",productos[x].importe);
		printf("\n");

		system("pause");
}

