#ifndef __MENUS_H__
#define __MENUS_H__

#include "clientes.h"
#include "productos.h"
#include "categorias.h"
#include "descuentos.h"
#include "pedidos.h"
#include "lockers.h"
#include "devoluciones.h"
#include "transportistas.h"

// Cabecera: void menu_inicial(int*,int,int,Cliente**, AdminProv*, Transportista*,int*,char*,int*,int*);
// Precondicion: Los tres parametros de enteros y las tres estructuras tienen que estar creadas previamente.
// Postcondicion:  Muestra menu de entrada y modifica la variable int* y char*.
// *char: Correo del usuario cuyo login es correcto.
void menu_inicial(int*, int, int, Cliente**, AdminProv*, Transportista*, int*, char*, int*, int*);

//Cabecera: void iniciar_sesion(int,int,int,Cliente *, AdminProv *, Transportista *, int* , char* , int*);
//Precondicion: Las tres estructuras tienen que estar creadas previamente.
//Postcondicion: Comprueba si los datos de inicio de sesion son correctos.
// *int:   1= Cliente, 2= Administrador, 3= Proveedor. 4= Transportista.
void iniciar_sesion(int, int, int, Cliente *, AdminProv *, Transportista *, int* , char* , int*);


void menu_administrador(Cliente**,AdminProv**,ProductosPedidos**,Productos**,Categorias**,Transportista**,Pedidos**,Descuentos**,DescuentosClientes**,int*,int*,int*,int*,int*,int*,int*,int*,int,int);
void menu_administrador_perfil(AdminProv*,int);
void menu_administrador_clientes(Cliente**,int*);
void menu_administrador_proveedores(AdminProv**,int*);
void menu_administrador_productos(AdminProv*,Productos**,Categorias*,int*,int,int,int);
void menu_administrador_categorias(Categorias**,Productos*,int*,int);
void menu_administrador_pedidos(ProductosPedidos**,int*,Pedidos**,int*,AdminProv*,int ,int);
void menu_administrador_transportista(Transportista**,int*,int);
void menu_administrador_descuentos(Descuentos**,DescuentosClientes**,Cliente*,int*,int,int*,int);
void menu_administrador_devoluciones();
void menu_superadministrador(AdminProv**,int*);

void menu_clientes(Cliente*, Productos*, Categorias*, DescuentosClientes*, Pedidos*, Lockers*, CompartimentosLockers*,
                   Devoluciones*, ProductosPedidos*, Descuentos*, int*, int, int, int, int, int, int, int*, int, int);

#endif
