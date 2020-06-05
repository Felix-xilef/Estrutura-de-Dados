#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
    FILE *arq = fopen("palavras.dat", "rt");
    if (arq == NULL) printf("\n\tNão foi possivel abrir o arquivo!\n");
    else {
        int lidas = 0, bolas = 0;
        char palavra[20];
        while (fscanf(arq, "%s", palavra) == 1) {
            lidas++;
            if (strcmp(palavra, "bola") == 0) bolas++;
        }
        printf("\n\tQuantidade de palavras lidas = %d\n\tQuantidade de palavras iguais a 'bola' = %d\n\n", lidas, bolas);
    }
    system("pause");
}