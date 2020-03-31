#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
void empilha_pilhas(Pilha *p1, Pilha *p2){
	Pilha *a;//pilha auxiliar
	a=pilha_cria();
	float v;
	//tira da pilha p2 e coloca em a
	while(!pilha_vazia(p2)){
	    v=pilha_pop(p2);
		pilha_push(a,v);
	}
	//restaura a pilha p2 colocando simultaneamente em p1
	while(!pilha_vazia(a)){
		v=pilha_pop(a);
		pilha_push(p1,v);
		pilha_push(p2,v);
	}
	pilha_libera(a);
}
Pilha *soma_pilhas(Pilha *p, Pilha *q){
	
}
main(){     
      Pilha *p1=pilha_cria();
      Pilha *p2=pilha_cria();
      Pilha *p3;
      //insere na pilha p1
      pilha_push(p1,10);
      pilha_push(p1,20);
      pilha_push(p1,30);
        pilha_push(p1,40);
       //insere na pilha p2
      pilha_push(p2,1);
      pilha_push(p2,2);
     // pilha_push(p2,3);
      //empilha pilhas
      //empilha_pilhas(p1,p2);
      p3=soma_pilhas(p1,p2);
      //mostra o conteudo das pilhas
      printf("***P1***\n");
      mostra_pilha(p1);
      printf("***\nP2***\n");
      mostra_pilha(p2);
  }
      

