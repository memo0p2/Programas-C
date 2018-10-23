#include <stdio.h>
#include <stdlib.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
int copia(){
	char palabra[20];
	char copia[20];
	int i;
	printf("Ingrese la cadena a copiar\n");
	gets(palabra);
	for(i=0;palabra[i]!='0';i++){
		copia[i]=palabra[i];
	}
	printf("Su copia es %s\n",copia);
	return 0;
}
int concatena(){
	char cadena1[40];
	char cadena2[40];
	char *ptr1;
	char *ptr2;
	int i=0,j;
	int tam1=0,tam2=0;
	printf("Ingrese la cadena1\n");
	gets(cadena1);
	printf("Ingrese la cadena2\n");
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
	printf("La palabra concatenada es:\n");
	printf("%s",cadena1);
	printf("\n");
	return 0;
}
int prefijo(){
	char cad[20];
	char pre[20];
	int i;
	int con=0;
	int bad=0;
	printf("Ingrese la cadena\n");
	gets(cad);
	printf("Ingrese el prefijo\n");
	gest(pre);
	for(i=0;cad[i]!='0';i++){
		if(cad[i]==pre[i]){
			con++;
		}else{
			bad=1;
			break;
		}
	}
	if((bad!=1)&&(con<0))
		printf("El prefijo es correcto\n");
	else
		printf("El prefijo es incorrecto\n");
	return 0;
}
int main(){
	char opc;
	while(1){
		printf("Seleccione una opcion\n");
		printf("1 para copia de una cadena\n");
		printf("2 para concatenacion\n");
		printf("3 para prefijo de una cadena\n");
		printf("4 sufijo de una cadena\n");
		printf("5 para salir\n");
		opc=getchar();
		fflush(stdin);
		switch(opc){
			case '1':
				copia();
				break;
			case '2':
				concatena();
				break;
			case '3':
				prefijo();
				break;
			case '4':
				
				break;
			case '5':
				printf("Adios :'v\n");
				exit(0);
				break;
			default:
				break;
		}
	}

	return 0;
}
