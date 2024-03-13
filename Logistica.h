#ifndef Logistica
#define Logistica


void consulta_pedidos(Productos* , ProductosPedidos*, Transportista*,int, int, int);

void modificacion_estado_pedidos(ProductosPedidos* , Transportista* , int, int);

void asignar_codigo_locker(Transportista*, ProductosPedidos* , Pedidos* , CompartimentosLockers* , Lockers* ,int , int , int , int , int );

void consulta_lockers_localidad(Lockers*, Pedidos*, ProductosPedidos*, Productos*, int , int , int , int );

void actualizar_estado_lockers(Transportista*, ProductosPedidos* , CompartimentosLockers* , Lockers* , int , int , int, int );

ProductosPedidos* alta_pedidos_admin(ProductosPedidos* ,int *);

ProductosPedidos* baja_pedidos_admin(ProductosPedidos* ,int *);

void realizar_pedido_cliente(Cliente* , Productos* , DescuentosClientes* , Descuentos*, int , int, int, int );

void comprobar_estado_productos_cliente(Pedidos*, Cliente* , ProductosPedidos* , Productos* , int , int , int , int );

void realizar_devolucion_cliente(Productos* , ProductosPedidos* , Pedidos*, Cliente* , Devoluciones* , int , int , int , int , int );


void seguimiento_devoluciones_pendientes(Pedidos* , ProductosPedidos* , Devoluciones* , Productos* , int , int , int, int );


#endif

