/*
fprintf(puntero,informacion);
fwrite(dato a guardar,tamaño,longitud,puntero);
*/
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
#include<stdio.h>
#include<stdlib.h>
FILE *fd;
struct datospersonales{
	char nombre[20];
	char apellidos[20];
	char correo[20];
}datos;
int main(){
	char dire[]="correos.txt";
	char res;
	fd=fopen(dire,"wt");
	if(fd==NULL){
		printf("Error prro >:v");
		return 1;
	}
	printf("AGENDA\n");
	fprintf(fd,"ADENDA\n");
	do{
		fflush(stdin);
		printf("\nNombre: ");
		gets(datos.nombre);
		printf("\nApellidos: ");
		gets(datos.apellidos);
		printf("\nCorreo: ");
		gets(datos.correo);
		
		fprintf(fd,"\n\nNombre: ");
		fwrite(datos.nombre,1,strlen(datos.nombre),fd);
		fprintf(fd,"\nApellidos: ");
		fwrite(datos.apellidos,1,strlen(datos.apellidos),fd);
		fprintf(fd,"\nCorreo: ");
		fwrite(datos.correo,1,strlen(datos.correo),fd);
		
		printf("\nDesea agregar mas contactos? s/n\n");
		res=getchar();
	}while(res=='s');
	fclose(fd);
	return 0;
}
