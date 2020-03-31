#include <stdio.h>
#include <stdlib.h>
//definição de um produto
typedef struct{
	int codigo;
	char nome[21];
	int estoque;
	float preco;
}Produto;

void mostra(Produto *p){//recebe o produto como um ponteiro 
	
	printf("Codigo: %d\n",p->codigo);//(*p).codigo
	printf("Nome: %s\n",p->nome);//)(*p).nome
	printf("Estoque: %d\n",p->estoque);//(*p).estoque
	printf("Preco: R$ %.2f\n\n",p->preco);//(*p).preco
}
//-----------------------------------------------
int main(){
	Produto *p=(Produto*)malloc(sizeof(Produto)*5);
	Produto *pp;//ponteiro auxiliar 
	pp=p;//guarda em pp o endereço inicial da área reservado pelo malloc
	int i;
	//usando notação de ponteiro
	for (i=0;i<5;i++,p++){
		printf("Informe o codigo do %d produto: ",i+1);
		//scanf("%d",&p[i].codigo);
		scanf("%d",&p->codigo);
		printf("Informe o nome: ");
		fflush(stdin);
		//gets(p[i].nome);
		gets(p->nome);
		printf("Informe o estoque: ");
		//scanf("%d",&p[i].estoque);
		scanf("%d",&p->estoque);
		printf("Informe o preco: ");
		//scanf("%f",&p[i].preco);
		scanf("%f",&p->preco);
	//	p++;//incrementando o ponteiro
		printf("\n");
	}
	system("cls");//limpa a tela
	//mostra os dados
	printf("*** Dados do produto ***\n");
	p=pp;//restaura o ponteiro para o inicio do vetor
	for(i=0;i<5;i++,p++){	
		mostra(p);
		//p++;
	}
	
}
