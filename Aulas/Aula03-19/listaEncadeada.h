typedef struct lista {
    int info; //valor do elemento
    struct lista *prox; //endereço do proximo elemento
}Lista; //definição da lista

/* retorna uma lista vazia - Pois a criação é feita em cada elemento, isto é, na inserção*/
Lista * lista_cria() {
    return NULL;
}

/* insere o novo dado no início da lista , e retorna a lista atualizada*/
Lista * lista_insere(Lista *li, int dado) {
    Lista *novo = (Lista*) malloc (sizeof(Lista)); //criação do novo elemento
    novo->info = dado; //recebe o valor do novo elemento
    novo->prox = li; //recebe o endereço do proximo elemento
    return novo;
}

/* retorna 1 se vazia ou zero se falso*/
int lista_vazia(Lista* li) {
    return (li==NULL); //retorna o resultado da comparação de l com NULL
}

/* retorna o elemento ou NULL se não achou*/
Lista* lista_busca(Lista* li, int dado) {
    Lista *a; //variável usada para percorrer a lista
    for(a = li; a != NULL; a = a->prox) {
        if (a->info == dado)
            return a;
    }
    return NULL;
}

/* retorna o elemento ou a lista original*/
Lista* lista_retira(Lista* li, int dado) {
    Lista* ant = NULL; //ponteiro para o anterior
    Lista *aux = li; //ponteiro para percorrer a lista
    while (aux != NULL && aux->info != dado) { //procura o elemento na lista guardando seu anterior
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL) { //verifica se achou o elemento
        printf("\nNao localizado\n");
        return li; //não achou - retorna a lista
    }
    //retira o elemento
    if (ant==NULL) //primeiro da lista
        li=aux->prox;
    else //retira do meio/fim da lista
        ant->prox = aux->prox;
    free(aux);
    // ?free(ant);
    return li;
}

Lista* lista_ordenada(Lista* li, int v) {
    Lista* ant = NULL;
    Lista* p = li;
    //cria novo elemento
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    //procura posição de inserção
    while (p != NULL && p->info < v) {
        ant = p;
        p = p->prox;
    }     
    //encadeia o elemento
    if (ant == NULL) { //insere no inicio  
        novo->prox = li;
        li = novo;
    } else { //insere no meio ou no fim da lista
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return li;
}        

void lista_libera(Lista *li) {
    Lista *p, *t;
    p = li;
    while (p != NULL) {
        t = p->prox;
        free(p); //libera um item por vez
        p = t;
    }
}

/* percorre a lista do inicio até o fim mostrando os elementos*/
void lista_mostra(Lista* li) {
    Lista *aux; //variável usada para percorrer a lista
    for(aux = li; aux != NULL; aux = aux->prox)
        printf("%d\t", aux->info);
}

int conta(Lista *l) {
    Lista *aux;
    int cont = 0;
    for(aux = l; aux != NULL; aux = aux->prox)
        cont++;
    return cont;
}

int soma(Lista *l) {
    Lista *aux;
    int soma = 0;
    for (aux = l; aux != NULL; aux = aux->prox)
        soma += aux->info;
    return soma;
}

void inicio(Lista *l) {
    Lista *aux = l;
    int ini = aux->info;
    printf("Inicio da lista = %d\n", ini);
}

void final(Lista *l) {
    Lista *aux;
    for (aux = l; aux->prox != NULL; aux = aux->prox);
    printf("Final da lista = %d\n", aux->info);
}

Lista *replica(Lista *l) {
    Lista *aux = l, *aux2;
    int qtd = conta(l);
    for (int i = 0; i < qtd; i++, aux = aux->prox)
        aux2 = lista_insere(aux2, aux->info);
    for (int i = 0; i < qtd; i++, aux2 = aux2->prox)
        l = lista_insere(l, aux2->info);
    printf("Fila replicada:\n");
    lista_mostra(l);
    return l;
}