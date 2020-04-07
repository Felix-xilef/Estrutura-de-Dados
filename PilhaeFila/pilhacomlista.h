typedef struct lista {
   float info;
   lista *prox;
}Lista;

typedef struct pilha {
   Lista *topo;
}Pilha;

Pilha *pilha_cria(void){
      Pilha *p= (Pilha*) malloc(sizeof(Pilha));
      p->topo=NULL;
      return p;
}

void pilha_push(Pilha *p, float v) {
     Lista *n = (Lista*) malloc (sizeof(Lista));
     n->info=v;
     n->prox =p->topo;
     p->topo=n;
}

int pilha_vazia(Pilha *p) {
    return (p->topo==NULL);
}

float pilha_pop(Pilha *p){
      Lista *t;
      float v;
      t=p->topo;
      v=t->info;
      p->topo=t->prox;
      free(t);
      return v;
}

void pilha_mostra(Pilha *p) {
     Lista *q;
     printf("\nPilha\n");
     for(q=p->topo;q!=NULL;q=q->prox)
        printf("%.0f\n", q->info);
     printf("\n");
      
}

void pilha_libera(Pilha *p){
     Lista *q= p->topo;
     while (q!=NULL) {
           Lista *t=q->prox;
           free(q);
           q=t;
           }
     free(p);
}          

                                    
