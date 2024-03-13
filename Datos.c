#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Datos.h"

int entero(char* a) {
	int n = 0;
	int c=0;
	while(a[c] != '\0')
	{
		n = n * 10 + a[c] - '0';
		c++;
	}
	return n;
}

int lineasfichero(char* );
int lineasfichero(char* nombre){
 FILE* fichero;
   int ch, num_lineas=0;

   if ((fichero = fopen(nombre, "r")) == NULL){
      printf("fallo al abrir %s",nombre);
   }else{

   num_lineas = 0;
   while ((ch = fgetc(fichero)) != EOF)
      if (ch == '\n')
         num_lineas++;
   }
   return num_lineas+1;
}

void MostrarDevoluciones(Devoluciones* devoluciones,int n_devoluciones){
    int j=n_devoluciones;
	j--;
	while(j>=0){
            printf("\n");
        printf("%d\n",devoluciones[j].id_pedido);
		printf("%d\n",devoluciones[j].id_producto);
		printf("%s\n",devoluciones[j].fecha);
		printf("%s\n",devoluciones[j].motivo);
		printf("%s\n",devoluciones[j].estado);
		printf("%s\n",devoluciones[j].fecha_aceptacion);
		printf("%s\n",devoluciones[j].fecha_caducidad);

		j--;
		printf("\n");
	}

}
void MostrarClientes(Cliente *clientes,int n_clientes){
	int j=n_clientes;
	j--;
	while(j>=0){
            printf("\n");
		printf("Cliente: %d\n",clientes[j].id);
		printf("Nombre: %s\n",clientes[j].nombre);
		printf("Apellido: %s\n",clientes[j].apellido);
		printf("Direccion: %s\n",clientes[j].direccion);
		printf("Localidad: %s\n",clientes[j].localidad);
		printf("Provincia: %s\n",clientes[j].provincia);
		printf("Email: %s\n",clientes[j].email);
		printf("Contraseña: %s\n",clientes[j].contrasena);
		printf("Cartera: %d\n",clientes[j].cartera);
		j--;
		printf("\n");
	}
}
void MostrarAdminProv(AdminProv *adminprov,int n_adminprov){
	int j=n_adminprov;
	j--;
	while(j>=0){
            printf("\n");
        printf("AdminProv: %d\n",adminprov[j].id);
		printf("Empresa: %s\n",adminprov[j].empresa);
		printf("Email: %s\n",adminprov[j].email);
		printf("Contraseña: %s\n",adminprov[j].contrasena);
		printf("Tipo: %s\n",adminprov[j].tipo);
		j--;
		printf("\n");
	}
}
void MostrarTransportistas(Transportista *transportista,int n_transportista){
	int j=n_transportista;
	j--;
	while(j>=0){
            printf("\n");
        printf("Transportista: %d\n",transportista[j].id);
		printf("Email: %s\n",transportista[j].email);
		printf("Contraseña: %s\n",transportista[j].contrasena);
		printf("Empresa: %s\n",transportista[j].empresa);
		printf("Ciudad: %s\n",transportista[j].ciudad);
		j--;
		printf("\n");
	}
}
void MostrarProductos(Productos *productos,int n_productos,AdminProv*adminprov,int posicion_vector){
    int j=n_productos-1,cont=0;
	while(j>=0){
            if(adminprov[posicion_vector].id==productos[j].id_gestor||strcmp(adminprov[posicion_vector].tipo,"admin")==0){
            printf("\n");
		printf("Producto: %d\n",productos[j].id);
		printf("Descripcion: %s\n",productos[j].descripcion);
		printf("Categoria: %d\n",productos[j].id_categoria);
		printf("Gestor: %d\n",productos[j].id_gestor);
		printf("Stock: %d\n",productos[j].stock);
		printf("Compromiso: %d\n",productos[j].compromiso);
		printf("Importe: %d\n",productos[j].importe);
		printf("\n");cont++;
        }
	j--;}
	if(cont<1){
        printf("Usted no tiene ningun producto dado de alta\n");
	}
}
void MostrarCategorias(Categorias *categorias,int n_categorias){
int j=n_categorias;
	j--;
	while(j>=0){
            printf("\n");
		printf("Categoria: %d\n",categorias[j].id);
		printf("Descripcion: %s\n",categorias[j].descripcion);
		j--;
		printf("\n");
	}
}
void MostrarPedidos(Pedidos* pedidos,int n_pedidos,AdminProv*adminprov,int posicion_vector){
    int j=n_pedidos;
	j--;
	while(j>=0){
            printf("\n");
		printf("%d\n",pedidos[j].id);
		printf("%s\n",pedidos[j].fecha);
		printf("%d\n",pedidos[j].id_cliente);
		printf("%s\n",pedidos[j].lugar);
		printf("%s\n",pedidos[j].id_locker);
		printf("%s\n",pedidos[j].codigo_cheque);
		printf("%s\n",pedidos[j].codigo_promocional);

		j--;
		printf("\n");
	}
}
void MostrarProductosPedidos(ProductosPedidos* productospedidos,int n_productospedidos){
    int j=n_productospedidos;
	j--;
	while(j>=0){
            printf("\n");
		printf("%d\n",productospedidos[j].id_pedido);
		printf("%d\n",productospedidos[j].id_producto);
		printf("%d\n",productospedidos[j].unidades);
		printf("%s\n",productospedidos[j].fecha_prevista);
		printf("%d\n",productospedidos[j].importe);
		printf("%s\n",productospedidos[j].estado);
		printf("%d\n",productospedidos[j].id_transportista);
		printf("%d\n",productospedidos[j].codigo);
		printf("%s\n",productospedidos[j].fecha_transportista);

		j--;
		printf("\n");
	}
}
void MostrarLockers(Lockers* lockers,int n_lockers){
    int j=n_lockers;
	j--;
	while(j>=0){
            printf("\n");
		printf("%s\n",lockers[j].id);
		printf("%s\n",lockers[j].localidad);
		printf("%s\n",lockers[j].provincia);
		printf("%s\n",lockers[j].ubicacion);
		printf("%d\n",lockers[j].compartimentos);
		printf("%d\n",lockers[j].ocupados);
		j--;
		printf("\n");
	}
}
void MostrarCompartimentosLockers(CompartimentosLockers* compartimentoslockers,int n_compartimentoslockers){
    int j=n_compartimentoslockers;
	j--;
	while(j>=0){
            printf("\n");
		printf("%s\n",compartimentoslockers[j].id);
		printf("%d\n",compartimentoslockers[j].compartimento);
		printf("%d\n",compartimentoslockers[j].codigo);
		printf("%s\n",compartimentoslockers[j].estado);
		printf("%s\n",compartimentoslockers[j].fecha_asignacion);
		printf("%s\n",compartimentoslockers[j].fecha_caducidad);
		j--;
		printf("\n");
	}
}
void MostrarDescuentos(Descuentos* descuentos,int n_descuentos){
    int j=n_descuentos;
	j--;
	while(j>=0){
            printf("\n");
		printf("%s\n",descuentos[j].id);
		printf("%s\n",descuentos[j].descripcion);
		printf("%s\n",descuentos[j].tipo);
		printf("%s\n",descuentos[j].estado);
		printf("%d\n",descuentos[j].importe);
		printf("%s\n",descuentos[j].aplicabilidad);
		j--;
		printf("\n");
	}
}
void MostrarDescuentosClientes(DescuentosClientes* descuentosclientes,int n_descuentosclientes){
    int j=n_descuentosclientes;
	j--;
	while(j>=0){

            printf("\n");
		printf("%d\n",descuentosclientes[j].id);
		printf("%s\n",descuentosclientes[j].codigo);
		printf("%s\n",descuentosclientes[j].fecha_asignacion);
		printf("%s\n",descuentosclientes[j].fecha_caducidad);
		printf("%d\n",descuentosclientes[j].estado);

		printf("\n");

            j--;
	}
}

