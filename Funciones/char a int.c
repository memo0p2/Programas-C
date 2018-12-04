#include <stdio.h>
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
int main(){
	char hola[40];
	hola[0]='3';
	int val;
	val=chaint(hola);
	printf("%i",val);
}

