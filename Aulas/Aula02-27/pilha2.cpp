#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void empilha_pilha(Pilha *p, Pilha *q) {
    Pilha *aux = pilha_cria();
    float auxN;
    while (!pilha_vazia(q)) {
        pilha_push(aux, pilha_pop(q));
    }
    while (!pilha_vazia(aux)) {
        auxN = pilha_pop(aux);
        pilha_push(p, auxN);
        pilha_push(q, auxN);
    }
    pilha_libera(aux);
}

Pilha *soma_pilha(Pilha *p, Pilha *q) {
    Pilha *aux1 = pilha_cria() , *aux2 = pilha_cria() , *soma = pilha_cria();
    float num1, num2;
    while ((!pilha_vazia(p)) || (!pilha_vazia(q))) {
        if (!pilha_vazia(p))
            pilha_push(aux1, pilha_pop(p));
        if (!pilha_vazia(q))
            pilha_push(aux2, pilha_pop(q));
    }
    while ((!pilha_vazia(aux1)) || (!pilha_vazia(aux2))) {
        if (!pilha_vazia(aux1)) {
            num1 = pilha_pop(aux1);
            pilha_push(p, num1);
        } else {
            num1 = 0;
        }
        if (!pilha_vazia(aux2)) {
            num2 = pilha_pop(aux2);
            pilha_push(q, num2);
        } else {
            num2 = 0;
        }
        pilha_push(soma, (num1+num2));
    }
    pilha_libera(aux1);
    pilha_libera(aux2);
    return soma;
}

main() {
    Pilha *p1 = pilha_cria();
    Pilha *p2 = pilha_cria();
    for (int i = 1; i < 4; i++) {
        pilha_push(p1, (i*10));
        if (i != 1)
            pilha_push(p2, i);
    }
    mostra_pilha(p1);
    mostra_pilha(p2);
    mostra_pilha(soma_pilha(p1, p2));
    empilha_pilha(p1, p2);
    mostra_pilha(p1);
    mostra_pilha(p2);
    system("pause");
}