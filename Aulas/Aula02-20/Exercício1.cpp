#include <stdlib.h>
#include <stdio.h>

//socorrammesubinoonibusemmarrocos

#define TAMANHO 40 //tamanho das palavras digitadas (em bytes)

int tam(char *s) {
    int cont;
    for (cont = 0; *s != '\0'; s++, cont++);
    return cont;
}

void inverte(char *s) {
    int i;
    char aux[TAMANHO], *sAux = s;
    for (; *s != '\0'; s++);
    s--;
    for (i = 0; s != sAux; s--, i++) {
        aux[i] = *s;
    }
    aux[i] = *s;
    aux[i+1] = '\0';
    printf("\tAo contrario: %s\n", aux);
}

void hifeniza(char *s) {
    char aux[TAMANHO*2];
    int i;
    for (i = 0; *s != '\0'; s++, i++) {
        aux[i*2] = *s;
        if (*(s+1) != '\0') {
            aux[(i*2)+1] = '-';
        } else {
            aux[(i*2)+1] = '\0';
        }
    }
    printf("\tHifenizado: %s\n", aux);
}

int letrasA(char *s) {
    int cont;
    for (cont = 0; *s != '\0'; s++) {
        if (*s == 'A' || *s =='a') {
            cont++;
        }
    }
    printf("\tNumero de letras 'A': %d\n\n", cont);
}

main() {
    int qtdPalavras;
    printf("Informe a quantidade de palavras que serao lidas: ");
    scanf("%d", &qtdPalavras);
    system("cls");

    char palavras[qtdPalavras][TAMANHO];

    for (int i = 0; i < qtdPalavras; i++) {
        printf("Digite a palavra %d: ", (i+1));
        fflush(stdin);
        gets(palavras[i]);
        system("cls");
    }
    system("cls");
    printf("Palavras:\n\n");
    for (int i = 0; i < qtdPalavras; i++) {
        printf("\t%d: '%s'\n", (i+1), palavras[i]);
        printf("\tTamanho: %d\n", tam(palavras[i]));
        inverte(palavras[i]);
        hifeniza(palavras[i]);
        letrasA(palavras[i]);
    }
    printf("\n");

    system("pause");
}