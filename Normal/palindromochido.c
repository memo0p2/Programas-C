//codigo para pasar algoritmia xd :V
//Autor:Ramirez Olvera Guillermo
#include <stdio.h>
int main(){
	int n=0;                    
    char palabra[20];         
    int i;
	int j;                
        
    printf("Escriba la palabra: \n");
    gets(palabra);
    //obtenemos el tamaño de la cadena
    for(c=0;palabra[c]!='\0'; c++){              
        n++;                          
    }
    //le restamos uno por que se pasa el for xd :v
    n--;
    int band=0;
    //creamos el for
    for(i=0;palabra[i]!='\0';i++,n--){
		//quitamo los espacios y tabuladores
		//OJO: el primer espacio es la tecla de espacio xd
		//El segundo es del tabulador son diferentes es una mamada
    	while((palabra[i]==' ')||(palabra[i]=='	')){
    		i++;
		}
		while((palabra[n]==' ')||(palabra[n]=='	')){
			n--;
		}
		//Comparamos bien mamalon para que vea que sea un palindromo
		if((palabra[n]==palabra[i])||(palabra[n]==palabra[i]+32)||(palabra[i]+32==palabra[n])||(palabra[n]==palabra[i]-32)||(palabra[i]-32==palabra[n])){
			
			continue;
		}else{
			band=1;
			break;
		}
	}
	if(band==0){
		printf("\nEs palindromo");
	}else{
		printf("\nNo es palindromo");
	}
	
	return 0;
}
