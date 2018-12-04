#include<stdio.h>
int main(){
	char cad1[]="hola";
	char cad2[]="HoLa";
	int i;
	int band=0;
	for(i=0;cad1[i]!='\0';i++){
		if((cad1[i]==cad2[i])||(cad1[i]==cad2[i]+32)||(cad1[i]==cad2[i]-32)||(cad1[i]+32==cad2[i])||(cad1[i]-32==cad2[i]))
			continue;
		else{
			band=1;
			break;
		}
	}
	if(band==0)
		printf("son iguales");
	else
		printf("nel");
	
}

