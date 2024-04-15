#ifndef __LOCKERS_H__
#define __LOCKERS_H__

typedef struct {
	char id_locker[10];
	char localidad[20];
	char provincia[20];
	char ubicacion[20];
	int num_comp;
	int ocupados;
}Lockers;

typedef struct {
	char id_locker[10];
	int num_comp;
	int cod_locker;
	char estado[15];
	char fecha_asignacion[11];
	char fecha_caducidad[11];
}CompartimentosLockers;

//cabecera:void LeerLockers(Lockers*,int*);
//Precondicion: lockers.txt existe y tiene datos
//Postcondicion: guarda los datos de lockers.txt en lockers
void LeerLockers(Lockers*);

void EscribirLockers(Lockers *lockers,int n_lockers);

void EscribirCompartimentosLockers(CompartimentosLockers *compartimentoslockers,int n_compartimentoslockers);

//cabecera:void MostrarLockers(Lockers*,int)
//Precondicion: lockers y n_lockers inicializados
//Postcondicion: muestra los lockers
void MostrarLockers(Lockers*,int);

//cabecera:void EscribirLockers(Lockers*,int);
//Precondicion: lockers existe y tiene datos
//Postcondicion: guarda los datos de lockers en lockers.txt
void EscribirLockers(Lockers*,int);

//cabecera:void LeerCompartimentosLockers(CompartimentosLockers*);
//Precondicion: compartimentoslockers.txt existe y tiene datos
//Postcondicion: guarda los datos de compartimentoslockers.txt en compartimentoslockers
void LeerCompartimentosLockers(CompartimentosLockers*);

//cabecera:void MostrarCompartimentosLockers(CompartimentosLockers*,int)
//Precondicion: compartimentoslockers y n_compartimentoslockers inicializados
//Postcondicion: muestra los compartimentoslockers
void MostrarCompartimentosLockers(CompartimentosLockers*,int);

//cabecera:void EscribirCompartimentosLockers(CompartimentosLockers*,int);
//Precondicion: compartimentoslockers existe y tiene datos
//Postcondicion: guarda los datos de compartimentoslockers en compartimentoslockers.txt
void EscribirCompartimentosLockers(CompartimentosLockers*,int);

#endif
