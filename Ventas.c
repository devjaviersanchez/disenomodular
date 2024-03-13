#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "Datos.h"
#include "Ventas.h"
#include "Logistica.h"
#include"Perfiles.h"

void menu_clientes (Cliente*clientes,Productos*productos,Categorias*categorias,DescuentosClientes*descuentosclientes,Pedidos*pedidos,Lockers*lockers,CompartimentosLockers*compartimentoslockers,Devoluciones*devoluciones,ProductosPedidos*productospedidos,
                    Descuentos*descuentos,int *n_clientes,int n_productos,int n_categorias,int posicion_vector,int n_descuentosclientes,int n_devoluciones,int n_productospedidos,int* n_pedidos,int n_descuentos,int n_lockers){
    int opcion;
    do{
printf("Elija la opcion que desea:\n\n");

printf("-> 1. Perfil\n\n");
printf("-> 2. Productos\n\n");
printf("-> 3. Descuentos\n\n");
printf("-> 4. Pedidos\n\n");
printf("-> 5. Devoluciones\n\n");
printf("-> 6. Salir del sistema\n\n");

printf("Opcion: ");
scanf("%i",&opcion);
fflush(stdin);

system("cls");


switch(opcion){
    case 1 :

            menu_clientes_perfil(clientes,*n_clientes,posicion_vector);break;
    case 2 :

            menu_clientes_productos(productos,categorias, n_categorias, n_productos);break;

    case 3 :

            menu_clientes_descuentos(descuentosclientes,n_descuentosclientes,clientes,posicion_vector);break;

    case 4 :

            menu_clientes_pedidos(pedidos,lockers,n_pedidos,n_lockers,clientes,productos,descuentosclientes,descuentos,productospedidos,n_productospedidos,n_descuentosclientes,n_productos,n_descuentos,posicion_vector);break;

    case 5 :

            menu_clientes_devoluciones(clientes,pedidos,productospedidos,devoluciones,productos,n_productos,*n_clientes,n_pedidos,n_productospedidos,n_devoluciones,posicion_vector);break;

}

}while(opcion!=6);
}


void menu_clientes_perfil(Cliente*clientes,int n_clientes,int posicion_vector){
int opcion,i;
        do{
        system("cls");
        printf("Elija la opcion que desea hacer en su perfil: \n\n");
        printf("-> 1. Consultar datos del perfil\n\n");
        printf("-> 2. Modificar datos del perfil\n\n");
        printf("-> 3. Ver saldo de la cartera\n\n");
        printf("-> 4. A%cadir saldo a la cartera\n\n",-92);
        printf("-> 5. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : Consulta_Cliente(clientes,posicion_vector);break;
            case 2 : Modificar_Cliente(clientes,posicion_vector);break;
            case 3 : printf("Saldo : %d euros\n",clientes[posicion_vector].cartera);break;
            case 4 : actualizar_cartera(clientes,posicion_vector);break;
            }
            system("pause");
        }while(opcion!=5);
return clientes;
}

