#include <stdio.h>
#include "menus.h"
#include "clientes.h"
#include "productos.h"
#include "categorias.h"
#include "descuentos.h"
#include "pedidos.h"
#include "lockers.h"
#include "devoluciones.h"

void menu_inicial(int *n_c,int n_a,int n_t,Cliente **clt, AdminProv *adm,
                  Transportista *tsp, int*type_user, char*name_user, int* pos_vector,int*atras)
{
    char aux_name[30];
    int aux_type,aux_pos,opcion;

    do {

        printf("\n\n\t\t\tESIZON:\n");
        puts("\n");
        printf("\n\t\t\t1-Iniciar sesion. \n");
        printf("\n\t\t\t2-Registrarse\n");
        printf("\n\t\t\t3-Salir.\n\n");

        printf("\n\t\t\tElija su opcion: ");
        fflush(stdin);
        scanf("%i",&opcion);

        *atras = opcion;

        switch (opcion) {
            case 1:
                iniciar_sesion(*n_c,n_a,n_t,*clt,adm,tsp,&aux_type,aux_name,&aux_pos);
                strcpy(name_user,aux_name);

                *type_user = aux_type;
                *pos_vector = aux_pos;

                // 1 = Cliente, 2 = Administrador, 3 = Proveedor, 4 = Transportista
                if(*type_user == 1 || *type_user == 2 || *type_user == 3 || *type_user == 4){

                    opcion = 3;

                    switch(*type_user) {
                        case 1:
                            printf("\n\t\t\t Bienvenido %s ,cliente, %i: \n\n\n\n",name_user,*pos_vector+1);
                            break;
                        case 2:
                            printf("\n\t\t\t Bienvenido %s ,administrador, %i: \n\n\n\n",name_user,*pos_vector+1);
                            break;
                        case 3:
                            printf("\n\t\t\t Bienvenido %s ,proveedor, %i: \n\n\n\n",name_user,*pos_vector+1);
                            system("pause");
                            break;
                        case 4:
                            printf("\n\t\t\t Bienvenido %s ,transportista, %i: \n\n\n\n",name_user,*pos_vector+1);
                            break;
                    }
                }
                break;
            case 2:
                    system("cls");
                    (*clt) = (Cliente*)realloc((*clt), (*n_c+ 1) * sizeof(Cliente));
                    Alta_Cliente(*clt, n_c);
                    break;

        }
    } while(opcion!=3);

    system("cls");
}

void iniciar_sesion(int n_c, int n_a, int n_t, Cliente *c, AdminProv *a, Transportista *t,
                    int* tipo, char *correo, int* pos)
{
    char usuario[30], password[10];
    int i,aux=0;

    *tipo=-1; // para cerrar la sesion cuando un usuario sale del sistema

    system("cls");

    printf("\n\t\tCorreo o email: ");
    fflush(stdin);
    gets(usuario);

    printf("\n\t\tContrasena: ");
    fflush(stdin);
    gets(password);

    // Usuario
    for(i = 0;i < n_c; i++) {
        if(strcmp(usuario, c[i].email) == 0) {
            strcpy(correo, c[i].email);
            aux=1;
        }
        if(aux == 1 && strcmp(c[i].contrasena,password) == 0) {
            *tipo=1;
            *pos=i;
        }
    }

    // ADMINISTRADOR
    for(i = 0; i < n_a; i++) {
        if(strcmp(usuario,a[i].email)==0) {
            strcpy(correo,a[i].email);
            aux = 1;
        }

        if(aux == 1 && strcmp(a[i].contrasena, password) == 0) {

            if(strcmp(a[i].perfil,"administrador")==0) *tipo=2;
            else *tipo=3;

            *pos=i;

        }
    }

    //TRANSPORTISTA//
    for(i=0;i<n_t;i++){
        if(strcmp(usuario,t[i].email) == 0) {
            strcpy(correo,t[i].email);
            aux=1;
        }

        if(aux==1 && strcmp(t[i].contrasena,password)==0) {
            *tipo=4;
            *pos=i;
        }
    }


    if (*tipo==-1) {
        printf("\n\t\tUsuario o contrasena incorrectos.\n\n");
        system("pause");
    }

    system("cls");
}

