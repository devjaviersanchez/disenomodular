#ifndef __ADMINPROV_H__
#define __ADMINPROV_H__

typedef struct {
	int id_empresa;
	char nombre[20];
	char email[30];
    char contrasena[15];
    char perfil[20];
}AdminProv;

//cabecera:void void LeerAdminProv(AdminProv *,int*);
//Precondicion: adminprov.txt existe y tiene datos
//Postcondicion: guarda los datos de adminprov.txt en adminprov
void LeerAdminProv(AdminProv *);

//cabecera:void MostrarAdminProv(AdminProv *,int )
//Precondicion: AdminProv y n_adminprov inicializados
//Postcondicion: muestra los adminprov
void MostrarAdminProv(AdminProv *,int );

//cabecera:void EscribirAdminProv(AdminProv*,int)
//Precondicion: adminprov existe y tiene datos
//Postcondicion: guarda los datos de adminprov en adminprov.txt
void EscribirAdminProv(AdminProv*,int);

int Buscar_AdminProv(AdminProv* adminyprov, int n_adminprov,int id, char* perfil);
void Consulta_AdminProv(AdminProv*, int);
void Alta_AdminProv(AdminProv* ,int*, char*);
void Baja_AdminProv(AdminProv*, int*, int, char*);
void Modificar_AdminProv(AdminProv*, int);

#endif