void LeerClientes(Cliente *clientes){
		FILE *fichero;
	fichero=fopen("Clientes.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir Clientes.txt");
	}
	else
	{

		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[9];//vector de cadenas ,contendra 9 cadenas
		char s[128];
		while (!feof(fichero)){

			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 9; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
			clientes[j].id=entero(tokens[0]) ;
			strcpy(clientes[j].nombre,tokens[1]) ;
			strcpy(clientes[j].apellido,tokens[2]);
			strcpy(clientes[j].direccion,tokens[3]);
			strcpy(clientes[j].localidad,tokens[4]);
			strcpy(clientes[j].provincia,tokens[5]);
			strcpy(clientes[j].email,tokens[6]);
			strcpy(clientes[j].contrasena,tokens[7]);
			clientes[j].cartera=entero(tokens[8]);

			j++;

		}
	}
	fclose(fichero);


}
void LeerAdminProv(AdminProv * adminprov){
		FILE *fichero;

	fichero=fopen("AdminProv.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir AdminProv.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[5];//vector de cadenas ,contendra 5 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 5; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
			adminprov[j].id=entero(tokens[0]) ;
			strcpy(adminprov[j].empresa,tokens[1]);
			strcpy(adminprov[j].email,tokens[2]);
			strcpy(adminprov[j].contrasena,tokens[3]);
			strcpy(adminprov[j].tipo,tokens[4]);
			j++;
		}

	}
	fclose(fichero);
}
void LeerTransportistas(Transportista* transportista){
    FILE *fichero;
	fichero=fopen("Transportistas.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir Transportistas.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[5];//vector de cadenas ,contendra 5 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 5; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
			transportista[j].id=entero(tokens[0]) ;
			strcpy(transportista[j].email,tokens[1]);
			strcpy(transportista[j].contrasena,tokens[2]);
			strcpy(transportista[j].empresa,tokens[3]);
			strcpy(transportista[j].ciudad,tokens[4]);
			j++;
		}
	}
	fclose(fichero);
}
void LeerProductos(Productos* productos){
    FILE *fichero;
	fichero=fopen("Productos.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir Productos.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[9];//vector de cadenas ,contendra 9 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 7; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
			productos[j].id=entero(tokens[0]) ;
			strcpy(productos[j].descripcion,tokens[1]);
			productos[j].id_categoria=entero(tokens[2]) ;
			productos[j].id_gestor=entero(tokens[3]) ;
			productos[j].stock=entero(tokens[4]) ;
			productos[j].compromiso=entero(tokens[5]) ;
            productos[j].importe=entero(tokens[6]) ;
			j++;
		}

	}
    fclose(fichero);

}
void LeerCategorias(Categorias* categorias){
FILE *fichero;
	fichero=fopen("Categorias.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir Categorias.txt");
	}
	else
	{
		int j=0;
		const char delim[2]="/";
		char* tokens[2];//vector de cadenas ,contendra 2 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			tokens[1] = strtok(NULL, delim);

			categorias[j].id=entero(tokens[0]) ;
			strcpy(categorias[j].descripcion,tokens[1]);
			j++;
		}
	}
    fclose(fichero);
}
void LeerPedidos(Pedidos* pedidos){
FILE *fichero;
	fichero=fopen("Pedidos.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir Pedidos.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[7];//vector de cadenas ,contendra 7 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 7; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
			pedidos[j].id=entero(tokens[0]) ;
			strcpy(pedidos[j].fecha,tokens[1]) ;
			pedidos[j].id_cliente=entero(tokens[2]) ;
            strcpy(pedidos[j].lugar,tokens[3]);
			strcpy(pedidos[j].id_locker,tokens[4]);
			strcpy(pedidos[j].codigo_cheque,tokens[5]);
			strcpy(pedidos[j].codigo_promocional,tokens[6]);
			j++;
		}
	}
	fclose(fichero);

}
void LeerProductosPedidos(ProductosPedidos* productospedidos){
 FILE *fichero;
	fichero=fopen("ProductosPedidos.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir ProductosPedidos.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[9];//vector de cadenas ,contendra 9 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 9; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
			productospedidos[j].id_pedido=entero(tokens[0]) ;
			productospedidos[j].id_producto=entero(tokens[1]) ;
			productospedidos[j].unidades=entero(tokens[2]) ;
			strcpy(productospedidos[j].fecha_prevista,tokens[3]) ;
			productospedidos[j].importe=entero(tokens[4]) ;
			strcpy(productospedidos[j].estado,tokens[5]);
			productospedidos[j].id_transportista=entero(tokens[6]) ;
			productospedidos[j].codigo=entero(tokens[7]) ;
			strcpy(productospedidos[j].fecha_transportista,tokens[8]) ;
			j++;
		}

	}
    fclose(fichero);
 }
