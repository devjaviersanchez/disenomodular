#ifndef __CATEGORIAS_H__
#define __CATEGORIAS_H__

typedef struct {
	int id_categoria;
	char descripcion[50];
}Categorias;

//cabecera:void LeerCategorias(Categorias*,int*);
//Precondicion: categorias.txt existe y tiene datos
//Postcondicion: guarda los datos de categorias.txt en categorias
void LeerCategorias(Categorias*);

void EscribirCategorias(Categorias *categorias,int n_categorias);

//cabecera:void MostrarCategorias(Categorias *,int)
//Precondicion: categorias y n_categorias inicializados
//Postcondicion: muestra los categorias
void MostrarCategorias(Categorias *,int);

//cabecera:void EscribirCategorias(Categorias*,int);
//Precondicion: categorias existe y tiene datos
//Postcondicion: guarda los datos de categorias en categorias.txt
void EscribirCategorias(Categorias*,int);

void Alta_Categoria(Categorias*, int*);

void Baja_Categoria(Categorias*, int*, int);

void Modificacion_Categoria(Categorias*, int);

int Busqueda_Categoria(Categorias*, int, int);

void Consultar_Categoria(Categorias*, int);

#endif
