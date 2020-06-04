#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Gravando com fprintf() a frase caracter por caracter no arquivo:
void fraseComfprintf(char *frase) {
    FILE *fp;
    fp = fopen("saida.txt", "wt");
    for (; *frase != '\0'; frase++) fprintf(fp, "%c", *frase);
    fclose(fp);
    printf("Arquivo gravado\n");
}

//Gravando com fprintf() frase por frase no arquivo:
void frasesComfprintf(int qtdFrases) {
    FILE *fp;
    char frase[41];
    fp = fopen("saida.txt","wt");
    for (int i = 0; i < qtdFrases; i++) {
        printf("Digite uma frase: ");
        fflush(stdin);
        gets(frase);
        fprintf(fp,"%s\n", frase);
    }
    fclose(fp);
    printf("Arquivo gravado\n");
}

//Gravando com fputc() a frase caracter por caracter no arquivo:
void fraseComfputc(char *frase) {
    FILE *arq;
    arq = fopen("saida.txt","wt");
    for (; *frase != '\0'; frase++) fputc(*frase, arq); //grava 1 caractere por vez
    fclose(arq);
    printf("Arquivo gravado\n");
}

//Gravando com fputc() frase por frase no arquivo:
void frasesComfputc(int qtdFrases) {
    FILE *fp;
    char frase[41], endline='\n';
    fp = fopen("saida.txt","wt");
    for (int i = 0; i < qtdFrases; i++) {
        printf("Digite uma frase: ");
        fflush(stdin);
        gets(frase);
        fputs(frase,fp);
        fputc(endline,fp); //grava o caractere de  pula linha
    }
    fclose(fp);
    printf("Arquivo gravado\n");
}

main() {
    int op, qtd;
    char aux[41];
    do {
        system("cls");
        printf("==================================\n: Sistema de Leitura de Arquivos :\n==================================\n: [1] Frase com fprintf          :\n: [2] Frases com fprintf         :\n: [3] Frase com fputc            :\n: [4] Frases com fputc           :\n: [5] Sair                       :\n==================================\n  Digite a opcao desejada >> ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Digite a frase que deseja gravar: ");
                fflush(stdin);
                gets(aux);
                fraseComfprintf(aux);
                break;
            case 2:
                printf("Digite a quantidade de frases que deseja gravar: ");
                scanf("%d", &qtd);
                frasesComfprintf(qtd);
                break;
            case 3:
                printf("Digite a frase que deseja gravar: ");
                fflush(stdin);
                gets(aux);
                fraseComfputc(aux);
                break;
            case 4:
                printf("Digite a quantidade de frases que deseja gravar: ");
                scanf("%d", &qtd);
                frasesComfputc(qtd);
                break;
        }
        system("pause");
    } while (op != 5);
}
