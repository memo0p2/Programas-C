#include<stdio.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
struct dato{
	char nombre[30];
	int edad;
	float est;
	char sexo;
};
int main(){
	struct dato var1;
	struct dato *ptrs;
	ptrs=&var1;
	printf("Ingrese el nombre de var 1\n");
	gets(ptrs->nombre);
	printf("Ingrese la edad de var1\n");
	scanf("%d",&ptrs->edad);
	printf("Ingrese el sexo\n");
	fflush(stdin);
	ptrs->sexo=getchar();
	printf("ptrs tiene el valor de %lu\n",ptrs);
	printf("La direccion de ptrs es %lu\n",&ptrs);
	printf("El nombre en var1 es %s y esta en la direccion %lu",ptrs->nombre,&ptrs->nombre);
	return 0;
}
