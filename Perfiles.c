#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Datos.h"
#include "Perfiles.h"


void iniciar_sesion(int n_c,int n_a,int n_t,Cliente *c, AdminProv *a, Transportista *t, int* tipo, char *correo, int* pos)
{
    char usuario[30], password[10];
    int i,aux=0;

                system("cls");
                system("cls");
                system("pause");
                printf("\n\t\tCorreo o email: ");
                fflush(stdin);
                gets(usuario);
                printf("\n\t\tPassword: ");
                fflush(stdin);
                gets(password);
                for(i=0;i<n_c;i++)  //USUARIO//
                {
                if(strcmp(usuario,c[i].email)==0)
                {
                strcpy(correo,c[i].email);
                aux=1;
                }
                if(aux==1 && strcmp(c[i].contrasena,password)==0)
                {
                *tipo=1;
                *pos=i;
                }
                }
                for(i=0;i<n_a;i++)   //ADMINISTRADOR//
                {
                if(strcmp(usuario,a[i].email)==0)
                {
                strcpy(correo,a[i].email);
                aux=1;
                }
                if(aux==1 && strcmp(a[i].contrasena,password)==0)
                {
                if(strcmp(a[i].tipo,"admin")==0) {*tipo=2;}
                else{*tipo=3;}
                *pos=i;

                }
                }
                for(i=0;i<n_t;i++)   //TRANSPORTISTA//
                {
                if(strcmp(usuario,t[i].email)==0)
                {
                strcpy(correo,t[i].email);
                aux=1;
                }
                if(aux==1 && strcmp(t[i].contrasena,password)==0)
                {
                *tipo=4;
                *pos=i;
                }
                }
                system("pause");

}

