#define N 50

typedef struct fila {
    int *Vetor;
    int tamVetor;
    int inicio;   /* indexa o início da Fila */
    int fim;      /*indexa o final da Fila */
    int tamFila;  /* testes de vazia/cheia */
}Fila;

Fila *fila_cria() {
    Fila *f=(Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->tamVetor = N;
    f->tamFila = 0;
    f->Vetor = (int*)malloc(N*sizeof(float));
    return f;
}

int fila_vazia(Fila *f) {
    if(f->tamFila == 0) return 1;
    return 0;
}

void fila_insere (Fila *f, float v) {
    if (f->tamFila == f->tamVetor) { //fila cheia
        printf("Capacidade da fila esgotada.\n");
        return; //retorna ao programa 
    }   //insere novo elemento
    if (f->fim == f->tamVetor)
        f->fim = 0;
    f->Vetor[f->fim] = v;
    f->fim++;
    f->tamFila++;
}

int fila_retira(Fila *f) {
    int v;
    //retira o elemento da fila
    v=f->Vetor[f->inicio];
    if (f->inicio == f->tamVetor-1)
        f->inicio = 0;
    else
        f->inicio++;
    f->tamFila--;
    return v;
}

void fila_libera(Fila *f) {
    free(f->Vetor);
    free(f);
}

void mostra_fila(Fila *f) {
    printf("Conteudo da fila:\n");
    int i = f->inicio;
    if (f->tamFila == f->tamVetor) {   //Fila cheia
        printf("%d\n", f->Vetor[i]);
        i++;
    }
    for (; i != f->fim; i++) {
        if (i == f->tamVetor)
            i = 0;
        printf("%d\n", f->Vetor[i]);
    }
    printf("\n");
}