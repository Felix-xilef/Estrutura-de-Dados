#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <time.h>

#define N 5

Fila *soma(Fila *p, Fila *q) {
    Fila *auxP = fila_cria(), *auxQ = fila_cria(), *soma = fila_cria();
    float numP, numQ;
    while ((!fila_vazia(p)) || (!fila_vazia(q))) {
        if (!fila_vazia(p)) {
            numP = fila_retira(p);
            fila_insere(auxP, numP);
        } else
            numP = 0;
        if (!fila_vazia(q)) {
            numQ = fila_retira(q);
            fila_insere(auxQ, numQ);
        } else
            numQ = 0;
        fila_insere(soma, numP + numQ);
    }
    while ((!fila_vazia(auxP)) || (!fila_vazia(auxQ))) {
        if (!fila_vazia(auxP))
            fila_insere(p, fila_retira(auxP));
        if (!fila_vazia(auxQ))
            fila_insere(q, fila_retira(auxQ));
    }
    fila_libera(auxP);
    fila_libera(auxQ);
    return soma;
}

main() {
    Fila *f1 = fila_cria(), *f2 = fila_cria();
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        if (i <= rand() % N)
            fila_insere(f1, rand() % 100);
        if (i <= rand() % N)
            fila_insere(f2, rand() % 100);
    }
    printf("Fila 1:\n");
    mostra_fila(f1);
    printf("Fila 2:\n");
    mostra_fila(f2);
    printf("Soma das filas:\n");
    mostra_fila(soma(f1, f2));
    system("pause");
}