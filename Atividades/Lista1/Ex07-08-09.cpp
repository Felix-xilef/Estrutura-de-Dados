#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha.h"

//Exercício 07:
void empilhaPilha(Pilha *p1, Pilha *p2) {
    Pilha *aux = pilha_cria();
    float auxNum;
    while (!pilha_vazia(p2))
        pilha_insere(aux, pilha_retira(p2));
    while (!pilha_vazia(aux)) {
        auxNum = pilha_retira(aux);
        pilha_insere(p1, auxNum);
        pilha_insere(p2, auxNum);
    }
    pilha_libera(aux);
}
//Fim

//Exercício 08:
Pilha* dividePilha(Pilha *p) {
    Pilha *metade = pilha_cria(), *aux = pilha_cria();
    float auxNum;
    while (!pilha_vazia(p))
        pilha_insere(aux, pilha_retira(p));
    while (!pilha_vazia(aux)) {
        auxNum = pilha_retira(aux);
        pilha_insere(metade, auxNum/2);
        pilha_insere(p, auxNum);
    }
    pilha_libera(aux);
    return metade;
}
//Fim

//Exercício 09:
float base(Pilha *pi) {
    Pilha *aux = pilha_cria();
    float base;
    while (!pilha_vazia(pi)) {
        base = pilha_retira(pi);
        pilha_insere(aux, base);
    }
    while (!pilha_vazia(aux))
        pilha_insere(pi, pilha_retira(aux));
    pilha_libera(aux);
    return base;
}
//Fim

void inputPilha(Pilha *a) {
    for (int i = 0, aux = (rand() % 6) + 3; i < aux; i++)
        pilha_insere(a, rand() % 100);
}

void outputPilhas(Pilha *a, Pilha *b) {
    printf("\nPilha 1:\t");
    mostra_pilha(a);
    printf("\nPilha 2:\t");
    mostra_pilha(b);
}

main() {
    Pilha *p = pilha_cria(), *q = pilha_cria();
    srand(time(NULL));

    //Exercio 7:
    system("cls");
    printf("Exercio 7:\n\n");
    inputPilha(p);
    inputPilha(q);
    outputPilhas(p, q);
    empilhaPilha(p, q);
    outputPilhas(p, q);
    pilha_libera(p);
    pilha_libera(q);
    system("pause");
    //Fim

    //Exercio 8:
    system("cls");
    printf("Exercio 8:\n\n");
    p = pilha_cria();
    inputPilha(p);
    mostra_pilha(p);
    q = dividePilha(p);
    outputPilhas(p, q);
    pilha_libera(p);
    pilha_libera(q);
    system("pause");
    //Fim

    //Exercio 9:
    system("cls");
    printf("Exercio 9:\n\n");
    p = pilha_cria();
    inputPilha(p);
    mostra_pilha(p);
    printf("Base = %.0f\n\n", base(p));
    mostra_pilha(p);
    pilha_libera(p);
    system("pause");
    //Fim
}