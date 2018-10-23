#include <stdio.h>
#include <math.h>

//Autor:Ramirez Olvera Guillermo
//Funcion a ocupar
float sustF(float x){
	return pow(x,2)-3*x-4;
}

int main(){
	float por,error,valor0,valor1,fx0,fx1,x;
	valor0=5.0;
	valor1=7.0;
	error=100.0;
	
	do{
		printf("\n Ingrese el porcentaje de error que desea \n");
		scanf("%f",&por);
	}while(por>100);
	
	while(por<error){
		fx0=sustF(valor0);
		fx1=sustF(valor1);
		x=valor1-(fx1*(valor0-valor1)/(fx0-fx1));
		error= ((x-valor1)/x)*100;
		valor0=valor1;
		valor1=x;	
	}
	printf("\nLa raiz es: %.5f",x);
	return 0;
}
