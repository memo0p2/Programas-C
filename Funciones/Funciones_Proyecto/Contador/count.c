#include<stdio.h>
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
int main(int argc,char *argv[]){
	FILE *f;
	f = fopen(argv[1], "r");
	int con=0;
    if (f == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo %s\n", argv[1]);
        return 1;
    }
    while(fread(&c,sizeof c,1,ent)>0){
		
		fwrite(&c,sizeof c,1,sal);			
    }
    printf("Se repite: %i\n",con);
	return 0;
}
