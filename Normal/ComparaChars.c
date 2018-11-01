#include<stdio.h>

int main(){
	char hola[20]="memo";
	if(compara(hola,"memo")==0){
		printf("kpez");
	}else{
		printf("nel");
	}
}
int compara(char * a , char * b){
    int i = 0;
    while (a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i]) 
			return(a[i]-b[i]);
        i++;
    }
    if (a[i]=='\0'&& b[i]=='\0') return 0;
    return (a[i] - b[i]);
}
