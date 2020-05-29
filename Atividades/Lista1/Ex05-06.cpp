#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nome[31];
    int dia, mes, ano;
}Amigo;

void inputAmigos(Amigo *amigos){
    srand(time(NULL));
    char aux[2];
    aux[1] = '\0';
    for (int i = 0; i < 10; i++, amigos++) {
        strcpy(amigos->nome, "");
        for (int j = 0; j < ((rand() % 9) + 3); j++) {
            aux[0] = (rand() % 26) + 97;
            strcat(amigos->nome, aux);
        }
        amigos->dia = (rand() % 27) + 1;
        amigos->mes = (rand() % 11) + 1;
        amigos->ano = (rand() % 20) +2000;
    }
}

void outputAmigos(Amigo *amigos) {
    system("cls");
    for (int i = 0; i < 10; i++, amigos++) {
        printf("\nAmigo %d:\n\t%s\n\t%d/%d/%d", (i + 1), amigos->nome, amigos->dia, amigos->mes, amigos->ano);
    }
}

//Exercício 05:
void aniversariantes(Amigo *a, int mes) {
    int aux = 0;
    printf("\nAmigos que fazem aniversario no mes %d:", mes);
    for (int i = 0; i < 10; i++, a++) {
        if (a->mes == mes) {
            printf("\n\t%s", a->nome);
            aux++;
        }
    }
    if (aux == 0) {
        printf("\nNenhum de seus amigos faz aniversario neste mes");
    }
}
//Fim

//Exercício 06
int nascidos (Amigo *a, int ano) {
    int aux = 0;
    for (int i = 0; i < 10; i++, a++) {
        if (a->ano == ano) {
            aux++;
        }
    }
    printf("\nQuantidade de amigos que nasceram no ano de %d: %d", ano, aux);
}
//Fim

main() {
    Amigo amigos[10];
    int aux;
    printf("Digite as seguintes informacoes:\n");
    /*for (int i = 0; i < 1; i++) {
        printf("\nAmigo %d :\n\n\tNome: ", (i + 1));
        fflush(stdin);
        gets(amigos->nome);
        printf("\tData de Nascimento (DD MM AAAA): ");
        scanf(" %d %d %d", &(amigos->dia), &(amigos->mes), &(amigos->ano));
    }*/
    inputAmigos(amigos);
    outputAmigos(amigos);
    printf("\n\nDigite o mes de filtro (1-Jan, 2-Fev...): ");
    scanf("%d", &aux);
    aniversariantes(amigos, aux);
    printf("\n\nDigite o ano de filtro (AAAA): ");
    scanf("%d", &aux);
    nascidos(amigos, aux);
    printf("\n\n");
    system("pause");
}
