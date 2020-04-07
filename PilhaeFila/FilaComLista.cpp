#include <stdio.h>
#include <stdlib.h>
#include "FilaComLista.h"

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Insere\n");       
     printf("2. Retira \n");
     printf("3. Mostra a fila\n");
     printf("9. Fim\n");
     printf("==> ");
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
          mostra_fila(fi);  break;                   
   }//switch
   printf("\n");
   system("pause"); 
 } while(opmenu!=4);
   fila_libera(fi);
}
