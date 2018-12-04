/*
	Genarar nodos usando memoria dinamica
	Autor: Carlos Nevárez
	Fecha: 12/11/2018
*/

#include <stdio.h>

struct nodo{
	char nombre[50];
	char apellido[50];
	int edad;
	float est;
};

int main(){
	struct nodo *ptr;
	ptr = (struct nodo *) malloc(sizeof(struct nodo));//Crear o reservar memoria en tiempo de ejecucion
	/*Crear memoria en tiempo de compilacion
		struct nodo var, *ptr;
		ptr = &var;
	*/
	printf("\n Ingresa nombre: ");
	gets(ptr->nombre);
	printf("\n Ingresa apellido: ");
	gets(ptr->apellido);
	printf("\n Ingresa edad: ");
	scanf("%d", &ptr->edad);
	printf("\n Ingresa estatura: ");
	scanf("%f", &ptr->est);
	
	printf("Los datos son %s\t%s\t%d\t%f", ptr->nombre, ptr->apellido, ptr->edad, ptr->est);
	
	return 0;
}
