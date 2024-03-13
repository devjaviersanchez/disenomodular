#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Datos.h"
#include "logistica.h"




void consulta_pedidos(Productos *productos_trans, ProductosPedidos *productospedidos, Transportista *transportista, int n_productos, int n_productospedidos, int pos_transportista){

    int i, j, cont_pedidos;

    cont_pedidos = 0;   //indica el numero de pedidos asignados al transportista

    //Para que un pedido aparezca en la lista del transportista, tiene que tener el mismo id del transportista y su estado
    //ha de ser"enReparto".

    for(i = 0; i < n_productospedidos; i++){

            if(productospedidos[i].id_transportista == transportista[pos_transportista].id){

                if(strcmp(productospedidos[i].estado,"enReparto") == 0){

                    for(j = 0; j < n_productos; j++){

                        if(productospedidos[i].id_producto == productos_trans[j].id){

                            printf("\n\n\t\tProducto asignado %i: %s, con fecha de entrega %s\n",cont_pedidos + 1,
                                    productos_trans[j].descripcion, productospedidos[i].fecha_prevista);
                            cont_pedidos++;
                        }
                    }
                }
            }
    }


    if(cont_pedidos == 0) printf("\n\n\t\tNo tiene ningun pedido asignado.\n");

    printf("\n\n");
}



void modificacion_estado_pedidos(ProductosPedidos* prod_pedidos, Transportista* transportista, int n_prod_pedidos, int posicion_usuario){

    int id_pedido_trans, id_producto_trans;
    int i, opcion, cont;

    cont = 0;         //esta variable es 1 si los id introducidos por el transportista coinciden con los guardados en el sistema.

    opcion = -1;      //utilizamos esta variable para que el transportista elija entre dos opciones de menu

    printf("\n\n\t\tIntroduce el id del pedido al que quiere realizar la modificacion:");
    scanf("%i", &id_pedido_trans);

    printf("\n\n\t\tIntroduce el id del producto al que quiere realizar la modificacion:");
    scanf("%i", &id_producto_trans);

    system("cls");

    //Para modificar el estado de un pedido este tiene que estar "enReparto", debe tener al menos una unidad y el id
    //del transportista tiene que coincidir con el del pedido. Ademas de los id de producto y pedidos introducidos anteriormente.
    //En el caso de que el pedido sea entregado, cambiamos su estado a "entregado" y modificamos el nº de unidades (una menos).
    //Si no es entregado, solo cambiamos su estado a "devuelto"
    //si el pedido no esta en estado enReparto y no tiene al menos una unidad, el transportista no puede modificar su estado

    for(i = 0; i < n_prod_pedidos; i++){

        if(prod_pedidos[i].id_transportista == transportista[posicion_usuario].id &&
           strcmp(prod_pedidos[i].estado, "enReparto") == 0 && prod_pedidos[i].unidades > 0){

            if(prod_pedidos[i].id_pedido == id_pedido_trans && prod_pedidos[i].id_producto == id_producto_trans){

                cont++;
                printf("\n\n\t\tPulsa 1 si la entrega se ha realizado correctamente\n\t\tPulsa 0 si no se ha podido llevar a cabo la entrega(devolucion): ");

                do{
                    scanf("%i", &opcion);
                }while(opcion > 1 || opcion < 0);


                if(opcion == 1){
                    strcpy(prod_pedidos[i].estado, "entregado");
                    prod_pedidos[i].unidades--;
                    printf("\n\n\t\tNuevo estado del producto: %s\n", prod_pedidos[i].estado);
                    printf("\t\tUnidades restantes: %i\n\n", prod_pedidos[i].unidades);
                }

                if(opcion == 0){
                    strcpy(prod_pedidos[i].estado, "devuelto");
                    printf("\n\n\t\tNuevo estado del producto: %s\n\n", prod_pedidos[i].estado);
                }
            }
        }

    }

    if(cont == 0)printf("\n\n\t\tNo tiene ningun producto en reparto con esos datos.\n\n");
    return prod_pedidos;
}


