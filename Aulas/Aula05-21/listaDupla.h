typedef struct lista2 {
    int info;
    lista2* ant;
    lista2* prox;
}Lista2;

void lista_primeiro_e_ultimo(Lista2 *l){
    Lista2 *aux;
    for (aux = l; aux->ant != NULL; aux = aux->ant);
    printf("\nPrimeiro elemento: %d\n", aux->info);
    for (aux = l; aux->prox != NULL; aux = aux->prox);
    printf("Ultimo elemento: %d\n", aux->info);
}

void lista_maior_e_menor(Lista2 *l){
    Lista2 *aux;
    int maior = l->info, menor = l->info;
    for (aux = l; aux->ant != NULL; aux = aux->ant);
    for (; aux != NULL; aux = aux->prox){
        if (aux->info > maior)
            maior = aux->info;
        if (aux->info < menor)
            menor = aux->info;
    }
    printf("\nMaior: %d\nMenor: %d\n", maior, menor);
}

Lista2* lista_cria() {
    return NULL;
}

int lista_vazia(Lista2* lst) {
    if(lst==NULL) return 1;
    return 0;
}

Lista2* lista_busca(Lista2* lst, int dado) {
    Lista2 *a; //vari�vel usada para percorrer a lista
    for(a=lst;a!=NULL;a=a->prox) {
        if(a->info == dado) return a;
    }
    return NULL;//retorna NULL se n�o encontrou
}
    
//insere novos elementos no inicio da lista
Lista2* lista_insere( Lista2* lst, int dado) {
    Lista2 *novo= (Lista2*) malloc (sizeof(Lista2));
    novo->info=dado;
    novo->prox=lst;
    novo->ant=NULL;
    //verifica se a lista n�o esta vazia
    if(lst!= NULL)
        lst->ant=novo;
    return novo;
}

Lista2* lista_ordenada(Lista2* lst, int v) {
    Lista2* novo;
    Lista2* anterior=NULL;
    Lista2* p=lst;
    //cria novo elemento
    novo=(Lista2*)malloc(sizeof(Lista2));
    novo->info=v;
    //procura posi��o de inser��o
    while (p!=NULL && p->info < v) {
        anterior=p;
        p=p->prox;
    }
    //encadeia o elemento
    if(anterior==NULL) { //insere no inicio
        if(lst!=NULL)
            lst->ant=novo;
        novo->prox=lst;
        novo->ant=NULL;
        lst=novo;
    } else { //insere no meio ou no fim da lista
        novo->prox=anterior->prox;
        novo->ant=anterior;
        if (anterior->prox!=NULL)
            anterior->prox->ant=novo;
        anterior->prox=novo;
    }
    return lst;
}

void lista_mostra(Lista2* lst) {
    Lista2 *aux; //vari�vel usada para percorrer a lista
    for(aux=lst;aux!=NULL;aux=aux->prox)
        printf("%d\t", aux->info);
    printf("\n");
}

Lista2* lista_retira(Lista2* lst, int dado) {
    //procura o elemento na lista usando a fun��o busca
    Lista2* aux=lista_busca(lst, dado);
    if (aux==NULL) //n�o achou o elemento
        return lst;
    //retira o elemento encadeado
    if(lst==aux) { //verifica se � o primeiro da lista
        // aux->prox->ant=aux->ant;
        lst=aux->prox;
    } else {
        aux->ant->prox=aux->prox;
    }
    //testa para ver se � o ultimo da lista
    if (aux->prox!=NULL)
        aux->prox->ant=aux->ant;
    printf("\nElemento retirado: %d\n",aux->info);
    free(aux);
    return lst;
}

void lista_libera(Lista2 *lst) {
    Lista2 *p,*t;
    p=lst;
    while(p!=NULL) {
        t=p->prox;
        free(p);
        p=t;
    }
}
