#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

//Exercício 10
void concatena_fila (Fila *f1, Fila *f2) {
    Fila *aux = fila_cria();
    int auxNum;
    while(!fila_vazia(f2)) {
        auxNum = fila_retira(f2);
        fila_insere(f1, auxNum);
        fila_insere(aux, auxNum);
    }
    while (!fila_vazia(aux))
        fila_insere(f2, fila_retira(aux));
    fila_libera(aux);
}
//Fim

//Exercício 11
int primeiroDaFila (Fila *f) {
    Fila *aux = fila_cria();
    int primeiro = fila_retira(f);
    fila_insere(aux, primeiro);
    while (!fila_vazia(f))
        fila_insere(aux, fila_retira(f));
    while (!fila_vazia(aux))
        fila_insere(f, fila_retira(aux));
    fila_libera(aux);
    return primeiro;
}
//Fim

//Exercício 12
Fila *intercala_fila (Fila *f1, Fila *f2) {
    Fila *aux1 = fila_cria(), *aux2 = fila_cria(), *intercalada = fila_cria();
    int auxNum;
    while (!fila_vazia(f1) || !fila_vazia(f2)) {
        if (!fila_vazia(f1)) {
            auxNum = fila_retira(f1);
            fila_insere(intercalada, auxNum);
            fila_insere(aux1, auxNum);
        }
        if (!fila_vazia(f2)) {
            auxNum = fila_retira(f2);
            fila_insere(intercalada, auxNum);
            fila_insere(aux2, auxNum);
        }
    }
    while (!fila_vazia(aux1))
        fila_insere(f1, fila_retira(aux1));
    fila_libera(aux1);
    while (!fila_vazia(aux2))
        fila_insere(f2, fila_retira(aux2));
    fila_libera(aux2);
    return intercalada;
}
//Fim

//Exercício 13
void  mostraImpares (Fila *f) {
    Fila *aux = fila_cria();
    int auxNum;
    printf("Elementos impares da fila:\n");
    while(!fila_vazia(f)) {
        auxNum = fila_retira(f);
        if (auxNum % 2 != 0)
            printf("%d\n", auxNum);
        fila_insere(aux, auxNum);
    }
    printf("\n");
    while (!fila_vazia(aux))
        fila_insere(f, fila_retira(aux));
    fila_libera(aux);
}
//Fim

void inputFila(Fila *a) {
    for (int i = 0, aux = (rand() % 6) + 3; i < aux; i++)
        fila_insere(a, rand() % 100);
}

void outputFilas(Fila *a, Fila *b) {
    printf("\Fila 1:\t");
    mostra_fila(a);
    printf("\Fila 2:\t");
    mostra_fila(b);
}

main() {
    srand(time(NULL));
    Fila *p, *q;

    //Exercício 10
    system("cls");
    printf("Exercicio 10:\n\n");
    p = fila_cria(), q = fila_cria();
    inputFila(p);
    inputFila(q);
    outputFilas(p, q);
    concatena_fila(p, q);
    outputFilas(p, q);
    fila_libera(p);
    fila_libera(q);
    system("pause");
    //Fim

    //Exercício 11
    system("cls");
    printf("Exercicio 11:\n\n");
    p = fila_cria();
    inputFila(p);
    mostra_fila(p);
    printf("Primeiro da fila = %d\n\n", primeiroDaFila(p));
    mostra_fila(p);
    fila_libera(p);
    system("pause");
    //Fim

    //Exercício 12
    system("cls");
    printf("Exercicio 12:\n\n");
    p = fila_cria(), q = fila_cria();
    inputFila(p);
    inputFila(q);
    outputFilas(p, q);
    printf("Fila intercalada:\n\n");
    mostra_fila(intercala_fila(p, q));
    outputFilas(p, q);
    fila_libera(p);
    fila_libera(q);
    system("pause");
    //Fim

    //Exercício 13
    system("cls");
    printf("Exercicio 13:\n\n");
    p = fila_cria();
    inputFila(p);
    mostra_fila(p);
    mostraImpares(p);
    mostra_fila(p);
    fila_libera(p);
    system("pause");
    //Fim
}