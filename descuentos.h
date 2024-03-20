#ifndef __DESCUENTOS_H__
#define __DESCUENTOS_H__

typedef struct {
	char id_cod[10];
	char descripcion[50];
	char tipo[10];
	char estado[15];
	int importe;
	char aplicabilidad[15];
}Descuentos;

typedef struct {
	int id_cliente;
	char id_cod[10];
	char fecha_asignacion[11];
	char fecha_caducidad[11];
	int estado;
}DescuentosClientes;

//cabecera:Descuentos* LeerDescuentos(Descuentos*,int*);
//Precondicion: descuentos.txt existe y tiene datos
//Postcondicion: guarda los datos de descuentos.txt en descuentos
void LeerDescuentos(Descuentos*);

//cabecera:void MostrarDescuentos(Descuentos* ,int)
//Precondicion: descuentos y n_descuentos inicializados
//Postcondicion: muestra los descuentos
void MostrarDescuentos(Descuentos* ,int);

//cabecera:void EscribirDescuentos(Descuentos*,int);
//Precondicion: descuentos existe y tiene datos
//Postcondicion: guarda los datos de descuentos en descuentos.txt
void EscribirDescuentos(Descuentos*,int);

//cabecera:DescuentosClientes* LeerDescuentosClientes(DescuentosClientes*,int*);
//Precondicion: descuentosclientes.txt existe y tiene datos
//Postcondicion: guarda los datos de descuentosclientes.txt en descuentosclientes
void LeerDescuentosClientes(DescuentosClientes*);

//cabecera:void MostrarDescuentosClientes(DescuentosClientes*,int)
//Precondicion: descuentosclientes y n_descuentosclientes inicializados
//Postcondicion: muestra los descuentosclientes
void MostrarDescuentosClientes(DescuentosClientes*,int);

//cabecera:void EscribirDescuentosClientes(DescuentosClientes*,int);
//Precondicion: descuentosclientes existe y tiene datos
//Postcondicion: guarda los datos de descuentosclientes en descuentosclientes.txt
void EscribirDescuentosClientes(DescuentosClientes*,int);


#endif
