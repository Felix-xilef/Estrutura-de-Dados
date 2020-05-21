#include <stdio.h>
#include <stdlib.h>
#include "pilhacomlista.h"

float obter_valor(){
     float v;
     printf("Digite o valor: ");
     scanf("%f",&v);
     return v;
}

float mostra_topo(Pilha *p){
     float valor;
     valor=pilha_pop(p);
     pilha_push(p,valor);
     return valor;
}
                              
void menu (){
     system("cls");
     printf("Escolha a opcao desejada:\n");
     printf("1. Empilha\n2. Retira\n3. Mostra\n");
     printf("4. Mostra topo\n5. Dobra a pilha\n6. Menor valor da pilha\n");
     printf("9. Sair\n");
     printf("==> ");
}

Pilha *pilha_dobro(Pilha *p){
     Pilha *aux = pilha_cria(), *dobro = pilha_cria();
     float v;
     while(!pilha_vazia(p))
          pilha_push(aux, pilha_pop(p));
     while(!pilha_vazia(aux)){
          v = pilha_pop(aux);
          pilha_push(p, v);
          pilha_push(dobro, 2*v);
     }
     pilha_libera(aux);
     return dobro;
}

float menorValor(Pilha *p){
     Pilha *aux = pilha_cria();
     float v, menor;
     while (!pilha_vazia(p)){
          menor = pilha_pop(p);
          pilha_push(aux, menor);
     }
     while (!pilha_vazia(aux)){
          v = pilha_pop(aux);
          if (v < menor)
               menor = v;
          pilha_push(p, v);
     }
     pilha_libera(aux);
     return menor;
}

int main(){
     int op;
     float v;
     Pilha *p = pilha_cria();
     do {
          menu();
          scanf("%d",&op);
          switch(op){
               case 1 : //insere
                    pilha_push(p,obter_valor());
                    break;        
               case 2 : //retira
                    if(pilha_vazia(p)) 
                         printf ("Pilha vazia.\n");
                    else
                         printf ("\nValor retirado = %.0f\n", pilha_pop(p));
                    break;
               case 3 : //mostra
                    pilha_mostra(p);
                    break;
               case 4: //mostra topo
                    if(!pilha_vazia(p))
                         printf("\nTopo=%.0f\n",mostra_topo(p));
                    else
                         printf("\nPilha vazia!\n");
                    break;
               case 5: //pilha dobro
                    pilha_mostra(pilha_dobro(p));
                    break;
               case 6: //menor valor
                    if(!pilha_vazia(p))
                         printf("\nMenor valor=%.0f\n",menorValor(p));
                    else
                         printf("\nPilha vazia!\n");
                    break;
               case 9: //sair
                    pilha_libera(p);
                    break;
               default: printf ("\nOpcao invalida\n");
          }
          printf("\n");
               system("pause");
     }while (op!=9);
     return 0;
}
