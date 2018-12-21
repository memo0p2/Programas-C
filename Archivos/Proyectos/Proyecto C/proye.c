//Autor: Ramirez Olvera Guillermo 1CM1
//31/10/18
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
char *corta(char *dest, const char *src, size_t n){
	size_t i;
    for(i = 0; i < n && src[i] != '\0'; i++)
    	dest[i] = src[i];
    for( ; i < n; i++)
    	dest[i] = '\0';
   	return dest;
}
char *copiar(char *ptr2, const char *ptr1){
    for(;*ptr1!='\0';ptr1++,ptr2++)
		*ptr2=*ptr1;
   return ptr2;
}
char *remplasador(char *str, char *orig, char *rep){
  	char cad[4096];
  	char *p;
  	int i;
  	if(!(p = subchar(str, orig)))
		return str;
    corta(cad, str, p-str);
	char aux[tam(p+tam(orig))+1]; 
	copiar(aux, p+tam(orig)); //Lo guardamos para que sprintf no lo machaque si rep es más largo que orig
	if(rep>orig){
		for(i=0;rep[i]!='\0';i++){
			rep[i]=NULL;
		}
	} 
	sprintf(cad+(p-str),"%s%s", rep, aux);
  	return remplasador(cad, orig, rep);
}
int chaint(char *str){
	int res=0;
	int sign=1;
	int i=0;
	if(str[0]=='-'){
		sign=-1;
		i++;
	}
	for(;str[i]!='\0';i++){
		res=res*10+str[i]-'0';
	}
	return sign*res;
}
void eliminar(char *cadena) {
	int i,j;
	for(i=0,j=1;cadena[i]!='\0';i++,j++){
		cadena[i]=cadena[j];
	}
}
int main(int argc,char *argv[]){
	char opc[5];
	int i;
	for(i=0;argv[2][i]!='-';i++){
		opc[i]=argv[2][i];
	}
	FILE *com;
	com=fopen(argv[1],"r");
	if(com==NULL){
		printf("No se pudo leer el archivo");
		return 1;
	}
	if(argc>4){
		printf("Demasiados argumentos");
		return 1;
	}
	if(compara(opc,"S")==0)
		atributo1(argv[1],argv[2],argv[3]);
	else if(compara(opc,"s")==0)
		atributo2(argv[1],argv[2],argv[3]);
	else if(compara(opc,"L")==0)
		atributo3(argv[1],argv[2],argv[3]);
	else if(compara(opc,"C")==0)
		atributo4(argv[1],argv[2],argv[3]);
	else if(compara(opc,"IL")==0)
		atributo5(argv[1],argv[2],argv[3]);
	else if(compara(opc,"IC")==0)
		atributo6(argv[1],argv[2],argv[3]);
	else if(compara(opc,"CC")==0)
		atributo7(argv[1],argv[2],argv[3]);
	else if(compara(opc,"CP")==0)
		atributo8(argv[1],argv[2],argv[3]);
	else if(compara(opc,"CS")==0)
		atributo9(argv[1],argv[2],argv[3]);
		else if(compara(opc,"SS")==0)
		atributo10(argv[1],argv[2],argv[3]);
	else{
		printf("No existe esa opcion");
		return 1;
	}
	return 0;
}
int compara(char*a,char*b){
    int i = 0;
    while (a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i]) 
			return(a[i]-b[i]);
        i++;
    }
    if (a[i]=='\0'&& b[i]=='\0') return 0;
    return (a[i] - b[i]);
}
int compMn(char*cad1,char*cad2){
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
    return band;
}
int tam(char *s) {
   int ch = 0;
   while(s[ch] != '\0')
      ch++;  
   return ch;
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
void reverso(char* begin, char* end) {
	char aux;
	while(end>begin)
		aux=*end, *end--=*begin, *begin++=aux;
}	
void inachar(int value, char* str, int base) {
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* wstr=str;
	int sign;
	if (base<2 || base>35){ *wstr='\0'; return; }
	if ((sign=value) < 0) value = -value;
	do *wstr++ = num[value%base]; while(value/=base);
	if(sign<0) *wstr++='-';
	*wstr='\0';
	reverso(str,wstr-1);
}
void atributo1(char *dirE,char *atri,char *dirS){
	char c;
	if(tam(atri)>4){
		printf("Error en el atributo");
		return 1;
	}
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen(dirS,"w");
	while(fread(&c,sizeof c,1,ent)>0){
		if(c==atri[2])
			c=atri[3];
		fwrite(&c,sizeof c,1,sal);
	}
	printf("texto copiado");
}
void atributo2(char *dirE,char *atri,char *dirS){
	char c;
	if(tam(atri)>4){
		printf("Error en el atributo");
		return 1;
	}
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen(dirS,"w");
	while(fread(&c,sizeof c,1,ent)>0){
		if(compara(atri,"s-Mm")==0){
			if((c>64)&&(c<91))
				c=c+32;
		}else 
			if(compara(atri,"s-mM")==0){
				if((c>96)&&(c<123))
					c=c-32;
			}else{
				printf("Error en el atributo");
				return 1;
			}
		fwrite(&c,sizeof c,1,sal);
	}
	printf("texto copiado");
}
void atributo3(char *dirE,char *cad,char *dirS){
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
					printf("No esta bien escrito");
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
						}else{printf("No esta bien escrito");return 1;}	
					} 
					if(cad1[i]=='d'){
						contd++;
						contglo++;
						contn=0;
						chido++;
					}		
					if(contd>1){
						printf("No esta bien escrito");
						return 1;
					}
					if(contn>1){
						printf("No esta bien escrito");
						return 1;
					}
					if ((chido==2)&&(cad1[i]>=48&&cad1[i]<=57)){
						contnum++;
						chido=0;
						ig=1;
					}
				}
				if(chido==1){
					printf("No esta bien escrito");
					return 1;
				}
				if(contnum<contglo){
					printf("No esta bien escrito");
					return 1;
				}
				atributo3chido(dirE,cad1,dirS);
			}
			else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
}
void atributo3chido(char *dirE,char *cad,char *dirS){
	char c;
	char aux[10];
	int impre[50];
	int blin;
	int linea;
	int i,j,l,h;
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen(dirS,"w");
	for(i=1;cad[i]!='\0';i++){
		if(cad[i]=='d'){
			for(h=0;aux[h]!='\0';h++)
				aux[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				aux[l]=cad[j];
			}
			blin=chaint(aux);
			ent=fopen(dirE,"r");
			linea=1;
			while(fread(&c,sizeof c,1,ent)>0){
				//printf("%i",linea);printf("==%i\n",blin);
				
				if(linea==blin){
					fwrite(&c,sizeof c,1,sal);
				}
				if(c=='\n'){
					++linea;
				}
			}
			//printf("%i\n",blin);
		}
	}
	printf("Texto copiado");
}
void atributo4(char *dirE,char *cad,char *dirS){
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
		if((cad[i]!=45)&&(cad[i]!=67)&&(cad[i]!=110)&&(cad[i]!=100)&&((cad[i]>58)||(cad[i]<47))){
			printf("No esta bien escrito");
			return 1;
		}
	}
	if(cad[0]=='C'){
		if(cad[1]=='-'){
			if(cad[2]=='n'){
				if(cad[3]==NULL){
					printf("No esta bien escrito");
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
						}else{printf("No esta bien escrito");return 1;}	
					} 
					if(cad1[i]=='d'){
						contd++;
						contglo++;
						contn=0;
						chido++;
					}		
					if(contd>1){
						printf("No esta bien escrito");
						return 1;
					}
					if(contn>1){
						printf("No esta bien escrito");
						return 1;
					}
					if ((chido==2)&&(cad1[i]>=48&&cad1[i]<=57)){
						contnum++;
						chido=0;
						ig=1;
					}
				}
				if(chido==1){
					printf("No esta bien escrito");
					return 1;
				}
				if(contnum<contglo){
					printf("No esta bien escrito");
					return 1;
				}
				atributo4chido(dirE,cad1,dirS);
			}
			else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
}
void atributo4chido(char *dirE,char *cad,char *dirS){
	char c;
	char aux[10];
	int impre[50];
	int blin;
	int columna;
	int linea;
	int glolinea=1;
	int i,j,l,h;
	int memo=0;
	for(h=0;h<=50;h++){
		impre[h]=NULL;
	}
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen(dirS,"w");
	for(i=1;cad[i]!='\0';i++){
		if(cad[i]=='d'){
			for(h=0;aux[h]!='\0';h++)
				aux[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				aux[l]=cad[j];
			}
			blin=chaint(aux);
			impre[memo]=blin;
			//printf("%i pos %i\n",impre[memo],memo);
			memo++;
		}
	}
	while(fread(&c,sizeof c,1,ent)>0){
		if(c=='\n'){
			glolinea++;
		}
	}
	int fd=1;
	glolinea++;
	while(fd!=glolinea){
		for(h=0;impre[h]!=0;h++){
			ent=fopen(dirE,"r");
			columna=1;
			linea=1;
			while(fread(&c,sizeof c,1,ent)>0){
				//printf("%i==%i\n",columna,impre[h]);
				if(columna==impre[h]&&linea==fd){
					fwrite(&c,sizeof c,1,sal);	
				}
				if(c=='\n'){
					linea++;
					columna=1;
				}
				if(c==' '||c=='	'){
					columna++;
				}
			}
		}
		c='\n';
		fwrite(&c,sizeof c,1,sal);
		fd++;
	}
	printf("Texto copiado");
}
void atributo5(char *dirE,char *cad,char *dirS){
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
		if((cad[i]!=45)&&(cad[i]!=73)&&(cad[i]!=76)&&(cad[i]!=110)&&(cad[i]!=100)&&((cad[i]>58)||(cad[i]<47))){
			printf("No esta bien escrito");
			return 1;
		}
	}
	if(cad[0]=='I'){
		if(cad[1]=='L'){
		if(cad[2]=='-'){
			if(cad[3]=='n'){
				if(cad[4]==NULL){
					printf("No esta bien escrito");
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
						}else{printf("No esta bien escrito");return 1;}	
					} 
					if(cad1[i]=='d'){
						contd++;
						contglo++;
						contn=0;
						chido++;
					}		
					if(contd>1){
						printf("No esta bien escrito");
						return 1;
					}
					if(contn>1){
						printf("No esta bien escrito");
						return 1;
					}
					if ((chido==2)&&(cad1[i]>=48&&cad1[i]<=57)){
						contnum++;
						chido=0;
						ig=1;
					}
				}
				if(chido==1){
					printf("No esta bien escrito");
					return 1;
				}
				if(contnum<contglo){
					printf("No esta bien escrito");
					return 1;
				}
				atributo5chido(dirE,cad1,dirS);
			}
			else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
	}else{printf("No esta bien escrito");return 1;}	
	
}
void atributo5chido(char *dirE,char *cad,char *dirS){
	char c;
	char aux[10];
	int impre[50];
	int blin;
	int columna;
	int linea;
	int i,j,l,h;
	int memo=0;
	for(h=0;h<=50;h++){
		impre[h]=NULL;
	}
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen(dirS,"w");
	
	for(i=1;cad[i]!='\0';i++){
		if(cad[i]=='d'){
			for(h=0;aux[h]!='\0';h++)
				aux[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				aux[l]=cad[j];
			}
			blin=chaint(aux);
			impre[memo]=blin;
			//printf("%i pos %i\n",impre[memo],memo);
			memo++;
		}
	}
	linea=1;
	while(fread(&c,sizeof c,1,ent)>0){
		
		for(h=0;impre[h]!=0;h++){
			//printf("%i==%i\n",linea,impre[h]);
			if(linea==impre[h]){
				//printf("hola\n");
				if(c=='\n'){
					fwrite(&c,sizeof c,1,sal);
					c='\n';
				}
			}
		}
		fwrite(&c,sizeof c,1,sal);
		if(c=='\n'){
			linea++;
		}
			
	}
	printf("Texto copiado");	
}
void atributo6(char *dirE,char *cad,char *dirS){
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
		if((cad[i]!=45)&&(cad[i]!=73)&&(cad[i]!=67)&&(cad[i]!=110)&&(cad[i]!=100)&&((cad[i]>58)||(cad[i]<47))){
			printf("No esta bien escrito");
			return 1;
		}
	}
	if(cad[0]=='I'){
		if(cad[1]=='C'){
		if(cad[2]=='-'){
			if(cad[3]=='n'){
				if(cad[4]==NULL){
					printf("No esta bien escrito");
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
						}else{printf("No esta bien escrito");return 1;}	
					} 
					if(cad1[i]=='d'){
						contd++;
						contglo++;
						contn=0;
						chido++;
					}		
					if(contd>1){
						printf("No esta bien escrito");
						return 1;
					}
					if(contn>1){
						printf("No esta bien escrito");
						return 1;
					}
					if ((chido==2)&&(cad1[i]>=48&&cad1[i]<=57)){
						contnum++;
						chido=0;
						ig=1;
					}
				}
				if(chido==1){
					printf("No esta bien escrito");
					return 1;
				}
				if(contnum<contglo){
					printf("No esta bien escrito");
					return 1;
				}
				atributo6chido(dirE,cad1,dirS);
			}
			else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
	}else{printf("No esta bien escrito");return 1;}	
	
}
void atributo6chido(char *dirE,char *cad,char *dirS){
	char c;
	char aux[10];
	int impre[50];
	char ward[10];
	int blin;
	int columna;
	int linea;
	int i,j,l,h;
	int memo=0;
	for(h=0;h<=50;h++){
		impre[h]=NULL;
	}
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen(dirS,"w");
	
	for(i=1;cad[i]!='\0';i++){
		if(cad[i]=='d'){
			for(h=0;aux[h]!='\0';h++)
				aux[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				aux[l]=cad[j];
			}
			blin=chaint(aux);
			impre[memo]=blin;
			//printf("%i pos %i\n",impre[memo],memo);
			memo++;
		}
	}
	linea=1;
	columna=1;
	char esp='	';
	char esp1=' ';
	char nub;
	while(fread(&c,sizeof c,1,ent)>0){
		for(h=0;ward[h]!='\0';h++){
			ward[h]==NULL;
		}
		if(linea==1&&columna==1){
			nub='1';
			fwrite(&nub,sizeof nub,1,sal);
			fwrite(&esp1,sizeof esp1,1,sal);
			columna++;
		}
		for(h=0;impre[h]!=0;h++){
			//printf("%i==%i\n",linea,impre[h]);
			if(linea==impre[h]){
				if(columna==1){
					fwrite(&esp,sizeof esp,1,sal);
					fwrite(&esp1,sizeof esp1,1,sal);
					columna++;
				}
			}
		}
		fwrite(&c,sizeof c,1,sal);
		if(c=='\n'){
			linea++;
			columna=1;
			inachar(linea,ward,10);
			for(h=0;ward[h]!='\0';h++){
				fwrite(&ward[h],sizeof ward[h],1,sal);
			}
			fwrite(&esp1,sizeof esp1,1,sal);
		}
		if(c==' '){
			columna++;
		}	
	}
	printf("Texto copiado");	
}
void atributo7(char *dirE,char *cadi,char *dirS){
	char c;
	char pal[]="veces";
	int impre[50];
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen("cache.txt","w");
	int linea;
	int columna;
	int i,h;
	int con=0;
	int ver;
	char esp=' ';
	char ward[10];
	for(h=0;h<=50;h++){
		impre[h]=NULL;
	}
	if(cadi[0]=='C'){
		if(cadi[1]=='C'){
		if(cadi[2]=='-'){
			if(cadi[3]==NULL){
				printf("No esta bien escrito");
				return 1;
			}
			if (ent == NULL) {
        		printf("No se pudo abrir el archivo");
        		return 1;
    		}
    		char*cad=subchar(cadi,"-");
			eliminar(cad);
    		linea=1;
			columna=1;
			i=0;
			int totalin=1;
			//printf(cad);
			int connum=0;
			//printf("%i",tamchido);
			while(fread(&c,sizeof c,1,ent)>0){
				if(columna==1){
					fwrite(&esp,sizeof esp,1,sal);
					columna++;
				}
				if(c=='\n'){
					fwrite(&esp,sizeof esp,1,sal);
				}
				fwrite(&c,sizeof c,1,sal);
				if(c==' '){
					columna++;
				}
				if(c=='\n'){
					totalin++;
					columna=1;
				}
			}
			fclose(sal);
			fclose(ent);
			linea=1;
			columna=1;
			ent=fopen("cache.txt","r");
			sal=fopen(dirS,"w");
			int antes=0;
			int despues=0;
			char comparacion[50];
			int k=0;
			int palcon=0;
			comparacion[k]=' ';
			for(h=0,k=1;cad[h]!='\0';h++,k++){
				comparacion[k]=cad[h];
			}
			comparacion[k]=' ';
			int tamchido=tam(comparacion);
			//printf("%i",tamchido);
			while(fread(&c,sizeof c,1,ent)>0){
				palcon++;
				antes=i-1;
				despues=i+tamchido+1;
				if(c=='\n'){
					totalin++;
				}
				if((c==comparacion[i])||(c==comparacion[i]+32)||(c+32==comparacion[i])||(c==comparacion[i]-32)||(c-32==comparacion[i])){
					i++;
				}else{
					i=0;
				}
				if(i==tamchido){
					con++;
				}
				if(c=='\n'){
					linea++;
					impre[connum]=con;
					connum++;
					columna=1;
					con=0;	
				}
			}
			impre[connum]=con;
			linea=1;
			columna=1;
			connum=0;
			ent=fopen("cache.txt","r");
    		while(fread(&c,sizeof c,1,ent)>0){
				if(columna==1){
					inachar(impre[connum],ward,10);
					for(h=0;ward[h]!='\0';h++){
						fwrite(&ward[h],sizeof ward[h],1,sal);
					}
					columna++;
					fwrite(&esp,sizeof esp,1,sal);
					for(h=0;pal[h]!='\0';h++){
						fwrite(&pal[h],sizeof pal[h],1,sal);
					}
					//columna++;
				}
				fwrite(&c,sizeof c,1,sal);
				if(c=='\n'){
					linea++;
					columna=1;
					connum++;	
				}
				if(c==' '){
					columna++;
				}
			}
			//printf("%i",impre[16]);
			fclose(sal);
			fclose(ent);
			printf("Texto copiado");
    	}else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
}
void atributo8(char *dirE,char *cadi,char *dirS){
	char c;
	char pal[]="veces ";
	int impre[50];
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen("cache.txt","w");
	int linea;
	int columna;
	int i,h;
	int con=0;
	int ver;
	char esp=' ';
	char ward[10];
	for(h=0;h<=50;h++){
		impre[h]=NULL;
	}
	if(cadi[0]=='C'){
		if(cadi[1]=='P'){
		if(cadi[2]=='-'){
			if(cadi[3]==NULL){
				printf("No esta bien escrito");
				return 1;
			}
			if (ent == NULL) {
        		printf("No se pudo abrir el archivo");
        		return 1;
    		}
    		char*cad=subchar(cadi,"-");
			eliminar(cad);
    		linea=1;
			columna=1;
			i=0;
			int totalin=1;
			//printf(cad);
			int connum=0;
			//printf("%i",tamchido);
			while(fread(&c,sizeof c,1,ent)>0){
				if(columna==1){
					fwrite(&esp,sizeof esp,1,sal);
					columna++;
				}
				if(c=='\n'){
					fwrite(&esp,sizeof esp,1,sal);
				}
				fwrite(&c,sizeof c,1,sal);
				if(c==' '){
					columna++;
				}
				if(c=='\n'){
					totalin++;
					columna=1;
				}
			}
			fclose(sal);
			fclose(ent);
			linea=1;
			columna=1;
			ent=fopen("cache.txt","r");
			sal=fopen(dirS,"w");
			int antes=0;
			int despues=0;
			char comparacion[50];
			int k=0;
			int palcon=0;
			comparacion[k]=' ';
			for(h=0,k=1;cad[h]!='\0';h++,k++){
				comparacion[k]=cad[h];
			}
			int tamchido=tam(comparacion);
			//printf("%i",tamchido);
			while(fread(&c,sizeof c,1,ent)>0){
				palcon++;
				antes=i-1;
				despues=i+tamchido+1;
				if(c=='\n'){
					totalin++;
				}
				if((c==comparacion[i])||(c==comparacion[i]+32)||(c+32==comparacion[i])||(c==comparacion[i]-32)||(c-32==comparacion[i])){
					i++;
				}else{
					i=0;
				}
				if(i==tamchido){
					con++;
				}
				if(c=='\n'){
					linea++;
					impre[connum]=con;
					connum++;
					columna=1;
					con=0;	
				}
			}
			impre[connum]=con;
			linea=1;
			columna=1;
			connum=0;
			ent=fopen("cache.txt","r");
    		while(fread(&c,sizeof c,1,ent)>0){
				if(columna==1){
					inachar(impre[connum],ward,10);
					for(h=0;ward[h]!='\0';h++){
						fwrite(&ward[h],sizeof ward[h],1,sal);
					}
					columna++;
					fwrite(&esp,sizeof esp,1,sal);
					for(h=0;pal[h]!='\0';h++){
						fwrite(&pal[h],sizeof pal[h],1,sal);
					}
					//columna++;
				}
				fwrite(&c,sizeof c,1,sal);
				if(c=='\n'){
					linea++;
					columna=1;
					connum++;	
				}
				if(c==' '){
					columna++;
				}
			}
			//printf("%i",impre[16]);
			fclose(sal);
			fclose(ent);
			printf("Texto copiado");
    	}else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
}
void atributo9(char *dirE,char *cadi,char *dirS){
	char c;
	char pal[]="veces ";
	int impre[50];
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen("cache.txt","w");
	int linea;
	int columna;
	int i,h;
	int con=0;
	int ver;
	char esp=' ';
	char ward[10];
	for(h=0;h<=50;h++){
		impre[h]=NULL;
	}
	if(cadi[0]=='C'){
		if(cadi[1]=='S'){
		if(cadi[2]=='-'){
			if(cadi[3]==NULL){
				printf("No esta bien escrito");
				return 1;
			}
			if (ent == NULL) {
        		printf("No se pudo abrir el archivo");
        		return 1;
    		}
    		char*cad=subchar(cadi,"-");
			eliminar(cad);
    		linea=1;
			columna=1;
			i=0;
			int totalin=1;
			//printf(cad);
			int connum=0;
			//printf("%i",tamchido);
			while(fread(&c,sizeof c,1,ent)>0){
				if(columna==1){
					fwrite(&esp,sizeof esp,1,sal);
					columna++;
				}
				if(c=='\n'){
					fwrite(&esp,sizeof esp,1,sal);
				}
				fwrite(&c,sizeof c,1,sal);
				if(c==' '){
					columna++;
				}
				if(c=='\n'){
					totalin++;
					columna=1;
				}
			}
			fclose(sal);
			fclose(ent);
			linea=1;
			columna=1;
			ent=fopen("cache.txt","r");
			sal=fopen(dirS,"w");
			int antes=0;
			int despues=0;
			char comparacion[50];
			int k;
			int palcon=0;
			for(h=0,k=0;cad[h]!='\0';h++,k++){
				comparacion[k]=cad[h];
			}
			comparacion[k]=' ';
			int tamchido=tam(comparacion);
			//printf("%i",tamchido);
			while(fread(&c,sizeof c,1,ent)>0){
				palcon++;
				antes=i-1;
				despues=i+tamchido+1;
				if(c=='\n'){
					totalin++;
				}
				if((c==comparacion[i])||(c==comparacion[i]+32)||(c+32==comparacion[i])||(c==comparacion[i]-32)||(c-32==comparacion[i])){
					i++;
				}else{
					i=0;
				}
				if(i==tamchido){
					con++;
				}
				if(c=='\n'){
					linea++;
					impre[connum]=con;
					connum++;
					columna=1;
					con=0;	
				}
			}
			impre[connum]=con;
			linea=1;
			columna=1;
			connum=0;
			ent=fopen("cache.txt","r");
    		while(fread(&c,sizeof c,1,ent)>0){
				if(columna==1){
					inachar(impre[connum],ward,10);
					for(h=0;ward[h]!='\0';h++){
						fwrite(&ward[h],sizeof ward[h],1,sal);
					}
					columna++;
					fwrite(&esp,sizeof esp,1,sal);
					for(h=0;pal[h]!='\0';h++){
						fwrite(&pal[h],sizeof pal[h],1,sal);
					}
					//columna++;
				}
				fwrite(&c,sizeof c,1,sal);
				if(c=='\n'){
					linea++;
					columna=1;
					connum++;	
				}
				if(c==' '){
					columna++;
				}
			}
			//printf("%i",impre[16]);
			fclose(sal);
			fclose(ent);
			printf("Texto copiado");
    	}else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
}
void atributo10(char *dirE,char *cad,char *dirS){
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
				atributo10chido(dirE,cad1,dirS);			
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
	}else{printf("No esta bien escrito");return 1;}	
}
void atributo10chido(char *dirE,char *cade,char *dirS){
	char cad1[50],cad2[50];
	int i,j;
	for(i=0;cade[i]!=':';++i){
		cad1[i]=cade[i];
	}
	i++;
	for(j=0;cade[i]!='\0';i++,j++){
		cad2[j]=cade[i];
	}
	FILE *ent,*sal;
 	char caracteres[100];
 	ent = fopen(dirE,"r");
 	sal = fopen (dirS,"w" );
 	if (ent == NULL)
 		return 1;
 	else{
 	    while (feof(ent) == 0){
 			fgets(caracteres,100,ent);
 			//printf("si--%s\n",caracteres);
 			//printf("no---%s\n",remplasador(caracteres,cad2,cad1));
 			fputs(remplasador(caracteres,cad1,cad2),sal);
 			for(i=0;caracteres[i]!='\0';i++){
 				caracteres==NULL;
			}
 	    }
    }
    printf("Texto copiado");
	return 0;
}

