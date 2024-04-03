#ifndef __TRANSPORTISTA_H__
#define __TRANSPORTISTA_H__

typedef struct {
	int id_transp;
	char nombre[20];
	char email[30];
    char contrasena[15];
	char nombre_empresa[20];
    char nombre_ciudad[20];
}Transportista;

//cabecera:void LeerTransportistas(Transportista*,int*);
//Precondicion: transportistas.txt existe y tiene datos
//Postcondicion: guarda los datos de transportistas.txt en transportistas
void LeerTransportistas(Transportista*);

//cabecera:void EscribirTransportistas(Transportistas*,int)
//Precondicion: transportistas existe y tiene datos
//Postcondicion: guarda los datos de transportistas en transportistas.txt
void EscribirTransportistas(Transportista*,int);

//cabecera:void MostrarTransportistas(Transportista*,int)
//Precondicion: transportistas y n_transportistas inicializados
//Postcondicion: muestra los transportistas
void MostrarTransportistas(Transportista*,int);

void Alta_Transportista(Transportista*, int*);

int Buscar_Transportista(Transportista*, int, int);

void Baja_Transportista(Transportista*, int*, int);

void Modificar_Transportista(Transportista* , int);

#endif
