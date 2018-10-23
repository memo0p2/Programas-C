//Lectura caracter por caracter
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
#include<stdio.h>
int main(){
	char c;
	puts("Ingreso de texto desde un archivo con read");
	FILE *ent;
	ent=fopen("prueba.txt","r");
	if(ent==NULL){
		puts("No se puede leer el archivo");
		return 1;
	}
	while(fread(&c,sizeof c,1,ent)>0){
		putchar(c);
	}
	return 0;
}
