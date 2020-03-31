#include <stdio.h>
#include <stdlib.h>
//#include "fila.h"
//#include "fila1.h"//compactação inteligente
#include "filaCirc.h"
//-------------------------------------------------------              
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Enfileira\n");       
     printf("2. Retira \n");
     printf("3. Mostra a fila\n");
     printf("4. Conta elementos\n");//int conta(Fila *f)
   // printf("5. Soma elementos\n");//float conta(Fila *f)
   // printf("6. Mostra inicio\n");//void inicio(Fila *f)
   // printf("7. Mostra final\n");//void final(Fila *f)
     printf("8. Replica fila\n");//void replica(Fila *f)
     printf("9. Fim\n");
}    
//---------------------------------------------- 
int conta (Fila *f){
	Fila *aux=fila_cria();//fila auxiliar para manejo
	int cont=0;
	//esvaziar a fila original na fila aux para contar
	while(!fila_vazia(f)){//enquanto a fila f não estiver vazia
		fila_insere(aux,fila_retira(f));
		cont++;
	}
	//restaura a fila original
	while(!fila_vazia(aux))
	   fila_insere(f,fila_retira(aux));
	fila_libera(aux);
	return cont;
}
//----------------------------------------------------------
void replica(Fila *f){//repete os elementos de f em f
	Fila *a1=fila_cria();
	Fila *a2=fila_cria();
	float x;
	while(!fila_vazia(f)){
		x=fila_retira(f);
		fila_insere(a1,x);
		fila_insere(a2,x);
	}
	while(!fila_vazia(a1))
	     fila_insere(f,fila_retira(a1));
	fila_libera(a1);
	while(!fila_vazia(a2))
	    fila_insere(f,fila_retira(a2));
	fila_libera(a2);
}
//---------------------------------------------------
main(){
 Fila *fi=fila_cria();
 int opmenu;
 float item;
 do{
    menu(); 
    scanf("%d", &opmenu);
    switch (opmenu){
    case 1 : //insere
          printf("Digite o valor a ser enfileirado: ");
          scanf("%f", &item);
          fila_insere(fi,item); break;
    case 2 : //retira
          if(fila_vazia(fi)) 
              printf("fila vazia.\n");
          else
              printf("Elemento retirado = %.0f\n",fila_retira(fi));
          break;    
    case 3 : //mostra
          mostra_fila(fi);
		  break; 
	case 4://conta elementos
			printf("Numero de elementos: %d\n",conta(fi))	;
			break;  
	case 8://replica
	        replica(fi);
	        mostra_fila(fi);
	        break;
		                   
   }//switch
   printf("\n");
   system("pause"); 
 } while(opmenu!=9);
}

