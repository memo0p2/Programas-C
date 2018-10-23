#include<stdio.h>
//Autor:Ramirez Olvera Guillermo
struct dato{
	char nombre[30];
};
int main(){
	struct dato name[4];
	char vocal;
	int i,j;
	int contador;
	for(i=0;i<5;i++){
		printf("Ingresa el nombre %i\n",i+1);
		gets(name[i].nombre);
	}
	printf("Ingresa tu vocal a buscar\n");
	fflush(stdin);
	vocal=getchar();
	for(i=0;i<5;i++){
		contador=0;
		for(j=0;name[i].nombre[j]!='\0';++j){
			if(vocal==name[i].nombre[j]){
				contador++;
			}
		}
		printf("El nombre de %s tiene %i la vocal %c\n",name[i].nombre,contador,vocal);
	}
	return 0;
}

