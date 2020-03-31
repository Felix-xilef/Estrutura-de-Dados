#include <stdio.h>
#include <stdlib.h>
//definição de um produto
typedef struct{
	int codigo;
	char nome[21];
	int estoque;
	float preco;
}Produto;
void mostra(Produto p){
	
	printf("Codigo: %d\n",p.codigo);
	printf("Nome: %s\n",p.nome);
	printf("Estoque: %d\n",p.estoque);
	printf("Preco: R$ %.2f\n\n",p.preco);
}

int main(){
	Produto p[5];
	int i;
	for (i=0;i<5;i++){
		printf("Informe o codigo do %d produto: ",i+1);
		scanf("%d",&p[i].codigo);
		printf("Informe o nome: ");
		fflush(stdin);
		gets(p[i].nome);
		printf("Informe o estoque: ");
		scanf("%d",&p[i].estoque);
		printf("Informe o preco: ");
		scanf("%f",&p[i].preco);
		printf("\n");
	}
	system("cls");//limpa a tela
	//mostra os dados
	printf("*** Dados do produto ***\n");
	for(i=0;i<5;i++)
		mostra(p[i]);
	
}
