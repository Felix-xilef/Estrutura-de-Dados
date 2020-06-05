#include <stdio.h>
#include <stdlib.h>

main() {
    int soma = 0, aux;
    FILE *arq = fopen("Numeros.txt", "rt");
    if (arq == NULL) {
        printf("Não foi possivel ler o arquivo!\n");
    } else {
        while (fscanf(arq, "%d", &aux) == 1) soma += aux;
        fclose(arq);
        printf("\n\tSoma dos numeros lidos = %d\n\n", soma);
    }
    system("pause");
}