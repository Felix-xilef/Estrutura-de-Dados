#include <stdlib.h>//necessário parra malloc
#include <stdio.h>
main() {
    int tam, i;
    printf("Digite o tamanho:");
    scanf("%d", &tam);
    int *vet = (int*)malloc(sizeof(int)*tam);
    printf("Posicao Vet = %d\n", vet);
    printf("Posicao i = %d\n", &i);
    for(i = 0; i< tam; i++){
        vet[i] = i++;
        printf("%d\t", vet[i]);
    }
    printf("\n");
    free(vet);

    system("pause");
}