void LeerLockers(Lockers* lockers){


 FILE *fichero;
	fichero=fopen("Lockers.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir Lockers.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[6];//vector de cadenas ,contendra 6 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 6; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
            strcpy(lockers[j].id,tokens[0]);
			strcpy(lockers[j].localidad,tokens[1]);
            strcpy(lockers[j].provincia,tokens[2]);
			strcpy(lockers[j].ubicacion,tokens[3]);
			lockers[j].compartimentos=entero(tokens[4]) ;
			lockers[j].ocupados=entero(tokens[5]) ;
			j++;
		}
	}
    fclose(fichero);
 }
void LeerCompartimentosLockers(CompartimentosLockers* compartimentoslockers){


 FILE *fichero;
	fichero=fopen("CompartimentosLockers.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir CompartimentosLockers.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[6];//vector de cadenas ,contendra 6 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 6; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
            strcpy(compartimentoslockers[j].id,tokens[0]);
            compartimentoslockers[j].compartimento=entero(tokens[1]) ;
			compartimentoslockers[j].codigo=entero(tokens[2]) ;
			strcpy(compartimentoslockers[j].estado,tokens[3]);
			strcpy(compartimentoslockers[j].fecha_asignacion,tokens[4]) ;
			strcpy(compartimentoslockers[j].fecha_caducidad,tokens[5]) ;

			j++;
		}
	}
 }
