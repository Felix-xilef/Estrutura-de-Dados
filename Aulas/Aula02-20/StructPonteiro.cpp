#include <stdio.h>
#include <stdlib.h>

//Definição de um produto (Struct)
typedef struct {
    int codigo;
    char nome[21];
    int estoque;
    float preco;
}Produto;

void receberProduto(Produto p) {
    
}

void mostraProduto(Produto *p) {
    //printf("\tCodigo: %d\n\tNome: %s\n\tEstoque: %d\n\tPreco: %.2f\n\n", p.codigo, p.nome, p.estoque, p.preco);
    printf("\tCodigo: %d\n\tNome: %s\n\tEstoque: %d\n\tPreco: %.2f\n\n", p->codigo, p->nome, p->estoque, p->preco);
}

main() {
    int tamVet;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamVet);
    system("cls");

    Produto *p = (Produto*)malloc(sizeof(Produto)*tamVet); //*5 - para um vetor de cinco ...
    Produto *pp = p; //ponteiro auxiliar "pp" recebe a posição inicial de "p"

    //Receber Dados
    for (int i = 0; i < tamVet; i++, p++) { //p++ = incrementando o ponteiro
        printf("Produto %d:\n\n", (i+1));
        printf("\tInforme o codigo do produto: ");
        scanf("%d", &p->codigo); // scanf("%d", &p[i].codigo);
        printf("\tInforme o nome do produto: ");
        fflush(stdin);
        gets(p->nome); // gets(p[i].nome);
        printf("\tInforme o estoque do produto: ");
        scanf("%d", &p->estoque); // scanf("%d", &p[i].estoque);
        printf("\tInforme o preco: ");
        scanf("%f", &p->preco); // scanf("%f", &p[i].preco);
        system("cls");
    }
    p = pp; // Restaura o ponteiro "p" para a posição inicial com o auxilio de "pp"
    //Mostra Dados
    printf("Produtos:\n\n");
    for (int i = 0; i < tamVet; i++, p++) {
        mostraProduto(p);
    }
    printf("---------\n");
    
    system("pause");
}