/* n_clientes,
n_adminprov,
n_transportistas,
&clientes,
adminprov,
transportistas,
&tipo_usuario,
usuario_actual,
&posicion_vector,
&atras; */
void menu_usuario(int *n_c,int n_a,int n_t,Cliente **clt, AdminProv *adm, 
Transportista *tsp, int*type_user, char*name_user, int* pos_vector,int*atras)
{
    char aux_name[30];
    int aux_type,aux_pos,opcion;
    do {//system("cls");

    puts("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
    printf("\t\t\tMENU DE USUARIOS:\n");
    puts("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
    puts("\n");


        printf("\n\t\t\t1-Iniciar sesion. \n");
        printf("\n\t\t\t2-Registrarse\n");
        printf("\n\t\t\t3-Salir.\n\n");
        puts("\n");
        puts("------------------------------------------------------------------------------------------------------------------------");
        puts("\n");
        printf("\n\t\t\tElija su opcion:");
        scanf("%i",&opcion);
        fflush(stdin);
        *atras=opcion;
        switch (opcion) {
            case 1:{
                iniciar_sesion(*n_c,n_a,n_t,*clt,adm,tsp,&aux_type,aux_name,&aux_pos);
                strcpy(name_user,aux_name);
                *type_user=aux_type;
                *pos_vector=aux_pos;
                if(*type_user==1 || *type_user==2 || *type_user==3 || *type_user==4)
                {
                    opcion=3;
                    switch(*type_user)
                    {
                        case 1:
                                {   system("cls");
                                    printf("\n\t\t\t Bienvenido %s ,cliente, %i: \n\n\n\n",name_user,*pos_vector+1);
                                    system("pause");}break;
                        case 2:
                                {   system("cls");
                                    printf("\n\t\t\t Bienvenido %s ,administrador, %i: \n\n\n\n",name_user,*pos_vector+1);
                                    system("pause");}break;
                        case 3:
                                {   system("cls");
                                    printf("\n\t\t\t Bienvenido %s ,proveedor, %i: \n\n\n\n",name_user,*pos_vector+1);
                                    system("pause");}break;
                        case 4:
                                {   system("cls");
                                    printf("\n\t\t\t Bienvenido %s ,transportista, %i: \n\n\n\n",name_user,*pos_vector+1);
                                    system("pause");}break;
                    }
                }
                }break;
            case 2:{system("cls");(*clt) = (Cliente*)realloc((*clt), (*n_c+ 1) * sizeof(Cliente));Alta_Cliente(*clt,n_c); puts("\n\n\n\n\n\n\n\n\n");MostrarClientes(*clt,*n_c); system("pause"); }break;

}
    } while(opcion!=3);
    system("cls");


return clt;
}
void Alta_Cliente(Cliente*clientes,int *n_clientes){  //Alta Cliente.//
    int i=*n_clientes,id;
    printf("\n\t Introduzca los siguientes datos: \n");
    do{
    printf("\n\t Introduzca el id del cliente: \n");
    fflush(stdin);
    scanf("%d",&id);
    }while(Buscar_Cliente(clientes,*n_clientes,id)!=0);
  clientes[i].id=id;

    printf("\n\t\t Nombre :\n");
    fflush(stdin);
    gets(clientes[i].nombre);
    printf("\n\t\t Apellido :\n");
    fflush(stdin);
    gets(clientes[i].apellido);
    printf("\n\t\t Direccion :\n");
    fflush(stdin);
    gets(clientes[i].direccion);
    printf("\n\t\t Localidad :\n");
    fflush(stdin);
    gets(clientes[i].localidad);
    printf("\n\t\t Provincia :\n");
    fflush(stdin);
    gets(clientes[i].provincia);
    printf("\n\t\t Email :\n");
    fflush(stdin);
    gets(clientes[i].email);
    printf("\n\t\t Password :\n");
    fflush(stdin);
    gets(clientes[i].contrasena);
    clientes[i].cartera=0;
    *n_clientes=i+1;

}
void Alta_AdminProv(AdminProv* adminyprov,int *n_adminprov,char* tipo){  //Alta Administradores y Proveedores.//

    char aux[6];
    int i=*n_adminprov,id;
    strcpy(adminyprov[i].tipo,tipo);
    do{
    printf("\n\t Introduzca el id del adminprov: \n");
    printf("\n\t\t Adminprov :\n");
    fflush(stdin);
    scanf("%d",&id);
    }while(Buscar_AdminProv(adminyprov,*n_adminprov,id)==0);
    adminyprov[i].id=id;

    if(entero(aux)==1){
        strcpy(adminyprov[i].empresa,"ESIZON");
    }else{
    printf("\n\t\t Nombre de la empresa :\n");
    fflush(stdin);
    gets(adminyprov[i].empresa);
    }
    printf("\n\t\t Email :\n");
    fflush(stdin);
    gets(adminyprov[i].email);
    printf("\n\t\t Password :\n");
    fflush(stdin);
    gets(adminyprov[i].contrasena);

    *n_adminprov=i+1;
}
void Alta_Transportista(Transportista* transportistas,int *n_transportistas){  //Alta Transportista.//
    int i=*n_transportistas,id;
     do{
    printf("\n\t Introduzca el id del adminprov: \n");
    printf("\n\t\t Adminprov :\n");
    fflush(stdin);
    scanf("%d",&id);
    }while(Buscar_Transportista(transportistas,*n_transportistas,id)!=0);
    transportistas[i].id=id;
    printf("\n\t Introduzca los siguientes datos: \n");
    printf("\n\t\t Email :\n");
    fflush(stdin);
    gets(transportistas[i].email);
    printf("\n\t\t Password :\n");
    fflush(stdin);
    gets(transportistas[i].contrasena);
    printf("\n\t\t Nombre de la empresa :\n");
    fflush(stdin);
    gets(transportistas[i].empresa);
    printf("\n\t\t Ciudad :\n");
    fflush(stdin);
    gets(transportistas[i].ciudad);

    *n_transportistas=i+1;
}
void Baja_Cliente(Cliente* clientes,int *n_clientes, int pos){  //Baja Cliente.//
    int i=*n_clientes,j,cont=1;

    for(j=pos;j<i;j++)
    {
        clientes[j].id=clientes[j+cont].id;
        strcpy(clientes[j].nombre,clientes[j+cont].nombre);
        strcpy(clientes[j].apellido,clientes[j+cont].apellido);
        strcpy(clientes[j].direccion,clientes[j+cont].direccion);
        strcpy(clientes[j].localidad,clientes[j+cont].localidad);
        strcpy(clientes[j].provincia,clientes[j+cont].provincia);
        strcpy(clientes[j].email,clientes[j+cont].email);
        strcpy(clientes[j].contrasena,clientes[j+cont].contrasena);
        clientes[j].cartera=clientes[j+cont].cartera;

    }
    *n_clientes=i-1;
}
void Baja_AdminProv(AdminProv* adminyprov,int *n_adminprov, int pos,char* tipo){  //Baja Administrador o Proveedor.//
    if (strcmp(adminyprov[pos].tipo,tipo)==0){
    int i=*n_adminprov,j,cont=1;
    for(j=pos;j<i;j++)
    {
        adminyprov[j].id=adminyprov[j+cont].id;
        strcpy(adminyprov[j].empresa,adminyprov[j+cont].empresa);
        strcpy(adminyprov[j].email,adminyprov[j+cont].email);
        strcpy(adminyprov[j].contrasena,adminyprov[j+cont].contrasena);
        strcpy(adminyprov[j].tipo,adminyprov[j+cont].tipo);

    }
    *n_adminprov=i-1;
    }
}
void Baja_Transportista(Transportista* transportistas,int *n_transportistas, int pos){  //Baja Transportista.//
    int i=*n_transportistas,j,cont=1;

    for(j=pos;j<i;j++)
    {

        transportistas[j].id=transportistas[j+cont].id;
        strcpy(transportistas[j].email,transportistas[j+cont].email);
        strcpy(transportistas[j].contrasena,transportistas[j+cont].contrasena);
        strcpy(transportistas[j].empresa,transportistas[j+cont].empresa);
        strcpy(transportistas[j].ciudad,transportistas[j+cont].ciudad);


    }
    *n_transportistas=i-1;
}


void Modificar_Cliente(Cliente* clientes, int pos){

    system("cls");
    int aux2;
    char opcion, aux[50];

    do{
        printf("\n\t\t �Que campo desea modificar?. \n");
        printf("\n\t\t 1. Nombre.\n");
        printf("\n\t\t 2. Apellido.\n");
        printf("\n\t\t 3. Direccion.\n");
        printf("\n\t\t 4. Localidad.\n");
        printf("\n\t\t 5. Provincia.\n");
        printf("\n\t\t 6. Email.\n");
        printf("\n\t\t 7. Password.\n");
        printf("\n\t\t 8. Cartera.\n");
        printf("\n\n\n\t\t 9. Salir.\n");

        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo Nombre:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(clientes[pos].nombre,aux);};break;

            case 2: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo Apellido:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(clientes[pos].apellido,aux);};break;

            case 3: { system("pause");
                      system("cls");
                      printf("\n\t Escriba la nueva Direccion:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(clientes[pos].direccion,aux);};break;
            case 4: { system("pause");
                      system("cls");
                      printf("\n\t Escriba la nueva Localidad:\n");
                      gets("aux");
                      fflush(stdin);
                      strcpy(clientes[pos].localidad,aux);};break;

            case 5: { system("pause");
                      system("cls");
                      printf("\n\t Escriba la nueva Provincia:\n");
                      gets("aux");
                      fflush(stdin);
                      strcpy(clientes[pos].provincia,aux);};break;

            case 6: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo Email\n");
                      gets("aux");
                      fflush(stdin);
                      strcpy(clientes[pos].email,aux);};break;
            case 7: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo Password:\n");
                      gets("aux");
                      fflush(stdin);
                      strcpy(clientes[pos].contrasena,aux);};break;

            case 8: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo Nombre:\n");
                      scanf("%i",&aux2);
                      fflush(stdin);
                      clientes[pos].cartera=aux2; };break;
        }

    }while(opcion!=9);
    //return clientes;
}

