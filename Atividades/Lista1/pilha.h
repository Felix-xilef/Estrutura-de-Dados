#define N 50

typedef struct pilha{
    int topo;
    float vet[N];
}Pilha;

Pilha *pilha_cria(){
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
    p->topo=0;
    return p;
}

int pilha_vazia(Pilha *p){
    if (p->topo==0) return 1;
    else  return 0;
}

void pilha_insere(Pilha *p, float v) {
    if (p->topo==N) {
      printf("Capacidade da pilha esgotada.\n");
      return; //volta para o programa
    } //insere novo elemento
    p->vet[p->topo]=v;
    p->topo++; 
}

float pilha_retira(Pilha *p){
    float v;
    //retira o elemento da pilha
    v=p->vet[p->topo-1];  
    p->topo--;
    return v;
}

void pilha_libera(Pilha *p){
    free(p);
}

void mostra_pilha(Pilha *p) {
    printf("Conteudo da pilha\n");
    for(int i=p->topo-1;i>=0;i--)
        printf("%.0f\n",p->vet[i]);
    printf("\n");
}