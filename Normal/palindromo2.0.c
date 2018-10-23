#include<stdio.h>
//Autor:Ramirez Olvera Guillermo
int main(){
	char cadena [20];
	printf("Ingrese su cadena \n");
	gets(cadena);
	int i;
	int n=0;
	for(i=0;cadena[i]!='\0';++i){
		n++;
	}
	int j=0;
	while(cadena[j]!='\0'){
		if(cadena[j]==' '){
			for(i=j;i<n;i++){
				cadena[i]=cadena[i+1];
			}
			n--;	
		}
		j++;
		
	}
	int dif= 'a'-'A';
	for(i=0;cadena[i]!='\0';++i){
		if((cadena[i]<=90)&&(cadena>=65)){
			cadena[i]=cadena[i]+32;
		}
	}
	
	int bandera=0;
    for(i=0,j=n-1;i<n;i++,j--){
		if(cadena[i]!=cadena[j]){	
			bandera=1;
			break;
		}
		
	}
	if(bandera==0)
		printf("Es palindromo");
	else
		printf("No es palindromo");
	return 0;
}