void asignar_codigo_locker(Transportista* transportista, ProductosPedidos* productospedidos, Pedidos* pedidos,
                           CompartimentosLockers* compartimentoslockers,Lockers* lockers, int n_productospedidos,
                            int n_pedidos,int n_compartimentoslockers, int n_lockers, int posicion_usuario){

    int id_pedido_trans, id_producto_trans;
    int cod_locker;
    int i, j, k, m, cont;

    cont = 0;

    printf("\n\n\t\tIntroduce el id del pedido al que quiere asignar un locker: ");
    scanf("%i", &id_pedido_trans);

    printf("\n\n\t\tIntroduce el id del producto al que quiere asignar un locker: ");
    scanf("%i", &id_producto_trans);

    //Para asignar un codigo locker, hacemos las mismas comprobaciones que en la funcion anterior. Asi nos aseguramos que
    //los cambios realizados afectan a un pedido que se encuentra en reparto y que realmente pertenece al transportista que
    //ha inicidado sesion
    //Modificamos el numero de lockers ocupados (uno mas), su estado (que pasamos a "ocupado") y asignamos fecha de ocupacion y de
    //caducidad.
    //Por ultimo asignamos el codigo locker al producto en cuestion y cambiamos su estado a "enLocker"

    for(i = 0; i < n_productospedidos; i++){

        if(productospedidos[i].id_transportista == transportista[posicion_usuario].id &&
           strcmp(productospedidos[i].estado, "enReparto") == 0 && productospedidos[i].unidades > 0){

            if(productospedidos[i].id_pedido == id_pedido_trans && productospedidos[i].id_producto == id_producto_trans){

                printf("\n\n\t\tIntroduce el codigo locker para el producto: ");
                scanf("%i", &cod_locker);

                for(j = 0; j < n_compartimentoslockers; j++){

                    if(cod_locker == compartimentoslockers[j].codigo && strcmp(compartimentoslockers[j].estado, "vacio") == 0){

                        strcpy(compartimentoslockers[j].estado, "ocupado");

                        system("cls");

                        printf("\n\n\t\tIntroduce la fecha en la que el locker ha sido ocupado (dd-mm-aaaa): ");
                        fflush(stdin);
                        gets(compartimentoslockers[j].fecha_asignacion);

                        printf("\n\n\t\tIntroduce la fecha de caducidad para la recogida (dd-mm-aaaa): ");
                        fflush(stdin);
                        gets(compartimentoslockers[j].fecha_caducidad);


                        for(k = 0; k < n_lockers; k++){

                            if(compartimentoslockers[j].id == lockers[k].id){

                                lockers[k].ocupados = lockers[k].ocupados + 1;

                                for(m = 0; m < n_pedidos; m++){

                                    if(pedidos[m].id == id_pedido_trans){

                                        strcpy(pedidos[m].id_locker, lockers[k].id);
                                    }
                                }
                            }
                        }

                        for(k = 0; k < n_productospedidos; k++){

                            if(productospedidos[k].id_pedido == id_pedido_trans){

                                productospedidos[k].codigo = cod_locker;

                                strcpy(productospedidos[k].estado, "enLocker");

                                cont++;
                            }
                        }
                    }
                }
            }
        }
    }


    if(cont == 0) printf("\n\n\t\tOperacion no valida. El compartimento locker no es valido o el producto introducido es "
                         "incorrecto.\n\n\n");

    if(cont != 0) printf("\n\n\t\tLocker asignado con exito.\n\n\n");

}


