#include<stdio.h>
//Autor:Ramirez Olvera Guillermo
int main(){
	char palabra[20];
	char copia[20];
	int i,j;
	int tam=0;
	printf("Ingresa la cadena a copiar %s\n");
	gets(palabra);
	for(i=0;palabra[i]!='\0';++i){
		tam=i;
	}
	for(j=0;j<=tam;++j){
		copia[j]=palabra[j];
	}
	copia[tam+1]='\0';
	printf("Tu copia es: %s",copia);
	return 0;
}
