#include<stdio.h>
int strcmp(char*a,char*b){
    int i = 0;
    while (a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i]) 
			return(a[i]-b[i]);
        i++;
    }
    if (a[i]=='\0'&& b[i]=='\0') return 0;
    return (a[i] - b[i]);
}
char *subcadena(char cad[],char ch[]){
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
int atoi(char *str){
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
void intochar(int value, char* str, int base) {
	char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* wstr=str;
	int sign;
	if (base<2 || base>35){ *wstr='\0'; return; }
	if ((sign=value) < 0) value = -value;
	do *wstr++ = num[value%base]; while(value/=base);
	if(sign<0) *wstr++='-';
	*wstr='\0';
	reves(str,wstr-1);
}
void reves(char* begin, char* end) {
	char aux;
	while(end>begin)
		aux=*end, *end--=*begin, *begin++=aux;
}
void eliminar(char *cadena) {
	int i,j;
	for(i=0,j=1;cadena[i]!='\0';i++,j++){
		cadena[i]=cadena[j];
	}
}
int tam(char *s) {
   int ch = 0;
   while(s[ch] != '\0')
      ch++;  
   return ch;
}
int main(int argc,char *argv[]){
	int i;
	char op[5];
	FILE *ent;
	ent=fopen(argv[1],"r");
	if(argc>4){
		printf("Muchos argumentos");
		return 1;
	}
	if(ent==NULL){
		printf("Error al abrir el archivo");
		return 1;
	}
	if(argv[3]==NULL){
		printf("No hay archivo de salida");
		return 1;
	}
	for(i=0;argv[2][i]!=':';i++){
		op[i]=argv[2][i];
	}
	if(strcmp(op,"S")==0)
		parte1(argv[1],argv[2],argv[3]);
	else if(strcmp(op,"s")==0)
		parte2(argv[1],argv[2],argv[3]);
	else if(strcmp(op,"L")==0)
		parte3(argv[1],argv[2],argv[3]);
	else if(strcmp(op,"C")==0)
		parte4(argv[1],argv[2],argv[3]);
	else if(strcmp(op,"IL")==0)
		parte5(argv[1],argv[2],argv[3]);
	else if(strcmp(op,"IC")==0)
		parte6(argv[1],argv[2],argv[3]);
	else if(strcmp(op,"CC")==0)
		parte7(argv[1],argv[2],argv[3]);
	else{
		printf("No existe esa opcion");
		return 1;
	}
	return 0;
}
void parte1(char *entra,char *coma,char *sali){
	int car;
	FILE *ent,*sal;
	ent=fopen(entra,"r");
	sal=fopen(sali,"w");
	while((car=fgetc(ent))!=EOF){
		if(car==coma[2])
			car=coma[3];
		fputc(car,sal);
	}
	printf("Revise el archivo de sailida");
}
void parte2(char *entra,char *coma,char *sali){
	int car;
	FILE *ent,*sal;
	ent=fopen(entra,"r");
	sal=fopen(sali,"w");
	while((car=fgetc(ent))!=EOF){
		if(strcmp(coma,"s:Mm")==0){
			if((car>64)&&(car<91))
				car=car+32;
		}else 
			if(strcmp(coma,"s:mM")==0){
				if((car>96)&&(car<123))
					car=car-32;
			}else{
				printf("Error en el atributo");
				return 1;
			}
		fputc(car,sal);
	}
	printf("Revise el archivo de sailida");
}
void parte3(char *entra,char *coma,char *sali){
	char*cad=subcadena(coma,"n");
	int car;
	char help[20];
	int lin;
	int linea;
	int i,j,l,h;
	FILE *ent,*sal;
	ent=fopen(entra,"r");
	sal=fopen(sali,"w");
	for(i=0;cad[i]!='\0';i++){
		if(cad[i]=='n'){
			for(h=0;help[h]!='\0';h++)
				help[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				help[l]=cad[j];
			}
			lin=atoi(help);
			ent=fopen(entra,"r");
			linea=1;
			while((car=fgetc(ent))!=EOF){				
				if(linea==lin){
					fputc(car,sal);
				}
				if(car==10){
					++linea;
				}
			}
		}
	}
	printf("Revise el archivo de sailida");
}
void parte4(char *entra,char *coma,char *sali){
	char*cad=subcadena(coma,"n");
	char car;
	char help[10];
	int numeros[50];
	int lin,columna,linea,i,j,l,h;
	int totalin=1,bandera=0;
	for(h=0;h<=50;h++){
		numeros[h]=NULL;
	}
	FILE *ent,*sal;
	ent=fopen(entra,"r");
	sal=fopen(sali,"w");
	for(i=0;cad[i]!='\0';i++){
		if(cad[i]=='n'){
			for(h=0;help[h]!='\0';h++)
				help[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				help[l]=cad[j];
			}
			lin=atoi(help);
			numeros[bandera]=lin;
			bandera++;
		}
	}
	while(fread(&car,sizeof car,1,ent)>0){
		if(car=='\n'){
			totalin++;
		}
	}
	int fd=1;
	totalin++;
	while(fd!=totalin){
		for(h=0;numeros[h]!=0;h++){
			ent=fopen(entra,"r");
			columna=1;
			linea=1;
			while(fread(&car,sizeof car,1,ent)>0){
				if(columna==numeros[h]&&linea==fd){
					fwrite(&car,sizeof car,1,sal);	
				}
				if(car=='\n'){
					linea++;
					columna=1;
				}
				if(car==' '){
					columna++;
				}
			}
		}
		car='\n';
		fwrite(&car,sizeof car,1,sal);
		fd++;
	}
	printf("Revise el archivo de sailida");
}
void parte5(char *entra,char *coma,char *sali){
	char*cad=subcadena(coma,"n");
	int car,lin,linea;
	char help[10];
	int numeros[50];
	int i,j,l,h;
	int bandera=0;
	FILE *ent,*sal;
	ent=fopen(entra,"r");
	sal=fopen(sali,"w");
	for(h=0;h<=50;h++){
		numeros[h]=NULL;
	}
	for(i=0;cad[i]!='\0';i++){
		if(cad[i]=='n'){
			for(h=0;help[h]!='\0';h++)
				help[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				help[l]=cad[j];
			}
			lin=atoi(help);
			numeros[bandera]=lin;
			bandera++;
		}
	}
	linea=1;
	while((car=fgetc(ent))!=EOF){
		for(h=0;numeros[h]!=0;h++){
			if(linea==numeros[h]){
				if(car==10){
					fputc(car,sal);
					car=10;
				}
			}
		}
		fputc(car,sal);
		if(car==10){
			linea++;
		}		
	}
	printf("Revise el archivo de sailida");	
}
void parte6(char *entra,char *coma,char *sali){
	char*cad=subcadena(coma,"n");
	int c;
	char help[10];
	int numeros[50];
	char alma[10];
	int lin,columna,linea;
	int i,j,l,h;
	int bandera=0;
	char tab='	';
	char tab1=' ';
	char nub;
	FILE *ent,*sal;
	ent=fopen(entra,"r");
	sal=fopen(sali,"w");
	for(h=0;h<=50;h++){
		numeros[h]=NULL;
	}
	for(i=0;cad[i]!='\0';i++){
		if(cad[i]=='n'){
			for(h=0;help[h]!='\0';h++)
				help[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				help[l]=cad[j];
			}
			lin=atoi(help);
			numeros[bandera]=lin;
			bandera++;
		}
	}
	linea=0;
	columna=0;
	while((c=fgetc(ent))!=EOF){
		if(c==' '){
			columna++;
		}
		for(h=0;alma[h]!='\0';h++){
			alma[h]==NULL;
		}
		for(h=0;numeros[h]!=0;h++){
			if(columna==numeros[h]){
				if(c==' '){
					c='	';
				}
			}
		}
		if(linea==0&&columna==0){
			nub='1';
			linea++;
			columna=0;
			fputc(nub,sal);
			fputc(tab1,sal);
		}
		fputc(c,sal);
		if(c=='\n'){
			linea++;
			columna=0;
			intochar(linea,alma,10);
			for(h=0;alma[h]!='\0';h++){
				fputc(alma[h],sal);
			}
			fputc(tab1,sal);
		}	
	}
	printf("Revise el archivo de sailida");	
}
void parte7(char *entra,char *coma,char *sali){
	char*cad=subcadena(coma,":");
	eliminar(cad);
	char c;
   	int linea=1,columna=1,i=0,lineastotal=1,connum=0,con=0,antes=0,despues=0,k=0,palcon=0;
	int h,ver;
	char tab=' ';
	int numeros[50];
	char comparacion[50];
	FILE *ent,*sal;
	ent=fopen(entra,"r");
	sal=fopen("basura.txt","w");
	for(h=0;h<=50;h++){
		numeros[h]=NULL;
	}
	while(fread(&c,sizeof c,1,ent)>0){
		if(columna==1){
			fwrite(&tab,sizeof tab,1,sal);
			columna++;
		}
		if(c=='\n'){
			fwrite(&tab,sizeof tab,1,sal);
		}
		fwrite(&c,sizeof c,1,sal);
		if(c==' '){
			columna++;
		}
		if(c=='\n'){
			lineastotal++;
			columna=1;
		}
	}
	if(fread(&c,sizeof c,1,ent)==0){
		fwrite(&tab,sizeof tab,1,sal);
	}
	fclose(sal);
	fclose(ent);
	linea=1;
	columna=1;
	ent=fopen("basura.txt","r");
	sal=fopen(sali,"w");
	comparacion[k]=' ';
	for(h=0,k=1;cad[h]!='\0';h++,k++){
		comparacion[k]=cad[h];
	}
	comparacion[k]=' ';
	int tamtotal=tam(comparacion);
	while(fread(&c,sizeof c,1,ent)>0){
		palcon++;
		antes=i-1;
		despues=i+tamtotal+1;
		if(c=='\n'){
			lineastotal++;
		}
		if((c==comparacion[i])||(c==comparacion[i]+32)||(c+32==comparacion[i])||(c==comparacion[i]-32)||(c-32==comparacion[i])){
			i++;
		}else{
			i=0;
		}
		if(i==tamtotal){
			con++;
		}
		if(c=='\n'){
			linea++;
			numeros[connum]=con;
			connum++;
			columna=1;
			con=0;	
		}
	}
	numeros[connum]=con;
	ent=fopen(sali,"r+");
	for(i=0;i<=connum;i++){
		fprintf(ent,"En la linea %i se repite %i\n",i+1,numeros[i]);
	}
	printf("Revise el archivo de sailida");
}