void menu_administrador(Cliente ** clientes,AdminProv** adminprov,ProductosPedidos** productospedidos,Productos** productos,
                        Categorias**categorias,Transportista**transportistas,Pedidos**pedidos,Descuentos**descuentos,
                        DescuentosClientes**descuentosclientes,int*n_descuentosclientes,int*n_descuentos,int* n_pedidos,int*n_productospedidos,
                        int*n_clientes,int*n_productos,int*n_adminprov,int*n_transportistas,int n_categorias,int posicion_vector){
    int opcion;

    do{
        system("cls");

        printf("\n\t\t\tMenu de administrador:\n\n");
        if((*adminprov[posicion_vector]).id_empresa==1){printf("\n\t\t\t0. Administrador\n"); }

        printf("\n\t\t\t1. Perfil\n");
        printf("\n\t\t\t2. Clientes\n");
        printf("\n\t\t\t3. Proveedores\n");
        printf("\n\t\t\t4. Productos\n");
        printf("\n\t\t\t5. Categorias\n");
        printf("\n\t\t\t6. Pedidos\n");
        printf("\n\t\t\t7. Transportista\n");
        printf("\n\t\t\t8. Descuentos\n");
        printf("\n\t\t\t9. Devoluciones\n");
        printf("\n\t\t\t10. Salir del sistema\n");

        printf("\n\t\t\tOpcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        switch(opcion){
            if((*adminprov[posicion_vector]).id_empresa==1){
                case 0: menu_superadministrador(adminprov,n_adminprov);break;
            };

            case 1: menu_administrador_perfil(*adminprov,posicion_vector);break;
            case 2 :menu_administrador_clientes(clientes,n_clientes);break;
            case 3: menu_administrador_proveedores(adminprov,n_adminprov);break;
            case 4: menu_administrador_productos(adminprov,productos,categorias,n_productos,*n_adminprov,n_categorias,posicion_vector);break;
            case 5: menu_administrador_categorias(categorias,productos,n_categorias,*n_productos);break;
            case 6:/*menu_administrador_pedidos(productospedidos,n_productospedidos,&pedidos, n_pedidos,adminprov, posicion_vector,n_categorias);*/break;
            case 7: menu_administrador_transportista(transportistas,n_transportistas,posicion_vector);break;
            case 8:/*menu_administrador_descuentos(descuentos,descuentosclientes,clientes,n_descuentosclientes,*n_clientes,n_descuentos,posicion_vector)*/;break;
            case 9:/*menu_administrador_devoluciones()*/;break;
        }

    }while(opcion!=10);

    system("cls");
}

void menu_superadministrador(AdminProv**adminprov,int*n_adminprov){

    int opcion,i,p;

    do{

        system("cls");

        printf("\n\t\t\tMenu de superadministrador:\n");
        printf("\n\t\t\t1. Dar de alta a un administrador\n");
        printf("\n\t\t\t2. Dar de baja a un administrador\n");
        printf("\n\t\t\t3. Atras\n");
        printf("\n\t\t\tOpcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");

        switch(opcion){
            case 1 :
                (*adminprov) = (AdminProv*)realloc((*adminprov), (*n_adminprov + 1) * sizeof(AdminProv));
                Alta_AdminProv(*adminprov,n_adminprov,"administrador");
                break;
            case 2 :
                do {
                    printf("\n\t\t\tIntroduce el id del administrador a eliminar: ");
                    fflush(stdin);
                    scanf("%i",&p);
                } while(Buscar_AdminProv(*adminprov,*n_adminprov,p)==0);
                Baja_AdminProv(*adminprov,n_adminprov,p,"administrador");
                (*adminprov) = (AdminProv*)realloc((*adminprov), (*n_adminprov) * sizeof(AdminProv));
                break;
        }

    } while(opcion!=3);
}

