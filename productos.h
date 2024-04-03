#ifndef __PRODUCTOS_H__
#define __PRODUCTOS_H__
#include "adminprov.h"
#include "categorias.h"

typedef struct {
	int id_prod;
	char descripcion[50];
	int id_categoria;
	int id_gestor;
	int stock;
	int entrega;
	int importe;
}Productos;

//cabecera:void LeerProductos(Productos*,int*);
//Precondicion: productos.txt existe y tiene datos
//Postcondicion: guarda los datos de productos.txt en productos
void LeerProductos(Productos*);

//cabecera:void MostrarProductos(Productos*,int,AdminProv*,int)
//Precondicion: Productos y n_productos inicializados
//Postcondicion: muestra los productos
void MostrarProductos(Productos*,int,AdminProv*,int);

//cabecera:void EscribirProductos(Productos*,int)
//Precondicion: productos existe y tiene datos
//Postcondicion: guarda los datos de productos en productos.txt
void EscribirProductos(Productos*,int);

void Alta_Producto(Productos*,AdminProv*,Categorias*,int,int,int,int*);
int Buscar_Producto(Productos*, int, int);
void Busqueda_Producto_Categorias(Productos*, Categorias*, int, int);
void Consultar_Producto(Productos*, int);

#endif
