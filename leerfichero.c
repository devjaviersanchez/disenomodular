#include <stdio.h>

int main(){
	FILE *archivo = fopen("texto1.txt", "w");
    if (archivo != NULL) {
        fprintf(archivo, "miau miau 2\nmiau");
    }
    
    int cont=0, contl=1, contp=1;;
    fclose(archivo);
	FILE *f=fopen("texto1.txt", "r");
	char letra;
	if(f==NULL)
	{
		printf("No se ha podido encontrar el fichero\n");
	}else
	{
		while((letra=fgetc(f)) != EOF)
		{
			printf("%c", letra);
			if(letra!='\n' && letra!=' ')
				cont++;
			if(letra=='\n')
				contl++;
				
			if(letra==' ' || letra=='\n')
				contp++;
		}
		printf("\nLetras: %d. Palabras: %d. Lineas: %d", cont, contp, contl);
	}
	fclose(f);
}