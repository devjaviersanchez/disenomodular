#ifndef Perfiles
#define Perfiles

void menu_usuario(int*,int,int,Cliente**, AdminProv*, Transportista*,int*,char*,int*,int*);
//Cabecera: void menu_usuario(int*,int,int,Cliente**, AdminProv*, Transportista*,int*,char*,int*,int*);
//Precondici�n: Los tres par�metros de enteros y las tres estructuras tienen que estar creadas previamente.
//Postcondici�n:  Muestra menu de entrada y modifica la variable int* y char*.
//*char: Correo del usuario cuyo login es correcto.
 void Inicializar(Cliente**);

void iniciar_sesion(int,int,int,Cliente *, AdminProv *, Transportista *, int* , char* , int*);
//Cabecera: void iniciar_sesion(int,int,int,Cliente *, AdminProv *, Transportista *, int* , char* , int*);
//Precondici�n: Las tres estructuras tienen que estar creadas previamente.
//Postcondici�n: Comprueba si los datos de inicio de sesion son correctos.
// *int:   1= Cliente, 2= Administrador, 3= Proveedor. 4= Transportista.

void Alta_Cliente(Cliente*,int*);
//Cabecera:void Alta_Cliente(Cliente*,int*);
//Precondici�n: Cliente y variable inicializadas.
//Postcondici�n: a�ade un cliente a la estructura Cliente.

void Alta_AdminProv(AdminProv*,int *,char*);
//Cabecera: void Alta_AdminProv(AdminProv*,int *,char*);
//Precondici�n: AminProv y variable inicializadas.
//Postcondici�n: a�ade un administrador o proveedor a la estructura AdminProv.

void Alta_Transportista(Transportista*,int *);
//Cabecera: void Alta_Transportista(Transportista*,int *);
//Precondici�n: Transportista y variable inicializadas.
//Postcondici�n: a�ade un transportista a la estructura Transportista.

void Baja_Cliente(Cliente*,int *, int);
//Cabecera: void Baja_Cliente(Cliente*,int *, int);
//Precondici�n: Cliente y variable inicializadas.
//Postcondici�n: Elimina un cliente de la estructura Cliente.

void Baja_AdminProv(AdminProv*,int *, int ,char*);
//Cabecera: void Baja_AdminProv(AdminProv*,int *, int ,char*);
//Precondici�n: AdminProv y variable inicializadas.
//Postcondici�n: Elimina un administrador o proveedor de la estructura AdminProv.

void Baja_Transportista(Transportista* ,int *, int );
//Cabecera: void Baja_Transportista(Transportista* ,int *, int );
//Precondici�n: Transportista y variable inicializadas.
//Postcondici�n: Elimina un transportista de la estructura Transportista.

void Modificar_Cliente(Cliente* , int );
//Cabecera: void Modificar_Cliente(Cliente* , int );
//Precondici�n: Cliente inicializada.
//Postcondici�n:Modifica las variables de un cliente de la estructura Cliente.

void Modificar_AdminProv(AdminProv*, int);
//Cabecera: void Modificar_AdminProv(AdminProv*, int);
//Precondici�n: AminProv inicializada.
//Postcondici�n:Modifica las variables de un administrador o proveedor de la estructura AminProv.

void Modificar_Transportista(Transportista* , int);
//Cabecera: void Modificar_Transportista(Transportista* , int);
//Precondici�n: Transportista inicializada.
//Postcondici�n:Modifica las variables de un transportista de la estructura Transportista.

void Consulta_Cliente(Cliente*, int);
//Cabecera: void Consulta_Cliente(Cliente*, int);
//Precondici�n: Cliente inicializada.
//Postcondici�n:Imprime informaci�n de un cliente determinado.

void Consulta_AdminProv(AdminProv*, int);
//Cabecera: void Consulta_AdminProv(AdminProv*, int);
//Precondici�n: AdminProv inicializada.
//Postcondici�n:Imprime informaci�n de un administrador o proveedor determinado.

void Consulta_Transportista(Transportista* , int);
//Cabecera: void Consulta_Transportista(Transportista* , int);
//Precondici�n: Transportista inicializada.
//Postcondici�n:Imprime informaci�n de un transportista determinado
int Buscar_AdminProv(AdminProv*,int,int);
int Buscar_Cliente(Cliente*,int,int);
int Buscar_Transportista(Transportista*,int,int);
void actualizar_cartera(Cliente*,int);

#endif

