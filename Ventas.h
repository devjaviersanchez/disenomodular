#ifndef Ventas
#define Ventas


void menu_clientes(Cliente*,Productos*,Categorias*,DescuentosClientes*,Pedidos*,Lockers*,CompartimentosLockers*,Devoluciones*,ProductosPedidos*,Descuentos*,
                   int* ,int ,int,int,int ,int ,int ,int* ,int,int);

void menu_clientes_perfil(Cliente*,int,int);
void menu_clientes_productos(Productos*,Categorias*,int,int);
void menu_clientes_descuentos(DescuentosClientes*,int ,Cliente*,int );
void menu_clientes_pedidos(Pedidos*,Lockers*,int*,int,Cliente*,Productos*,DescuentosClientes*,Descuentos*,ProductosPedidos*,int,int ,int,int,int);
void menu_clientes_devoluciones(Cliente*,Pedidos*,ProductosPedidos*,Devoluciones*,Productos*,int,int*,int*,int*,int*,int);

void menu_proveedores(AdminProv*,Categorias*,Productos**,Pedidos*,Lockers*,Transportista*,int*,int*,int,int,int,int,int);
void menu_proveedores_perfil(AdminProv*,int,int);
void menu_proveedores_productos(AdminProv*,Productos**,Categorias*,int*,int,int,int);
void menu_proveedores_pedidos();

void menu_transportista(Transportista*,Productos*,ProductosPedidos*,Lockers*,Pedidos*,CompartimentosLockers*,int,int,int,int,int,int,int);
void menu_transportista_perfil(Transportista * ,int,int);
void menu_transportista_repartos(Transportista* ,Productos*,ProductosPedidos*,Lockers* ,Pedidos*,CompartimentosLockers* ,int,int ,int ,int ,int ,int,int );
void menu_transportista_retornos(Transportista*,Productos*,ProductosPedidos* ,Lockers* ,Pedidos* pedidos,CompartimentosLockers* compartimentoslockers,int n_transportistas,int n_productos,int n_productospedidos,int n_lockers,int n_pedidos,int n_compartimentoslockers,int posicion_vector);

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


void Alta_Pedido(Pedidos* pedidos,AdminProv* adminprov,int posicion_vector,int n_categorias,int* n_pedidos);
void Consultar_Pedido(Pedidos*pedidos,int x);
void Baja_Pedido(Pedidos*pedidos,int*n_pedidos,AdminProv*adminprov,int posicion_vector);
void Modificacion_Pedido(Pedidos* pedidos,AdminProv* adminprov,int n_pedidos,int posicion_vector);
void Busqueda_Pedido(Pedidos*pedidos,int n_pedidos,int opcion);

void Alta_Categoria(Categorias* ,int* );
void Consultar_Categoria(Categorias*,int );
void Baja_Categoria(Categorias*,int* );
void Modificacion_Categoria(Categorias* ,int );
int Busqueda_Categoria(Categorias*,int,int);
int Busqueda_Categoria_nombre(Categorias*,int ,char*);

void Alta_Descuentos(Descuentos*,DescuentosClientes**,Cliente*,int*,int,int* );
void Consultar_Descuento(Descuentos*,int );
void Baja_Descuentos(Descuentos*,int*,DescuentosClientes**,int *,int);
void Modificacion_Descuento(Descuentos* ,int );
int Busqueda_Descuento(Descuentos*,int,char *);

void Alta_DescuentosClientes(DescuentosClientes* ,Cliente*,int*,int,char*);
void Baja_DescuentosClientes(DescuentosClientes*,int*,char*);
void Modificacion_DescuentosClientes(DescuentosClientes* ,int ,int );
void Busqueda_DescuentosClientes(DescuentosClientes*descuentosclientes,int n_descuentosclientes,int opcion);
void Consultar_DescuentoClientes(DescuentosClientes*descuentosclientes,int x);


void Alta_Producto(Productos*,AdminProv*,Categorias*,int,int,int,int*);
void Baja_Producto(Productos*,int*,AdminProv*,int);
void Modificacion_Producto(Productos*,AdminProv*,int,int,int);
void Busqueda_Producto_Categorias(Productos*,Categorias*,int,int);
void Consultar_Producto(Productos*,int);
void busqueda_proveedor_productos(Productos*,Categorias*,AdminProv*,int,int,int);
void Busqueda_Producto_Nombre(Productos*,int);
int Buscar_Producto(Productos*,int,int);

#endif


