
//lista simplesmente encadeada
typedef struct lista {
     int info;
     struct lista* prox;
}Lista;

Lista* lista_cria() {
     return NULL;
}

int lista_vazia(Lista* l){
     return(l==NULL);
}

Lista* lista_busca(Lista* l, int dado) {
     Lista *a; //vari�vel usada para percorrer a lista
     for(a=l;a!=NULL;a=a->prox)
          if(a->info == dado) return a;
     return NULL;
}

Lista* lista_insere( Lista* l, int dado) { //insere no inicio
     Lista *novo= (Lista*) malloc (sizeof(Lista));
     novo->info=dado;
     novo->prox=l;
     return novo;
}

void lista_mostra(Lista* l) {
     Lista *aux; //vari�vel usada para percorrer a lista
     for(aux=l;aux!=NULL;aux=aux->prox)
          printf("%d\t", aux->info);
     printf("\n");
}
  
Lista* lista_retira(Lista* l, int dado){
     Lista* ant=NULL; //ponteiro para o anterior
     Lista *aux=l; // ponteiro para percorrer a lista
     //procura o elemento na lista guardando seu anterior
     while(aux!=NULL && aux->info!=dado) {
          ant=aux;
          aux=aux->prox;
     }
     //verifica se achou o elemento
     if(aux==NULL) {
          printf("\nNAO localizado\n");
          return l; //n�o achou - retorna a lista
     }
     //retira o elemento
     if (ant==NULL) //primeiro da lista
          l=aux->prox;
     else //retira do meio da lista
          ant->prox=aux->prox;
     free(aux);
     return l;
}

//Opcionalmente pode-se inserir na lista de forma ordenada
Lista* lista_ordenada(Lista* l, int v) {
     Lista* novo;
     Lista* ant=NULL;
     Lista* p=l;
     
     //cria novo elemento
     novo=(Lista*)malloc(sizeof(Lista));
     novo->info=v;

     //procura posi��o de inser��o
     while (p!=NULL && p->info < v)  {
          ant=p;
          p=p->prox;
     }
     //encadeia o elemento
     if(ant==NULL) { //insere no inicio
          novo->prox=l;
          l=novo;
     } else { //insere no meio ou no fim da lista
          novo->prox=ant->prox;
          ant->prox=novo;
     }
     return l;
}

void lista_libera(Lista *l){
     Lista *p,*t;
     p=l;
     while(p!=NULL) {
          t=p->prox;
          free(p);
          p=t;
     }
}
