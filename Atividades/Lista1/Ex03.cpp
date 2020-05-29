#include <stdlib.h>
#include <stdio.h>

void retira_brancos(char *frase) {
    for (int cont = 0; *frase != '\0'; frase++) {
        *frase = *(frase + cont);
        if (*frase == ' ') {
            cont++;
            *frase = *(frase + cont);
        }
    }
}

char mostrarString(char *f) {
    while(*f != '\0') {
        printf("%c", *f);
        f++;
    }
}

main() {
    char stringAux[100];
    printf("Digite uma frase: ");
    fflush(stdin);
    gets(stringAux);
    retira_brancos(stringAux);
    printf("\n\n\t-> ");
    mostrarString(stringAux);
    printf(" <-\n\n");
    system("pause");
}