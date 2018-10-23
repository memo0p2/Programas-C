#include<stdio.h>
#include<stdlib.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
FILE *fd;
int main(){
	char dire[]="hola.txt";
	int c;
	//fd=fopen(dire,"at");//--a un archivo ya existente agregar texto al final del texto
	//fd=fopen(dire,"w")--crear el archivo
	//fd=fopen(dire,"wt");--wr write text--crear y escribir en el
	fd=fopen(dire,"rt");//Leer texto
	if(fd==NULL){
		printf("No se puede crear el archivo");
		return 1;
	}
	//Para ingresar un texto a un archivo
	/*while((c=getchar())!='.'){//también pueden poner un salto de línea"\n"
        fputc(c,fd);
    }*/
    while((c=getc(fd))!=EOF){
    	putchar(c);
	}
    //Para leer el texto
    /*
    while((c=fgetc(fd))!='\n'){
    	if(c=='\n')
    		printf("\n");
    	else
    		putchar(c);
	}*/
	fclose(fd);
	return 0;
}
