#include <stdio.h>
#include <math.h>
//Autor:Ramirez Olvera Guillermo
int main(){
	float li,ls,dx,fx,x,suma=0.0;
	int n,i=0;
	int bandera=0;
	int modulo=0;
	printf("Ingrese limite inferior\n");
	scanf("%f",&li);
	printf("Ingrese limite superior\n");
	scanf("%f",&ls);
	while(bandera==0){
		printf("Ingrese numero de repeticiones\n");
		scanf("%d",&n);
		modulo=n%2;
		if(modulo==0)
			bandera=1;
		else{
		    printf("Ingrese un numero par\n");
			bandera=0;
		}
	}
	dx=(ls-li)/n;
	x=li;
	fx=pow(x,2)*sin(x);	
	suma= suma+fx;
	x=x+dx;
	for(i=2;i<=n;i++){
		if(0==i%2){
			fx=4*pow(x,2)*sin(x);
			suma= suma+fx;
			x=x+dx;
		}else{
			fx=2*pow(x,2)*sin(x);
			suma= suma+fx;
			x=x+dx;
		} 
	}
	fx=pow(x,2)*sin(x);
	suma= suma+fx;
	suma=(dx/3)*suma;
	printf("Tu resltado es \n %f",suma);
}
