//Lectura de un archivo de tecto
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
#include<stdio.h>
int main(){
	char arreglo[40];
	puts("Ingreso desde un archivo de texto en disco\n");
	//printf("Ingreso desde un archivo de texto en disco\n");
	FILE *ent;
	ent=fopen("prueba.txt","r");
	if(ent==NULL){
		printf("No se puede abrir el archivo");
		return 1;
	}
	while(!feof(ent)){
		fgets(arreglo,40,ent);
		printf(arreglo);
	}
	return 0;
}
