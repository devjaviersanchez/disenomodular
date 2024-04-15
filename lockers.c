#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "lockers.h"
#include "lectura.h"

void LeerLockers(Lockers* lockers){

    FILE *fichero;
	fichero=fopen("Lockers.txt","r");

    if (fichero == NULL) puts("\nError al abrir Lockers.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[6];//vector de cadenas ,contendra 6 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 6; i++) tokens[i] = strtok(NULL, delim);

            strcpy(lockers[j].id_locker,tokens[0]);
			strcpy(lockers[j].localidad,tokens[1]);
            strcpy(lockers[j].provincia,tokens[2]);
			strcpy(lockers[j].ubicacion,tokens[3]);
			lockers[j].num_comp=entero(tokens[4]) ;
			lockers[j].ocupados=entero(tokens[5]) ;
			j++;
		}
	}
    fclose(fichero);
}

void EscribirLockers(Lockers *lockers,int n_lockers){

    FILE *fichero;
	fichero=fopen("Lockers.txt","w");
    if (fichero == NULL)
		puts("\nError al abrir Lockers.txt");
	else
	{
        rewind(fichero);
		int j=0;
		while (j<n_lockers){
			fprintf(fichero, "%s-%s-%s-%s-%d-%d",lockers[j].id_locker,lockers[j].localidad,lockers[j].provincia,lockers[j].ubicacion,lockers[j].num_comp,lockers[j].ocupados);
            if(j!=n_lockers-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}

void EscribirCompartimentosLockers(CompartimentosLockers *compartimentoslockers,int n_compartimentoslockers){
    FILE *fichero;
	fichero=fopen("CompartimentosLockers.txt","w");
    if (fichero == NULL)
		puts("\nError al abrir CompartimentosLockers.txt");
	else
	{
        rewind(fichero);
		int j=0;
		while (j<n_compartimentoslockers){
			fprintf(fichero, "%s-%d-%d-%s-%s-%s",compartimentoslockers[j].id_locker,compartimentoslockers[j].num_comp,compartimentoslockers[j].cod_locker,compartimentoslockers[j].estado,compartimentoslockers[j].fecha_asignacion,compartimentoslockers[j].fecha_caducidad);
            if(j!=n_compartimentoslockers-1){
            fputc('\n',fichero);
            }
			j++;
    }
    fclose(fichero);
    }
}


void LeerCompartimentosLockers(CompartimentosLockers* compartimentoslockers){

    FILE *fichero;
	fichero=fopen("CompartimentosLockers.txt","r");

    if (fichero == NULL) puts("\nError al abrir CompartimentosLockers.txt");
	else {
		int j=0;
		int i;
		const char delim[2]="-";
		char* tokens[6];//vector de cadenas ,contendra 6 cadenas
		char s[128];

		while (!feof(fichero)){
			fgets(s, 128, fichero);
			if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
			tokens[0] = strtok(s, delim);

			for ( i = 1; i < 6; i++)tokens[i] = strtok(NULL, delim);

            strcpy(compartimentoslockers[j].id_locker,tokens[0]);
            compartimentoslockers[j].num_comp=entero(tokens[1]) ;
			compartimentoslockers[j].cod_locker=entero(tokens[2]) ;
			strcpy(compartimentoslockers[j].estado,tokens[3]);
			strcpy(compartimentoslockers[j].fecha_asignacion,tokens[4]) ;
			strcpy(compartimentoslockers[j].fecha_caducidad,tokens[5]) ;

			j++;
		}
	}
}

void MostrarLockers(Lockers* lockers,int n_lockers){

    int j=n_lockers - 1;

	while(j>=0){
        printf("\n");
		printf("Id: %s\n",lockers[j].id_locker);
		printf("Localidad: %s\n",lockers[j].localidad);
		printf("Provincia: %s\n",lockers[j].provincia);
		printf("Ubicacion: %s\n",lockers[j].ubicacion);
		printf("Numero total de compartimentos: %d\n",lockers[j].num_comp);
		printf("Numero de compartimentos ocupados: %d\n",lockers[j].ocupados);

		j--;
		printf("\n");
	}
}

void MostrarCompartimentosLockers(CompartimentosLockers* compartimentoslockers,int n_compartimentoslockers){
    int j=n_compartimentoslockers - 1;

	while(j>=0){
        printf("\n");
		printf("Id: %s\n",compartimentoslockers[j].id_locker);
		printf("Numero del compartimento: %d\n",compartimentoslockers[j].num_comp);
		printf("Codigo del locker: %d\n",compartimentoslockers[j].cod_locker);
		printf("Estado: %s\n",compartimentoslockers[j].estado);
		printf("Fecha ocupacion: %s\n",compartimentoslockers[j].fecha_asignacion);
		printf("Fecha caducidad: %s\n",compartimentoslockers[j].fecha_caducidad);

		j--;
		printf("\n");
	}
}
