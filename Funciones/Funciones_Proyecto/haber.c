//copiar texto con un buffer
//Autor:Ramirez Olvera Guillermo
//fecha:22/10/2018
#include <stdio.h>
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
int tam(char *s) {
   int ch = 0;
   while(s[ch] != '\0')
      ch++;  
   return ch;
}
char *remplasador(char *str, char *orig, char *rep){
  	char cad[4096];
  	char *p;
  	if(!(p = subchar(str, orig)))
		return str;
    corta(cad, str, p-str);
	char aux[tam(p+tam(orig))+1]; 
	copiar(aux, p+tam(orig)); //Lo guardamos para que sprintf no lo machaque si rep es más largo que orig 
	sprintf(cad+(p-str), "%s%s", rep, aux);
  	return remplasador(cad, orig, rep);
}
int main(void)
{
 puts(remplasador("Se EntiENde eN como texto periodistico a aquel que se redacta para ser en publicado","en", "hola"));
  return 0;
}
