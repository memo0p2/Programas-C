#include<stdio.h>
//Autor:Ramirez Olvera Guillermo
int main(){
	int n=-1;
	char cadena[20];
	char aux[20];
	printf("Ingresa la cadena\n");
	gets(cadena);
	int i,j;
	for(i=0;cadena[i]!='\0';++i){
		n++;
	}

	for(j=0;j<=n;j++){
		aux[j]=cadena[n-j];
	}
	aux[n+1]='\0';
	printf("La cadena volteada es %s",aux);
	return 0;
}
