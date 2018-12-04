#include <stdio.h>

int main(){
	char cad[]="nd1nd2nd3";
	char sub[20];
	extraer(cad,sub);
	printf("%s",sub);
	return 0;
}
void extraer(char *cad,char*sub){
	while(*cad!='d'&&*cad!='\0'){
		cad++;
	}
	if(*cad!='\0')
		cad++;
	while(*cad!='n'&&*cad!='\0'){
		*sub=*cad;
		sub++;
		cad++;
	}
	*sub='\0';
}