void menu_administrador_perfil(AdminProv*adminprov,int posicion_vector){

    int opcion,i;

    do{

        system("cls");

        printf("\n\t\t\tMenu de gestion del perfil: \n");
        printf("\n\t\t\t1. Consultar datos del perfil\n");
        printf("\n\t\t\t2. Modificar datos del perfil\n");
        printf("\n\t\t\t3. Atras\n\n");
        printf("\n\t\t\tOpcion: ");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion){
            case 1 : Consulta_AdminProv(adminprov,posicion_vector);break;
            case 2 : Modificar_AdminProv(adminprov,posicion_vector);break;
        }
    }while(opcion!=3);
}


void menu_administrador_clientes(Cliente**clientes,int*n_clientes){

    int opcion,i,p,id;

    do {

        system("cls");

        printf("\n\t\t\tMenu de gestion de clientes:\n\n");
        printf("\n\t\t\t1. Dar de alta a un cliente\n");
        printf("\n\t\t\t2. Dar de baja a un cliente\n");
        printf("\n\t\t\t3. Listar clientes\n");
        printf("\n\t\t\t4. Buscar cliente\n");
        printf("\n\t\t\t5. Modificar datos de un cliente\n");
        printf("\n\t\t\t6. Atras\n\n");
        printf("\n\t\t\tOpcion: ");
        fflush(stdin);
        scanf("%i",&opcion);

        system("cls");
        switch(opcion){
            case 1 :
                (*clientes) = (Cliente*)realloc((*clientes), (*n_clientes+ 1) * sizeof(Cliente));
                Alta_Cliente(*clientes,n_clientes);
                break;

            case 2 :
                do{
                    printf("\n\t\t\tIntroduce el id del cliente que quieres eliminar: ");
                    fflush(stdin);
                    scanf("%i",&p);
                }while(Buscar_Cliente(*clientes,*n_clientes,p)==0);
                Baja_Cliente(*clientes,n_clientes,p - 1);
                (*clientes) = (Cliente*)realloc((*clientes), (*n_clientes) * sizeof(Cliente));break;

             case 3 : MostrarClientes(*clientes,*n_clientes);break;

            case 4 :
                do{
                    printf("\n\t\t\tIntroduce el id del cliente que estas buscando: ");
                    fflush(stdin);
                    scanf("%i",&p);
                }while(Buscar_Cliente(*clientes,*n_clientes,p)==0);
                Listar_Cliente(*clientes,*n_clientes,p);
                ;break;

            case 5 :
                do{
                    printf("\n\t\t\tIntroduce el id del cliente que quieres modificar: ");
                    fflush(stdin);
                    scanf("%i",&p);
                }while(Buscar_Cliente(*clientes,*n_clientes,p)==0);
                Modificar_Cliente(*clientes,p - 1);break;
            }
    } while(opcion!=6);
    return clientes;
}


