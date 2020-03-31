#define N 50

typedef struct fila {
    int tamVetor;
    int ini;
    int fim;
    float *vet;
}Fila;

Fila *fila_cria() {
    Fila *f=(Fila*)malloc(sizeof(Fila));
    f->tamVetor = N;
    f->ini = 0;
    f->fim = 0;
    f->vet = (float*)malloc(N*sizeof(float));
    return f;
}

int fila_vazia(Fila *f) {
    if(f->fim == f->ini) return 1;
    return 0;
}

void compacta(Fila *f) { //compactação a cada retirada
    int tamFila = (f->fim) - (f->ini);
    for (int i = 0; i < tamFila; i++) //ou: for (int i=0;i<f->fim;i++)
        f->vet[i] = f->vet[f->ini + i];
    f->fim = tamFila;
    f->ini = 0;
}

void fila_insere (Fila *f, float v) {
    if (f->fim == f->tamVetor) {
        if (f->ini == 0) {
            printf("Capacidade da fila esgotada.\n");
            return;
        } else {
            compacta(f);
        }
    }
    f->vet[f->fim] = v;
    f->fim++;
}

float fila_retira(Fila *f) {
    float v;
    //retira o elemento da fila
    v=f->vet[f->ini];
    f->ini++;
    return v;
}

void fila_libera(Fila *f) {
    free(f->vet);
    free(f);
}

void mostra_fila(Fila *f) {
    printf("Conteudo da fila\n");
    for(int i = f->ini; i < f->fim; i++)
        printf("%.0f\n", f->vet[i]);
    printf("\n");
}