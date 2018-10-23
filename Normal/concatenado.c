#include <stdio.h>
//Autor:Ramirez Olvera Guillermo
int main(){
	char cadena[100],cadena1[100];
	int i,j,tam1,tam2;
	
	printf("Ingrese la cadena 1\n");
	gets(cadena);
	printf("\nIngresa la cadena 2\n");
	gets(cadena1);
	
	for(i=0;cadena[i]!='\0';i++){
		tam1=i;
	}
	for(i=tam1+1,j=0;cadena1[j]!='\0';i++,j++){
		cadena[i]=cadena1[j];
		tam2=j;
	}
	i=tam1+tam2+2;
	cadena[i]='\0';
	printf("La cadena concatenada es %s",cadena);
	return 0;
}
