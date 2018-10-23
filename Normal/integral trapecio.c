//Autor: Rmirez Olvera Guillermo 27/08/2018
//Integral de (x^2)(sinx)
#include <stdio.h>
#include <math.h>
//Cambiar la funcion cada vez xdddd
int main(){
	float li,ls,dx,fx,x,suma=0.0;
	int n,i;
	printf("\n Ingrese limite infeior\n");
	scanf("%f",&li);
	printf("\n Ingrese el limite superior\n");
	scanf("%f",&ls);
	printf("\n Ingrese el numero de repeticiones\n");
	scanf("%d",&n);
	dx=(ls-li)/n;
	x=li;
	fx=pow(x,2)*sin(x);	
	suma= suma+fx;
	x=x+dx;
	for(i=2;i<=n;i++){
		fx=2*pow(x,2)*sin(x);
		suma= suma+fx;
		x=x+dx; 
	}
	fx=pow(x,2)*sin(x);
	suma= suma+fx;
	suma=(dx/2)*suma;
	printf("Tu resltado es \n %f",suma);
	
}
