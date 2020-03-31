#include <stdio.h>
int main(){
	int idade;
	char nome[20];
	printf("Informe se nome: ");
//	scanf(" %s",nome);//scanf(" %s", &nome[0])
    gets(nome);
	printf("Informe sua idade: ");
	scanf("%d",&idade);
	printf("%s, voce tem %d anos\n",nome, idade);
}
