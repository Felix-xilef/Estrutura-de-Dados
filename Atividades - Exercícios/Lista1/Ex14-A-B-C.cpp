#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista{
    int numero;
    struct lista *next;
}Lista;

//Exercíco 14a
int somaNumeros (Lista *L) {
    Lista *aux;
    int soma = 0;
    for (aux = L; aux != NULL; aux = aux->next)
        soma += aux->numero;
    return soma;
}
//Fim

//Exercíco 14b
int maiorNumero (Lista *Li) {
    Lista *aux = Li;
    int maior = aux->numero;
    aux = aux->next;
    while (aux != NULL) {
        if (aux->numero > maior)
            maior = aux->numero;
        aux = aux->next;
    }
    return maior;
}
//Fim

//Exercíco 14c
Lista *lista_pares(Lista *L1) {
    Lista *aux, *pares = NULL;
    for (aux = L1; aux != NULL; aux = aux->next) {
        if ((aux->numero % 2) == 0) {
            Lista *nova = (Lista*) malloc (sizeof(Lista));
            nova->numero = aux->numero;
            nova->next = pares;
            pares = nova;
        }
    }
    return pares;
}
//Fim

Lista *inputLista(Lista *l) {
    for (int i = 0; i < (rand() % 5) + 5; i++) {
        Lista *nova = (Lista*) malloc (sizeof(Lista));
        nova->numero = rand() % 100;
        nova->next = l;
        l = nova;
    }
    return l;
}

void outputLista(Lista *l) {
    Lista *aux;
    printf("\n\tElementos da lista:\n\n");
    for (aux = l; aux != NULL; aux = aux->next)
        printf("\t%d", aux->numero);
}

main() {
    srand(time(NULL));
    Lista *li = NULL;
    li = inputLista(li);
    outputLista(li);

    //Exercíco 14a
    printf("\n\n\tSoma dos Numeros = %d\n", somaNumeros(li));
    //Fim

    //Exercíco 14b
    printf("\n\tMaior numero = %d\n", maiorNumero(li));
    //Fim

    //Exercíco 14c
    outputLista(lista_pares(li));
    //Fim

    printf("\n\n");
    system("pause");
}