#ifndef __PEDIDOS_H__
#define __PEDIDOS_H__
#include "adminprov.h"

typedef struct {
	int id_pedido;
	char fecha_pedido[11];
	int id_cliente;
	char lugar[10];
	char id_locker[10];
	char id_cod[10];
}Pedidos;

typedef struct {
	int id_pedido;
	int id_prod;
	int num_unid;
	char fecha_prevista[11];
	int importe;
	char estado[15];
	int id_transp;
	int cod_locker;
	char fecha_transportista[11];
}ProductosPedidos;

//cabecera:void LeerPedidos(Pedidos*,int*);
//Precondicion: pedidos.txt existe y tiene datos
//Postcondicion: guarda los datos de pedidos.txt en pedidos
void LeerPedidos(Pedidos*);

//cabecera:void MostrarPedidos(Pedidos*,int,AdminProv*,int)
//Precondicion: pedidos y n_pedidos inicializados
//Postcondicion: muestra los pedidos
void MostrarPedidos(Pedidos*,int,AdminProv*,int);

//cabecera:void EscribirPedidos(Pedidos*,int)
//Precondicion: pedidos existe y tiene datos
//Postcondicion: guarda los datos de pedidos en pedidos.txt
void EscribirPedidos(Pedidos*,int);

//cabecera:void LeerProductosPedidos(ProductosPedidos*,int*);
//Precondicion: productospedidos.txt existe y tiene datos
//Postcondicion: guarda los datos de productospedidos.txt en productospedidos
void LeerProductosPedidos(ProductosPedidos*);

//cabecera:void MostrarProductosPedidos(ProductosPedidos*,int)
//Precondicion: productos y n_productos inicializados
//Postcondicion: muestra los productos
void MostrarProductosPedidos(ProductosPedidos*,int);

//cabecera:void EscribirProductosPedidos(ProductosPedidos*,int);
//Precondicion: productospedidos existe y tiene datos
//Postcondicion: guarda los datos de productospedidos en productospedidos.txt
void EscribirProductosPedidos(ProductosPedidos*,int);


#endif