//Esta funcion permite consultar el contenido de los lockers
void consulta_lockers_localidad(Lockers* lockers, Pedidos* pedidos, ProductosPedidos* productospedidos, Productos* productos,
                                int n_lockers, int n_pedidos, int n_productospedidos, int n_productos){


    char localidad[50];
    int i, j, k, m, cont;
    int comprueba_lockers;     //sirve para determinar si en la localidad consultada hay lockers o no

    cont = 0;
    comprueba_lockers = 0;

    system("cls");

    printf("\n\n\t\tIntroduce la localidad: ");
    fflush(stdin);
    gets(localidad);

    //Si la localidad introducida por el usuario coincide con una que tiene lockers, este bucle se ejecuta para mostrar
    //los productos que se encuentran con estado "enLocker", a partir del id del locker y el codigo locker del compartimento

    for(i = 0; i < n_lockers; i++){

        if(strcmp(localidad, lockers[i].localidad) == 0){

            comprueba_lockers++;

            for(j = 0; j < n_pedidos; j++){

                if(strcmp(lockers[i].id, pedidos[j].id_locker) == 0){

                    for(k = 0; k < n_productospedidos; k++){

                        if(pedidos[j].id == productospedidos[k].id_pedido && strcmp(productospedidos[k].estado, "enLocker" ) == 0){

                            for(m = 0; m < n_productos; m++){

                                    if(productos[m].id == productospedidos[k].id_producto){

                                        printf("\n\n\t\t%s\n", lockers[i].id);
                                        printf("\n\t\t\tPedido con id %d: %s\n\n", productospedidos[k].id_pedido, productos[m].descripcion);
                                        cont++;
                                    }
                            }
                        }
                    }
                }
           }
        }
    }

    if(cont == 0 && comprueba_lockers != 0) printf("\n\n\t\tTodos los lockers de esta localidad estan vacios.\n\n");
    if(cont == 0 && comprueba_lockers == 0) printf("\n\n\t\tNo hay lockers disponibles en esta localidad.\n\n");
}



//esta funcion sirve para modificar el estado de los productos, el stock de los mismos, modificar el numero de compartimentos
//ocupados y eliminar el codigo locker asociado a los productos.
//Todo esto cuando el transportista recoge un producto de un locker.
void actualizar_estado_lockers(Transportista* transportista, ProductosPedidos* productospedidos,
                               CompartimentosLockers* compartimentoslockers, Lockers* lockers, int n_productospedidos,
                               int n_compartimentoslockers, int n_lockers, int posicion_usuario){

    int id_pedido_trans, id_producto_trans;
    int i, j, k, cont;

    cont = 0;

    system("cls");

    printf("\n\n\t\tIntroduce el id del pedido que quiere recoger del locker: ");
    scanf("%i", &id_pedido_trans);

    printf("\n\n\t\tIntroduce el id del producto: ");
    scanf("%i", &id_producto_trans);


    for(i = 0; i < n_productospedidos; i++){

        if(productospedidos[i].id_transportista == transportista[posicion_usuario].id &&
           strcmp(productospedidos[i].estado, "enLocker") == 0 && productospedidos[i].unidades > 0){

            if(productospedidos[i].id_pedido == id_pedido_trans && productospedidos[i].id_producto == id_producto_trans){

                strcpy(productospedidos[i].estado, "devuelto");
                productospedidos[i].unidades++;

                for(j = 0; j < n_compartimentoslockers; j++){

                    if(productospedidos[i].codigo == compartimentoslockers[j].codigo){

                        compartimentoslockers[j].codigo = 0;
                        strcpy(compartimentoslockers[j].estado, "vacio");
                        productospedidos[i].codigo = 0;

                        for(k = 0; k < n_lockers; k++){

                            if(strcmp(compartimentoslockers[j].id, lockers[k].id) == 0){

                                lockers[k].ocupados--;

                                printf("\n\n\t\tEl estado del producto y del locker se ha actualizado con exito.\n\n");

                                cont++;
                            }
                        }
                    }
                }
            }
        }
    }

    if(cont == 0) printf("\n\n\t\tLa informacion que has introducido no es correcta.\n\n\n");

}

