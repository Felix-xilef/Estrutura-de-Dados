#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
    int i, tam;
    srand(time(NULL));
    tam = (rand() % 20) + 1;
    int vet[tam];
    printf("tam = %d\n\n", tam);
    for (i = 0; i < tam; i++) {
        vet[i] = (rand() % 50) + 1;
        printf("vet[%d] = %d\n", i, vet[i]);
    }
    system("pause");
}