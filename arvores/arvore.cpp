#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
	int info;
	struct arv *esq;
	struct arv *dir;
}Arv;

Arv *abb_cria(){//inicializa a arvore
	return NULL;
}
int abb_vazia(Arv *a){
	return(a==NULL);
}
Arv* abb_insere(Arv *a, int v){
    if (a==NULL){
       a=(Arv*) malloc(sizeof(Arv));
		a->info=v;
		a->esq=a->dir=NULL;
     } 
     else if (v< a->info)
                   a->esq=abb_insere(a->esq,v);
             else    
                   a->dir=abb_insere(a->dir,v);
     return a;
} 
// percurso em ordem  esq – raiz - dir
void abb_mostraEmOrdem(Arv *a){
    if (a!=NULL){
       abb_mostraEmOrdem(a->esq);
       printf("%d\t", a->info);
	   abb_mostraEmOrdem(a->dir); 	
	} 
}
// percurso em ordem  raiz - esq - dir
void abb_mostraPreOrdem(Arv *a){
    if (a!=NULL){
       printf("%d\t", a->info);
	   abb_mostraPreOrdem(a->esq);
       abb_mostraPreOrdem(a->dir); 	
	} 
}
// percurso em ordem  esq - dir - raiz
void abb_mostraPosOrdem(Arv *a){
    if (a!=NULL){
       abb_mostraPosOrdem(a->esq);
       abb_mostraPosOrdem(a->dir); 
	   printf("%d\t", a->info);	
	} 
}
//altura da arvore
int max2 (int a, int b){
       return (a>b)?a:b;
}       

int abb_altura(Arv *a){
       if (abb_vazia(a))
           return -1;
       return 1+ max2(abb_altura(a->esq),abb_altura(a->dir));   
}     
/*int contaNos(Arv *a){
	int c=0;
	if(a!=NULL){
		c=c+1;
		c=c+contaNos(a->esq);
		c=c+contaNos(a->dir);
	}
	return c;
} */
int contaNos(Arv *a){
	if(a==NULL)return 0;
	return 1+contaNos(a->esq)+contaNos(a->dir);
	
}        
//-----------------------------------------------
int main() {
  int num;
  Arv *a=abb_cria();
  int v;
  //insere elementos na abb até que um -1 seja digitado
  do{
     printf("Entre com o valor a ser inserido, ou -1 para finalizar:\n");
     scanf("%d", &num);
     if(num>=0)
           a=abb_insere(a,num);
     }while(num>=0);
     
   printf("\nPercurso em Ordem\n");
   abb_mostraEmOrdem(a); //imprime em ordem
   printf("\n\nPercurso em Pre Ordem\n");
   abb_mostraPreOrdem(a); //imprime em pre-ordem
   printf("\n\nPercurso em Pos Ordem\n");
   abb_mostraPosOrdem(a); //imprime em pre-ordem
   printf("\n\nAltura: %d\n",abb_altura(a));
   printf("\n\nNumero de nos: %d\n",contaNos(a));
   printf("\n\n");
   return 0;
}                                                                                        

