#include <stdio.h>
#include <stdlib.h>
#include "FilaComLista.h"

void menu(){
      system("cls");
      printf("Escolha uma das opcoes do menu: \n");
      printf("1. Insere\n");       
      printf("2. Retira \n");
      printf("3. Mostra a fila\n");
      printf("4. Media da fila\n");
      printf("5. Maior valor da fila\n");
      printf("9. Fim\n");
      printf("==> ");
}

float mediaDaFila(Fila *q){
      float v, soma = 0, cont = 0;
      Fila *aux = fila_cria();
      while (!fila_vazia(q))
            fila_insere(aux, fila_retira(q));
      while (!fila_vazia(aux)){
            v = fila_retira(aux);
            soma += v;
            cont++;
            fila_insere(q, v);
      }
      fila_libera(aux);
      return soma/cont;
}

float maiorValor(Fila *f){
      Fila *aux = fila_cria();
      float v, maior;
      while(!fila_vazia(f)){
            maior = fila_retira(f);
            fila_insere(aux, maior);
      }
      while(!fila_vazia(aux)){
            v = fila_retira(aux);
            if (v > maior)
                  maior = v;
            fila_insere(f, v);
      }
      fila_libera(aux);
      return maior;
}

main(){
      Fila *fi=fila_cria();
      int opmenu; 
      float item;
      do{
            menu(); 
            scanf("%d", &opmenu);
            switch (opmenu){
                  case 1 : //insere
                        printf("Digite o valor a ser enfileirado: ");
                        scanf("%f", &item);
                        fila_insere(fi,item); break;
                  case 2 : //retira
                        if(fila_vazia(fi)) 
                              printf("fila vazia.\n");
                        else
                              printf("Elemento retirado = %.0f\n",fila_retira(fi));
                        break;
                  case 3 : //mostra
                        mostra_fila(fi);
                        break;
                  case 4:
                        if (fila_vazia(fi))
                              printf("Fila vazia\n");
                        else
                              printf("Media: %.2f\n", mediaDaFila(fi));
                        break;
                  case 5:
                        if (fila_vazia(fi))
                              printf("Fila vazia\n");
                        else
                              printf("Maior valor: %.0f\n", maiorValor(fi));
                        break;
            } //switch
            printf("\n");
            system("pause"); 
      }while(opmenu!=9);
      fila_libera(fi);
}
