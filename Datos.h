#ifndef Datos
#define Datos


typedef struct {
	int id;
	char nombre[10];
	char apellido[10];
	char direccion[50];
	char localidad[15];
    char provincia[15];
	char email[30];
    char contrasena[10];
    int cartera;
}Cliente;
typedef struct {
	int id;
	char empresa[15];
	char email[30];
    char contrasena[10];
    char tipo[15];
}AdminProv;

typedef struct {
	int id;
	char email[30];
    char contrasena[10];
	char empresa[15];
    char ciudad[10];
}Transportista;

typedef struct {
	int id;
	char descripcion[50];
	int id_categoria;
	int id_gestor;
	int stock;
	int compromiso;
	int importe;
}Productos;
typedef struct {
	int id;
	char descripcion[100];
}Categorias;
typedef struct {
	char id[10];
	char descripcion[50];
	char tipo[10];
	char estado[15];
	int importe;
	char aplicabilidad[20];
}Descuentos;
typedef struct {
	int id;
	char codigo[10];
	char fecha_asignacion[11];
	char fecha_caducidad[11];
	int estado;

}DescuentosClientes;
typedef struct {
	char id[10];
	char localidad[15];
	char provincia[20];
	char ubicacion[10];
	int compartimentos;
	int ocupados;
}Lockers;
typedef struct {
	char id[10];
	int compartimento;
	int codigo;
	char estado[15];
	char fecha_asignacion[11];
	char fecha_caducidad[11];
}CompartimentosLockers;
typedef struct {
	int id;
	char fecha[11];
	int id_cliente;
	char lugar[10];
	char id_locker[10];
	char codigo_cheque[10];
	char codigo_promocional[10];
}Pedidos;
typedef struct {
	int id_producto;
	int id_pedido;
	int unidades;
	char fecha_prevista[11];
	int importe;
	char estado[15];
	int id_transportista;
	int codigo;
	char fecha_transportista[11];
}ProductosPedidos;
typedef struct {
    int id_pedido;
	int id_producto;
	char fecha[11];
	char motivo[15];
	char estado[10];
	char fecha_aceptacion[11];
	char fecha_caducidad[11];
}Devoluciones;

//cabecera:int lineasfichero(char*)
//Precondición: recibe una cadena
//Postcondición: devuelve las lineas del fichero que se llame como esa cadena
int lineasfichero(char* );

//cabecera:int entero(char*)
//Precondición: recibe una cadena
//Postcondición: devuelve el valor entero de esa cadena
int entero(char* );

//cabecera:void MostrarClientes(Cliente *,int )
//Precondición: clientes y n_clientes inicializados
//Postcondición: muestra los clientes
void MostrarClientes(Cliente *,int );

//cabecera:void MostrarAdminProv(AdminProv *,int )
//Precondición: AdminProv y n_adminprov inicializados
//Postcondición: muestra los adminprov
void MostrarAdminProv(AdminProv *,int );

//cabecera:void MostrarProductos(Productos*,int,AdminProv*,int)
//Precondición: Productos y n_productos inicializados
//Postcondición: muestra los productos
void MostrarProductos(Productos*,int,AdminProv*,int);

//cabecera:void MostrarTransportistas(Transportista*,int)
//Precondición: transportistas y n_transportistas inicializados
//Postcondición: muestra los transportistas
void MostrarTransportistas(Transportista*,int);

//cabecera:void MostrarCategorias(Categorias *,int)
//Precondición: categorias y n_categorias inicializados
//Postcondición: muestra los categorias
void MostrarCategorias(Categorias *,int);

//cabecera:void MostrarPedidos(Pedidos*,int,AdminProv*,int)
//Precondición: pedidos y n_pedidos inicializados
//Postcondición: muestra los pedidos
void MostrarPedidos(Pedidos*,int,AdminProv*,int);

//cabecera:void MostrarProductosPedidos(ProductosPedidos*,int)
//Precondición: productos y n_productos inicializados
//Postcondición: muestra los productos
void MostrarProductosPedidos(ProductosPedidos*,int);

//cabecera:void MostrarLockers(Lockers*,int)
//Precondición: lockers y n_lockers inicializados
//Postcondición: muestra los lockers
void MostrarLockers(Lockers*,int);

//cabecera:void MostrarCompartimentosLockers(CompartimentosLockers*,int)
//Precondición: compartimentoslockers y n_compartimentoslockers inicializados
//Postcondición: muestra los compartimentoslockers
void MostrarCompartimentosLockers(CompartimentosLockers*,int);

//cabecera:void MostrarDescuentos(Descuentos* ,int)
//Precondición: descuentos y n_descuentos inicializados
//Postcondición: muestra los descuentos
void MostrarDescuentos(Descuentos* ,int);

//cabecera:void MostrarDescuentosClientes(DescuentosClientes*,int)
//Precondición: descuentosclientes y n_descuentosclientes inicializados
//Postcondición: muestra los descuentosclientes
void MostrarDescuentosClientes(DescuentosClientes*,int);

//cabecera:void MostrarDevoluciones(Devoluciones*,int)
//Precondición: devoluciones y n_devoluciones inicializados
//Postcondición: muestra los devoluciones
void MostrarDevoluciones(Devoluciones*,int);

//cabecera:void void LeerAdminProv(AdminProv *,int*);
//Precondición: adminprov.txt existe y tiene datos
//Postcondición: guarda los datos de adminprov.txt en adminprov
void LeerAdminProv(AdminProv *);