void menu_clientes_productos(Productos*productos,Categorias*categorias,int n_categorias,int n_productos){
int opcion,i;

        do{
        printf("Elija la opcion que desea de los productos: \n\n");
        printf("-> 1. Consultar productos por categoria\n\n");
        printf("-> 2. Consultar productos por nombre\n\n");
        printf("-> 3. Atras\n\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        if(opcion==1)Busqueda_Producto_Categorias(productos,categorias,n_categorias,n_productos);
        if(opcion==2)Busqueda_Producto_Nombre(productos,n_productos);

        }while(opcion!=3);
}

void menu_clientes_descuentos(DescuentosClientes*descuentosclientes,int n_descuentosclientes,Cliente*clientes,int posicion_vector){
int opcion,i;
        do{
        printf("Elija la opcion que desea de los descuentos: \n\n");
        printf("-> 1. Ver cheques regalo y codigos promocionales\n\n");
        printf("-> 2. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        if(opcion==1){
                Busqueda_DescuentosClientes(descuentosclientes,n_descuentosclientes,clientes[posicion_vector].id);
            }
        }while(opcion!=2);
}
//por hacer
void menu_clientes_pedidos(Pedidos*pedidos,Lockers*lockers,int* n_pedidos,int n_lockers,Cliente* clientes,Productos*productos,DescuentosClientes*descuentoclientes,Descuentos*descuentos,ProductosPedidos*productospedidos,int n_productospedidos,int n_descuentosclientes,int n_productos,int n_descuentos,int posicion_vector){
int opcion,i;

        do{

        printf("Elija la opcion que desea ver de sus pedidos: \n\n");
        printf("-> 1. Consultar estado de sus pedidos\n\n");
        printf("-> 2. Recoger pedido en un ESILocker\n\n");
        printf("-> 3. Realizar pedidos segun codigos promocionales\n\n");//??????????????????????
        printf("-> 4. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : comprobar_estado_productos_cliente(pedidos,clientes,productospedidos,productos,n_productospedidos,n_productos,n_pedidos,posicion_vector);break;
            case 2 : printf("2");break;
            case 3 : realizar_pedido_cliente(clientes,productos,descuentoclientes,descuentos,n_descuentosclientes,n_productos,n_descuentos,posicion_vector);break;
            }
}while(opcion!=4);


}
//falla
void menu_clientes_devoluciones(Cliente*clientes,Pedidos*pedidos,ProductosPedidos*productospedidos,Devoluciones*devoluciones,Productos*productos,int n_productos,int *n_clientes,int*n_pedidos,int*n_productospedidos,int*n_devoluciones,int posicion_vector){
int opcion,i;

        do{
        printf("Elija la opcion que desea hacer en el menu de devoluciones: \n\n");
        printf("-> 1. Realizar una devolucion de un pedido\n\n");
        printf("-> 2. Seguimiento de las devoluciones realizadas\n\n");
        printf("-> 3. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : realizar_devolucion_cliente(productos,productospedidos,pedidos,clientes,devoluciones,n_productos,n_productospedidos,n_pedidos,n_devoluciones,posicion_vector);break;
            case 2 : seguimiento_devoluciones_pendientes(pedidos,productospedidos,devoluciones,productos,n_productospedidos,n_devoluciones,n_productos,posicion_vector);break;
            }
        }while(opcion!=3);
}








void menu_proveedores(AdminProv*adminprov,Categorias*categorias,Productos**productos,Pedidos*pedidos,Lockers*lockers,Transportista*transportistas,int*n_adminprov,int*n_productos,int n_pedidos,int n_lockers,
                      int n_transportistas,int n_categorias,int posicion_vector){
    int opcion;

    do{
    printf("Elija la opcion que desea:\n\n");

    printf("-> 1. Perfil\n\n");
    printf("-> 2. Productos\n\n");
    printf("-> 3. Pedidos\n\n");
    printf("-> 4. Salir del sistema\n\n");

    printf("Opcion: ");
    scanf("%i",&opcion);
    fflush(stdin);

    system("cls");


switch(opcion){
    case 1 :

        menu_proveedores_perfil(adminprov,n_adminprov,posicion_vector);break;

    case 2 :

        menu_proveedores_productos(adminprov,&productos,categorias,n_adminprov,&n_productos,n_categorias,posicion_vector);break;

    case 3 :


        menu_proveedores_pedidos(pedidos,transportistas,lockers,n_transportistas,n_pedidos,n_lockers);break;

}

    }while(opcion!=4);

}


void menu_proveedores_perfil(AdminProv*adminprov,int n_adminprov,int posicion_vector){
int opcion;

    do{
        printf("Elija la opcion que desea hacer en su perfil: \n\n");
        printf("-> 1. Consultar datos del perfil\n\n");
        printf("-> 2. Modificar datos del perfil\n\n");
        printf("-> 3. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : Consulta_AdminProv(adminprov,posicion_vector);break;
            case 2 : Modificar_AdminProv(adminprov,posicion_vector);break;
            }
    }while(opcion!=3);
            return adminprov;
}


void  menu_proveedores_productos(AdminProv*adminprov,Productos**productos,Categorias*categorias,int* n_productos, int n_adminprov,int n_categorias,int posicion_vector){
int opcion,i;

    do{
        printf("Elija la opcion que desea de los productos: \n\n");
        printf("-> 1. Dar de alta un producto\n\n");
        printf("-> 2. Dar de baja un producto\n\n");
        printf("-> 3. Listar productos\n\n");
        printf("-> 4. Buscar un producto\n\n");
        printf("-> 5. Modificar un producto\n\n");
        printf("-> 6. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : (*productos) = (Productos*)realloc((*productos), (*n_productos+ 1) * sizeof(Productos));
                Alta_Producto(*productos,adminprov,categorias,posicion_vector,n_categorias,n_adminprov,n_productos);break;
            case 2 : Baja_Producto(*productos,n_productos,adminprov,posicion_vector);
                    (*productos) = (Productos*)realloc((*productos), (*n_productos) * sizeof(Productos));break;
            case 3 : MostrarProductos(*productos,*n_productos,adminprov,posicion_vector);break;
            case 4 : busqueda_proveedor_productos(*productos,categorias,adminprov, n_categorias, *n_productos,posicion_vector);break;
            case 5 : Modificacion_Producto(*productos,adminprov,n_categorias,*n_productos,posicion_vector);break;
            }
    }while(opcion!=6);

    return productos;
}


void menu_proveedores_pedidos(Pedidos*pedidos,Transportista*transportistas,Lockers*lockers,int *n_transportistas,int n_pedidos,int n_lockers){
int opcion,i;

    do{
        printf("Elija la opcion que desea ver de los pedidos de productos que suministra: \n\n");
        printf("-> 1. Consultar informacion de pedidos\n\n");
        printf("-> 2. Gestionar estado de los pedidos\n\n");
        printf("-> 3. Asignar transportistas\n\n");
        printf("-> 4. Asignar Lockers\n\n");
        printf("-> 5. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : printf("");break;
            case 2 : ;break;
            case 3 : /*Asignar_Transportista()*/;break;
            case 4 : /*Asignar_Locker()*/;break;
            }
        }while(opcion!=5);
}















void menu_transportista(Transportista* transportistas,Productos* productos,ProductosPedidos* productospedidos,Lockers* lockers,Pedidos* pedidos,CompartimentosLockers* compartimentoslockers,int n_transportistas,int n_productos,int n_productospedidos,int n_lockers,int n_pedidos,int n_compartimentoslockers,int posicion_vector){
    int opcion;
do{
printf("Elija la opcion que desea:\n\n");

printf("-> 1. Perfil\n\n");
printf("-> 2. Repartos\n\n");
printf("-> 3. Retornos\n\n");
printf("-> 4. Salir del sistema\n\n");

printf("Opcion: ");
scanf("%i",&opcion);
fflush(stdin);

system("cls");


switch(opcion){
    case 1 :

            menu_transportista_perfil(transportistas,n_transportistas,posicion_vector);break;

    case 2 :

            menu_transportista_repartos(transportistas,productos,productospedidos,lockers,pedidos,compartimentoslockers,n_transportistas,n_productos,n_productospedidos,n_lockers,n_pedidos,n_compartimentoslockers,posicion_vector);break;


    case 3 :

            menu_transportista_retornos(transportistas,productos,productospedidos,lockers,pedidos,compartimentoslockers,n_transportistas,n_productos,n_productospedidos,n_lockers,n_pedidos,n_compartimentoslockers,posicion_vector);break;

}
}while(opcion!=4);
}


void menu_transportista_perfil(Transportista* transportistas,int n_transportistas,int posicion_vector){
int opcion;

        do{
        printf("Elija la opcion que desea hacer en su perfil: \n\n");
        printf("-> 1. Consultar datos del perfil\n\n");
        printf("-> 2. Modificar datos del perfil\n\n");
        printf("-> 3. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : Consulta_Transportista(transportistas,posicion_vector);break;
            case 2 : Modificar_Transportista(transportistas,posicion_vector);break;
            }
        }while(opcion!=3);

}


void menu_transportista_repartos(Transportista* transportistas,Productos* productos,ProductosPedidos* productospedidos,Lockers* lockers,Pedidos* pedidos,CompartimentosLockers* compartimentoslockers,int n_transportistas,int n_productos,int n_productospedidos,int n_lockers,int n_pedidos,int n_compartimentoslockers,int posicion_vector){
int opcion;

        do{
        printf("Elija la opcion que desea ver de los repartos: \n\n");
        printf("-> 1. Consultar lista de productos asignados\n\n");
        printf("-> 2. Modificar los productos asignados\n\n");
        printf("-> 3. Asignar codigo locker a un producto\n\n");
        printf("-> 4. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : consulta_pedidos(productos,productospedidos, transportistas,  n_productos, n_productospedidos,posicion_vector);break;
            case 2 : modificacion_estado_pedidos(productospedidos, transportistas, n_productospedidos, posicion_vector); break;
            case 3 : asignar_codigo_locker(transportistas,productospedidos,pedidos,compartimentoslockers,lockers,n_productospedidos,n_pedidos,n_compartimentoslockers,n_lockers,posicion_vector);break;
}
        }while(opcion!=4);
}


void menu_transportista_retornos(Transportista* transportistas,Productos* productos,ProductosPedidos* productospedidos,Lockers* lockers,Pedidos* pedidos,CompartimentosLockers* compartimentoslockers,int n_transportistas,int n_productos,int n_productospedidos,int n_lockers,int n_pedidos,int n_compartimentoslockers,int posicion_vector){
int opcion;

        do{
        printf("Elija la opcion que desea ver del retorno de pedidos: \n\n");
        printf("-> 1. Consultar lockers\n\n");
        printf("-> 2. Actualizar estado de los compartimentos locker\n\n");
        printf("-> 3. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : consulta_lockers_localidad(lockers,pedidos,productospedidos,productos,n_lockers,n_pedidos,n_productospedidos,n_productos);break;
            case 2 : actualizar_estado_lockers(transportistas,productospedidos,compartimentoslockers,lockers,n_productospedidos,n_compartimentoslockers,n_lockers,posicion_vector);break;
            }
        }while(opcion!=3);
}















void menu_administrador(Cliente ** clientes,AdminProv** adminprov,ProductosPedidos** productospedidos,Productos** productos,Categorias**categorias,Transportista**transportistas,Pedidos**pedidos,Descuentos**descuentos,DescuentosClientes**descuentosclientes,int*n_descuentosclientes,int*n_descuentos,int* n_pedidos,int*n_productospedidos,int*n_clientes,int*n_productos,int*n_adminprov,int*n_transportistas,int n_categorias,int posicion_vector){
    int opcion;

do{
printf("Elija la opcion que desea:\n\n");
if((*adminprov[posicion_vector]).id==1){
    printf("-> 0. Administrador\n\n");
}
printf("-> 1. Perfil\n\n");
printf("-> 2. Clientes\n\n");
printf("-> 3. Proveedores\n\n");
printf("-> 4. Productos\n\n");
printf("-> 5. Categorias\n\n");
printf("-> 6. Pedidos\n\n");
printf("-> 7. Transportista\n\n");
printf("-> 8. Descuentos\n\n");
printf("-> 9. Devoluciones\n\n");
printf("-> 10. Salir del sistema\n\n");

printf("Opcion: ");
scanf("%i",&opcion);
fflush(stdin);

system("cls");


switch(opcion){
    if((*adminprov[posicion_vector]).id==1){
        case 0:menu_superadministrador(adminprov,n_adminprov);break;
    };
    case 1 :

            menu_administrador_perfil(*adminprov,posicion_vector);break;

    case 2 :

           menu_administrador_clientes(clientes,n_clientes);break;

    case 3 :

           menu_administrador_proveedores(adminprov,n_adminprov);break;

    case 4 :

            menu_administrador_productos(adminprov,productos,categorias,n_productos,*n_adminprov,n_categorias,posicion_vector);break;

    case 5 :

            menu_administrador_categorias(categorias,productos,n_categorias,*n_productos);break;

    case 6 :

            menu_administrador_pedidos(productospedidos,n_productospedidos,&pedidos, n_pedidos,adminprov, posicion_vector,n_categorias);break;

    case 7 :

            menu_administrador_transportista(transportistas,n_transportistas,posicion_vector);break;

    case 8 :

            menu_administrador_descuentos(descuentos,descuentosclientes,clientes,n_descuentosclientes,*n_clientes,n_descuentos,posicion_vector);break;

    case 9 :

            menu_administrador_devoluciones();break;
}

}while(opcion!=10);
}

void menu_superadministrador(AdminProv**adminprov,int*n_adminprov){
    int opcion,i,p;

        do{
        printf("Elija la opcion que desea hacer : \n\n");
        printf("-> 1. Dar de Alta a un administrador\n\n");
        printf("-> 2. Dar de Baja a un administrador\n\n");
        printf("-> 3. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : (*adminprov) = (AdminProv*)realloc((*adminprov), (*n_adminprov+ 1) * sizeof(AdminProv));
                Alta_AdminProv(*adminprov,n_adminprov,"admin") ;break;

            case 2 :do{printf("introduce el administrador a eliminar: ");
                    scanf("%i",&p);
                    fflush(stdin);
                    }while(Buscar_AdminProv(*adminprov,n_adminprov,p)==0);
                    Baja_AdminProv(*adminprov,n_adminprov,p,"prov");
                    (*adminprov) = (AdminProv*)realloc((*adminprov), (*n_adminprov) * sizeof(AdminProv));break;
            }
        }while(opcion!=3);
}

void menu_administrador_perfil(AdminProv*adminprov,int posicion_vector){
int opcion,i;

        do{
        printf("Elija la opcion que desea hacer en su perfil: \n\n");
        printf("-> 1. Consultar datos del perfil\n\n");
        printf("-> 2. Modificar datos del perfil\n\n");
        printf("-> 3. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : Consulta_AdminProv(adminprov,posicion_vector);break;
            case 2 : Modificar_AdminProv(adminprov,posicion_vector);break;
            }
        }while(opcion!=3);
}


void menu_administrador_clientes(Cliente**clientes,int*n_clientes){
int opcion,i,p,id;

        do{
        printf("Elija la opcion que desea de los clientes: \n\n");
        printf("-> 1. Realizar altas de clientes\n\n");
        printf("-> 2. Realizar bajas de clientes\n\n");
        printf("-> 3. Realizar listados de clientes\n\n");
        printf("-> 4. Realizar busqueda de clientes\n\n");
        printf("-> 5. Realizar modificacion de clientes\n\n");
        printf("-> 6. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : (*clientes) = (Cliente*)realloc((*clientes), (*n_clientes+ 1) * sizeof(Cliente));
                Alta_Cliente(*clientes,n_clientes);break;

            case 2 : do{printf("introduce el cliente a eliminar: ");
                    scanf("%i",&p);
                    fflush(stdin);
                    }while(Buscar_Cliente(*clientes,*n_clientes,p)==0);
                    Baja_Cliente(*clientes,n_clientes,p);
                    (*clientes) = (Cliente*)realloc((*clientes), (*n_clientes) * sizeof(Cliente));break;

            case 3 : MostrarClientes(*clientes,*n_clientes);break;

            case 4 : printf("Introduce un cliente a buscar");
                     scanf("%d",&id);
                    if(Buscar_Cliente(*clientes,*n_clientes,id)!=0){printf("El cliente %d Existe",id);
                    }else{printf("El cliente %d NO Existe",id);}   ;break;

            case 5 : do{printf("introduce el cliente a modificar: ");
                    scanf("%i",&p);
                    fflush(stdin);
                    }while(Buscar_Cliente(*clientes,*n_clientes,p)==0);
                    Modificar_Cliente(*clientes,p);break;
            }
        }while(opcion!=6);
        return clientes;
}


void menu_administrador_proveedores(AdminProv**adminprov,int*n_adminprov){
int opcion,i,p,id;

        do{
        printf("Elija la opcion que desea de los proveedores: \n\n");
        printf("-> 1. Realizar altas de proveedores\n\n");
        printf("-> 2. Realizar bajas de proveedores\n\n");
        printf("-> 3. Realizar listados de proveedores\n\n");
        printf("-> 4. Realizar busqueda de proveedores\n\n");
        printf("-> 5. Realizar modificacion de proveedores\n\n");
        printf("-> 6. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 :
                (*adminprov) = (AdminProv*)realloc((*adminprov), (*n_adminprov+ 1) * sizeof(AdminProv));
                Alta_AdminProv(*adminprov,n_adminprov,"prov");break;

            case 2 : do{printf("introduce el proveedor a eliminar: ");
                    scanf("%i",&p);
                    fflush(stdin);
                    }while(Buscar_AdminProv(*adminprov,*n_adminprov,p)==0);
                    Baja_AdminProv(*adminprov,n_adminprov,p,"prov");
                    (*adminprov) = (AdminProv*)realloc((*adminprov), (*n_adminprov) * sizeof(AdminProv));break;

            case 3 : MostrarAdminProv(*adminprov,*n_adminprov);break;

            case 4 : printf("Introduce un proveedor a buscar");
                     scanf("%d",&id);
                    if( Buscar_AdminProv(*adminprov,*n_adminprov,id)!=0){printf("El cliente %d Existe",id);
                     }else{printf("El cliente %d NO Existe",id);}  ;break;

            case 5 : do{printf("introduce el proveedor a modificar: ");
                    scanf("%i",&p);
                    fflush(stdin);
                    }while(Buscar_AdminProv(*adminprov,*n_adminprov,p)==0);
                    Modificar_AdminProv(*adminprov,p);break;
            }
        }while(opcion!=6);
}


void menu_administrador_productos(AdminProv*adminprov,Productos**productos,Categorias*categorias,int*n_productos,int n_adminprov,int n_categorias,int posicion_vector){
int opcion,id;

        do{
        printf("Elija la opcion que desea de los productos: \n\n");
        printf("-> 1. Dar de alta un producto\n\n");
        printf("-> 2. Dar de baja un producto\n\n");
        printf("-> 3. Listar un producto\n\n");
        printf("-> 4. Buscar un producto\n\n");
        printf("-> 5. Modificar un producto\n\n");
        printf("-> 6. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 :(*productos) = (Productos*)realloc((*productos), (*n_productos+ 1) * sizeof(Productos));
                Alta_Producto(*productos,adminprov,categorias,posicion_vector,n_categorias,n_adminprov,n_productos);break;

            case 2 : Baja_Producto(*productos,n_productos,adminprov,posicion_vector);
            (*productos) = (Productos*)realloc((*productos), (*n_productos) * sizeof(Productos)); break;

            case 3 : MostrarProductos(*productos,*n_productos,adminprov,posicion_vector);break;

            case 4 : printf("\n\t\tIntroduce el producto: ");
                    fflush(stdin);
                   scanf("%d",&id);
                if(Buscar_Producto(*productos,*n_productos,id)==0){printf("El producto %s Existe",id);
                     }else{printf("El producto %s NO Existe",id);};break;

            case 5 : Modificacion_Producto(*productos,adminprov,n_categorias,n_productos,posicion_vector);break;
            }
        }while(opcion!=6);
}


void menu_administrador_categorias(Categorias**categorias,Productos*productos,int*n_categorias,int n_productos){
int opcion;
char * nombre;

        do{
        printf("Elija la opcion que desea hacer en el menu de categorias: \n\n");
        printf("-> 1. Dar de alta una categoria\n\n");
        printf("-> 2. Dar de baja una categoria\n\n");
        printf("-> 3. Listar una categoria\n\n");
        printf("-> 4. Buscar una categoria\n\n");
        printf("-> 5. Modificar una categoria\n\n");
        printf("-> 6. Generar listados de productos por categoria\n\n");
        printf("-> 7. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : (*categorias) = (Categorias*)realloc((*categorias), (*n_categorias+ 1) * sizeof(Categorias));
                Alta_Categoria(*categorias,n_categorias);break;

            case 2 : Baja_Categoria(*categorias,n_categorias);
            (*categorias) = (Categorias*)realloc((*categorias), (*n_categorias) * sizeof(Categorias)); break;

            case 3 : MostrarCategorias(*categorias,*n_categorias);break;

            case 4 :
                printf("\n\t\tIntroduce la categoria: ");
                    fflush(stdin);
                    gets(nombre);
                if(Busqueda_Categoria_nombre(*categorias,*n_categorias,nombre)==0){printf("La categoria %s Existe",nombre);
                     }else{printf("La categoria %s NO Existe",nombre);};break;

            case 5 : Modificacion_Categoria(*categorias,*n_categorias);break;

            case 6 : Busqueda_Producto_Categorias(productos,*categorias,*n_categorias,n_productos);
                ;break;
            }
        }while(opcion!=7);
}

//por hacer
void menu_administrador_pedidos(ProductosPedidos**productospedidos,int *n_productospedidos,Pedidos**pedidos,int *n_pedidos,AdminProv*adminprov,int posicion_vector,int n_categorias){
int opcion;

        do{
        printf("Elija la opcion que desea hacer en el menu de pedidos: \n\n");
        printf("-> 1. Dar de alta un pedido\n\n");
        printf("-> 2. Dar de baja un pedido\n\n");
        printf("-> 3. Listar un pedido\n\n");
        printf("-> 4. Buscar un pedido\n\n");
        printf("-> 5. Modificar un pedido\n\n");
        printf("-> 6. Asignar transportistas a productos\n\n");
        printf("-> 7. Asignar lockers a pedidos\n\n");
        printf("-> 8. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : Alta_Pedido(pedidos,adminprov,posicion_vector,n_categorias,n_pedidos);break;
            case 2 : Baja_Pedido(pedidos,n_pedidos,adminprov,posicion_vector);break;
            case 3 : MostrarPedidos(pedidos,n_pedidos,adminprov,posicion_vector);break;
            case 4 : Busqueda_Pedido(pedidos,n_pedidos,opcion);break;
            case 5 : Modificacion_Pedido(pedidos,adminprov,n_pedidos,posicion_vector);break;
            case 6 : /*asignar_transportista*/;break;
            case 7 : /*asignar_lockers*/;break;
            }
        }while(opcion!=8);
}


void menu_administrador_transportista(Transportista** transportistas,int* n_transportistas,int posicion_vector){
int opcion,p,id;

        do{
        printf("Elija la opcion que desea hacer en el menu de transportistas: \n\n");
        printf("-> 1. Dar de alta un transportista\n\n");
        printf("-> 2. Dar de baja un transportista\n\n");
        printf("-> 3. Listar un transportista\n\n");
        printf("-> 4. Buscar un transportista\n\n");
        printf("-> 5. Modificar un transportista\n\n");
        printf("-> 6. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 :(*transportistas) = (Transportista*)realloc((*transportistas), (*n_transportistas+ 1) * sizeof(Transportista));
                Alta_Transportista(*transportistas,n_transportistas);break;

            case 2 :  do{printf("introduce el transportista a eliminar: ");
                    scanf("%i",&p);
                    fflush(stdin);
                    }while(Buscar_Transportista(*transportistas,*n_transportistas,p)==0);
                    Baja_Transportista(*transportistas,n_transportistas,p);
                    (*transportistas) = (Transportista*)realloc((*transportistas), (*n_transportistas+ 1) * sizeof(Transportista));break;

            case 3 : MostrarTransportistas(*transportistas,*n_transportistas);break;

            case 4 : printf("Introduce un cliente a buscar");
                     scanf("%d",&id);
                    if( Buscar_Transportista(*transportistas,*n_transportistas,id)==0){printf("El cliente %d Existe",id);
                    }else{printf("El cliente %d NO Existe",id); };break;

            case 5 :  do{printf("introduce el transportistas a modificar: ");
                    scanf("%i",&p);
                    fflush(stdin);
                    }while(Buscar_Transportista(*transportistas,*n_transportistas,p)==0);
                    Modificar_Transportista(*transportistas,p);break;
            }
        }while(opcion!=6);
}


void menu_administrador_descuentos(Descuentos**descuentos,DescuentosClientes**descuentosclientes,Cliente*clientes,int* n_descuentosclientes,int n_clientes,int* n_descuentos,int posicion_vector){
int opcion;
char * id;
        do{
        printf("Elija la opcion que desea hacer en el menu de descuentos: \n\n");
        printf("-> 1. Dar de alta descuentos\n\n");
        printf("-> 2. Dar de baja descuentos\n\n");
        printf("-> 3. Listar descuentos\n\n");
        printf("-> 4. Buscar descuentos\n\n");
        printf("-> 5. Modificar descuentos\n\n");
        printf("-> 6. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : (*descuentos) = (Descuentos*)realloc((*descuentos), (*n_descuentos+ 1) * sizeof(Descuentos));
                Alta_Descuentos(*descuentos,&descuentosclientes,clientes,n_descuentosclientes,n_clientes,n_descuentos);break;

            case 2 : Baja_Descuentos(*descuentos,n_descuentos,&descuentosclientes,n_descuentosclientes,n_clientes);
           (*descuentos) = (Descuentos*)realloc((*descuentos), (*n_descuentos) * sizeof(Descuentos)); break;

            case 3 : MostrarDescuentos(*descuentos,*n_descuentos);break;
            case 4 : printf("\n\t\tIntroduce el descuento: ");
                    fflush(stdin);
                    gets(id);
                if(Busqueda_Descuento(*descuentos,*n_descuentos,id)==0){printf("El descuento %s Existe",id);
                     }else{printf("El descuento %s NO Existe",id);}break;
            case 5 : Modificacion_Descuento(*descuentos,*n_descuentos);break;
            }
        }while(opcion!=6);
}

//por hacer
void menu_administrador_devoluciones(){
int opcion;

        do{
        printf("Elija la opcion que desea hacer en el menu de devoluciones: \n\n");
        printf("-> 1. Dar de alta devoluciones\n\n");
        printf("-> 2. Dar de baja devoluciones\n\n");
        printf("-> 3. Listar devoluciones\n\n");
        printf("-> 4. Buscar devoluciones\n\n");
        printf("-> 5. Modificar devoluciones\n\n");
        printf("-> 6. Atras\n\n");
        printf("Opcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 : printf("1");break;
            case 2 : printf("2");break;
            case 3 : printf("3");break;
            case 4 : printf("4");break;
            case 5 : printf("5");break;
            }
        }while(opcion!=6);
}




//PEDIDOS///////////


void Alta_Pedido(Pedidos* pedidos,AdminProv* adminprov,int posicion_vector,int n_categorias,int* n_pedidos){
    char s[100];
    int i=*n_pedidos;
    pedidos = (Pedidos*)realloc(pedidos, (i + 1) * sizeof(Pedidos));

    pedidos[i].id=*n_pedidos+1;

    printf("introduce la fecha :");
    fflush(stdin);
    gets(s);
    strcpy(pedidos[i].fecha,s);


    pedidos[i].id_cliente=0;

    do{
    printf("introduce el lugar de entrega (domicilio/locker) :");
    fflush(stdin);
    gets(s);
    }while(strcmp(s,"domicilio")!=0||strcmp(s,"locker")!=0);
    strcpy(pedidos[i].lugar,s);
    strcpy(pedidos[i].id_locker,"no");

    printf("introduce el cheque regalo:");
    fflush(stdin);
    gets(s);
    strcpy(pedidos[i].codigo_cheque,s);
    printf("introduce el codigo promocional:");
    fflush(stdin);
    gets(s);
    strcpy(pedidos[i].codigo_promocional,s);
    *n_pedidos=i+1;
    return pedidos;
}

void Consultar_Pedido(Pedidos*pedidos,int x){

        printf("\n");
		printf("Pedido: %d\n",pedidos[x].id);
		printf("Fecha: %s\n",pedidos[x].fecha);
		printf("Identificador del cliente: %d\n",pedidos[x].id_cliente);
		printf("Lugar de entrega: %s\n",pedidos[x].lugar);
		printf("Identificacion Locker: %s\n",pedidos[x].id_locker);
		printf("Codigo cheque regalo: %s\n",pedidos[x].codigo_cheque);
		printf("Codigo promocional: %s\n",pedidos[x].codigo_promocional);
		printf("\n");
}


void Baja_Pedido(Pedidos*pedidos,int*n_pedidos,AdminProv*adminprov,int posicion_vector){
    int i=*n_pedidos,j,cont=1,x;
        MostrarPedidos(pedidos,n_pedidos,adminprov,posicion_vector);
        fflush(stdin);
        printf("pedido: ");
        scanf("%i",&x);

    for(j=x-1;j<i;j++)
    {

       /* strcpy(descuentos[j].descripcion,descuentos[j+cont].descripcion);
        descuentos[j].tipo=descuentos[j+cont].tipo;
        descuentos[j].estado=descuentos[j+cont].estado;
        descuentos[j].stock=descuentos[j+cont].stock;
        descuentos[j].aplicabilidad=descuentos[j+cont].aplicabilidad;*/

    }
    *n_pedidos=i-1;

    //descuentos = (Descuentos*)realloc(descuentos, (i -1) * sizeof(Descuentos));}
    return pedidos;}


void Modificacion_Pedido(Pedidos* pedidos,AdminProv* adminprov,int n_pedidos,int posicion_vector){
    int x;
    system("cls");
    MostrarPedidos(pedidos,n_pedidos,adminprov,posicion_vector);
        fflush(stdin);
        printf("pedido: ");
        scanf("%i",&x);

    int opcion;
    char aux[50];
        do{
     Consultar_Pedido(pedidos,x-1);


    printf("Elija la opcion que desea hacer en el menu de descuentos: \n\n");
        printf("-> 1. modificar descripcion del descuento\n\n");
        printf("-> 2. modificar tipo del descuento\n\n");
        printf("-> 3. modificar estado del descuento\n\n");
        printf("-> 4. modificar importe del descuento\n\n");
        printf("-> 5. modificar aplicabilidad del descuento\n\n");
        printf("-> 6. Atras\n\n");

    fflush(stdin);
    scanf("%d", &opcion);
    switch(opcion){
    case 1:         printf("\n\t\tIntroduce la descripcion: ");
                    fflush(stdin);
                    //gets(descuentos[x-1].descripcion);break;

    case 2:
                    fflush(stdin);
                    //gets(descuentos[x-1].tipo);break;

    case 3:         printf("\n\t\tIntroduce el estado: ");
                    fflush(stdin);
                    //gets(descuentos[x-1].estado);break;

    case 4:         printf("\n\t\tIntroduce el importe: ");
                    fflush(stdin);
                    gets(aux);
                   // descuentos[x-1].importe=entero(aux);break;

    case 5:         printf("\n\t\tIntroduce la aplicabilidad: ");
                    fflush(stdin);
                   // gets(descuentos[x-1].aplicabilidad);break;

}

}while(opcion!=6);
return pedidos;
}



void Busqueda_Pedido(Pedidos*pedidos,int n_pedidos,int opcion){
    int aux=0,i,j;
    char * x;

        system("cls");
        switch(opcion){
            case 1 :     printf("introduce la categoria: \n\n");
                        fflush(stdin);
                         gets(x);
                         i=0;
                           /* while(i<n_categorias){
                            if(strstr(categorias[i].descripcion,x)!=NULL){
                                j=0;
                                while(j<n_productos){
                                    if(productos[j].id_categoria==categorias[i].id){
                                    Consultar_Producto(productos,j);}
                                j++;}
                            }
                            i++;
                            }*/;break;

            case 2 :    printf("introduce el nombre: \n\n");break;
                        fflush(stdin);
                        gets(x);
                        i=0;
                         /* while(i<n_productos){
                                if(strstr(descuentos[i].descripcion,x)!=NULL){
                                Consultar_Descuentos(descuentos,i);
                                }
                            i++;
                            }*/;break;
}
system("pause");
}


void Alta_Producto(Productos* productos,AdminProv* adminprov,Categorias*categorias,int posicion_vector,int n_categorias,int n_adminprov,int* n_productos){
    char s[100];
    int i=*n_productos;
    int id,cat;
    do{
    printf("\n\t Introduzca el id del Producto: \n");
    fflush(stdin);
    scanf("%i",&id);

    }while(Buscar_Producto(productos,i,id)!=0);
    productos[i].id=id;


    printf("introduce la descripcion :");
    fflush(stdin);
    gets(s);
    strcpy(productos[i].descripcion,s);

    do{
    printf("introduce el numero de categoria :");
    fflush(stdin);
    scanf("%i",&cat);
    }while(Busqueda_Categoria(categorias,n_categorias,cat)==0);
    productos[i].id_categoria=cat;

    productos[i].id_gestor=adminprov[posicion_vector].id;

    printf("introduce el stock :");
    fflush(stdin);
    gets(s);
    productos[i].stock=entero(s);
    printf("introduce el compromiso:");
    fflush(stdin);
    gets(s);
    productos[i].compromiso=entero(s);
    printf("introduce el importe:");
    fflush(stdin);
    gets(s);
    productos[i].importe=entero(s);
    *n_productos=i+1;
    Consultar_Producto(productos,i);

}

void Modificacion_Producto(Productos* productos,AdminProv* adminprov,int n_categorias,int n_productos,int posicion_vector){
    int x,i;
    system("cls");
    MostrarProductos(productos,n_productos,adminprov,posicion_vector);
        fflush(stdin);
        printf("producto: ");
        scanf("%i",&x);
        for(i=0;i<n_productos;i++){
                if(productos[i].id==x){
    if(productos[i].id_gestor!=adminprov[posicion_vector].id && strcmp(adminprov[posicion_vector].tipo,"admin")!=0){
        printf("ESTE PRODUCTO NO LE PERTENECE");
    }else{
    int opcion;
    char aux[50];
        do{
     Consultar_Producto(productos,i);


    printf("Elija la opcion que desea hacer en el menu de pedidos: \n\n");
        printf("-> 1. modificar descripcion del producto\n\n");
        printf("-> 2. modificar categoria del producto\n\n");
        printf("-> 3. modificar stock del producto\n\n");
        printf("-> 4. modificar compromiso del producto\n\n");
        printf("-> 5. modificar importe del producto\n\n");
        printf("-> 6. Atras\n\n");

    fflush(stdin);
    scanf("%d", &opcion);
    switch(opcion){
    case 1:         printf("\n\t\tIntroduce la descripcion: ");
                    fflush(stdin);
                    gets(productos[i].descripcion);break;

    case 2:         do{
                    printf("\n\t\tIntroduce la categoria: ");
                    fflush(stdin);
                    gets(aux);}while(entero(aux)>=n_categorias);
                    productos[i].id_categoria=entero(aux);break;

    case 3:         printf("\n\t\tIntroduce el stock: ");
                    fflush(stdin);
                    gets(aux);
                    productos[i].stock=entero(aux);break;

    case 4:         printf("\n\t\tIntroduce el compromiso: ");
                    fflush(stdin);
                    gets(aux);
                    productos[i].compromiso=entero(aux);break;

    case 5:         printf("\n\t\tIntroduce el importe: ");
                    fflush(stdin);
                    gets(aux);
                    productos[i].importe=entero(aux);break;
    }
}while(opcion!=6);

}
                }
        }
}


void Busqueda_Producto_Categorias(Productos*productos,Categorias*categorias,int n_categorias,int n_productos){
    int i=0,j,aux=0;
    char  x[100];
        printf("introduce la categoria: \n\n");
                        fflush(stdin);
                         gets(x);
                            fflush(stdin);
                            while(i<n_categorias){
                            if(strstr(categorias[i].descripcion,x)!=NULL){
                                j=0;
                                while(j<n_productos){
                                    if(productos[j].id_categoria==categorias[i].id){
                                    Consultar_Producto(productos,j);
                                    aux=1;}
                                j++;}
                            }
                            i++;
                            }
    if(aux==0)printf("Ese nombre de Categoria no corresponde con ningun Producto");
}


void Busqueda_Producto_Nombre(Productos*productos,int n_productos){
    int i=0,aux=0;
    char  x[100];
    printf("introduce el nombre: \n\n");

                        fflush(stdin);
                        gets(x);
                        fflush(stdin);
                          while(i<n_productos){
                                if(strstr(productos[i].descripcion,x)!=NULL){
                                Consultar_Producto(productos,i);
                                aux=1;
                                }
                            i++;
                            }
    if(aux==0)printf("Ese nombre de Producto no corresponde con ningun producto");
}

void busqueda_proveedor_productos(Productos*productos,Categorias* categorias,AdminProv* adminprov,int n_categorias,int n_productos,int posicion_vector){
    int i,j,opcion=0;
    char  x[100];
        printf("Elija la opcion que desea de los productos: \n\n");
        printf("-> 1. Consultar productos por categoria\n\n");
        printf("-> 2. Consultar productos por nombre\n\n");
        system("cls");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%i",&opcion);
        fflush(stdin);
        if(opcion==1){   printf("introduce la categoria: \n\n");
                        fflush(stdin);
                         gets(x);
                         i=0;
                            while(i<n_categorias){
                            if(strstr(categorias[i].descripcion,x)!=NULL){
                                j=0;
                                while(j<n_productos){
                                    if(productos[j].id_categoria==categorias[i].id){
                                            if(productos[j].id_gestor==adminprov[posicion_vector].id)
                                                Consultar_Producto(productos,j);
                                    }
                                j++;}
                            }
                            i++;
                            }
        }

        if(opcion==2){printf("introduce el nombre: \n\n");
                        fflush(stdin);
                        gets(x);
                        fflush(stdin);
                        i=0;
                          while(i<n_productos){
                                if(strstr(productos[i].descripcion,x)!=NULL){
                                        if(productos[i].id_gestor==adminprov[posicion_vector].id)
                                            Consultar_Producto(productos,i);
                                }
                            i++;
                            }
        }

system("pause");

}

void Consultar_Producto(Productos*productos,int x){

        printf("\n");
		printf("Producto: %d\n",productos[x].id);
		printf("Descripcion: %s\n",productos[x].descripcion);
		printf("Categoria: %d\n",productos[x].id_categoria);
		printf("Gestor: %d\n",productos[x].id_gestor);
		printf("Stock: %d\n",productos[x].stock);
		printf("Compromiso: %d\n",productos[x].compromiso);
		printf("Importe: %d\n",productos[x].importe);
		printf("\n");
}

void Baja_Producto(Productos*productos,int*n_productos,AdminProv*adminprov,int posicion_vector){

    int j,cont=1,x,i;
        MostrarProductos(productos,*n_productos,adminprov,posicion_vector);
        fflush(stdin);
        printf("producto: ");
        scanf("%i",&x);
         for(i=0;i<*n_productos;i++){
                if(productos[i].id==x){
       if(productos[i].id_gestor!=adminprov[posicion_vector].id && strcmp(adminprov[posicion_vector].tipo,"admin")!=0){
        printf("ESTE PRODUCTO NO LE PERTENECE");
    }else{
    for(j=i;j<*n_productos;j++)
    {
        productos[j].id=productos[j+cont].id;
        strcpy(productos[j].descripcion,productos[j+cont].descripcion);
        productos[j].id_categoria=productos[j+cont].id_categoria;
        productos[j].id_gestor=productos[j+cont].id_gestor;
        productos[j].stock=productos[j+cont].stock;
        productos[j].compromiso=productos[j+cont].compromiso;
        productos[j].importe=productos[j+cont].importe;

    }
    *n_productos=i-1;
    }

    }
         }
}

   int Buscar_Producto(Productos* productos,int n_productos,int id){
     int i,cont=0;

    for (i=0;i<n_productos;i++)
    {
        if(productos[i].id==id)cont++;
    }
return cont;
   }




//CATEGORIAS//////////

void Alta_Categoria(Categorias* categorias,int* n_categorias){
    char s[100];
    int i=*n_categorias;


    categorias[i].id=*n_categorias+1;

    printf("introduce la descripcion :");
    fflush(stdin);
    gets(s);
    strcpy(categorias[i].descripcion,s);


    *n_categorias=i+1;
    return categorias;
}

void Consultar_Categoria(Categorias*categorias,int x){

        printf("\n");
		printf("Identificacion de la categoria: %d\n",categorias[x].id);
		printf("Descripcion: %s\n",categorias[x].descripcion);
		printf("\n");
}


void Baja_Categoria(Categorias*categorias,int*n_categorias){
    int i=*n_categorias,j,cont=1,x;
        MostrarCategorias(categorias,*n_categorias);
        fflush(stdin);
        printf("Categoria: ");
        scanf("%i",&x);

    for(j=x-1;j<i;j++)
    {
        categorias[j].id=categorias[j+cont].id;
     strcpy(categorias[j].descripcion,categorias[j+cont].descripcion);
      }
    *n_categorias=i-1;

    }


void Modificacion_Categoria(Categorias* categorias,int n_categorias){
    int x;
    system("cls");
    MostrarCategorias(categorias,n_categorias);
        fflush(stdin);
        printf("categoria: ");
        scanf("%i",&x);

    int opcion;
        do{


    printf("Elija la opcion que desea hacer en el menu de descuentos: \n\n");
        printf("-> 1. modificar descripcion de la categoria\n\n");
        printf("-> 2. Atras\n\n");

    fflush(stdin);
    scanf("%d", &opcion);
    if(opcion==1){
                    printf("\n\t\tIntroduce la descripcion: ");
                    fflush(stdin);
                    gets(categorias[x-1].descripcion);break;

    }

}while(opcion!=2);
return categorias;
}

int Busqueda_Categoria(Categorias*categorias,int n_categorias,int id){
    int cont=0,i;
system("cls");
for (i=0;i<n_categorias;i++)
    {
        if(categorias[i].id==id)cont++;
    }
return cont;
}
int Busqueda_Categoria_nombre(Categorias*categorias,int n_categorias,char*nombre){
int cont=0,i;
system("cls");
for (i=0;i<n_categorias;i++)
    {
        if(strcmp(categorias[i].descripcion,nombre)==0)cont=i;
    }
return cont;}



//DESCUENTOS////////////////

void Alta_Descuentos(Descuentos* descuentos,DescuentosClientes** descuentosclientes,Cliente* clientes,int* n_descuentosclientes,int n_clientes,int* n_descuentos){
    char s[100];
    int i=*n_descuentos,j=0;

    do{
    printf("introduce la id :");
    fflush(stdin);
    gets(s);
    }while(Busqueda_Descuento(descuentos,*n_descuentos,s)!=0);
    strcpy(descuentos[i].id,s);

    printf("introduce la descripcion :");
    fflush(stdin);
    gets(s);
    strcpy(descuentos[i].descripcion,s);


    printf("introduce el tipo, codpro o cheqreg :");
    fflush(stdin);
    gets(s);
    strcpy(descuentos[i].tipo,s);


    printf("introduce el estado, activo o no activo :");
    fflush(stdin);
    gets(s);
    strcpy(descuentos[i].estado,s);


    printf("introduce el importe del descuento en euros  :");
    fflush(stdin);
    gets(s);
    descuentos[i].importe=entero(s);

    printf("introduce la aplicabilidad, todos o esizon:");
    fflush(stdin);
    gets(s);
    strcpy(descuentos[i].aplicabilidad,s);


    if(strcmp(descuentos[i].tipo,"codpro")==0){
        while(j<n_clientes){
                (*descuentosclientes) = (DescuentosClientes*)realloc((*descuentosclientes), (*n_descuentosclientes+ 1) * sizeof(DescuentosClientes));
        Alta_DescuentosClientes(*descuentosclientes,clientes,n_descuentosclientes,j,descuentos[i].id);
        j++;
    }}
    *n_descuentos=i+1;
}


void Consultar_Descuento(Descuentos*descuentos,int x){

        printf("\n");
		printf("Descuento: %s\n",descuentos[x].id);
		printf("Descripcion: %s\n",descuentos[x].descripcion);
		printf("Tipo: %s\n",descuentos[x].tipo);
		printf("Estado: %s\n",descuentos[x].estado);
		printf("Importe: %d\n",descuentos[x].importe);
		printf("Aplicabilidad: %s\n",descuentos[x].aplicabilidad);
		printf("\n");
}


void Baja_Descuentos(Descuentos*descuentos,int*n_descuentos,DescuentosClientes** descuentosclientes,int* n_descuentosclientes,int n_clientes){
    int i,j,cont=0;
    char*x;
    do{
        MostrarDescuentos(descuentos,n_descuentos);
        fflush(stdin);
        printf("descuento: ");
       gets(x);
            }while(Busqueda_Descuento(descuentos,n_descuentos,x)==0);
    Baja_DescuentosClientes(*descuentosclientes,n_descuentosclientes,x);
    (*descuentosclientes) = (DescuentosClientes*)realloc((*descuentosclientes), (*n_descuentosclientes-n_clientes) * sizeof(DescuentosClientes));

     for(j=0;j<*n_descuentos;j++)
    {
        if(strcmp(descuentos[j].id,x)==0)cont++;
        strcpy(descuentos[j].id,descuentos[j+cont].id);
        strcpy(descuentos[j].descripcion,descuentos[j+cont].descripcion);
        strcpy(descuentos[j].tipo,descuentos[j+cont].tipo);
        strcpy(descuentos[j].estado,descuentos[j+cont].estado);
        descuentos[j].importe=descuentos[j+cont].importe;
        strcpy(descuentos[j].aplicabilidad,descuentos[j+cont].aplicabilidad);

    }

    *n_descuentos=i-1;

}


void Modificacion_Descuento(Descuentos* descuentos,int n_descuentos){
    int x,i;
    system("cls");
    MostrarDescuentos(descuentos,n_descuentos);
        fflush(stdin);
        printf("descuento: ");
        scanf("%i",&x);

    int opcion;
    char aux[50];
        do{
                for(i=0;i<n_descuentos;i++){
                if(Busqueda_Descuento(descuentos,n_descuentos,x)!=0){
     Consultar_Descuento(descuentos,i);


    printf("Elija la opcion que desea hacer en el menu de descuentos: \n\n");
        printf("-> 1. modificar descripcion del descuento\n\n");
        printf("-> 2. modificar estado del descuento\n\n");
        printf("-> 3. modificar importe del descuento\n\n");
        printf("-> 4. modificar aplicabilidad del descuento\n\n");
        printf("-> 5. Atras\n\n");

    fflush(stdin);
    scanf("%d", &opcion);
    switch(opcion){
    case 1:         printf("\n\t\tIntroduce la descripcion: ");
                    fflush(stdin);
                    gets(descuentos[i].descripcion);break;

    case 2:         printf("\n\t\tIntroduce el estado: ");
                    fflush(stdin);
                    gets(descuentos[i].estado);break;

    case 3:         printf("\n\t\tIntroduce el importe: ");
                    fflush(stdin);
                    gets(aux);
                    descuentos[i].importe=entero(aux);break;

    case 4:         printf("\n\t\tIntroduce la aplicabilidad: ");
                    fflush(stdin);
                    gets(descuentos[i].aplicabilidad);break;

}
                }}
}while(opcion!=5);

}



int Busqueda_Descuento(Descuentos*descuentos,int n_descuentos,char * id){
    int cont=0,i,j;
        system("cls");
        for (i=0;i<n_descuentos;i++)
    {
        if(strcmp(descuentos[i].id,id)==0)cont++;
    }
return cont;
}





//DESCUENTOSCLIENTES/////////////


void Alta_DescuentosClientes(DescuentosClientes* descuentosclientes,Cliente*clientes,int* n_descuentosclientes,int pos_cliente,char * codigo){
    char s[9],h[11];
    int i=*n_descuentosclientes,j=10,x=0;
     time_t t;
    struct tm *tm;
    char fechayhora[100];
    char fecha[11];
    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%d-%m-%Y", tm);


    descuentosclientes[i].id=clientes[pos_cliente].id;
    strcpy(descuentosclientes[i].codigo,codigo);
    strcpy(descuentosclientes[i].fecha_asignacion,fechayhora);
    descuentosclientes[i].estado=0;

    printf("introduce la fecha de caducidad :");
    fflush(stdin);
    scanf("%s",&fecha);

    fecha[9]=fecha[7];
    fecha[8]=fecha[6];
    fecha[7]=fecha[5];
    fecha[6]=fecha[4];
    fecha[5]="-";
    fecha[4]=fecha[3];
    fecha[3]=fecha[2];
    fecha[2]="-";



   *n_descuentosclientes=i+1;
}

void Consultar_DescuentosClientes(DescuentosClientes*descuentosclientes,int x){

        printf("\n");
		printf("Cliente: %d\n",descuentosclientes[x].id);
		printf("Codigo: %s\n",descuentosclientes[x].codigo);
		printf("Fecha asignacion: %s\n",descuentosclientes[x].fecha_asignacion);
		printf("Fecha caducidad: %s\n",descuentosclientes[x].fecha_caducidad);
		printf("Estado: %d\n",descuentosclientes[x].estado);
		printf("\n");
}


void Baja_DescuentosClientes(DescuentosClientes*descuentosclientes,int*n_descuentosclientes,char * codigo){
    int i=*n_descuentosclientes,j,cont=1,x=0,aux=0;
        MostrarDescuentosClientes(descuentosclientes,n_descuentosclientes);
        fflush(stdin);
    while(x<i){
            aux=0;
    for(j=x;j<i;j++)
    {
        if(strcmp(descuentosclientes[j].codigo,codigo)==0||aux==1){
        descuentosclientes[j].id=descuentosclientes[j+cont].id;
        strcpy(descuentosclientes[j].codigo,descuentosclientes[j+cont].codigo);
        strcpy(descuentosclientes[j].fecha_asignacion,descuentosclientes[j+cont].fecha_asignacion);
       strcpy(descuentosclientes[j].fecha_caducidad,descuentosclientes[j+cont].fecha_caducidad);
       descuentosclientes[j].estado=descuentosclientes[j+cont].estado;
       aux=1;
        }
    }
    x++;
    }
    *n_descuentosclientes=i-1;

}


void Modificacion_DescuentosClientes(DescuentosClientes* descuentosclientes,int n_descuentosclientes,int posicion_vector){
    int x;
    system("cls");
    MostrarDescuentosClientes(descuentosclientes,n_descuentosclientes);
        fflush(stdin);
        printf("descuentocliente: ");
        scanf("%i",&x);

    int opcion,estado;
    char aux[50];
        do{
     Consultar_DescuentosClientes(descuentosclientes,x-1);


    printf("Elija la opcion que desea hacer en el menu de descuentos: \n\n");
        printf("-> 1. modificar estado del descuento\n\n");
        printf("-> 2. Atras\n\n");

    fflush(stdin);
    scanf("%d", &opcion);
   if(opcion==1){
    do{
    printf("introduce 1-Aplicado/0-No aplicado");
    scanf("%d",&estado);
    }while(estado!=1||estado!=0);
    descuentosclientes[x-1].estado=estado;
   }

}while(opcion!=2);

}


void Busqueda_DescuentosClientes(DescuentosClientes*descuentosclientes,int n_descuentosclientes,int id_cliente){
    int aux=0,i=n_descuentosclientes-1;
    char * x;

        system("cls");

        while(i>=0){
            if(descuentosclientes[i].id==id_cliente){
                Consultar_DescuentosClientes(descuentosclientes,i);
            }
            i--;

        }
system("pause");
}

void consultar_productos (Productos *productos,int n_productos)
{
    int i;
    for(i=0;i<n_productos;i++)
    {
        printf("\n\t\t %i. %s   ,   STOCK: %i unidades.\n",i,productos[i].descripcion,productos[i].stock);
    }
}
void comprar_producto (Productos *productos, ProductosPedidos *productospedidos , int pos)
{
    if(productos[pos].stock>0)
    {
        productos[pos].stock=productos[pos].stock-1;

    }
    else{printf("\n\tNo hay stock de dicho producto\n");}
}
