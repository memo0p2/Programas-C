#include <stdio.h>
#include <stdlib.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
void copiar(char *ptr2,char *ptr1){
	for(;*ptr1!='\0';ptr1++,ptr2++)
		*ptr2=*ptr1;
	
}
void conca(char *ptr1,char *ptr2){
	for(;*ptr1!='\0';ptr1++);
	for(;*ptr2!='\0';ptr2++,ptr1++)
		*ptr1=*ptr2;
	
}
int pre(char *ptr1,char *ptr2){
	int aver=1;
	for(;*ptr2!='\0';ptr1++,ptr2++){
		if(*ptr1!=*ptr2){
			aver=0;
		}
	}
	return aver;
}
int sub(char *ptr1,char *ptr2){
	int memo=1;
	int co=0;
	for(ptr1;*ptr1!='\0';ptr1++);
	for(ptr2;*ptr2!='\0';ptr2++,co++);
	for(ptr1,ptr2;co!=0;ptr1--,ptr2--,co--)
		if(*ptr1!=*ptr2)
			memo=0;	
	return memo;
}
void limpiar(char *ptr1,char *ptr2){
	for(;*ptr1!='\0';ptr1++)
		*ptr1=' ';
	for(;*ptr2!='\0';ptr2++)
		*ptr2=' ';
}

int main(){
	char opc;
	char cad1[50];
	char cad2[50];
	while(1){
		limpiar(cad1,cad2);
		printf("Ingrese un numero\n");
		printf("1 para copiar\n");
		printf("2 para concatenar\n");
		printf("3 para prefijo\n");
		printf("4 para subfijo\n");
		printf("5 para salir\n");
		opc=getchar();
		fflush(stdin);
		switch(opc){
			case '1':
				printf("Ingrese la palabra a copiar\n");
				gets(cad1);
				copiar(cad2,cad1);
				printf("Su cadena copiada es %s\n",cad2);
				getchar();
				break;
			case '2':
				printf("Ingrese la 1 cadena\n");
				gets(cad1);
				printf("Ingrese la 2 cadena\n");
				gets(cad2);
				conca(cad1,cad2);
				printf("Su cadena concatenada es %s\n",cad1);
				getchar();
				break;
			case '3':
				printf("Ingrese la cadena\n");
				gets(cad1);
				printf("Ingrese el prefijo\n");
				gets(cad2);
				if(pre(cad1,cad2))
					printf("Si es un prefijo\n");
				else
					printf("No es un prefijo\n");
				getchar();
				break;
			case '4':
				printf("Ingrese la cadena\n");
				gets(cad1);
				printf("Ingrese el subfijo\n");
				gets(cad2);
				if(sub(cad1,cad2))
					printf("Si es un subfijo\n");
				else
					printf("No es un subfijo\n");
				getchar();
				break;
			case '5':
				printf("Adios :'v\n");
				exit(0);
			default:
				printf("Ingrese una opcion valida\n");
		}
	}
	
	return 0;
}
