#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
    FILE *arq = fopen("palavras2.txt", "wt");
    char palavra[16];
    do {
        printf("Digite uma palavra: ");
        fflush(stdin);
        gets(palavra);
        if (strcmp(palavra, "fim")) fprintf(arq, "%s\n", palavra);
    } while (strcmp(palavra, "fim"));
    fclose(arq);
}