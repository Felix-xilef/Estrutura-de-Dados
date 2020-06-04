#include <stdio.h>
#include <stdlib.h>

//Lendo com fgetc() e contando a quantidade de linhas('\n') no arquivo:
void linhasComfgetc() {
    FILE *arq;
    arq = fopen("entrada.txt", "rt");
    if (arq == NULL) {
        printf("Não foi possivel abrir o arquivo!\n\n");
        return;
    }
    int c, nlinhas = 0;
    while((c = fgetc(arq)) != EOF)
        if (c == '\n') nlinhas++;
    fclose(arq);
    printf("Numero de linhas = %d\n", nlinhas);
}

//Lendo com fscanf() e contando a quantidade de linhas('\n') no arquivo:
void linhasComfscanf() {
    FILE *arq;
    arq = fopen("entrada.txt", "rt");
    if (arq == NULL) {
        printf("Não foi possivel abrir o arquivo!\n\n");
        system("pause");
        return;
    }
    int nlinhas = 0;
    char c;
    while (fscanf(arq, "%c", &c) == 1)
        if (c == '\n') nlinhas++;
    fclose(arq);
    printf("Numero de linhas = %d\n", nlinhas);
}

//Lendo com fscanf() e contando a quantidade de palavras(' ') no arquivo:
void palavrasComfscanf() {
    FILE *p;
    p = fopen("entrada.txt", "rt");
    if (p == NULL) {
        printf("Não foi possivel abrir o arquivo!\n\n");
        system("pause");
        return;
    }
    int cont = 0;
    char palavra[20];
    while (fscanf(p, "%s", palavra) == 1) cont++;
    fclose(p);
    printf("Numero de palavras = %d\n", cont);
}

//Lendo com fgets() e mostrando frases(linhas) do arquivo:
void frasesComfgets() {
    FILE *arq;
    arq = fopen("entrada.txt", "rt");
    if (arq == NULL) {
        printf("Não foi possivel abrir o arquivo!\n\n");
        system("pause");
        return;
    }
    char frase[41];
    while (fgets(frase, 40, arq) != NULL) printf("%s", frase) /*ou puts(c)*/;
    fclose(arq);
    printf("\n");
}

main() {
    int op;
    do {
        system("cls");
        printf("==================================\n: Sistema de Leitura de Arquivos :\n==================================\n: [1] Linhas com fgetc           :\n: [2] Linhas com fscanf          :\n: [3] Palavras com fscanf        :\n: [4] Frases com fgets           :\n: [5] Sair                       :\n==================================\n  Digite a opcao desejada >> ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                linhasComfgetc();
                break;
            case 2:
                linhasComfscanf();
                break;
            case 3:
                palavrasComfscanf();
                break;
            case 4:
                frasesComfgets();
                break;
        }
        system("pause");
    } while (op != 5);
}
