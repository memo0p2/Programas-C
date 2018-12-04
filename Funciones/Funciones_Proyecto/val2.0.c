#include<stdio.h>
char *subchar(char cad[],char ch[]){
  int i,j=0;
  for(i=0;cad[i]!='\0';i++){
      while(cad[i]==ch[j]){
	i++;j++;
      }
      if(ch[j]=='\0')
	return cad+i-j;
      else j=0;
    }
	return NULL;
}
int main(){
	char cad[]="SS-sdf:sdf";
	int i,j;
	int con=0;
	if(cad[0]=='S'){
		if(cad[1]=='S'){
		if(cad[2]=='-'){
				if(cad[3]==NULL||cad[3]==':'){
					printf("Esta mal escrito");
					return 1;
				}
				char*cad1=subchar(cad,"-");
				for(i=0,j=1;cad1[j]!='\0';i++,j++){
					cad1[i]=cad1[j];
				}
				cad1[i]=NULL;
				//printf("%s",cad1);
				for(i=0;cad1[i]!='\0';i++){
					if(cad1[i]==':'){
						con++;
						if(cad1[i+1]==NULL){
							printf("Esta mal escrito");
							return 1;
						}
					}
					if(con>1){
						printf("Esta mal escrito");
						return 1;
					}
				}
				printf("hola");
			
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
	}else{printf("No esta bien escrito");return 1;}	
	
	
}
int tam(char *s) {
   int ch = 0;
   while(s[ch] != '\0')
      ch++;  
   return ch;
}


