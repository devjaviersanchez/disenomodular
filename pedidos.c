#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "pedidos.h"
#include "lectura.h"

void LeerPedidos(Pedidos* pedidos){

    FILE *fichero;
	fichero=fopen("Pedidos.txt","r");

	if (fichero == NULL) puts("\nError al abrir Pedidos.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[6];//vector de cadenas ,contendra 7 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 6; i++) tokens[i] = strtok(NULL, delim);

			pedidos[j].id_pedido=entero(tokens[0]) ;
			strcpy(pedidos[j].fecha_pedido,tokens[1]) ;
			pedidos[j].id_cliente=entero(tokens[2]) ;
            strcpy(pedidos[j].lugar,tokens[3]);
			strcpy(pedidos[j].id_locker,tokens[4]);
			strcpy(pedidos[j].id_cod,tokens[5]);

			j++;
		}
	}
	fclose(fichero);
}

void LeerProductosPedidos(ProductosPedidos* productospedidos){

    FILE *fichero;
	fichero=fopen("ProductosPedidos.txt","r");

    if (fichero == NULL) puts("\nError al abrir ProductosPedidos.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[9];//vector de cadenas ,contendra 9 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 9; i++) tokens[i] = strtok(NULL, delim);

			productospedidos[j].id_pedido=entero(tokens[0]) ;
			productospedidos[j].id_prod=entero(tokens[1]) ;
			productospedidos[j].num_unid=entero(tokens[2]) ;
			strcpy(productospedidos[j].fecha_prevista,tokens[3]) ;
			productospedidos[j].importe=entero(tokens[4]) ;
			strcpy(productospedidos[j].estado,tokens[5]);
			productospedidos[j].id_transp=entero(tokens[6]) ;
			productospedidos[j].cod_locker=entero(tokens[7]) ;
			strcpy(productospedidos[j].fecha_transportista,tokens[8]) ;

			j++;
		}
	}
    fclose(fichero);
}

void MostrarPedidos(Pedidos* pedidos,int n_pedidos,AdminProv*adminprov,int posicion_vector){

    int j=n_pedidos - 1;

	while(j>=0){
        printf("\n");
		printf("Id:%d\n",pedidos[j].id_pedido);
		printf("Fecha del pedido: %s\n",pedidos[j].fecha_pedido);
		printf("Id del cliente: %d\n",pedidos[j].id_cliente);
		printf("Lugar: %s\n",pedidos[j].lugar);
		printf("id del locker: %s\n",pedidos[j].id_locker);
		printf("Id del codigo promocional: %s\n",pedidos[j].id_cod);

		j--;
		printf("\n");
	}
}

void MostrarProductosPedidos(ProductosPedidos* productospedidos,int n_productospedidos){

    int j=n_productospedidos - 1;

	while(j>=0){
        printf("\n");
		printf("Id del pedido: %d\n",productospedidos[j].id_pedido);
		printf("Id del producto: %d\n",productospedidos[j].id_prod);
		printf("Numero de unidades: %d\n",productospedidos[j].num_unid);
		printf("Fecha de entrega: %s\n",productospedidos[j].fecha_prevista);
		printf("Importe: %d\n",productospedidos[j].importe);
		printf("Estado: %s\n",productospedidos[j].estado);
		printf("Id del transportista: %d\n",productospedidos[j].id_transp);
		printf("Codigo del locker: %d\n",productospedidos[j].cod_locker);
		printf("Fecha de entrega/devolucion por el transportista: %s\n",productospedidos[j].fecha_transportista);

		j--;
		printf("\n");
	}
}

void Alta_Pedido(Pedidos* pedidos,AdminProv* adminprov,int posicion_vector,int n_categorias,int* n_pedidos){

    char s[100];
    int i=*n_pedidos;

    pedidos = (Pedidos*)realloc(pedidos, (i + 1) * sizeof(Pedidos));

    pedidos[i].id_pedido=*n_pedidos+1;

    printf("introduce la fecha :");
    fflush(stdin);
    gets(s);
    strcpy(pedidos[i].fecha_pedido,s);


    pedidos[i].id_cliente=0;

    do{
        printf("introduce el lugar de entrega (domicilio/locker) :");
        fflush(stdin);
        gets(s);
    }while(strcmp(s,"domicilio")!=0||strcmp(s,"locker")!=0);

    strcpy(pedidos[i].lugar,s);
    strcpy(pedidos[i].id_locker,"no");

    printf("introduce el codigo promocional:");
    fflush(stdin);
    gets(s);
    strcpy(pedidos[i].id_cod,s);
    *n_pedidos=i+1;
    return pedidos;
}

