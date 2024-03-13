#ifndef __DATOS_H__
#define __DATOS_H__

typedef struct {
	int id_cliente;
	char nomb_cliente[20];
	char dir_cliente[50];
	char localidad[20];
    char provincia[20];
	char email[30];
    char contrasena[15];
    int cartera;
}Cliente;

typedef struct {
	int id_empresa;
	char nombre[20];
	char email[30];
    char contrasena[15];
    char perfil[20];
}AdminProv;

typedef struct {
	int id_transp;
	char nombre[20];
	char email[30];
    char contrasena[15];
	char nombre_empresa[20];
    char nombre_ciudad[20];
}Transportista;

typedef struct {
	int id_prod;
	char descripcion[50];
	int id_categoria;
	int id_gestor;
	int stock;
	int entrega;
	int importe;
}Productos;

typedef struct {
	int id_categoria;
	char descripcion[50];
}Categorias;

typedef struct {
	char id_cod[10];
	char descripcion[50];
	char tipo[10];
	char estado[15];
	int importe;
	char aplicabilidad[15];
}Descuentos;

typedef struct {
	int id_cliente;
	char id_cod[10];
	char fecha_asignacion[11];
	char fecha_caducidad[11];
	int estado;
}DescuentosClientes;

typedef struct {
	char id_locker[10];
	char localidad[20];
	char provincia[20];
	char ubicacion[20];
	int num_comp;
	int ocupados;
}Lockers;

typedef struct {
	char id_locker[10];
	int num_comp;
	int cod_locker;
	char estado[15];
	char fecha_asignacion[11];
	char fecha_caducidad[11];
}CompartimentosLockers;

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

typedef struct {
    int id_pedido;
	int id_prod;
	char fecha_devolucion[11];
	char motivo[50];
	char estado[20];
	char fecha_aceptacion[11];
	char fecha_caducidad[11];
}Devoluciones;

//cabecera:int lineasfichero(char*)
//Precondici�n: recibe una cadena
//Postcondici�n: devuelve las lineas del fichero que se llame como esa cadena
int LineasFichero(char* );

//cabecera:int entero(char*)
//Precondici�n: recibe una cadena
//Postcondici�n: devuelve el valor entero de esa cadena
int entero(char* );

//cabecera:void MostrarClientes(Cliente *,int )
//Precondici�n: clientes y n_clientes inicializados
//Postcondici�n: muestra los clientes
void MostrarClientes(Cliente *,int );

//cabecera:void MostrarAdminProv(AdminProv *,int )
//Precondici�n: AdminProv y n_adminprov inicializados
//Postcondici�n: muestra los adminprov
void MostrarAdminProv(AdminProv *,int );

//cabecera:void MostrarProductos(Productos*,int,AdminProv*,int)
//Precondici�n: Productos y n_productos inicializados
//Postcondici�n: muestra los productos
void MostrarProductos(Productos*,int,AdminProv*,int);

//cabecera:void MostrarTransportistas(Transportista*,int)
//Precondici�n: transportistas y n_transportistas inicializados
//Postcondici�n: muestra los transportistas
void MostrarTransportistas(Transportista*,int);

//cabecera:void MostrarCategorias(Categorias *,int)
//Precondici�n: categorias y n_categorias inicializados
//Postcondici�n: muestra los categorias
void MostrarCategorias(Categorias *,int);

//cabecera:void MostrarPedidos(Pedidos*,int,AdminProv*,int)
//Precondici�n: pedidos y n_pedidos inicializados
//Postcondici�n: muestra los pedidos
void MostrarPedidos(Pedidos*,int,AdminProv*,int);

//cabecera:void MostrarProductosPedidos(ProductosPedidos*,int)
//Precondici�n: productos y n_productos inicializados
//Postcondici�n: muestra los productos
void MostrarProductosPedidos(ProductosPedidos*,int);

//cabecera:void MostrarLockers(Lockers*,int)
//Precondici�n: lockers y n_lockers inicializados
//Postcondici�n: muestra los lockers
void MostrarLockers(Lockers*,int);

//cabecera:void MostrarCompartimentosLockers(CompartimentosLockers*,int)
//Precondici�n: compartimentoslockers y n_compartimentoslockers inicializados
//Postcondici�n: muestra los compartimentoslockers
void MostrarCompartimentosLockers(CompartimentosLockers*,int);

//cabecera:void MostrarDescuentos(Descuentos* ,int)
//Precondici�n: descuentos y n_descuentos inicializados
//Postcondici�n: muestra los descuentos
void MostrarDescuentos(Descuentos* ,int);

//cabecera:void MostrarDescuentosClientes(DescuentosClientes*,int)
//Precondici�n: descuentosclientes y n_descuentosclientes inicializados
//Postcondici�n: muestra los descuentosclientes
void MostrarDescuentosClientes(DescuentosClientes*,int);

//cabecera:void MostrarDevoluciones(Devoluciones*,int)
//Precondici�n: devoluciones y n_devoluciones inicializados
//Postcondici�n: muestra los devoluciones
void MostrarDevoluciones(Devoluciones*,int);

//cabecera:void void LeerAdminProv(AdminProv *,int*);
//Precondici�n: adminprov.txt existe y tiene datos
//Postcondici�n: guarda los datos de adminprov.txt en adminprov
void LeerAdminProv(AdminProv *);

//cabecera:void LeerClientes(Cliente* ,int*);
//Precondici�n: clientes.txt existe y tiene datos
//Postcondici�n: guarda los datos de clientes.txt en clientes
void LeerClientes(Cliente* );