ProductosPedidos* alta_pedidos_admin(ProductosPedidos* productos,int *n_productospedidos){


    int i = *n_productospedidos;

    productos = (ProductosPedidos*)realloc(productos, (i + 1) * sizeof(ProductosPedidos));
    productos[i].id_pedido = i + 1;

    printf("\n\t Introduzca los siguientes datos: \n");

    printf("\n\t\tIdentificador del producto: ");
    scanf("%d", &productos[i].id_producto);

    printf("\n\t\tNumero de unidades: ");
    scanf("%d", &productos[i].unidades);

    printf("\n\t\tFecha prevista de entrega (dd-mm-aaaa): ");
    fflush(stdin);
    gets(productos[i].fecha_prevista);

    printf("\n\t\tImporte del producto: ");
    scanf("%d", &productos[i].importe);

    printf("\n\t\tEstado del envio (enPreparacion, enviado, etc): ");
    fflush(stdin);
    gets(productos[i].estado);

    printf("\n\t\tIdentificador del transportista: ");
    scanf("%d", &productos[i].id_transportista);

    printf("\n\t\tCodigo locker: ");
    scanf("%d", &productos[i].codigo);

    printf("\n\t\tFecha de entrega: ");
    fflush(stdin);
    gets(productos[i].fecha_transportista);

    printf("\n\n");
    system("pause");
    system("cls");

    *n_productospedidos = *n_productospedidos + 1;


    return productos;
}



ProductosPedidos* baja_pedidos_admin(ProductosPedidos* productos,int *n_productospedidos){

    int i, j, cont=1;
    int id_pedido, id_producto;

    printf("Introduce el id del pedido: ");
    scanf("%d", &id_pedido);

    printf("Introduce el id del producto: ");
    scanf("%d", &id_producto);

    for(j = 0; j < *n_productospedidos; j++){

        if(productos[j].id_pedido == id_pedido && productos[j].id_producto == id_producto)

            for(i = j; i < *n_productospedidos; i++)

                productos[i].id_pedido = productos[i + cont].id_pedido;
                productos[i].id_producto = productos[i + cont].id_producto;
                productos[i].unidades = productos[i + cont].unidades;
                strcpy(productos[i].fecha_prevista,productos[i+cont].fecha_prevista);
                productos[i].importe = productos[i + cont].importe;
                strcpy(productos[i].estado,productos[i+cont].estado);
                productos[i].id_transportista = productos[i + cont].id_transportista;
                productos[i].codigo = productos[i + cont].codigo;
                strcpy(productos[i].fecha_transportista,productos[i+cont].fecha_transportista);
    }

    *n_productospedidos = *n_productospedidos - 1;

    productos = (ProductosPedidos*)realloc(productos, (i -1) * sizeof(ProductosPedidos));

    return productos;
}