// sin terminar
void Baja_Pedido(Pedidos*pedidos,int*n_pedidos,AdminProv*adminprov,int posicion_vector){

    int i=*n_pedidos,j,cont=1,x;

    MostrarPedidos(pedidos,n_pedidos,adminprov,posicion_vector);
    fflush(stdin);
    printf("pedido: ");
    scanf("%i",&x);
    /*
    Sin terminar
    for(j=x-1;j<i;j++)
    {

        strcpy(descuentos[j].descripcion,descuentos[j+cont].descripcion);
        descuentos[j].tipo=descuentos[j+cont].tipo;
        descuentos[j].estado=descuentos[j+cont].estado;
        descuentos[j].stock=descuentos[j+cont].stock;
        descuentos[j].aplicabilidad=descuentos[j+cont].aplicabilidad;

    }*/
    *n_pedidos=i-1;

    //descuentos = (Descuentos*)realloc(descuentos, (i -1) * sizeof(Descuentos));}
    return pedidos;
}


void Busqueda_Pedido(Pedidos*pedidos,int n_pedidos,int opcion){

    int aux=0,i,j;
    char * x;

    system("cls");
    switch(opcion){
        case 1 :     printf("introduce la categoria: \n\n");
                    fflush(stdin);
                     gets(x);
                     i=0;
                       /* while(i<n_categorias){
                        if(strstr(categorias[i].descripcion,x)!=NULL){
                            j=0;
                            while(j<n_productos){
                                if(productos[j].id_categoria==categorias[i].id){
                                Consultar_Producto(productos,j);}
                            j++;}
                        }
                        i++;
                        }*/;break;

        case 2 :    printf("introduce el nombre: \n\n");break;
                    fflush(stdin);
                    gets(x);
                    i=0;
                     /* while(i<n_productos){
                            if(strstr(descuentos[i].descripcion,x)!=NULL){
                            Consultar_Descuentos(descuentos,i);
                            }
                        i++;
                        }*/;break;
        }
system("pause");
}

void Modificacion_Pedido(Pedidos* pedidos,AdminProv* adminprov,int n_pedidos,int posicion_vector){
    int x;
    system("cls");
    MostrarPedidos(pedidos,n_pedidos,adminprov,posicion_vector);
        fflush(stdin);
        printf("pedido: ");
        scanf("%i",&x);

    int opcion;
    char aux[50];
        do{
     Consultar_Pedido(pedidos,x-1);


    printf("Elija la opcion que desea hacer en el menu de descuentos: \n\n");
        printf("-> 1. modificar descripcion del descuento\n\n");
        printf("-> 2. modificar tipo del descuento\n\n");
        printf("-> 3. modificar estado del descuento\n\n");
        printf("-> 4. modificar importe del descuento\n\n");
        printf("-> 5. modificar aplicabilidad del descuento\n\n");
        printf("-> 6. Atras\n\n");

    fflush(stdin);
    scanf("%d", &opcion);
    switch(opcion){
    case 1:         printf("\n\t\tIntroduce la descripcion: ");
                    fflush(stdin);
                    //gets(descuentos[x-1].descripcion);break;

    case 2:
                    fflush(stdin);
                    //gets(descuentos[x-1].tipo);break;

    case 3:         printf("\n\t\tIntroduce el estado: ");
                    fflush(stdin);
                    //gets(descuentos[x-1].estado);break;

    case 4:         printf("\n\t\tIntroduce el importe: ");
                    fflush(stdin);
                    gets(aux);
                   // descuentos[x-1].importe=entero(aux);break;

    case 5:         printf("\n\t\tIntroduce la aplicabilidad: ");
                    fflush(stdin);
                   // gets(descuentos[x-1].aplicabilidad);break;

}

}while(opcion!=6);
return pedidos;
}

void Consultar_Pedido(Pedidos*pedidos,int x){

        printf("\n");
		printf("Pedido: %d\n",pedidos[x].id_pedido);
		printf("Fecha: %s\n",pedidos[x].fecha_pedido);
		printf("Identificador del cliente: %d\n",pedidos[x].id_cliente);
		printf("Lugar de entrega: %s\n",pedidos[x].lugar);
		printf("Identificacion Locker: %s\n",pedidos[x].id_locker);
		printf("Codigo promocional: %s\n",pedidos[x].id_cod);
		printf("\n");
}