//cabecera:void LeerClientes(Cliente* ,int*);
//Precondición: clientes.txt existe y tiene datos
//Postcondición: guarda los datos de clientes.txt en clientes
void LeerClientes(Cliente* );

//cabecera:void LeerTransportistas(Transportista*,int*);
//Precondición: transportistas.txt existe y tiene datos
//Postcondición: guarda los datos de transportistas.txt en transportistas
void LeerTransportistas(Transportista*);

//cabecera:void LeerProductos(Productos*,int*);
//Precondición: productos.txt existe y tiene datos
//Postcondición: guarda los datos de productos.txt en productos
void LeerProductos(Productos*);

//cabecera:void LeerCategorias(Categorias*,int*);
//Precondición: categorias.txt existe y tiene datos
//Postcondición: guarda los datos de categorias.txt en categorias
void LeerCategorias(Categorias*);

//cabecera:void LeerPedidos(Pedidos*,int*);
//Precondición: pedidos.txt existe y tiene datos
//Postcondición: guarda los datos de pedidos.txt en pedidos
void LeerPedidos(Pedidos*);

//cabecera:void LeerProductosPedidos(ProductosPedidos*,int*);
//Precondición: productospedidos.txt existe y tiene datos
//Postcondición: guarda los datos de productospedidos.txt en productospedidos
void LeerProductosPedidos(ProductosPedidos*);

//cabecera:void LeerLockers(Lockers*,int*);
//Precondición: lockers.txt existe y tiene datos
//Postcondición: guarda los datos de lockers.txt en lockers
void LeerLockers(Lockers*);

//cabecera:void LeerCompartimentosLockers(CompartimentosLockers*);
//Precondición: compartimentoslockers.txt existe y tiene datos
//Postcondición: guarda los datos de compartimentoslockers.txt en compartimentoslockers
void LeerCompartimentosLockers(CompartimentosLockers*);

//cabecera:Descuentos* LeerDescuentos(Descuentos*,int*);
//Precondición: descuentos.txt existe y tiene datos
//Postcondición: guarda los datos de descuentos.txt en descuentos
void LeerDescuentos(Descuentos*);

//cabecera:DescuentosClientes* LeerDescuentosClientes(DescuentosClientes*,int*);
//Precondición: descuentosclientes.txt existe y tiene datos
//Postcondición: guarda los datos de descuentosclientes.txt en descuentosclientes
void LeerDescuentosClientes(DescuentosClientes*);

//cabecera:Devoluciones* LeerDevoluciones(Devoluciones*,int*);
//Precondición: devoluciones.txt existe y tiene datos
//Postcondición: guarda los datos de devolucioes.txt en devoluciones
void LeerDevoluciones(Devoluciones*);


//cabecera:void EscribirClientes(Cliente*,int)
//Precondición: clientes existe y tiene datos
//Postcondición: guarda los datos de clientes en clientes.txt
void EscribirClientes(Cliente*,int);

//cabecera:void EscribirAdminProv(AdminProv*,int)
//Precondición: adminprov existe y tiene datos
//Postcondición: guarda los datos de adminprov en adminprov.txt
void EscribirAdminProv(AdminProv*,int);

//cabecera:void EscribirTransportistas(Transportistas*,int)
//Precondición: transportistas existe y tiene datos
//Postcondición: guarda los datos de transportistas en transportistas.txt
void EscribirTransportistas(Transportista*,int);

//cabecera:void EscribirProductos(Productos*,int)
//Precondición: productos existe y tiene datos
//Postcondición: guarda los datos de productos en productos.txt
void EscribirProductos(Productos*,int);

//cabecera:void EscribirPedidos(Pedidos*,int)
//Precondición: pedidos existe y tiene datos
//Postcondición: guarda los datos de pedidos en pedidos.txt
void EscribirPedidos(Pedidos*,int);

//cabecera:void EscribirProductosPedidos(ProductosPedidos*,int);
//Precondición: productospedidos existe y tiene datos
//Postcondición: guarda los datos de productospedidos en productospedidos.txt
void EscribirProductosPedidos(ProductosPedidos*,int);

//cabecera:void EscribirLockers(Lockers*,int);
//Precondición: lockers existe y tiene datos
//Postcondición: guarda los datos de lockers en lockers.txt
void EscribirLockers(Lockers*,int);

//cabecera:void EscribirCategorias(Categorias*,int);
//Precondición: categorias existe y tiene datos
//Postcondición: guarda los datos de categorias en categorias.txt
void EscribirCategorias(Categorias*,int);

//cabecera:void EscribirDescuentos(Descuentos*,int);
//Precondición: descuentos existe y tiene datos
//Postcondición: guarda los datos de descuentos en descuentos.txt
void EscribirDescuentos(Descuentos*,int);

//cabecera:void EscribirCompartimentosLockers(CompartimentosLockers*,int);
//Precondición: compartimentoslockers existe y tiene datos
//Postcondición: guarda los datos de compartimentoslockers en compartimentoslockers.txt
void EscribirCompartimentosLockers(CompartimentosLockers*,int);

//cabecera:void EscribirDescuentosClientes(DescuentosClientes*,int);
//Precondición: descuentosclientes existe y tiene datos
//Postcondición: guarda los datos de descuentosclientes en descuentosclientes.txt
void EscribirDescuentosClientes(DescuentosClientes*,int);

//cabecera:void EscribirDevoluciones(Devoluciones*,int);
//Precondición: devoluciones existe y tiene datos
//Postcondición: guarda los datos de devoluciones en devoluciones.txt
void EscribirDevoluciones(Devoluciones*,int);

#endif

