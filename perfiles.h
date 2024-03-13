#ifndef __PERFILES_H__
#define __PERFILES_H__

void menu_inicial(int*,int,int,Cliente**, AdminProv*, Transportista*,int*,char*,int*,int*);

//Cabecera: void iniciar_sesion(int,int,int,Cliente *, AdminProv *, Transportista *, int* , char* , int*);
//Precondicion: Las tres estructuras tienen que estar creadas previamente.
//Postcondicion: Comprueba si los datos de inicio de sesion son correctos.
// *int:   1= Cliente, 2= Administrador, 3= Proveedor. 4= Transportista.
void iniciar_sesion(int,int,int,Cliente *, AdminProv *, Transportista *, int* , char* , int*);

#endif

