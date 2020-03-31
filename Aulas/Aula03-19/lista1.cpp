#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

void menu() {
    system("cls");
    printf("Escolha uma das opcoes do menu: \n");
    printf("1. Enfileira\n");       
    printf("2. Retira \n");
    printf("3. Mostra a lista\n");
    printf("4. Conta elementos\n"); //int conta(Lista *l)
    printf("5. Soma elementos\n"); //float soma(Lista *l)
    printf("6. Mostra inicio\n"); //void inicio(Lista *l)
    printf("7. Mostra final\n"); //void final(Lista *l)
    printf("8. Replica lista\n"); //void replica(Lista *l)
    printf("9. Fim\n");
}

main() {
    Lista *li = lista_cria();
    int opmenu, item;
    do {
        menu(); 
        scanf("%d", &opmenu);
        switch (opmenu) {
            case 1 : //insere
                printf("Digite o valor a ser enfileirado: ");
                scanf("%d", &item);
                li = lista_insere(li, item);
                break;
            case 2 : //retira
                if (lista_vazia(li)) {
                    printf("lista vazia.\n");
                } else {
                    printf("Digite o valor a ser retirado: ");
                    scanf("%d", &item);
                    li = lista_retira(li, item);
                }
                break;
            case 3 : //mostra
                lista_mostra(li);
                break;
            case 4 :
                printf("Numero de elementos da lista = %d\n", conta(li));
                break;
            case 5 :
                printf("Soma dos elementos da lista = %d\n", soma(li));
                break;
            case 6 :
                if (lista_vazia(li))
                    printf("lista vazia.\n");
                else
                    inicio(li);
                break;
            case 7 :
                if (lista_vazia(li))
                    printf("lista vazia.\n");
                else
                    final(li);
                break;
            case 8 :
                li = replica(li);
                break;
        } //switch
        printf("\n");
        system("pause"); 
    } while(opmenu != 9);
}