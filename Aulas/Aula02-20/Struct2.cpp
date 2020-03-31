#include <stdio.h>
#include <stdlib.h>

//Definição de um produto (Struct)
typedef struct {
    int codigo;
    char nome[21];
    int estoque;
    float preco;
}Produto;

void mostraProduto(Produto p) {
    printf("\tCodigo: %d\n\tNome: %s\n\tEstoque: %d\n\tPreco: %.2f\n\n", p.codigo, p.nome, p.estoque, p.preco);
}

main() {
    int tamVet;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamVet);
    system("cls");

    Produto p[tamVet];

    //Receber Dados
    for (int i = 0; i < tamVet; i++) {
        printf("Informe o codigo do produto %d: ", (i+1));
        scanf("%d", &p[i].codigo);
        printf("Informe o nome do produto %d: ", (i+1));
        fflush(stdin);
        gets(p[i].nome);
        printf("Informe o estoque do produto %d: ", (i+1));
        scanf("%d", &p[i].estoque);
        printf("Informe o preco %d: ", (i+1));
        scanf("%f", &p[i].preco);
        system("cls");
    }

    //Mostra Dados
    printf("Produtos:\n\n");
    for (int i = 0; i < tamVet; i++) {
        mostraProduto(p[i]);
    }
    printf("---------\n");
    
    system("pause");
}