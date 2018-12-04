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
	char cad[]="L-nd32nd12";
	int i;
	int ver;
	int contn=0;
	int contd=0;
	int contglo=0;
	int contnum=0;
	int nume=0;
	int chido=0;
	int ig=0;
	for(i=0;cad[i]!='\0';i++){
		if((cad[i]!=45)&&(cad[i]!=76)&&(cad[i]!=110)&&(cad[i]!=100)&&((cad[i]>58)||(cad[i]<47))){
			printf("No esta bien escrito");
			return 1;
		}
	}
	if(cad[0]=='L'){
		if(cad[1]=='-'){
			if(cad[2]=='n'){
				if(cad[3]==NULL){
					printf("Esta mal escrito");
					return 1;
				}
				char*cad1=subchar(cad,"n");
				for(i=0;cad1[i]!='\0';i++){
					ig=0;
					if(cad1[i]=='n'){
						if(cad1[i+1]=='d'){
							contn++;
							contd=0;
							chido++;
						}else{printf("puta madre >:c");return 1;}	
					} 
					if(cad1[i]=='d'){
						contd++;
						contglo++;
						contn=0;
						chido++;
					}		
					if(contd>1){
						printf("No esta bien escrito1");
						return 1;
					}
					if(contn>1){
						printf("No esta bien escrito2");
						return 1;
					}
					if ((chido==2)&&(cad1[i]>=48&&cad1[i]<=57)){
						contnum++;
						chido=0;
						ig=1;
					}
				}
				if(chido==1){
					printf("No esta chido1");
					return 1;
				}
				if(contnum<contglo){
					printf("No esta bien escrito3");
					return 1;
				}
				printf("holiii\n");
				printf("%s",cad1);
			}
			else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
	
}
int tam(char *s) {
   int ch = 0;
   while(s[ch] != '\0')
      ch++;  
   return ch;
}


