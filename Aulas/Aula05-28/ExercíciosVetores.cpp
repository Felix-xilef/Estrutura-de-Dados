#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Ex 2
void buscaRepetidos(int v[], int valor, int tam) {
    int achou = 0;
    printf("Posicoes do valor %d no vetor:\n", valor);
    for (int i = 0; i < tam; i++) {
        if (v[i] == valor) {
            printf("%d\t", i);
            achou = 1;
        }
    }
    if (!achou)
        printf("Elemento %d nao encontrado no vetor!\n", valor);
}
//Fim

//Ex 3
void semRepetidos(int v[], int tam) {
    srand((unsigned)time(NULL));
    int aux, repetido;
    for (int i = 0; i < tam; i++) {
        do {
            aux = (rand() % 10) + 1;
            repetido = 1;
            for (int j = 0; j < i; j++)
                if (aux == v[j]) repetido = 0;
        } while (!repetido);
        v[i] = aux;
    }
}
//Fim

//Ex 4
int buscaElemento(int v[], int valor, int tam) {
    for (int i = 0; i < tam; i++)
        if (v[i] == valor) return i;
    return -1;
}
//Fim

void imprimeVetor(int v[], int tam) {
    for (int i = 0; i < tam; i++)
        printf("%d\t", v[i]);

    printf("\n\n");
}

main() {

    /*int aux;

    //Ex 1:
    srand((unsigned)time(NULL));
    int tam = (rand() % 30) + 1;
    int vet[tam];
    for (int i = 0; i < tam; i++)
        vet[i] = (rand() % 30) + 1;
    //Fim

    //ex1
    imprimeVetor(vet, tam);*/

    //ex2
    /*printf("Digite o valor a ser procurado:\n\t\t>> ");
    scanf("%d", &aux);
    buscaRepetidos(vet, aux, tam);*/

    //ex3
    /*int tam = 10, vet[tam];
    semRepetidos(vet, tam);
    imprimeVetor(vet, tam);*/


    //ex4
    /*printf("Digite o valor a ser buscado:\n\t\t>> ");
    scanf("%d", &aux);
    printf("Posicao (-1 -> nao encontrado): %d\n\n", buscaElemento(vet, aux, tam));*/
    
    system("pause");
}