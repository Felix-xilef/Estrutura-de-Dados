#define N 50

typedef struct fila {
    int n;
    int ini;
    float vet[N];
}Fila;

Fila *fila_cria() {
    Fila *f=(Fila*)malloc(sizeof(Fila));
    f->n=0;
    f->ini=0; 
    return f;
}

int fila_vazia(Fila *f) {
    if(f->n==f->ini) return 1;
    return 0;
}

void fila_insere (Fila *f, float v) {
    if (f->n == N) { //fila cheia
        printf("Capacidade da fila esgotada.\n");
        return; //retorna ao programa 
    }   //insere novo elemento
    f->vet[f->n]=v;
    f->n++; 
}

void compacta(Fila *f) { //compactação a cada retirada
    for (int i = 0; i < f->n; i++)
        f->vet[i] = f->vet[i+1];
    f->n--;
}

float fila_retira(Fila *f) {
    float v;
    //retira o elemento da fila
    v=f->vet[f->ini];
    //f->ini++; - fila burra
    compacta(f);
    return v;
}

void fila_libera(Fila *f) {
    free(f);
}

void mostra_fila(Fila *f) {
    printf("Conteudo da fila\n");
    for(int i = f->ini; i < f->n; i++)
        printf("%.0f\n", f->vet[i]);
    printf("\n");
}