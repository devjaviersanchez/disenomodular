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

	while(j>=0){
        if(adminprov[posicion_vector].id_empresa == productos[j].id_gestor || strcmp(adminprov[posicion_vector].perfil,"admin") == 0){
            printf("\n");
            printf("Producto: %d\n",productos[j].id_prod);
            printf("Descripcion: %s\n",productos[j].descripcion);
            printf("Categoria: %d\n",productos[j].id_categoria);
            printf("Gestor: %d\n",productos[j].id_gestor);
            printf("Stock: %d\n",productos[j].stock);
            printf("Entrega: %d\n",productos[j].entrega);
            printf("Importe: %d\n",productos[j].importe);
            printf("\n");cont++;
        }

        j--;
    }

	if (cont < 1) printf("Usted no tiene ningun producto dado de alta\n");
}

void Alta_Producto(Productos* productos,AdminProv* adminprov,Categorias*categorias,int posicion_vector,int n_categorias,int n_adminprov,int* n_productos){

    char s[100];
    int i=*n_productos;
    int id,cat;

    do{
        printf("\n\t Introduzca el id del Producto: \n");
        fflush(stdin);
        scanf("%i",&id);
    }while(Buscar_Producto(productos,i,id)!=0);

    productos[i].id_prod=id;

    printf("introduce la descripcion :");
    fflush(stdin);
    gets(s);
    strcpy(productos[i].descripcion,s);

    do{
        printf("introduce el numero de categoria :");
        fflush(stdin);
        scanf("%i",&cat);
    }while(Busqueda_Categoria(categorias,n_categorias,cat)==0);

    productos[i].id_categoria=cat;

    productos[i].id_gestor=adminprov[posicion_vector].id_empresa;

    printf("introduce el stock :");
    fflush(stdin);
    gets(s);
    productos[i].stock=entero(s);
    printf("introduce el compromiso de entrega:");
    fflush(stdin);
    gets(s);
    productos[i].entrega=entero(s);
    printf("introduce el importe:");
    fflush(stdin);
    gets(s);
    productos[i].importe=entero(s);
    *n_productos=i+1;
    // Consultar_Producto(productos,i);

}

void Baja_Producto(Productos*productos,int*n_productos,AdminProv*adminprov,int posicion_vector){

    int j,cont=1,x,i;

    MostrarProductos(productos,*n_productos,adminprov,posicion_vector);
    fflush(stdin);
    printf("Id del producto: ");
    scanf("%i",&x);

    for(i=0;i<*n_productos;i++){
        if(productos[i].id_prod==x){
            if(productos[i].id_gestor!=adminprov[posicion_vector].id_empresa && strcmp(adminprov[posicion_vector].perfil,"admin")!=0)printf("ESTE PRODUCTO NO LE PERTENECE");
            else{
                for(j=i;j<*n_productos;j++) {
                    productos[j].id_prod=productos[j+cont].id_prod;
                    strcpy(productos[j].descripcion,productos[j+cont].descripcion);
                    productos[j].id_categoria=productos[j+cont].id_categoria;
                    productos[j].id_gestor=productos[j+cont].id_gestor;
                    productos[j].stock=productos[j+cont].stock;
                    productos[j].entrega=productos[j+cont].entrega;
                    productos[j].importe=productos[j+cont].importe;

                }
                *n_productos=i-1;
            }

        }
    }
}

int Buscar_Producto(Productos* productos,int n_productos,int id){

    int i,cont=0;

    for (i=0;i<n_productos;i++){
        if(productos[i].id_prod==id) cont++;
    }

    return cont;
}

void Modificacion_Producto(Productos* productos,AdminProv* adminprov,int n_categorias,int n_productos,int posicion_vector){

    int x,i;
    system("cls");

    MostrarProductos(productos,n_productos,adminprov,posicion_vector);
    fflush(stdin);
    printf("producto: ");
    scanf("%i",&x);

        for(i=0;i<n_productos;i++){
            if(productos[i].id_prod==x){
                if(productos[i].id_gestor!=adminprov[posicion_vector].id_empresa && strcmp(adminprov[posicion_vector].perfil,"admin")!=0)printf("ESTE PRODUCTO NO LE PERTENECE");
                else{
                    int opcion;
                    char aux[50];

                    do {

                        Consultar_Producto(productos,i);

                        printf("Elija la opcion que desea hacer en el menu de pedidos: \n\n");
                        printf("-> 1. modificar descripcion del producto\n\n");
                        printf("-> 2. modificar categoria del producto\n\n");
                        printf("-> 3. modificar stock del producto\n\n");
                        printf("-> 4. modificar compromiso del producto\n\n");
                        printf("-> 5. modificar importe del producto\n\n");
                        printf("-> 6. Atras\n\n");

                        fflush(stdin);
                        scanf("%d", &opcion);
                        switch(opcion){
                            case 1:         printf("\n\t\tIntroduce la descripcion: ");
                                            fflush(stdin);
                                            gets(productos[i].descripcion);break;

                            case 2:         do{
                                                printf("\n\t\tIntroduce la categoria: ");
                                                fflush(stdin);
                                                gets(aux);
                                            }while(entero(aux)>=n_categorias);
                                            productos[i].id_categoria=entero(aux);break;

                            case 3:         printf("\n\t\tIntroduce el stock: ");
                                            fflush(stdin);
                                            gets(aux);
                                            productos[i].stock=entero(aux);break;

                            case 4:         printf("\n\t\tIntroduce el compromiso: ");
                                            fflush(stdin);
                                            gets(aux);
                                            productos[i].entrega=entero(aux);break;

                            case 5:         printf("\n\t\tIntroduce el importe: ");
                                            fflush(stdin);
                                            gets(aux);
                                            productos[i].importe=entero(aux);break;
                        }

                    }while(opcion!=6);

                }
            }
        }
}

void Busqueda_Producto_Categorias(Productos*productos,Categorias*categorias,int n_categorias,int n_productos){

    int i=0,j,aux=0;
    char  x[100];

    printf("introduce la categoria: \n\n");
    fflush(stdin);
    gets(x);
    fflush(stdin);

    while(i<n_categorias){
        if(strstr(categorias[i].descripcion,x)!=NULL){
            j=0;
            while(j<n_productos){
                if(productos[j].id_categoria==categorias[i].id_categoria){
                    Consultar_Producto(productos,j);
                    aux=1;
                }
                j++;
            }
        }
        i++;
    }
    if(aux==0)printf("Ese nombre de Categoria no corresponde con ningun Producto");
}

void Consultar_Producto(Productos*productos,int x){

        printf("\n");
		printf("Producto: %d\n",productos[x].id_prod);
		printf("Descripcion: %s\n",productos[x].descripcion);
		printf("Categoria: %d\n",productos[x].id_categoria);
		printf("Gestor: %d\n",productos[x].id_gestor);
		printf("Stock: %d\n",productos[x].stock);
		printf("Compromiso: %d\n",productos[x].entrega);
		printf("Importe: %d\n",productos[x].importe);
		printf("\n");
}

