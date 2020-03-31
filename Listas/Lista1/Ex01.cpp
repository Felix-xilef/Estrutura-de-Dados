#include <stdlib.h>
#include <stdio.h>

int trocaCarac(char *f, char m, char p) {
    int cont = 0; //Contador de caracteres trocados
    while(*f != '\0') { //Loop repete até o final da String (\0)
        if (*f == m) { //Verifica se o caracter deve ser substituido
            *f = p; //Substitui caracter
            cont++; //Conta + 1
        }
        f++; //Vai para o próximo caracter
    }
    return cont; //Retorna o valor de caracteres trocados
}

char mostrarString(char *f) {
    while(*f != '\0') {
        printf("%c", *f);
        f++;
    }
}

main() {
    char varStrg[100], m[2], p[2];
    printf("Digite uma palavra: ");
    fflush(stdin);
    scanf("%s", varStrg);
    printf("\nDigite a letra a ser trocada: ");
    fflush(stdin);
    scanf("%c", m);
    printf("Digite a letra que entrara no lugar: ");
    fflush(stdin);
    scanf("%c", p);
    int qtdT = trocaCarac(varStrg, *m, *p);
    printf("\nPalavra apos a troca: ");
    mostrarString(varStrg);
    printf("\nNumero de vezes que a letra '%c' foi trocada pela letra '%c': %d\n\n", *m, *p, qtdT);
    system("pause");
}