//cabecera:void LeerTransportistas(Transportista*,int*);
//Precondici�n: transportistas.txt existe y tiene datos
//Postcondici�n: guarda los datos de transportistas.txt en transportistas
void LeerTransportistas(Transportista*);

//cabecera:void LeerProductos(Productos*,int*);
//Precondici�n: productos.txt existe y tiene datos
//Postcondici�n: guarda los datos de productos.txt en productos
void LeerProductos(Productos*);

//cabecera:void LeerCategorias(Categorias*,int*);
//Precondici�n: categorias.txt existe y tiene datos
//Postcondici�n: guarda los datos de categorias.txt en categorias
void LeerCategorias(Categorias*);

//cabecera:void LeerPedidos(Pedidos*,int*);
//Precondici�n: pedidos.txt existe y tiene datos
//Postcondici�n: guarda los datos de pedidos.txt en pedidos
void LeerPedidos(Pedidos*);

//cabecera:void LeerProductosPedidos(ProductosPedidos*,int*);
//Precondici�n: productospedidos.txt existe y tiene datos
//Postcondici�n: guarda los datos de productospedidos.txt en productospedidos
void LeerProductosPedidos(ProductosPedidos*);

//cabecera:void LeerLockers(Lockers*,int*);
//Precondici�n: lockers.txt existe y tiene datos
//Postcondici�n: guarda los datos de lockers.txt en lockers
void LeerLockers(Lockers*);

//cabecera:void LeerCompartimentosLockers(CompartimentosLockers*);
//Precondici�n: compartimentoslockers.txt existe y tiene datos
//Postcondici�n: guarda los datos de compartimentoslockers.txt en compartimentoslockers
void LeerCompartimentosLockers(CompartimentosLockers*);

//cabecera:Descuentos* LeerDescuentos(Descuentos*,int*);
//Precondici�n: descuentos.txt existe y tiene datos
//Postcondici�n: guarda los datos de descuentos.txt en descuentos
void LeerDescuentos(Descuentos*);

//cabecera:DescuentosClientes* LeerDescuentosClientes(DescuentosClientes*,int*);
//Precondici�n: descuentosclientes.txt existe y tiene datos
//Postcondici�n: guarda los datos de descuentosclientes.txt en descuentosclientes
void LeerDescuentosClientes(DescuentosClientes*);

//cabecera:Devoluciones* LeerDevoluciones(Devoluciones*,int*);
//Precondici�n: devoluciones.txt existe y tiene datos
//Postcondici�n: guarda los datos de devolucioes.txt en devoluciones
void LeerDevoluciones(Devoluciones*);


//cabecera:void EscribirClientes(Cliente*,int)
//Precondici�n: clientes existe y tiene datos
//Postcondici�n: guarda los datos de clientes en clientes.txt
void EscribirClientes(Cliente*,int);

//cabecera:void EscribirAdminProv(AdminProv*,int)
//Precondici�n: adminprov existe y tiene datos
//Postcondici�n: guarda los datos de adminprov en adminprov.txt
void EscribirAdminProv(AdminProv*,int);

//cabecera:void EscribirTransportistas(Transportistas*,int)
//Precondici�n: transportistas existe y tiene datos
//Postcondici�n: guarda los datos de transportistas en transportistas.txt
void EscribirTransportistas(Transportista*,int);

//cabecera:void EscribirProductos(Productos*,int)
//Precondici�n: productos existe y tiene datos
//Postcondici�n: guarda los datos de productos en productos.txt
void EscribirProductos(Productos*,int);

//cabecera:void EscribirPedidos(Pedidos*,int)
//Precondici�n: pedidos existe y tiene datos
//Postcondici�n: guarda los datos de pedidos en pedidos.txt
void EscribirPedidos(Pedidos*,int);

//cabecera:void EscribirProductosPedidos(ProductosPedidos*,int);
//Precondici�n: productospedidos existe y tiene datos
//Postcondici�n: guarda los datos de productospedidos en productospedidos.txt
void EscribirProductosPedidos(ProductosPedidos*,int);

//cabecera:void EscribirLockers(Lockers*,int);
//Precondici�n: lockers existe y tiene datos
//Postcondici�n: guarda los datos de lockers en lockers.txt
void EscribirLockers(Lockers*,int);

//cabecera:void EscribirCategorias(Categorias*,int);
//Precondici�n: categorias existe y tiene datos
//Postcondici�n: guarda los datos de categorias en categorias.txt
void EscribirCategorias(Categorias*,int);

//cabecera:void EscribirDescuentos(Descuentos*,int);
//Precondici�n: descuentos existe y tiene datos
//Postcondici�n: guarda los datos de descuentos en descuentos.txt
void EscribirDescuentos(Descuentos*,int);

//cabecera:void EscribirCompartimentosLockers(CompartimentosLockers*,int);
//Precondici�n: compartimentoslockers existe y tiene datos
//Postcondici�n: guarda los datos de compartimentoslockers en compartimentoslockers.txt
void EscribirCompartimentosLockers(CompartimentosLockers*,int);

//cabecera:void EscribirDescuentosClientes(DescuentosClientes*,int);
//Precondici�n: descuentosclientes existe y tiene datos
//Postcondici�n: guarda los datos de descuentosclientes en descuentosclientes.txt
void EscribirDescuentosClientes(DescuentosClientes*,int);

//cabecera:void EscribirDevoluciones(Devoluciones*,int);
//Precondici�n: devoluciones existe y tiene datos
//Postcondici�n: guarda los datos de devoluciones en devoluciones.txt
void EscribirDevoluciones(Devoluciones*,int);

#endif