void realizar_pedido_cliente(Cliente* clientes, Productos* productos, DescuentosClientes* descuentosclientes,
                             Descuentos* descuentos, int n_descuentosclientes, int n_productos, int n_descuentos, int pos_vector){

    int i, j, k, cont;
    char compra[50], cod_promocional[50];
    char opcion;
    int importe_final;

    printf("\n\t\tIntroduce el nombre del producto que quieres comprar: ");
    fflush(stdin);
    gets(compra);

    cont = 0;

    for(i = 0; i < n_productos; i++){

        if(strcmp(compra, productos[i].descripcion) == 0){


                printf("\n\t\tTe gustaria aplicar un codigo promocional?: ");

                do{
                    fflush(stdin);
                    scanf("%c", &opcion);
                }while(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

                if(opcion == 's' || opcion == 'S'){

                    printf("\n\t\tIntroduce tu codigo promocional: ");
                    fflush(stdin);
                    gets(cod_promocional);

                    for(j = 0; j < n_descuentosclientes; j++){

                        if(clientes[pos_vector].id == descuentosclientes[j].id &&
                            strcmp(cod_promocional, descuentosclientes[j].codigo) == 0 && descuentosclientes[j].estado == 0){

                            for(k = 0; k < n_descuentos; k++){

                                if(strcmp(descuentosclientes[j].codigo, descuentos[k].id)){

                                    importe_final = productos[i].importe - descuentos[k].importe;

                                    if(clientes[pos_vector].cartera >= importe_final){

                                        printf("\n\t\tLa operacion se ha realizado con exito.\nEl importe "
                                               "final son %d euros\n\n", importe_final);

                                        productos[i].stock--;

                                        cont = 1;

                                        //falta escribir una nueva linea en el fichero productospedidos

                                    }

                                }
                            }
                        }
                    }

                }
        }
    }

    if(cont == 0) printf("\n\t\tOperacion no valida con los datos introducidos.\n\n");
}



void comprobar_estado_productos_cliente(Pedidos* pedidos, Cliente* cliente, ProductosPedidos* productospedidos,
                                        Productos* productos, int n_productospedidos, int n_productos,
                                        int n_pedidos, int pos_vector){

    int i, j, k;

    for(i = 0; i < n_pedidos; i++){

        if(cliente[pos_vector].id == pedidos[i].id_cliente)

        for(j = 0; j < n_productospedidos; j++){

            if(pedidos[i].id == productospedidos[j].id_pedido)

            for(k = 0; k < n_productos; k++){

                if(productospedidos[j].id_producto == productos[k].id)

                    printf("\n\t\t%s: %s\n\n", productos[k].descripcion,productospedidos[j].estado);
            }
        }
    }
}




void realizar_devolucion_cliente(Productos* productos, ProductosPedidos* productospedidos, Pedidos* pedidos,
                                 Cliente* cliente, Devoluciones* devoluciones, int n_productos, int n_productospedidos,
                                 int n_pedidos, int n_devoluciones, int pos_vector){

    int i, j, k, m;
    char producto_devolucion[50], motivo[200];
    char opcion;

    printf("\n\t\tIntroduce el nombre del producto que quieres devolver: ");
    fflush(stdin);
    gets(producto_devolucion);

    for(i = 0; i < n_productos; i++)

        if(strcmp(producto_devolucion, productos[i].descripcion) == 0)

            for(j = 0; j < n_productospedidos; j++)

                if(productospedidos[j].id_producto == productos[i].id)

                    for(k = 0; k < n_pedidos; k++)

                        if(productospedidos[j].id_pedido == pedidos[k].id && pedidos[k].id_cliente == cliente[pos_vector].id)

                            printf("\n\t\tTe gustaria devolver este articulo?");

                            do{
                                fflush(stdin);
                                scanf("%c", &opcion);
                            }while(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

                            if(opcion == 's' || opcion == 'S'){


                                        printf("\n\t\tIntroduce el motivo de la devolucion: ");
                                        fflush(stdin);
                                        gets(motivo);

                                        //aqui hay que añadir una linea al fichero devoluciones con

                                        //strcpy(devoluciones[m].motivo, motivo);
                                        //strcpy(devoluciones[m].estado, "pendiente");
                                        //printf("\n\t\tEstado cambiado a pendiente de aceptacion\n\n");

                                        printf("\n\t\tDevolucion realizada con exito\n\n");
                                    }
}





void seguimiento_devoluciones_pendientes(Pedidos* pedidos, ProductosPedidos* productospedidos, Devoluciones* devoluciones,
                                         Productos* productos, int n_productospedidos, int n_devoluciones, int n_productos,
                                         int pos_vector){

    int i, j, k;

    for(i = 0; i < n_productospedidos; i++){

        if(pedidos[pos_vector].id == productospedidos[i].id_pedido)

            for(j = 0; j < n_devoluciones; j++)

                if(productospedidos[i].id_pedido == devoluciones[j].id_pedido &&
                   productospedidos[i].id_producto == devoluciones[j].id_producto &&
                   strcmp(devoluciones[j].estado, "pendiente") == 0)

                   for(k = 0; k < n_productos; k++)

                        if(productospedidos[i].id_producto == productos[k].id){

                            printf("\n\t\tEstado de %s: %s\n\n", productos[k].descripcion, devoluciones[j].estado);

                        }
    }
}


