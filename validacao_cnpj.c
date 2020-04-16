#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool ehdigito(char c){
	return (c >='0' && c <= '9');
}
int convertenumerico(char c){
	return c - '0';	
}
void converteentrada(char entrada[], int cnpj[]){
	int i = strlen(entrada)-1,j = 13;
	while (i >=0){
		if(ehdigito(entrada[i])){
			cnpj[j] = convertenumerico(entrada[i]);
			j--; 
		}
		i--;		
	}
	while (j>=0){
		cnpj[j]=0;
		j--;
	}
}
bool verificadigito(int cnpj[], int mult[],int n, int m){
	int i ,soma=0,dig;
	for(i=0;i<=n;i++){
		soma=cnpj[i]*mult[i]+soma;
	}
	dig=soma%11;
	if(dig<2) dig=0;
	else dig=11-dig;
	return dig == cnpj[m];
}
int main (){
	int cnpj[14];
	int pd[12]={5,4,3,2,9,8,7,6,5,4,3,2};
	int sd[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
	int i,j;
	char entrada[50];
	printf("Entre com os 14 digitos do CNPJ:\n");
	gets (entrada);
	converteentrada(entrada,cnpj);
	if(verificadigito(cnpj,pd,11,12) && verificadigito(cnpj,sd,12,13))
		printf("cnpj valido\n");
	else printf("cnpj invalido\n");		
	return 0;
}
