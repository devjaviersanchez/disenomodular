
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datos.h"
#include "perfiles.h"

void iniciar_sesion(
    int n_c, int n_a, int n_t, Cliente *c, AdminProv *a, Transportista *t,
    int* tipo, char *correo, int* pos
)
{
    char usuario[30], password[10];
    int i;
    int aux = 0;

    system("cls");
    system("pause");

    printf("\n\t\tCorreo o email: ");
    fflush(stdin);
    gets(usuario);

    printf("\n\t\tPassword: ");
    fflush(stdin);
    gets(password);

    for (i=0;i<n_c;i++) {  // USUARIO

        if(strcmp(usuario,c[i].email) == 0) {
            strcpy(correo,c[i].email);
            aux=1;
        }

        if(aux == 1 && strcmp(c[i].contrasena,password) == 0){
            *tipo=1;
            *pos=i;
        }
    }

    for (i=0;i<n_a;i++) {   // ADMINISTRADOR

        if(strcmp(usuario,a[i].email) == 0) {
            strcpy(correo,a[i].email);
            aux=1;
        }

        if(aux==1 && strcmp(a[i].contrasena,password)==0) {

            if(strcmp(a[i].perfil,"admin") == 0) *tipo=2;
            else *tipo=3;

            *pos=i;
        }
    }

    for (i=0;i<n_t;i++) {   // TRANSPORTISTA

        if(strcmp(usuario,t[i].email)==0) {
            strcpy(correo,t[i].email);
            aux=1;
        }

        if(aux==1 && strcmp(t[i].contrasena,password)==0) {
            *tipo=4;
            *pos=i;
        }
    }

    system("pause");
}


void menu_inicial(
    int *n_c,int n_a,int n_t,Cliente **clt, AdminProv *adm,
    Transportista *tsp, int*type_user, char*name_user, int* pos_vector,int*atras
)
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
            case 1:
                {
                    iniciar_sesion(*n_c,n_a,n_t,*clt,adm,tsp,&aux_type,aux_name,&aux_pos);
                    strcpy(name_user,aux_name);
                    *type_user=aux_type;
                    *pos_vector=aux_pos;

                    if(*type_user == 1 || *type_user == 2 || *type_user == 3 || *type_user == 4) {

                        opcion=3;

                        switch (*type_user){
                            case 1:
                                {
                                    system("cls");
                                    printf("\n\t\t\t Bienvenido %s ,cliente, %i: \n\n\n\n",name_user,*pos_vector+1);
                                    system("pause");
                                }break;
                            case 2:
                                {
                                    system("cls");
                                    printf("\n\t\t\t Bienvenido %s ,administrador, %i: \n\n\n\n",name_user,*pos_vector+1);
                                    system("pause");
                                }break;
                            case 3:
                                {
                                    system("cls");
                                    printf("\n\t\t\t Bienvenido %s ,proveedor, %i: \n\n\n\n",name_user,*pos_vector+1);
                                    system("pause");
                                }break;
                            case 4:
                                {
                                    system("cls");
                                    printf("\n\t\t\t Bienvenido %s ,transportista, %i: \n\n\n\n",name_user,*pos_vector+1);
                                    system("pause");
                                }break;
                        }
                    }
                }break;
            case 2:
                {

                    system("cls");

                    // Implementar Alta_cliente
                    // (*clt) = (Cliente*) realloc((*clt), (*n_c+ 1) * sizeof(Cliente));
                    // Alta_Cliente(*clt,n_c);

                    puts("\n\n\n\n\n\n\n\n\n");
                    MostrarClientes(*clt,*n_c);
                    system("pause");
                }break;

        }

    } while(opcion!=3);

    system("cls");
}
