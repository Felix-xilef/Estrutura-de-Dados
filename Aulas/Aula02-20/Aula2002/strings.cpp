#include <stdio.h>
#include <stdlib.h>
#define N 3

int tam(char *s){//recebe a string como ponteiro
	int i;
	for(i=0;s[i]!='\0';i++);//conta as letras até o '\0'
	return i;//retorna o número de caracteres
}
/*
int tam(char *s){//função equivalente à anterior
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
	while(s>=aux){//enquanto endereço de s for maior ou igual 
					//ao endereço inicial
		printf("%c",*s--);//printa o conteúdo do endereco
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
