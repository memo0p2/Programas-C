#include<stdio.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
int main(){
	char cadena[20];
	char *ptr;
	char *ptr1;
	int n;
	int band=0;
	printf("Ingresa la cadena \n");
	gets(cadena);
	for(ptr1=cadena,n=0;cadena[n]!='\0';n++,ptr1++);
	ptr1--;
	for(ptr=cadena;ptr!=&cadena[n];ptr++,ptr1--){
		while((*ptr==' ')||(*ptr=='	')){
			ptr++;
		}
		while((*ptr1==' ')||(*ptr1=='	')){
			ptr1--;
		}
		if((*ptr==*ptr1)||(*ptr==*ptr1+32)||(*ptr==*ptr1-32)||(*ptr+32==*ptr1)||(*ptr-32==*ptr1))
			continue;
		else{
			band=1;
			break;
		}
		
	}
	if(band==0)
		printf("Es palindromo");
	else
		printf("No es palindromo");	
	return 0;
}