void menu_administrador_proveedores(AdminProv**adminprov,int*n_adminprov){

    int opcion,i,p,id;

    do {

        system("cls");

        printf("\n\t\t\tMenu de gestion de proveedores:\n");
        printf("\n\t\t\t1. Realizar altas de proveedores\n");
        printf("\n\t\t\t2. Realizar bajas de proveedores\n");
        printf("\n\t\t\t3. Realizar listados de proveedores\n");
        printf("\n\t\t\t4. Realizar busqueda de proveedores\n");
        printf("\n\t\t\t5. Realizar modificacion de proveedores\n");
        printf("\n\t\t\t6. Atras\n\n");
        printf("\n\t\t\tOpcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        system("cls");
        switch(opcion){
            case 1 :
                (*adminprov) = (AdminProv*)realloc((*adminprov), (*n_adminprov+ 1) * sizeof(AdminProv));
                Alta_AdminProv(*adminprov,n_adminprov,"prov");break;

            case 2 : do{printf("Introduce el proveedor a eliminar: ");
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

        system("cls");

        printf("\n\t\t\tMenu de gestion de productos:\n");
        printf("\n\t\t\t1. Dar de alta un producto\n");
        printf("\n\t\t\t2. Dar de baja un producto\n");
        printf("\n\t\t\t3. Listar un producto\n");
        printf("\n\t\t\t4. Buscar un producto\n");
        printf("\n\t\t\t5. Modificar un producto\n");
        printf("\n\t\t\t6. Atras\n\n");
        printf("\n\t\t\tOpcion: ");
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

    do {

        system("cls");

        printf("\n\t\t\tMenu de gestion de categorias:\n");
        printf("\n\t\t\t1. Dar de alta una categoria\n");
        printf("\n\t\t\t2. Dar de baja una categoria\n");
        printf("\n\t\t\t3. Listar una categoria\n");
        printf("\n\t\t\t4. Buscar una categoria\n");
        printf("\n\t\t\t5. Modificar una categoria\n");
        printf("\n\t\t\t6. Generar listados de productos por categoria\n");
        printf("\n\t\t\t7. Atras\n\n");
        printf("Opcion: ");
        scanf("\n\t\t\t%i",&opcion);
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

            case 6 : Busqueda_Producto_Categorias(productos,*categorias,*n_categorias,n_productos);break;
            }
    } while(opcion!=7);
}

//casi terminado. Faltan dos opciones
void menu_administrador_pedidos(ProductosPedidos**productospedidos,int *n_productospedidos,Pedidos**pedidos,int *n_pedidos,AdminProv*adminprov,int posicion_vector,int n_categorias){

    int opcion;

    do{

        system("cls");

        printf("\n\t\t\tMenu de gestion de pedidos:\n");
        printf("\n\t\t\t1. Dar de alta un pedido\n");
        printf("\n\t\t\t2. Dar de baja un pedido\n");
        printf("\n\t\t\t3. Listar un pedido\n");
        printf("\n\t\t\t4. Buscar un pedido\n");
        printf("\n\t\t\t5. Modificar un pedido\n");
        printf("\n\t\t\t6. Asignar transportistas a productos\n");
        printf("\n\t\t\t7. Asignar lockers a pedidos\n");
        printf("\n\t\t\t8. Atras\n\n");
        printf("\n\t\t\tOpcion: ");
        scanf("\n\t\t\t%i",&opcion);
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

    do {
        system("cls");

        printf("\n\t\t\tMenu de gestion de transportistas: \n");
        printf("\n\t\t\t1. Dar de alta un transportista\n");
        printf("\n\t\t\t2. Dar de baja un transportista\n");
        printf("\n\t\t\t3. Listar un transportista\n");
        printf("\n\t\t\t4. Buscar un transportista\n");
        printf("\n\t\t\t5. Modificar un transportista\n");
        printf("\n\t\t\t6. Atras\n\n");

        printf("\n\t\t\tOpcion: ");
        scanf("%i",&opcion);
        fflush(stdin);

        switch(opcion){
            case 1 :
                (*transportistas) = (Transportista*)realloc((*transportistas), (*n_transportistas+ 1) * sizeof(Transportista));
                Alta_Transportista(*transportistas,n_transportistas);
                break;

            case 2 :  do{
                        printf("introduce el transportista a eliminar: ");
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

/*
void menu_administrador_descuentos(Descuentos**descuentos,DescuentosClientes**descuentosclientes,Cliente*clientes,int* n_descuentosclientes,int n_clientes,int* n_descuentos,int posicion_vector){
int opcion;
char * id;
        do{
        system("cls");
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
/*void menu_administrador_devoluciones(){
int opcion;

        do{
        system("cls");
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
*/