void Modificar_AdminProv(AdminProv* adminyprov, int pos){

    system("cls");
    int aux2;
    char opcion, aux[50];


    do{
        printf("\n\t\t �Que campo desea modificar?. \n");
        printf("\n\t\t 1. Nombre de la empresa.\n");
        printf("\n\t\t 2. Email.\n");
        printf("\n\t\t 3. Password.\n");
        printf("\n\n\n\t\t 4. Salir.\n");

        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo nombre de la empresa:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(adminyprov[pos].empresa,aux);};break;

            case 2: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo Email:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(adminyprov[pos].email,aux);};break;

            case 3: { system("pause");
                      system("cls");
                      printf("\n\t Escriba la nueva Password:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(adminyprov[pos].contrasena,aux);};break;

        }

    }while(opcion!=4);
    //return adminyprov;
}

void Modificar_Transportista(Transportista* transportistas, int pos){

    system("cls");
    int opcion;
    char  aux[50];


    do{
        printf("\n\t\t �Que campo desea modificar?. \n");
        printf("\n\t\t 1. Email.\n");
        printf("\n\t\t 2. Password.\n");
        printf("\n\t\t 3. Empresa.\n");
        printf("\n\t\t 4. Ciudad.\n");
        printf("\n\n\n\t\t 5. Salir.\n");

        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo Email:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(transportistas[pos].email,aux);};break;

            case 2: { system("pause");
                      system("cls");
                      printf("\n\t Escriba la nueva Password:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(transportistas[pos].contrasena,aux);};break;

            case 3: { system("pause");
                      system("cls");
                      printf("\n\t Escriba el nuevo nombre de la empresa:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(transportistas[pos].empresa,aux);};break;

            case 4: { system("pause");
                      system("cls");
                      printf("\n\t Escriba la nueva Ciudad:\n");
                      gets(aux);
                      fflush(stdin);
                      strcpy(transportistas[pos].ciudad,aux);};break;


        }

    }while(opcion!=5);
//return transportistas;
}
void Consulta_Cliente(Cliente* clientes, int pos){
        system("cls");

        printf("\n\t\t 1. Nombre: %s\n",clientes[pos].nombre);
        printf("\n\t\t 2. Apellido: %s\n",clientes[pos].apellido);
        printf("\n\t\t 3. Direccion: %s\n",clientes[pos].direccion);
        printf("\n\t\t 4. Localidad: %s\n",clientes[pos].localidad);
        printf("\n\t\t 5. Provincia: %s\n",clientes[pos].provincia);
        printf("\n\t\t 6. Email: %s\n",clientes[pos].email);
        printf("\n\t\t 7. Cartera: %i euros\n",clientes[pos].cartera);

}
void Consulta_AdminProv(AdminProv* adminyprov, int pos){

        system("cls");

        printf("\n\t\t 1. Empresa: %s\n",adminyprov[pos].empresa);
        printf("\n\t\t 2. Email: %s\n",adminyprov[pos].email);
        printf("\n\t\t 3. Tipo: %s\n",adminyprov[pos].tipo);

}
void Consulta_Transportista(Transportista* transportistas, int pos){

        system("cls");

        printf("\n\t\t 1. Email: %s\n",transportistas[pos].email);
        printf("\n\t\t 2. Empresa: %s\n",transportistas[pos].empresa);
        printf("\n\t\t 3. Ciudad: %s\n",transportistas[pos].ciudad);

}
int Buscar_Cliente(Cliente* clientes, int n_clientes,int id)
{
    int i,cont=0;
    for (i=0;i<n_clientes;i++)
    {
        printf("%d",clientes[i].id);
        if(clientes[i].id==id)cont++;
    }
return cont;
}
int Buscar_AdminProv(AdminProv* adminyprov, int n_adminprov,int id)
{
    int i,cont=0;
    char email[30];
    for (i=0;i<n_adminprov;i++)
    {
        if(adminyprov[i].id=id)cont++;
    }
    return cont;
}
int Buscar_Transportista(Transportista* transportistas, int n_transportistas,int id)
{
    int i,cont=0;
    char email[30];

    for (i=0;i<n_transportistas;i++)
    {
        if(transportistas[i].id==id)cont++;
    }
    return cont;
}

void actualizar_cartera(Cliente* clientes,int posicion_vector){
    char x[10];
    int i=clientes[posicion_vector].cartera;
    do{
    printf("\n\t\t introduce el importe a a�adir a la cartera:\n");
    fflush(stdin);
    gets(x);
    }while(entero(x)<0);
    clientes[posicion_vector].cartera= i + entero(x);
    return clientes;
}

void inicilizar (Cliente**clientes){
Cliente copia[2];
copia[0]=*clientes[0];
copia[1]=*clientes[1];
(*clientes)= (Cliente*)calloc(3,sizeof(Cliente));
(*clientes[0])=copia[0];
(*clientes[1])=copia[1];
}
