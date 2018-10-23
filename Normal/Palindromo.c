//Palindromp
//Guillermo Ramirez Olvera >:v
#include <stdio.h> 
int main (void){
    
    int n=0;                    
    char palabra[20];         
    char operacion[n];         
    int i, j, c;                
        
    printf("Escriba la palabra: \n");
    gets(palabra);
    for(c=0;palabra[c]!='\0'; c++){                 
        operacion[c]=palabra[c];
        n=n+1;                          
    }
    
    int bandera=0;
    for(i=0,j=n-1;i<n;i++,j--){
		if(operacion[i]!=operacion[j]){	
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
 
