#include<stdio.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
int main(){
	puts("Ingreso de texto desde un archivo de texto");
	char c;
	FILE *ent,*sal;
	ent=fopen("prueba.txt","r");
	sal=fopen("repoio.txt","w");
	while(fread(&c,sizeof c,1,ent)>0){
		fwrite(&c,sizeof c,1,sal);
	}
	puts("texto copiado");
	return 0;
}
