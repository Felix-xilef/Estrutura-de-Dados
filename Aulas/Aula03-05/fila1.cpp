#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void menu() {
    system("cls");
    printf("Escolha uma das opcoes do menu: \n");
    printf("1. Enfileira\n");       
    printf("2. Retira \n");
    printf("3. Mostra a fila\n");
    printf("4. Conta elementos\n"); //int conta(Fila *f)
    printf("5. Soma elementos\n"); //float soma(Fila *f)
    printf("6. Mostra inicio\n"); //void inicio(Fila *f)
    printf("7. Mostra final\n"); //void final(Fila *f)
    printf("8. Replica fila\n"); //void replica(Fila *f)
    printf("9. Fim\n");
}

int conta(Fila *f) {
    Fila *aux = fila_cria();
    int cont = 0;
    while (!fila_vazia(f)) {
        fila_insere(aux, fila_retira(f));
        cont++;
    }
    while (!fila_vazia(aux))
        fila_insere(f, fila_retira(aux));
    fila_libera(aux);
    return cont;
}

float soma(Fila *f) {
    Fila *aux = fila_cria();
    float num, soma = 0;
    while (!fila_vazia(f)) {
        num = fila_retira(f);
        soma += num;
        fila_insere(aux, num);
    }
    while (!fila_vazia(aux))
        fila_insere(f, fila_retira(aux));
    fila_libera(aux);
    return soma;
}

void inicio(Fila *f) {
    Fila *aux = fila_cria();
    float ini;
    ini = fila_retira(f);
    fila_insere(aux, ini);
    while (!fila_vazia(f))
        fila_insere(aux, fila_retira(f));
    while (!fila_vazia(aux))
        fila_insere(f, fila_retira(aux));
    fila_libera(aux);
    printf("Inicio da fila = %.0f\n", ini);
}

void final(Fila *f) {
    Fila *aux = fila_cria();
    float fim;
    while (!fila_vazia(f)) {
        fim = fila_retira(f);
        fila_insere(aux, fim);
    }
    while (!fila_vazia(aux))
        fila_insere(f, fila_retira(aux));
    fila_libera(aux);
    printf("Final da fila = %.0f\n", fim);
}

void replica(Fila *f) {
    Fila *aux1 = fila_cria(), *aux2 = fila_cria();
    float aux;
    while (!fila_vazia(f)) {
        aux = fila_retira(f);
        fila_insere(aux1, aux);
        fila_insere(aux2, aux);
    }
    while (!fila_vazia(aux1))
        fila_insere(f, fila_retira(aux1));
    fila_libera(aux1);
    while (!fila_vazia(aux2))
        fila_insere(f, fila_retira(aux2));
    fila_libera(aux2);
    printf("Fila replicada:\n");
    mostra_fila(f);
}

main() {
    Fila *fi=fila_cria();
    int opmenu;  float item;
    do {
        menu(); 
        scanf("%d", &opmenu);
        switch (opmenu) {
            case 1 : //insere
                printf("Digite o valor a ser enfileirado: ");
                scanf("%f", &item);
                fila_insere(fi,item);
                break;
            case 2 : //retira
                if(fila_vazia(fi)) 
                    printf("fila vazia.\n");
                else
                    printf("Elemento retirado = %.0f\n",fila_retira(fi));
                break;    
            case 3 : //mostra
                mostra_fila(fi);
                break;
            case 4 :
                printf("Numero de elementos da fila = %d\n", conta(fi));
                break;
            case 5 :
                printf("Soma dos elementos da fila = %.0f\n", soma(fi));
                break;
            case 6 :
                if(fila_vazia(fi)) 
                    printf("fila vazia.\n");
                else
                    inicio(fi);
                break;
            case 7 :
                if(fila_vazia(fi)) 
                    printf("fila vazia.\n");
                else
                    final(fi);
                break;
            case 8 :
                replica(fi);
                break;
        }//switch
        printf("\n");
        system("pause"); 
    } while(opmenu != 9);
}