void LeerDescuentos(Descuentos* descuentos){
 FILE *fichero;
	fichero=fopen("Descuentos.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir Descuentos.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[6];//vector de cadenas ,contendra 6 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 6; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
            strcpy(descuentos[j].id,tokens[0]);
            strcpy(descuentos[j].descripcion,tokens[1]);
            strcpy(descuentos[j].tipo,tokens[2]);
			strcpy(descuentos[j].estado,tokens[3]);
			descuentos[j].importe=entero(tokens[4]) ;
			strcpy(descuentos[j].aplicabilidad,tokens[5]);

			j++;
		}
	}
    fclose(fichero);
 }
void LeerDescuentosClientes(DescuentosClientes* descuentosclientes){
 FILE *fichero;
	fichero=fopen("DescuentosClientes.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir DescuentosClientes.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[5];//vector de cadenas ,contendra 5 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);
			for ( i = 1; i < 5; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
            descuentosclientes[j].id=entero(tokens[0]);
            strcpy(descuentosclientes[j].codigo,tokens[1]);
			strcpy(descuentosclientes[j].fecha_asignacion,tokens[2]) ;
			strcpy(descuentosclientes[j].fecha_caducidad,tokens[3]) ;
			descuentosclientes[j].estado=entero(tokens[4]) ;

			j++;
		}
	}
 }
 void LeerDevoluciones(Devoluciones* devoluciones){
 FILE *fichero;
	fichero=fopen("Devoluciones.txt","r");
		if (fichero == NULL)
	{
		puts("\nError al abrir Devoluciones.txt");
	}
	else
	{
		int j=0;
		int i;
		const char delim[2]="/";
		char* tokens[7];//vector de cadenas ,contendra 9 cadenas
		char s[128];
		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n')
			{
				s[strlen(s) - 1] = '\0';
			}
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 7; i++)
			{
				tokens[i] = strtok(NULL, delim);
			}
            devoluciones[j].id_pedido=entero(tokens[0]);
            devoluciones[j].id_producto=entero(tokens[1]);
            strcpy(devoluciones[j].fecha,tokens[2]);
            strcpy(devoluciones[j].motivo,tokens[3]);
            strcpy(devoluciones[j].estado,tokens[4]);
			strcpy(devoluciones[j].fecha_aceptacion,tokens[5]) ;
			strcpy(devoluciones[j].fecha_caducidad,tokens[6]) ;
			j++;
		}
	}
 }


