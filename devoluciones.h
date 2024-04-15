#ifndef __DEVOLUCIONES_H__
#define __DEVOLUCIONES_H__

typedef struct {
    int id_pedido;
	int id_prod;
	char fecha_devolucion[11];
	char motivo[50];
	char estado[20];
	char fecha_aceptacion[11];
	char fecha_caducidad[11];
}Devoluciones;

//cabecera:Devoluciones* LeerDevoluciones(Devoluciones*,int*);
//Precondicion: devoluciones.txt existe y tiene datos
//Postcondicion: guarda los datos de devolucioes.txt en devoluciones
void LeerDevoluciones(Devoluciones*);

void EscribirDevoluciones(Devoluciones *devoluciones,int n_devoluciones);

//cabecera:void MostrarDevoluciones(Devoluciones*,int)
//Precondicion: devoluciones y n_devoluciones inicializados
//Postcondicion: muestra los devoluciones
void MostrarDevoluciones(Devoluciones*,int);

//cabecera:void EscribirDevoluciones(Devoluciones*,int);
//Precondicion: devoluciones existe y tiene datos
//Postcondicion: guarda los datos de devoluciones en devoluciones.txt
void EscribirDevoluciones(Devoluciones*,int);

#endif
