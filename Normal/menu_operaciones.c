#include <stdio.h>
//Ramirez Olvera Guillermo :v

int main(){
	char opc;
	float num1,num2,res;
	int band=0;
	char tipo[30];
	//ciclo infinito
	while(1){
		band=0;
		printf("Ingrese 1 para sumar\n");
		printf("Ingrese 2 para restar\n");
		printf("Ingrese 3 para multiplicar\n");
		printf("Ingrese 4 para dividir\n");
		printf("Ingrese 5 para salir\n");
		opc=getchar();
		//para que en solo salga en casos especificos
		if(opc=='1'||opc=='2'||opc=='3'||opc=='4'){
			printf("Ingrese el numero 1\n");
			scanf("%f",&num1);
			printf("Ingrese el numero 2\n");
			scanf("%f",&num2);
		}
		fflush(stdin);
		switch(opc){
			case '1':
				res=num1+num2;
				break;
			case '2':
				res=num1-num2;
				break;
			case '3':
				res=num1*num2;
				break;
			case '4':;
				res=num1/num2;
				break;
			case '5':
				printf("Adios :'v\n");
				exit(0);
				break;
			default:
				printf("Ingrese una opcion valida\n");
				band=1;
				break;
		}
		if(band==0){
			printf("Su resultado de es %.1f\n",res);
			fflush(stdin);
		}
	}
	return 0;
}
