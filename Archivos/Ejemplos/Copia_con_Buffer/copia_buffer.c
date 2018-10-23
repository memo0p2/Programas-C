//copiar texto con un buffer
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
#include<stdio.h>
int main(){
	char cadena[40];
	FILE *ent,*sal;
	ent=fopen("prueba.txt","r");
	sal=fopen("repoio.txt","w");
	while(fread(cadena,sizeof (cadena[40]),3,ent)>0){
		fwrite(cadena,sizeof (cadena[40]),3,sal);
	}
	return 0;
}