void EscribirClientes(Cliente* clientes ,int n_clientes){
    FILE *fichero;
	fichero=fopen("Clientes.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Clientes.txt");
	}
	else
	{
	    rewind(fichero);
		int j=0;
		while (j<n_clientes){
			fprintf(fichero, "%d/%s/%s/%s/%s/%s/%s/%s/%d", clientes[j].id, clientes[j].nombre, clientes[j].apellido, clientes[j].direccion, clientes[j].localidad, clientes[j].provincia, clientes[j].email,clientes[j].contrasena,clientes[j].cartera);
            if(j!=n_clientes-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirAdminProv(AdminProv * adminprov,int n_adminprov){
    FILE *fichero;
	fichero=fopen("Adminprov.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Adminprov.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_adminprov){
			fprintf(fichero, "%d/%s/%s/%s/%s",adminprov[j].id,adminprov[j].empresa,adminprov[j].email,adminprov[j].contrasena,adminprov[j].tipo);
            if(j!=n_adminprov-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirTransportistas(Transportista * transportista,int n_transportista){
    FILE *fichero;
	fichero=fopen("Transportistas.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Transportistas.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_transportista){
			fprintf(fichero, "%d/%s/%s/%s/%s",transportista[j].id,transportista[j].email,transportista[j].contrasena,transportista[j].empresa,transportista[j].ciudad);
            if(j!=n_transportista-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirDevoluciones(Devoluciones *devoluciones,int n_devoluciones){
    FILE *fichero;
	fichero=fopen("Devoluciones.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Devoluciones.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_devoluciones){
			fprintf(fichero, "%d/%d/%s/%s/%s/%s/%s",devoluciones[j].id_pedido,devoluciones[j].id_producto,devoluciones[j].fecha,devoluciones[j].motivo,devoluciones[j].estado,devoluciones[j].fecha_aceptacion,devoluciones[j].fecha_caducidad);
            if(j!=n_devoluciones-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirDescuentos(Descuentos *descuentos,int n_descuentos){
    FILE *fichero;
	fichero=fopen("Descuentos.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Descuentos.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_descuentos){
			fprintf(fichero, "%s/%s/%s/%s/%d/%s",descuentos[j].id,descuentos[j].descripcion,descuentos[j].tipo,descuentos[j].estado,descuentos[j].importe,descuentos[j].aplicabilidad);
            if(j!=n_descuentos-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirDescuentosClientes(DescuentosClientes *descuentosclientes,int n_descuentosclientes){
    FILE *fichero;
	fichero=fopen("DescuentosClientes.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir DescuentosClientes.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_descuentosclientes){
			fprintf(fichero, "%d/%s/%s/%s/%d",descuentosclientes[j].id,descuentosclientes[j].codigo,descuentosclientes[j].fecha_asignacion,descuentosclientes[j].fecha_caducidad,descuentosclientes[j].estado);
            if(j!=n_descuentosclientes-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirProductos(Productos *productos,int n_productos){
    FILE *fichero;
	fichero=fopen("Productos.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Productos.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_productos){
			fprintf(fichero, "%d/%s/%d/%d/%d/%d/%d",productos[j].id,productos[j].descripcion,productos[j].id_categoria,productos[j].id_gestor,productos[j].stock,productos[j].compromiso,productos[j].importe);
            if(j!=n_productos-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirProductosPedidos(ProductosPedidos *productospedidos,int n_productospedidos){
    FILE *fichero;
	fichero=fopen("ProductosPedidos.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir ProductosPedidos.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_productospedidos){
			fprintf(fichero, "%d/%d/%d/%s/%d/%s/%d/%d/%s",productospedidos[j].id_pedido,productospedidos[j].id_producto,productospedidos[j].unidades,productospedidos[j].fecha_prevista,productospedidos[j].importe,productospedidos[j].estado,productospedidos[j].id_transportista,productospedidos[j].codigo,productospedidos[j].fecha_transportista);
            if(j!=n_productospedidos-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirPedidos(Pedidos *pedidos,int n_pedidos){
    FILE *fichero;
	fichero=fopen("Pedidos.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Pedidos.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_pedidos){
			fprintf(fichero, "%d/%s/%d/%s/%s/%s/%s",pedidos[j].id,pedidos[j].fecha,pedidos[j].id_cliente,pedidos[j].lugar,pedidos[j].id_locker,pedidos[j].codigo_cheque,pedidos[j].codigo_promocional);
            if(j!=n_pedidos-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirLockers(Lockers *lockers,int n_lockers){
    FILE *fichero;
	fichero=fopen("Lockers.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Lockers.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_lockers){
			fprintf(fichero, "%s/%s/%s/%s/%d/%d",lockers[j].id,lockers[j].localidad,lockers[j].provincia,lockers[j].ubicacion,lockers[j].compartimentos,lockers[j].ocupados);
            if(j!=n_lockers-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirCategorias(Categorias *categorias,int n_categorias){
    FILE *fichero;
	fichero=fopen("Categorias.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir Categorias.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_categorias){
			fprintf(fichero, "%d/%s",categorias[j].id,categorias[j].descripcion);
            if(j!=n_categorias-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}
void EscribirCompartimentosLockers(CompartimentosLockers *compartimentoslockers,int n_compartimentoslockers){
    FILE *fichero;
	fichero=fopen("CompartimentosLockers.txt","w");
		if (fichero == NULL)
	{
		puts("\nError al abrir CompartimentosLockers.txt");
	}
	else
	{
	     rewind(fichero);
		int j=0;
		while (j<n_compartimentoslockers){
			fprintf(fichero, "%s/%d/%d/%s/%s/%s",compartimentoslockers[j].id,compartimentoslockers[j].compartimento,compartimentoslockers[j].codigo,compartimentoslockers[j].estado,compartimentoslockers[j].fecha_asignacion,compartimentoslockers[j].fecha_caducidad);
            if(j!=n_compartimentoslockers-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}


