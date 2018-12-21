#include<stdio.h>
char *cadsub(char cad[],char cad1[]){
	int i,j=0;
    for(i=0;cad[i]!='\0';i++){
      	while(cad[i]==cad1[j]){
			i++;j++;
    	}
    if(cad1[j]=='\0')
		return cad+i-j;
    else j=0;
    }
	return NULL;
}
int atoi(char *str){
	int res=0;
	int signo=1;
	int i=0;
	if(str[0]=='-'){
		signo=-1;
		i++;
	}
	for(;str[i]!='\0';i++){
		res=res*10+str[i]-'0';
	}
	return signo*res;
}
int main(int argc,char *argv[]){
	int i;
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
	if(argv[2][0]=='L'){
		opcion3(argv[1],argv[2],argv[3]);
	}else if(argv[2][0]=='I'&&argv[2][1]=='C'){
		opcion6(argv[1],argv[2],argv[3]);
	}else{
		printf("No existe esa opcion");
		return 1;
	}
	return 0;
}
void ichar(int value, char* str, int base) {
	char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* wstr=str;
	int sign;
	if (base<2 || base>35){ *wstr='\0'; return; }
	if ((sign=value) < 0) value = -value;
	do *wstr++ = num[value%base]; while(value/=base);
	if(sign<0) *wstr++='-';
	*wstr='\0';
	voltea(str,wstr-1);
}
void voltea(char* begin, char* end) {
	char aux;
	while(end>begin)
		aux=*end, *end--=*begin, *begin++=aux;
}
void opcion3(char *entrada,char *atributo,char *salida){
	int lin;
	int linea;
	int i,j,l,h;
	FILE *ent,*sal;
	char*cad=cadsub(atributo,"n");
	char c;
	char burbu[20];
	ent=fopen(entrada,"r");
	sal=fopen(salida,"w");
	
	for(i=0;cad[i]!='\0';i++){
		if(cad[i]=='n'){
			for(h=0;burbu[h]!='\0';h++)
				burbu[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				burbu[l]=cad[j];
			}
			lin=atoi(burbu);
			ent=fopen(entrada,"r");
			linea=1;
			while(fread(&c,sizeof c,1,ent)>0){
				if(linea==lin){
					fwrite(&c,sizeof c,1,sal);
				}
				if(c=='\n'){
					++linea;
				}
			}
		}
	}
	printf("Texto modificado exitosamente");
}
void opcion6(char *entrada,char *atributo,char *salida){
	int lin,columna,linea;
	int i,j,l,h;
	int bandera=0;
	char esp='	';
	char esp1=' ';
	char nub;
	char*cad=cadsub(atributo,"n");
	int c;
	char burbu[10];
	int nume[50];
	char aux[10];
	FILE *ent,*sal;
	ent=fopen(entrada,"r");
	sal=fopen(salida,"w");
	
	for(h=0;h<=50;h++){
		nume[h]=NULL;
	}
	for(i=0;cad[i]!='\0';i++){
		if(cad[i]=='n'){
			for(h=0;burbu[h]!='\0';h++)
				burbu[h]=NULL;
			for(j=i+1,l=0;(cad[j]>=48&&cad[j]<=57);j++,l++){
				burbu[l]=cad[j];
			}
			lin=atoi(burbu);
			nume[bandera]=lin;
			bandera++;
		}
	}
	linea=0;
	columna=0;
	while((c=fgetc(ent))!=EOF){
		if(c==' '){
			columna++;
		}
		for(h=0;aux[h]!='\0';h++){
			aux[h]==NULL;
		}
		for(h=0;nume[h]!=0;h++){
			if(columna==nume[h]){
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
			fputc(esp1,sal);
		}
		fputc(c,sal);
		if(c=='\n'){
			linea++;
			columna=0;
			ichar(linea,aux,10);
			for(h=0;aux[h]!='\0';h++){
				fputc(aux[h],sal);
			}
			fputc(esp1,sal);
		}	
	}
	printf("Texto modificado exitosamente");
}
