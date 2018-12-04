void atributo7(char *dirE,char *cadi,char *dirS){
	char c;
	char pal[]="veces";
	int impre[50];
	FILE *ent,*sal;
	ent=fopen(dirE,"r");
	sal=fopen(dirS,"w");
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
			int tamchido=tam(cad);
			printf(cad);
			int connum=0;
			printf("%i",tamchido);
			while(fread(&c,sizeof c,1,ent)>0){
				if(c=='\n'){
					totalin++;
				}
				if((c==cad[i])||(c==cad[i]+32)||(c+32==cad[i])||(c==cad[i]-32)||(c-32==cad[i])){
					i++;
				}else{
					i=0;
				}
				if(i==tamchido){
					con++;
				}
				//fwrite(&c,sizeof c,1,sal);
				if(c=='\n'){
					linea++;
					impre[connum]=con;
					connum++;
					columna=1;
					con=0;	
				}
			}
			
			for(h=0;impre[h]<=50;h++){
				printf("%i\n",impre[h]);
			}
			linea=1;
			columna=1;
			totalin=1;
			connum=0;
			ent=fopen(dirE,"r");
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
					fwrite(&esp,sizeof esp,1,sal);
				}
				fwrite(&c,sizeof c,1,sal);
				if(c=='\n'){
					linea++;
					columna=1;
					printf("Salto de linea prro el con es %i\n",con);
					con=0;
					connum++;	
				}
				if(c==' '){
					columna++;
				}
			}
			printf("Texto copiado");
    	}else{printf("No esta bien escrito");return 1;}
		}else{printf("No esta bien escrito");return 1;}
	}else{printf("No esta bien escrito");return 1;}	
}
