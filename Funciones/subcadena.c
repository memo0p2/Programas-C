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
int main()
{
	char cadena[] = "nd1nd2nd3";
	char subcadena[] = "n";
	char *ret = subchar(cadena,subcadena);

   printf("%s\n", ret);

   return 0;
}

