#include <stdio.h>
#include <stdlib.h>
#define N 3

int tam(char *s){//recebe a string como ponteiro
	int i;
	for(i=0;s[i]!='\0';i++);//conta as letras at� o '\0'
	return i;//retorna o n�mero de caracteres
}
/*
int tam(char *s){//fun��o equivalente � anterior
  int i;
  for(i=0;*s!='\0';i++,s++);
  return i;
}
*/
//-----------------------------------------
void inverte(char *s){
	char *aux;
	aux=s;//guarda o endereco inicial
	while(*s!='\0'){//enquanto o conteudo do ponteiro nao for '\0'
					//incrementa o ponteiro
	    s++;
	}
	s--;
	while(s>=aux){//enquanto endere�o de s for maior ou igual 
					//ao endere�o inicial
		printf("%c",*s--);//printa o conte�do do endereco
						// e depois decrementa o ponteiro
	}
	
}
void hifeniza(char *s){
}

int letrasA(char *s){
	
}
//----------------------------------------
int main(){
	char palavra[25];
	int i,t;
	for(i=0;i<N;i++){
		printf("Digite uma palavra: ");
		scanf(" %s",palavra);
		t=tam(palavra);
		printf("Tamanho: %d\n",t);
		inverte(palavra);
	//	hifeniza(palavra);
	//	t=letrasA(palavra);
	//	printf("Letras 'a': %d\n",t);
		printf("\n");
	}
	
}
