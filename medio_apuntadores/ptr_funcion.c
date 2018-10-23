#include<stdio.h>
#include<ctype.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
int funcion();
int main(){
	int(*ptrfun)();//declaracion del puntero de una funcion
	char car;
	printf("La direeccion de la funcion es %lu\n",funcion);
	ptrfun=funcion;//La funcion sin parentesis es su direccion *O*
	printf("Se invoca la funcion usando puntero a funcion\n");
	(*ptrfun)();

	return 0;
}
int funcion(){
	printf("hola k pedo we");
}
