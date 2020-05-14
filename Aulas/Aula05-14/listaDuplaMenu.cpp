#include <stdio.h>
#include <stdlib.h>
#include "lista2.h"

void menu() {
    system("cls");
    printf("Escolha uma das opcoes do menu: \n");
    printf("------------------------------\n");
    printf("1. Insere na lista\n");
    printf("2. Retira da lista\n");
    printf("3. Mostra a lista\n");
    printf("4. Busca item na lista\n");// void vizinhos(Lista2 *item)
    printf("5. Mostra reverso\n");
    printf("9. Fim\n");
    printf("==> ");
}

void vizinhos(Lista2 *item) {
    Lista2 *anterior, *proximo;
    anterior = item->ant;
    proximo = item->prox;
    if (anterior == NULL)
        printf("Primeiro da lista\n");
    else
        printf("Anterior - %d\n", anterior->info);
    
    if (proximo == NULL)
        printf("Ultimo da lista\n");
    else
        printf("Proximo - %d\n", proximo->info);
}

main() {
    int opmenu, item;
    Lista2 *li=lista_cria();
    Lista2 *aux; //ponteiro auxiliar usado na fun��o lista_busca
    do {
        menu();
        scanf("%d",&opmenu);
        switch(opmenu) {
            case 1:
                printf("Informe o item que deseja inserir: ");
                scanf("%d",&item);
                li=lista_ordenada(li,item);
                //li=lista_insere(li,item);
                break;
            case 2:
                printf("Informe o item que deseja retirar: ");
                scanf("%d",&item);
                li=lista_retira(li,item);
                break;
            case 3:
                if(lista_vazia(li))
                    printf("Lista vazia\n");
                else {
                    printf("Lista: ");
                    lista_mostra(li);
                }
                break;
            case 4:
                printf("Informe o item que deseja procurar: ");
                scanf("%d",&item);
                //ponteiro auxiliar para n�o perder a referencia
                //da lista
                aux=lista_busca(li,item);
                if(aux==NULL)
                    printf("\nItem %d nao localizado na lista\n",item);
                else {
                    printf("\nItem %d localizado\n",aux->info);
                    vizinhos(aux);
                }
                break;
            case 5:
                if (lista_vazia(li))
                    printf("Lista vazia\n");
                else {
                    printf("Lista reversa: ");
                    lista_reverso(li);
                }
                break;
        } //fim switch
        printf("\n");
        system("pause");
    }while(opmenu!=9);
    lista_libera(li);
}
