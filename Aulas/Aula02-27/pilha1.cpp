#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void menu(){
    system("cls");
    printf("Escolha uma das opcoes do menu: \n");
    printf("1. Empilha (push)\n");       
    printf("2. Retira (pop)\n");
    printf("3. Mostra a pilha\n");
    printf("4. Mostra o topo\n");
    printf("5. Mostra a base\n");
    printf("6. Conta elementos\n");
    printf("7. Soma elementos\n");
    printf("8. Dobra elementos\n");
    printf("9. Fim\n");
}

void mostra_topo(Pilha *p) {
    float x = pilha_pop(p);
    printf("Topo: %.0f\n", x);
    pilha_push(p, x);
}

void mostra_base(Pilha *p) {
    float x;
    Pilha *aux = pilha_cria();
    while (!pilha_vazia(p)) {
        x = pilha_pop(p);
        pilha_push(aux, x);
    }
    printf("Base: %.0f\n", x);
    //restaura pilha original
    while (!pilha_vazia(aux)) {
        x = pilha_pop(aux);
        pilha_push(p, x);
    }
    pilha_libera(aux);
}

int conta_elementos(Pilha *p) {
    int cont = 0;
    Pilha *aux = pilha_cria();
    while (!pilha_vazia(p)) {
        pilha_push(aux, pilha_pop(p));
        cont++;
    }
    while (!pilha_vazia(aux)) {
        pilha_push(p, pilha_pop(aux));
    }
    pilha_libera(aux);
    return cont;
}

float soma_elementos(Pilha *p) {
    float x, soma = 0;
    Pilha *aux = pilha_cria();
    while (!pilha_vazia(p)) {
        x = pilha_pop(p);
        soma += x;
        pilha_push(aux, x);
    }
    while (!pilha_vazia(aux)) {
        pilha_push(p, pilha_pop(aux));
    }
    pilha_libera(aux);
    return soma;
}

void dobra_elementos(Pilha *p) {
    Pilha *aux = pilha_cria();
    while (!pilha_vazia(p)) {
        pilha_push(aux, (pilha_pop(p))*2);
    }
    while (!pilha_vazia(aux)) {
        pilha_push(p, pilha_pop(aux));
    }
    pilha_libera(aux);
}

main(){     
    Pilha *pi=pilha_cria();
    int opmenu;
    float item;
    do{
        menu(); 
        scanf("%d", &opmenu);
        switch (opmenu) {
            case 1 : //insere
                printf("Digite o valor a ser empilhado: "); 
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
            case 2 : //retira
			    if(pilha_vazia(pi)) 
                    printf("Pilha Vazia\n");
                else
                    printf("Elemento retirado = %.0f\n",pilha_pop(pi));
                break;
            case 3 : //mostra
                mostra_pilha(pi);
                break;
            case 4 :
                if(pilha_vazia(pi)) 
                    printf("Pilha Vazia\n");
                else
                    mostra_topo(pi);
                break;
            case 5 :
                if(pilha_vazia(pi)) 
                    printf("Pilha Vazia\n");
                else
                    mostra_base(pi);
                break;
                break;
            case 6 :
                printf("Quantidade de elementos: %d\n", conta_elementos(pi));
                break;
            case 7 :
                printf("Soma dos elementos: %.0f\n", soma_elementos(pi));
                break;
            case 8 :
                if(pilha_vazia(pi)) {
                    printf("Pilha Vazia\n");
                } else {
                    dobra_elementos(pi);
                    printf("Elementos depois da dobra:\n");
                    mostra_pilha(pi);
                }
                break;
       }  //switch
       printf("\n"); system("pause"); 
    } while(opmenu!=9);
}