#include <stdio.h>
#include <stdlib.h>

void contaLetras(char *p) {
    char alfabeto[26];
    int alfabetoN[26];
    for (int i = 0; i < 26; i++) {
        alfabeto[i] = i + 97;
        alfabetoN[i] = 0;
    }
    for (; *p != '\0'; p++) {
        for (int i = 0; i < 26; i++) {
            if ((*p == alfabeto[i]) || (*p == (alfabeto[i] - 32))) {
                alfabetoN[i]++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (alfabetoN[i] > 0) {
            printf("\n\t%c=%d", alfabeto[i], alfabetoN[i]);
        }
    }
}

main() {
    char stringA[100];
    printf("Digite uma palavra: ");
    scanf("%s", stringA);
    contaLetras(stringA);
    printf("\n\n");
    system("pause");
}