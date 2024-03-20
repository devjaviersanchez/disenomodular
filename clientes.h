#ifndef __CLIENTES_H__
#define __CLIENTES_H__

typedef struct {
	int id_cliente;
	char nomb_cliente[20];
	char dir_cliente[50];
	char localidad[20];
    char provincia[20];
	char email[30];
    char contrasena[15];
    int cartera;
}Cliente;

//cabecera:void LeerClientes(Cliente* ,int*);
//Precondicion: clientes.txt existe y tiene datos
//Postcondicion: guarda los datos de clientes.txt en clientes
void LeerClientes(Cliente* );

//cabecera:void EscribirClientes(Cliente*,int)
//PrecondiciOn: clientes existe y tiene datos
//PostcondiciOn: guarda los datos de clientes en clientes.txt
void EscribirClientes(Cliente*,int);

//cabecera:void MostrarClientes(Cliente *,int )
//Precondicion: clientes y n_clientes inicializados
//Postcondicion: muestra los clientes
void MostrarClientes(Cliente *,int );

#endif
