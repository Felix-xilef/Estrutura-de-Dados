#include <stdio.h>
#include <stdlib.h>
#include "pilhacomlista.h"
                                    
void menu (){
     system("cls");
     printf("Escolha a opcao desejada:\n");
     printf("1. Empilha\n2. Retira\n3. Mostra\n");
     printf("4. Mostra topo\n");
     printf("9. Sair\n");
     printf("==> ");
     
}                      
float obter_valor() {
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
int main(){
    int op;
    float v;
    Pilha *p = pilha_cria();
    do {
            menu();
            scanf("%d",&op);
            switch(op){
               case 1 : 
                    pilha_push(p,obter_valor()); break;        
               case 2 : 
                    if(pilha_vazia(p)) 
                         printf ("Pilha vazia.\n");
                    else
                        printf ("\nValor retirado = %.0f\n", pilha_pop(p));
                   
                    break;
               case 3 : 
                    pilha_mostra(p);
                    break;  
               case 9 :
                     pilha_libera(p);
                     break;
               case 4:
                     if(!pilha_vazia(p))
                        printf("\nTopo=%.0f\n",mostra_topo(p));
                     else
                        printf("\nPilha vazia!\n");
                     break;
               default : printf ("\nOpcao invalida\n"); 
               } 
                printf("\n");
				system("pause");
       }while (op!=9);      
   
     return 0;
       
}                                             
