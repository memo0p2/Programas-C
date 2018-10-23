#include <stdio.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
int main(){
	char cadena1[40];
	char cadena2[40];
	char *ptr1;
	char *ptr2;
	int i=0,j;
	int tam1=0,tam2=0;
	printf("Ingrese la cadena1\n");
	gets(cadena1);
	printf("\nIngrese la cadena2\n");
	gets(cadena2);
	
	for(ptr1=cadena1;*ptr1!='\0';ptr1++,i++){
		tam1++;
	}
	for(ptr2=cadena2;*ptr2!='\0';ptr2++,i++){
		tam2++;
		cadena1[i]=*ptr2;
	}
	j=tam1+tam2+1;
	cadena1[j]='\0';
	printf("\nLa palabra concatenada es:\n");
	printf("%s",cadena1);
	return 0;
}
