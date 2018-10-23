#include<stdio.h>
//Autor:Ramirez Olvera Guillermo
int main(){
	char cad[20];
	printf("Ingrese la cadena \n");
	gets(cad);
	printf("La cadena es %s \n",&cad);
	printf("La cadena imprime %s",&cad[5]);
	int j,i;
	int bamdera=0;
	return 0;
}
