#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscavetor(int *vet, int tam, int valor) {
    if (*vet == valor || tam == 0) return 0;
    int pos = buscavetor(vet + 1, tam - 1, valor) + 1;
    if (pos == tam) return -1;
    return pos;
}

main () {
    srand((unsigned)time(NULL));
    int continuar; 
    do {
        system("cls");
        int aux, repetido, tam = (rand() % 10) + 1, vetor[tam];
        for (int i = 0; i < tam; i++) {
            do {
                aux = rand() % 30;
                repetido = 0;
                for (int j = 0; j < i; j++)
                    if (vetor[j] == aux) repetido = 1;
            } while (repetido);
            vetor[i] = aux;
            printf("%d\t", aux);
        }
        printf("\n\nDigite o valor que deseja busacar no vetor\n\t\t>> ");
        scanf("%d", &aux);
        printf("Posicao (-1 = nao encontrado): %d\n\n Deseja continuar?\n [0] Nao\n [1] Sim\n  >> ", buscavetor(vetor, tam, aux));
        scanf("%d", &continuar);
    } while (continuar);
}