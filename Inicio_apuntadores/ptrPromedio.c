#include <stdio.h>
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
int main(){
	float cali[5];
	float *ptr;
	float res;
	float suma;
	for(ptr=cali;ptr<=&cali[5];ptr++){
		printf("\nIngrese la calificacion %d",(int)(ptr-cali+1));
		printf("\n");
		scanf("\n%f",ptr);
		suma=suma+*ptr;
	}
	res=suma/6;
	printf("\nTu promedio es de: %f",res);
	return 0;
}