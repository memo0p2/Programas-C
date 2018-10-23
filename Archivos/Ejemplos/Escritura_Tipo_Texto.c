//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
#include<stdio.h>
int main(){
	char arreglo[25];
	puts("Ingrese texto desde el teclado");
	while(1){
		gets(arreglo);
		if(arreglo[0]=='\0')
			break;
		puts(arreglo);
	}
	return 0;
}
