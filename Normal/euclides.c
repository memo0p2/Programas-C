#include <stdio.h>
//Autor:Ramirez Olvera Guillermo
int main(){
	int a,b,c,r;
	int aux1,aux2;
	printf("Ingrese el 1 numero\n");
	scanf("%d",&aux1);
	printf("Ingrese el 2 numero\n");
	scanf("%d",&aux2);
	if(aux2<aux1){
		a=aux1;
		b=aux2;
	}else
	if(aux1<aux2){
		a=aux2;
		b=aux1;
	}else
	if(aux1==aux2){
		a=aux1;
		b=aux2;
	}
	int bandera=0;
	int res=0;
	do{
		r=a%b;
		a=b;
		b=r;		
	}while(r!=0);
	printf("El MCD es: %d",a);
	return 0;
}
