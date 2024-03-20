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
