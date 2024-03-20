#include <stdio.h>
#include <stdlib.h>

#include "adminprov.h"
#include "categorias.h"
#include "clientes.h"
#include "descuentos.h"
#include "devoluciones.h"
#include "lockers.h"
#include "menus.h"
#include "pedidos.h"
#include "productos.h"
#include "transportistas.h"
#include "lectura.h"

int main()
{

    int tipo_usuario;
    int posicion_vector;
    int atras = 0;
    char usuario_actual[20];

    // Comprobamos el numero de elementos que contiene cada fichero
    // Esta informacion es necesaria para reservar memoria a continuacion
    int n_clientes = LineasFichero("Clientes.txt");
    int n_adminprov = LineasFichero("AdminProv.txt");
    int n_transportistas = LineasFichero("Transportistas.txt");
    int n_productos = LineasFichero("Productos.txt");
    int n_categorias = LineasFichero("Categorias.txt");
    int n_pedidos = LineasFichero("Pedidos.txt");
    int n_productospedidos = LineasFichero("ProductosPedidos.txt");
    int n_lockers = LineasFichero("Lockers.txt");
    int n_compartimentoslockers = LineasFichero("CompartimentosLockers.txt");
    int n_descuentos = LineasFichero("Descuentos.txt");
    int n_descuentosclientes = LineasFichero("DescuentosClientes.txt");
    int n_devoluciones = LineasFichero("Devoluciones.txt");

    // Declaramos y reservamos memoria para un vector por cada fichero de datos en el sistema
    Cliente *clientes =(Cliente*)malloc(n_clientes*sizeof(Cliente));
    AdminProv *adminProv = (AdminProv*)malloc(n_adminprov*sizeof(AdminProv));
    Transportista* transportistas = (Transportista*)malloc(n_transportistas*sizeof(Transportista));
    Productos *productos = (Productos*)malloc(n_productos*sizeof(Productos));
    Categorias* categorias = (Categorias*)malloc(n_categorias*sizeof(Categorias));
    Pedidos* pedidos = (Pedidos*)malloc(n_pedidos*sizeof(Pedidos));
    ProductosPedidos* productosPedidos = (ProductosPedidos*)malloc(n_productospedidos*sizeof(ProductosPedidos));
    Lockers* lockers = (Lockers*)malloc(n_lockers*sizeof(Lockers));
    CompartimentosLockers* compartimentosLockers = (CompartimentosLockers*)malloc(n_compartimentoslockers*sizeof(CompartimentosLockers));
    Descuentos* descuentos = (Descuentos*)malloc(n_descuentos*sizeof(Descuentos));
    DescuentosClientes*descuentosClientes = (DescuentosClientes*)malloc(n_descuentosclientes*sizeof(DescuentosClientes));
    Devoluciones*  devoluciones = (Devoluciones*)malloc(n_devoluciones*sizeof(Devoluciones));

    // Añadimos cada elemento de cada fichero en el vector correspondiente
    LeerClientes(clientes);
    LeerAdminProv(adminProv);
    LeerTransportistas(transportistas);
    LeerProductos(productos);
    LeerCategorias(categorias);
    LeerPedidos(pedidos);
    LeerProductosPedidos(productosPedidos);
    LeerLockers(lockers);
    LeerDevoluciones(devoluciones);
    LeerCompartimentosLockers(compartimentosLockers);
    LeerDescuentos(descuentos);
    LeerDescuentosClientes(descuentosClientes);

    //do {
        // El usuario inicia sesion o se registra en el sistema
        //menu_inicial(&n_clientes, n_adminprov, n_transportistas, &clientes, adminProv, transportistas, &tipo_usuario,
          //          usuario_actual, &posicion_vector, &atras);


        // Una vez que el usuario ha iniciado sesion, accede al menu correspondiente a su rol
//        switch(tipo_usuario) {
//            case 1: menu_clientes(clientes, productos, categorias, descuentosClientes,pedidos,lockers,
//                                  compartimentosLockers,devoluciones,productospedidos,descuentos,
//                                  &n_clientes,n_productos,n_categorias,posicion_vector,n_descuentosclientes,
//                                  n_devoluciones,n_productospedidos,n_pedidos,n_descuentos,n_lockers);break;
//            case 2: menu_administrador(&clientes,&adminprov,&productospedidos,&productos,&categorias,
//                                       &transportistas,&pedidos,&descuentos,&descuentosclientes,&n_descuentosclientes,
//                                       &n_descuentos,&n_pedidos,&n_productospedidos,&n_clientes,&n_productos,
//                                       &n_adminprov,&n_transportistas,n_categorias,posicion_vector);break;
//            case 3: menu_proveedores(adminprov,categorias,&productos,pedidos,lockers,transportistas,
//                                     &n_adminprov,&n_productos,n_pedidos,n_lockers,n_transportistas,
//                                     n_categorias,posicion_vector);break;
//            case 4: menu_transportista(transportistas,productos,productospedidos,lockers,pedidos,compartimentoslockers,
//                                       n_transportistas,n_productos,n_productospedidos,n_lockers,n_pedidos,
//                                       n_compartimentoslockers,posicion_vector);break;
//        }
    // } while(atras!=3);

    // Funciones usadas durante el desarrollo para comprobar que la lectura de ficheros es correcta
    // MostrarClientes(clientes  ,n_clientes);
    // MostrarAdminProv(adminProv ,n_adminprov);
    // MostrarTransportistas(transportistas,n_transportistas);
    // MostrarProductos(productos,n_productos, adminProv, posicion_vector);
    // MostrarCategorias (categorias,n_categorias);
    // MostrarPedidos(pedidos,n_pedidos, adminProv, posicion_vector);
    // MostrarProductosPedidos(productosPedidos,n_productospedidos);
    // MostrarLockers(lockers,n_lockers);
    // MostrarDevoluciones(devoluciones, n_devoluciones);
    // MostrarCompartimentosLockers(compartimentosLockers,n_compartimentoslockers);
    // MostrarDescuentos(descuentos,n_descuentos);
    // MostrarDescuentosClientes(descuentosClientes,n_descuentosclientes);

    return 0;
}
