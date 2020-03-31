#include <stdio.h>
#include <stdlib.h>

//definição de um produto (Struct)
typedef struct {
    int codigo;
    char nome[21];
    int estoque;
    float preco;
}Produto;

void mostraProduto(Produto p) {
    printf("Produto:\n\tCodigo: %d\n\tNome: %s\n\tEstoque: %d\n\tPreco: %.2f\n-------\n", p.codigo, p.nome, p.estoque, p.preco);
}

main() {
    Produto p;
    printf("Informe o codigo do produto: ");
    scanf("%d", &p.codigo);
    printf("Informe o nome do produto: ");
    fflush(stdin);
    gets(p.nome);
    printf("Informe o estoque do produto: ");
    scanf("%d", &p.estoque);
    printf("Informe o preco: ");
    scanf("%f", &p.preco);

    system("cls");
    //Mostra Dados
    mostraProduto(p);

    system("pause");
}