#include <stdio.h>
#include <stdlib.h>
#include <time.h> //ex 3, 4 e 5

typedef struct lista{ //ex 4
    int info;
    struct lista *prox;
}Lista;

void imprimeVetor(int v[], int tam) { //ex 3 e 5
    for (int i = 0; i < tam; i++)
        printf("%d\t", v[i]);

    printf("\n\n");
}

//Ex 1
int soma(int a, int b) {
    if (a == b) return b;
    return a + soma(a + 1, b);
}
//Fim

//Ex 2
double juroscompostos(double valor, double taxa, int meses) {
    if (meses == 0) return 0;
    return ((taxa + 1) * (valor + juroscompostos(valor, taxa, meses - 1))) - valor;
}
//Fim

//Ex 3
int buscavetor (int *vet, int tam, int valor) {
    if (tam == 0) return -1;
    if (*vet == valor) return 0;
    int p = buscavetor(vet + 1, tam - 1, valor);
    if (p == -1) return p;
    return p + 1;
}
//Fim

//Ex 4
void buscalista (Lista *l, int valor) {
    if (l == NULL) printf("Valor nao encontrado\n\n");
    else if (l->info == valor) printf("Valor %d encontrado\n\n", l->info);
    else buscalista(l->prox, valor);
}
//Fim

//Ex 5
void bolha_rec (int *vet, int tam) {
    if (tam == 0) return;
    int nAux, *pAux = vet;
    for (int i = 0; i < tam - 1; i++, pAux++) {
        if (*pAux > *(pAux + 1)) {
            nAux = *pAux;
            *pAux = *(pAux + 1);
            *(pAux + 1) = nAux;
        }
    }
    free(pAux);
    bolha_rec(vet, tam - 1);
}
//Fim

main() {

    //ex 1
    /*int val1, val2;
    printf("Soma entre dos valores entre ");
    scanf("%d", &val1);
    printf(" e ");
    scanf("%d", &val2);
    printf(" = %d\n", soma(val1, val2));*/

    //ex 2
    /*double val, taxa;
    int meses;
    printf("Valor em R$ ");
    scanf("%lf", &val);
    printf("Taxa de juros >> ");
    scanf("%lf", &taxa);
    printf("Quantidade de meses >>");
    scanf("%d", &meses);
    printf("\n- Juros compostos do valor de R$ %.2lf apos %d mes(es) a uma taxa de %.4lf:\n\tR$ %.2lf\n\n", val, meses, taxa, juroscompostos(val, taxa, meses));*/

    //ex 3
    /*srand((unsigned)time(NULL));
    int aux, tam = (rand() % 30) + 1;
    int vet[tam];
    for (int i = 0; i < tam; i++) {
        vet[i] = (rand() % 30) + 1;
    }
    imprimeVetor(vet, tam);
    printf("\n\nValor a ser procurado no vetor >> ");
    scanf("%d", &aux);
    printf("\nPosicao (-1 -> nao encontrado): %d\n\n", buscavetor(vet, tam, aux));*/

    //ex 4
    /*srand((unsigned)time(NULL));
    int aux, tam = (rand() % 20) + 1;
    Lista *l = NULL;
    for (int i = 0; i < tam; i++) {
        Lista *novo = (Lista*) malloc (sizeof(Lista));
        novo->info = (rand() % 30) + 1;
        novo->prox = l;
        l = novo;
        printf("%d\t", l->info);
    }
    printf("\n\nValor a ser procurado na lista SE >> ");
    scanf("%d", &aux);
    buscalista(l, aux);*/

    //ex 5
    /*srand((unsigned)time(NULL));
    int tam = (rand() % 10) + 1;
    int vet[tam];
    for (int i = 0; i < tam; i++) {
        vet[i] = (rand() % 30) + 1;
    }
    printf("Vetor original:\n");
    imprimeVetor(vet, tam);
    printf("Vetor ordenado:\n");
    bolha_rec(vet, tam);
    imprimeVetor(vet, tam);*/

    system("pause");
}