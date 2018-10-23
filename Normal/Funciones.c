#include<stdio.h>
#include <string.h>
//Autor:Ramirez Olvera Guillermo
int main(void){
	char nombre[8]="Ana";
	char apellido[4]="Luz";
	
	printf("Nombre es %s\n",nombre);
	printf("Apellido es %s\n",apellido);
	strcat(nombre, apellido);
	printf("todo junto es %s\n",nombre);
	
	char palabra[10]="Guillermo";
	printf("La palabra es es %s\n",palabra);
	strrev(palabra);
	printf("La palabra invertida es %s\n",palabra);
	
	int n=0;
	char palo[20];
	char palo1[n];
	printf("Ingresa la palabra \n");
	gets(palo);
	strcpy(palo1,palo);
	printf("La copia es %s\n",palo1);
	return 0;
}
