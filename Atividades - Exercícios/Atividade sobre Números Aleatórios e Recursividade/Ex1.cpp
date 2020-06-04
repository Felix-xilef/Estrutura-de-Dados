#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void semRepetidos(int v[], int tam) {
    int aux, repetido;
    for (int i = 0; i < tam; i++) {
        do {
            aux = (rand() % 10) + 1;
            repetido = 0;
            for (int j = 0; j < i; j++)
                if (v[j] == aux) repetido = 1;
        } while (repetido);
        v[i] = aux;
    }
}

main () {
    srand((unsigned)time(NULL));
    int tam = 10, vetor[tam];
    semRepetidos(vetor, tam);
    for (int i = 0; i < tam; i++)
        printf("%d\t", vetor[i]);
    printf("\n\n");
    system("pause");
}