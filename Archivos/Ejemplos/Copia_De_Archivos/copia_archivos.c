//copiar texto a otro texto
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
#include<stdio.h>
int main(){
	int car;
	FILE *ent,*sal;
	ent=fopen("prueba.txt","r");
	sal=fopen("repoio.txt","w");
	while((car=fgetc(ent))!=EOF){
		fputc(car,sal);
	}
	printf("Se han copiado los archivos");
	return 0;
}
