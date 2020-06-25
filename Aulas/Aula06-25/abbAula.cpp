#include <stdio.h>
#include <stdlib.h>
//PROGRAMA:  abbAula
//arvore binaria
typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
}Arv;

//cria arvore vazia
Arv* abb_cria() {
    return NULL;
}

//verifica se a arvore est� vazia
int abb_vazia(Arv* a) {
    return a == NULL;
}

//insere elemento
Arv  *abb_insere(Arv* a,int c) {
    Arv *p,*q,*r;
    p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = p->dir = NULL;

    if (abb_vazia(a))//primeiro elemento da �rvore
        a=p;
    else {
        q=a;
        while(q!=NULL) {
            r=q;
            if(c < q->info)
                q=q->esq;
            else
                q=q->dir;
        }
        if(c < r->info)
            r->esq=p;
        else
            r->dir=p;
    }
    return a;
}

//busca elemento na arvore
Arv* abb_busca(Arv *r, int v){
    if(r==NULL) return NULL;
    if(v<r->info)
        return abb_busca(r->esq,v);
    if(v>r->info)
        return abb_busca(r->dir,v);
    return r;
}

//retira elemento
Arv* abb_retira(Arv *r, int v){
    if (r==NULL) return NULL;
    if(r->info > v) r->esq = abb_retira(r->esq, v);
    else if (r->info < v) r->dir = abb_retira(r->dir, v);
    else {
        //achou o elemento 
        if ( r->esq ==NULL && r->dir ==NULL) { // no sem filhos
            free(r);
            r=NULL;
        } else if (r->esq ==NULL) { //filho a direita            
            Arv *t = r;
            r=r->dir;
            free(t);
        } else if( r->dir ==NULL) { //filho a esquerda
            Arv *t=r;
            r=r->esq;
            free(t);
        } else { //tem 2 filhos     
            Arv *f=r->esq;
            while (f->dir != NULL)f=f->dir;
            r->info =f->info;
            f->info=v;
            r->esq=abb_retira(r->esq,v);
        }
    }
    return r;
}

void abb_posfixo(Arv* a){
    if(!abb_vazia(a)) {//travessia em pos-ordem
        abb_posfixo(a->esq); //visita a arvore esquerda, depois a direita e depois a raiz
        abb_posfixo(a->dir);
        printf("%d ", a->info);
    }
}

void abb_infixo(Arv* a){
    if(!abb_vazia(a)) {//travessia em ordem
        abb_infixo(a->esq); //visita a arvore esquerda, depois a raiz e depois a arvore direita
        printf("%d ", a->info);
        abb_infixo(a->dir);
    }
}

void abb_pares(Arv* t){
    if(t != NULL) {//travessia em ordem
        abb_pares(t->esq); //visita a arvore esquerda, depois a raiz e depois a arvore direita
        if((t->info % 2) == 0) printf("%d ", t->info);
        abb_pares(t->dir);
    }
}

void abb_folhas(Arv* t){
    if(t != NULL) {//travessia em ordem
        abb_folhas(t->esq); //visita a arvore esquerda, depois a raiz e depois a arvore direita
        if((t->esq == NULL) && (t->dir == NULL)) printf("%d ", t->info);
        abb_folhas(t->dir);
    }
}

void abb_prefixo(Arv* a){
    if(!abb_vazia(a)) {//travessia em preordem
        printf("%d ", a->info);
        abb_prefixo(a->esq); //visita a arvore raiz, depois a esquerda, depois a direita
        abb_prefixo(a->dir);
    }
}

int contaNos(Arv *t) { //numero de nodos da arvore
    int tot = 0;
    if (t != NULL) {
        tot++; //pre-ordem
        tot += contaNos(t->esq);
        tot += contaNos(t->dir);
    }
    return tot;
}

int somaNos(Arv *t) { //numero de nodos da arvore
    int tot = 0;
    if (t != NULL) {
        tot += t->info; //pre-ordem
        tot += somaNos(t->esq);
        tot += somaNos(t->dir);
    }
    return tot;
}

//altura da arvore
int max2 (int a, int b){
    return (a>b)?a:b; //if ternario
}

int abb_altura(Arv *a){
    if (abb_vazia(a))
        return -1;
    return 1+ max2(abb_altura(a->esq),abb_altura(a->dir));
}

//-------------------------------------------------------

main() {
    int num;
    Arv *a=abb_cria(), *aux; //aux = ponteiro auxiliar para busca
    //insere elementos na abb at� que um valor negativo seja digitado
    do{
        printf("Entre com o valor a ser inserido, ou -1 para finalizar:\n");
        scanf("%d", &num);
        if(num>=0)
            a=abb_insere(a,num);
    }while(num>=0);
    printf("\n\nPercurso em ordem\n");
    abb_infixo(a); //imprime em ordem
    printf("\n\nNos pares\n");
    abb_pares(a); //imprime em ordem
    printf("\n\nPercurso em pre-ordem\n");
    abb_prefixo(a); //imprime em pre-ordem
    printf("\n\nPercurso em pos-ordem\n");
    abb_posfixo(a); //imprime em pos-ordem
    printf("\n\nNos folha\n");
    abb_folhas(a); //imprime em pos-ordem
    printf("\n\nAltura da arvore = %d",abb_altura(a));
    printf("\n\nNumero de nos da arvore = %d",contaNos(a));
    printf("\n\nSoma dos nos da arvore = %d",somaNos(a));
    do {
        printf("\n\nQual elemento: ");
        scanf("%d", &num);
        aux = abb_busca(a, num);
        if (aux == NULL) printf("\n%d nao encontrado\n", num);
        else {
            printf("\nEncontrado: %d\n", num);
            if (aux->esq != NULL) printf("\tEsquerda: %d\n", aux->esq->info);
            else printf("\tNao tem esquerda\n");
            if (aux->dir != NULL) printf("\tDireita: %d\n", aux->dir->info);
            else printf("\tNao tem direita\n");
        }
    } while (num != -1);

    printf("\n\n----------------------------------------------\n");
    system("pause");
}
