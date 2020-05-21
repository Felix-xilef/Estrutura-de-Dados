#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

void menu() {
    system("cls");
    printf("Escolha uma das opcoes do menu: \n");
    printf("------------------------------\n");
    printf("1. Insere na lista\n");
    printf("2. Retira da lista\n");
    printf("3. Mostra a lista\n");
    printf("4. Mostra primeiro e ultimo elemento\n");
    printf("5. Mostra maior e menor elemento\n");
    printf("9. Fim\n");
    printf("==> ");
}

main() {
    int opmenu, item, insercao;
    Lista2 *li=lista_cria();
    do {
        printf("Insercao:\n[1] Ordenada\n[2] No inicio\n ==> ");
        scanf("%d", &insercao);
    }while (insercao != 1 && insercao != 2);
    do {
        menu();
        scanf("%d",&opmenu);
        switch(opmenu) {
            case 1:
                printf("Informe o item que deseja inserir: ");
                scanf("%d",&item);
                if (insercao == 1)
                    li=lista_ordenada(li,item);
                else
                    li=lista_insere(li,item);
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
                if(lista_vazia(li))
                    printf("Lista vazia\n");
                else {
                    lista_primeiro_e_ultimo(li);
                }
                break;
            case 5:
                if(lista_vazia(li))
                    printf("Lista vazia\n");
                else {
                    lista_maior_e_menor(li);
                }
                break;
        } //fim switch
        printf("\n");
        system("pause");
    }while(opmenu!=9);
    lista_libera(li);
}
