#ifndef __PERFILES_H__
#define __PERFILES_H__



typedef struct {
	int id_empresa;
	char nombre[20];
	char email[30];
    char contrasena[15];
    char perfil[20];
}AdminProv;

typedef struct {
	int id_transp;
	char nombre[20];
	char email[30];
    char contrasena[15];
	char nombre_empresa[20];
    char nombre_ciudad[20];
}Transportista;

//cabecera:void void LeerAdminProv(AdminProv *,int*);
//Precondicion: adminprov.txt existe y tiene datos
//Postcondicion: guarda los datos de adminprov.txt en adminprov
void LeerAdminProv(AdminProv *);


//cabecera:void LeerTransportistas(Transportista*,int*);
//Precondicion: transportistas.txt existe y tiene datos
//Postcondicion: guarda los datos de transportistas.txt en transportistas
void LeerTransportistas(Transportista*);


//cabecera:void MostrarAdminProv(AdminProv *,int )
//Precondicion: AdminProv y n_adminprov inicializados
//Postcondicion: muestra los adminprov
void MostrarAdminProv(AdminProv *,int );

//cabecera:void MostrarTransportistas(Transportista*,int)
//Precondicion: transportistas y n_transportistas inicializados
//Postcondicion: muestra los transportistas
void MostrarTransportistas(Transportista*,int);

#endif
