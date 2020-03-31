#include <stdio.h>
#include <stdlib.h>

void palindromo(char *palavra) {
    char *aux = palavra;
    for (; *palavra != '\0'; palavra++);
    for (palavra--; aux <= palavra; aux++, palavra--) {
        if (*aux != *palavra) {
            printf("\n--- Nao e um palindromo! ---\n\n");
            return;
        }
    }
    printf("\n\t--- E um palindromo! ---\n\n");
}

main() {
    char pAux[100];
    printf("Digite uma palavra para verificar se e um palindromo:\n\n\t-> ");
    scanf("%s", pAux);
    palindromo(pAux);
    system("pause");
}