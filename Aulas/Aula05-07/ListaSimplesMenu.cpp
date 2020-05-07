#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//programa principal
void menu() {
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("------------------------------------\n");
     //printf("1. Insere na lista\n");
     printf("2. Retira da lista\n");
     printf("3. Mostra a lista\n");
     printf("4. Busca item na lista\n");
     printf("5. Conta elementos\n"); //int conta(Lista *L)
     printf("6. Insere sem repetir\n"); //Lista *lista_semRepetir(Lista *li, int v)
     printf("7. Dobra elementos da lista em outra\n"); //Lista *lista_dobra(Lista *li)
     printf("8. Duplica lista\n"); //Lista lista_duplica(Lista *li)
     printf("9. Fim\n");
     printf("==> ");
}

int conta(Lista *L) {
     Lista *a;
     int qtd = 0;
     for (a = L; a != NULL; a = a->prox)
          qtd++;
     return qtd;
}

Lista *lista_semRepetir(Lista *li, int v) {
     if (lista_busca(li, v) == NULL)
          li = lista_ordenada(li, v);
     else
          printf("\nDado repetido!\n");
     return li;
}

Lista *lista_dobra(Lista *li) {
     Lista *a, *d = lista_cria();
     for (a = li; a != NULL ; a = a->prox) {
          d = lista_ordenada(d, a->info * 2);
     }
     return d;
}

Lista *lista_duplica(Lista *li) {
     Lista *d = lista_cria(), *aux;
     for (aux = li; aux != NULL; aux = aux->prox)
          d = lista_insere(d, aux->info);
     for (aux = li; d != NULL; d = d->prox)
          aux = lista_insere(aux, d->info);
     return aux;
}

main(){
     int opmenu, item;
     Lista *li=lista_cria();
     Lista *aux;//ponteiro auxiliar - necess�rio para a busca
     do{
          menu();
          scanf("%d",&opmenu);
          switch(opmenu){
               case 1: //inserir
                    printf("Informe o item que deseja adicionar: ");
                    scanf("%d",&item);
                    li=lista_ordenada(li,item);
               case 2: //retirar
                    printf("Informe o item que deseja retirar: ");
                    scanf("%d",&item);
                    li=lista_retira(li,item); 
                    break;
               case 3: //mostrar
          	     if(lista_vazia(li))
          	          printf("Lista vazia\n");
          	     else {
          	      	printf("Lista: ");
          	          lista_mostra(li);
          	     }
                    break;
               case 4: //procurar
                    printf("Informe o item que deseja procurar: ");
                    scanf("%d",&item);
                    //ponteiro auxiliar para n�o perder a referencia
                    //da lista
                    aux=lista_busca(li,item); 
                    if(aux==NULL)
                         printf("\nItem %d nao localizado na lista\n",item);
                    else
                         printf("\nItem %d localizado\n",aux->info);
                    break;
               case 5: //conta
                    printf("\nA lista possui %d elemento(s)\n", conta(li));
                    break;
               case 6: //insere sem repetir
                    printf("Informe o item que deseja adicionar: ");
                    scanf("%d",&item);
                    li = lista_semRepetir(li, item);
                    break;
               case 7: //mostra elementos dobrados
          	     if(lista_vazia(li))
          	          printf("Lista vazia\n");
          	     else {
                         printf("Lista dobrada: ");
                         aux = lista_dobra(li);
          	          lista_mostra(aux);
          	     }
                    break;
               case 8: //mostra elementos duplicados
          	     if(lista_vazia(li))
          	          printf("Lista vazia\n");
          	     else {
                         printf("Lista duplicada: ");
                         aux = lista_duplica(li);
          	          lista_mostra(aux);
          	     }
                    break;
          } //fim switch
          printf("\n");
          system("pause");
     } while(opmenu!=9);
     lista_libera(li);
}
