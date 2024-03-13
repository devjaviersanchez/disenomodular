#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Datos.h"
#include "Perfiles.h"
#include "Ventas.h"
#include "Logistica.h"

int main()
{
    int tipo_usuario,posicion_vector,atras=0;
    char usuario_actual[30];

int n_clientes=lineasfichero("Clientes.txt");
int n_adminprov=lineasfichero("Adminprov.txt");
int n_transportistas=lineasfichero("Transportistas.txt");
int n_productos=lineasfichero("Productos.txt");
int n_categorias=lineasfichero("Categorias.txt");
int n_pedidos=lineasfichero("Pedidos.txt");
int n_productospedidos=lineasfichero("Productospedidos.txt");
int n_lockers=lineasfichero("Lockers.txt");
int n_compartimentoslockers=lineasfichero("Compartimentoslockers.txt");
int n_descuentos=lineasfichero("Descuentos.txt");
int n_descuentosclientes=lineasfichero("Descuentosclientes.txt");
int n_devoluciones=lineasfichero("Devoluciones.txt");

    Cliente *clientes=(Cliente*)malloc(n_clientes*sizeof(Cliente));
    AdminProv *adminprov=(AdminProv*)malloc(n_adminprov*sizeof(AdminProv));
    Transportista* transportistas=(Transportista*)malloc(n_transportistas*sizeof(Transportista));
    Productos *productos=(Productos*)malloc(n_productos*sizeof(Productos));
    Categorias* categorias=(Categorias*)malloc(n_categorias*sizeof(Categorias));
    Pedidos* pedidos=(Pedidos*)malloc(n_pedidos*sizeof(Pedidos));
    ProductosPedidos* productospedidos=(ProductosPedidos*)malloc(n_productospedidos*sizeof(ProductosPedidos));
    Lockers* lockers=(Lockers*)malloc(n_lockers*sizeof(Lockers));
    CompartimentosLockers* compartimentoslockers=(CompartimentosLockers*)malloc(n_compartimentoslockers*sizeof(CompartimentosLockers));
    Descuentos* descuentos=(Descuentos*)malloc(n_descuentos*sizeof(Descuentos));
    DescuentosClientes*descuentosclientes=(DescuentosClientes*)malloc(n_descuentosclientes*sizeof(DescuentosClientes));
    Devoluciones*  devoluciones=(Devoluciones*)malloc(n_devoluciones*sizeof(Devoluciones));


    LeerClientes(clientes);
    LeerAdminProv(adminprov);
    LeerTransportistas(transportistas);
    LeerProductos(productos);
    LeerCategorias(categorias);
    LeerPedidos(pedidos);
    LeerProductosPedidos(productospedidos);
    LeerLockers(lockers);
    LeerCompartimentosLockers(compartimentoslockers);
    LeerDescuentos(descuentos);
    LeerDescuentosClientes(descuentosclientes);
    LeerDevoluciones(devoluciones);


    do{




   menu_usuario(&n_clientes,n_adminprov,n_transportistas,&clientes,adminprov,transportistas,&tipo_usuario,usuario_actual,&posicion_vector,&atras);
    switch(tipo_usuario)
    {
        case 1: menu_clientes(clientes,productos,categorias,descuentosclientes,pedidos,lockers,compartimentoslockers,devoluciones,productospedidos,descuentos,&n_clientes,n_productos,n_categorias,posicion_vector,n_descuentosclientes,n_devoluciones,n_productospedidos,n_pedidos,n_descuentos,n_lockers);break;
        case 2: menu_administrador(&clientes,&adminprov,&productospedidos,&productos,&categorias,&transportistas,&pedidos,&descuentos,&descuentosclientes,&n_descuentosclientes,&n_descuentos,&n_pedidos,&n_productospedidos,&n_clientes,&n_productos,&n_adminprov,&n_transportistas,n_categorias,posicion_vector);break;
        case 3: menu_proveedores(adminprov,categorias,&productos,pedidos,lockers,transportistas,&n_adminprov,&n_productos,n_pedidos,n_lockers,n_transportistas,n_categorias,posicion_vector);break;
        case 4: menu_transportista(transportistas,productos,productospedidos,lockers,pedidos,compartimentoslockers,n_transportistas,n_productos,n_productospedidos,n_lockers,n_pedidos,n_compartimentoslockers,posicion_vector);break;
    }
   }while(atras!=3);
    EscribirDevoluciones(devoluciones, n_devoluciones);
    EscribirClientes(clientes  ,n_clientes);
    EscribirAdminProv(adminprov ,n_adminprov);
    EscribirTransportistas(transportistas,n_transportistas);
    EscribirProductos(productos,n_productos);
    EscribirPedidos(pedidos,n_pedidos);
    EscribirProductosPedidos(productospedidos,n_productospedidos);
    EscribirLockers(lockers,n_lockers);
    EscribirCategorias(categorias,n_categorias);
    EscribirDescuentos(descuentos,n_descuentos);
    EscribirCompartimentosLockers(compartimentoslockers,n_compartimentoslockers);
    EscribirDescuentosClientes(descuentosclientes,n_descuentosclientes);
    return (0);
}
