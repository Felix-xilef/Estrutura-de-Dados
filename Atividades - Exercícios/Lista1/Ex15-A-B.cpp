#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct lista {
    char nome[20];
    char fone[9];
    struct lista *prox;
}Lista;

//Exercício 15a
void mostraFone(Lista *l, char *nome) {
    Lista *aux;
    for (aux = l; aux != NULL; aux = aux->prox) {
        if (strcmp(strlwr(aux->nome), strlwr(nome)) == 0) {
            printf("\n\tFone associado ao nome %s:\n\t%s\n", nome, aux->fone);
            return;
        }
    }
    printf("\n\tO nome %s nao foi encontrado\n", nome);
}
//Fim

//Exercício 15b
void insere_final(Lista *primeiro, char *nome, char *tel) {
    Lista *aux;
    for (aux = primeiro; aux->prox != NULL; aux = aux->prox);
    Lista *nova = (Lista*) malloc (sizeof(Lista));
    strcpy(nova->nome, nome);
    strcpy(nova->fone, tel);
    nova->prox = NULL;
    aux->prox = nova;
}
//Fim

Lista *inputLista(Lista *l) {
    char letra[2];
    letra[0] = ' ';
    letra[1] = '\0';
    for (int i = 0; i < (rand() % 5) + 5; i++) {
        Lista *nova = (Lista*) malloc (sizeof(Lista));
        //nome
        strcpy(nova->nome, "");
        for (int k = 0; k < (rand() % 5) + 5; k++) {
            letra[0] = (rand() % 25) + 97;
            strcat(nova->nome, letra);
        }
        //fone
        letra[0] = (rand() % 8) + 49;
        strcpy(nova->fone, letra);
        for (int j = 0; j < 7; j++) {
            letra[0] = (rand() % 9) + 49;
            strcat(nova->fone, letra);
        }
        //prox
        nova->prox = l;
        l = nova;
    }
    return l;
}

void outputLista(Lista *l) {
    Lista *aux;
    printf("\n\tElementos da lista:\n");
    for (aux = l; aux != NULL; aux = aux->prox)
        printf("\n\tNome: %s\n\tFone: %s\n", aux->nome, aux->fone);
}

main() {
    srand(time(NULL));
    Lista *li = NULL;
    li = inputLista(li);
    outputLista(li);

    //Exercício 15a
    char nome[20];
    printf("\n\tDigite um nome para consultar o telefone associado:\n\t>");
    scanf("%s", &nome);
    mostraFone(li, nome);
    //Fim

    //Exercício 15b
    char fone[20];
    printf("\n\tDigite um nome e telefone para cadastrar:\n\tNome: ");
    scanf("%s", &nome);
    printf("\tTelefone (8 digitos, sem hifem '-'): ");
    scanf("%s", &fone);
    insere_final(li, nome, fone);
    outputLista(li);
    //Fim

    printf("\n\n");
    system("pause");
}