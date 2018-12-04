#include <stdio.h>
int conversion (int num, int base,int []);
int main(){
  	int num,base,i,k;
  	int residuo[100];
  	printf("Escribe el numero\n");
  	scanf("%d",&num);
  	printf("Escribe a la base \n");
  	scanf("%d",&base);
  	if(base<2||base>16){
  		printf("Ingrese una base entre el 2 y 16");
  		return 1;
	}
  	k=conversion (num,base,residuo);
	for(i=k-1;i>=0;i--){
	   	if(residuo[i]<10){
	   		printf("%d",residuo[i]);	
		}else if(residuo[i]==10){
			printf("%c",'A');
		}else if(residuo[i]==11){
			printf("%c",'B');
		}else if(residuo[i]==12){
			printf("%c",'C');
		}else if(residuo[i]==13){
			printf("%c",'D');
		}else if(residuo[i]==14){
			printf("%c",'E');
		}else if(residuo[i]==15){
			printf("%c",'F');
		}
    }
	printf(" representa al entero %d en base %d",num,base);
  	return 0;
}
int conversion (int num, int base, int residuo[]){
    int i;
    for(i=0;num>0;i++){
        residuo[i]=num%base;
        num/=base; 
    }
    return i;
}
 
