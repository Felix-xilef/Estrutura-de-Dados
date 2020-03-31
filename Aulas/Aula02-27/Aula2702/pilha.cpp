#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");       
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Mostra o topo\n");
     printf("5. Mostra a base\n");
     
     printf("6. Conta elementos\n");//int conta (Pilha *p)
     printf("7. Soma elementos\n");//float soma (Pilha *p)
     printf("8. Dobra elementos\n");//void dobra (Pilha *p)
     
     printf("9. Fim\n");
} 
void mostra_topo(Pilha *p){
	float x;
	x=pilha_pop(p);//retira
	printf("Topo = %.0f\n",x);
	pilha_push(p,x);//restaura
}
void mostra_base(Pilha *p){
	float x;
	Pilha *aux;//ponteiro para pilha auxiliar
	aux=pilha_cria();
	while(!pilha_vazia(p)){
		x=pilha_pop(p);
		pilha_push(aux,x);
	}
	//x contem a base
	printf("Base = %.0f\n",x);
	//restaura pilha original
	while(!pilha_vazia(aux)){
		x=pilha_pop(aux);
		pilha_push(p,x);
	}
	pilha_libera(aux);
}
int conta(Pilha *p){
	int tot=0;
	float v;
	Pilha *a=pilha_cria();//pilha auxiliar
	//esvazia a pilha original para contar
	while(!pilha_vazia(p)){
		v=pilha_pop(p);
		pilha_push(a,v);
		tot++;
	}
	//restaura a pilha original
	while(!pilha_vazia(a)){
		v=pilha_pop(a);
		pilha_push(p,v);
	}
	pilha_libera(a);
	return tot;//tem o numero de elementos
}
float soma(Pilha *p){
	float v,total=0;
	Pilha *aux=pilha_cria();
	//esvazia a pilha original para somar os elementos
	while(!pilha_vazia(p)){
		v=pilha_pop(p);
		pilha_push(aux,v);
		total=total+v;//acumula os valores da pilha
	}
	//restaura a pilha original
	while(!pilha_vazia(aux)){
		pilha_push(p,pilha_pop(aux));
	}
	//libera espaço da pilha auxiliar
	pilha_libera(aux);
	return total;
}
void dobra(Pilha *p){
	Pilha *d;
	d=pilha_cria();//pilha auxiliar
	float y;
	//esvazia a pilha original
	while(!pilha_vazia(p)){
		y=pilha_pop(p);
		pilha_push(d,2*y);//dobra cada elemento
	}
	//restaura a pilha original com os elementos dobrados
	while(!pilha_vazia(d))
	   pilha_push(p,pilha_pop(d));
	pilha_libera(d);//libera a pilha d
}
main(){     
      Pilha *pi=pilha_cria();
      int opmenu;
      float item;
      do{
         menu(); 
         scanf("%d", &opmenu);
         switch (opmenu) {
         case 1 : //insere
                printf("Digite o valor a ser empilhado: "); 
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
        case 2 : //retira
			 if(pilha_vazia(pi)) 
                    printf("Pilha Vazia\n");
                else
                 printf("Elemento retirado = %.0f\n",pilha_pop(pi));
                break;    
        case 3 : //mostra
                mostra_pilha(pi);
				break; 
		case 4://mostra o topo
		        if(pilha_vazia(pi))
				   printf("Pilha vazia\n");
				else
				  mostra_topo(pi);
				break; 
		case 5://mostra a base
		        if(pilha_vazia(pi))
				   printf("Pilha vazia\n");
				else
				  mostra_base(pi);
				break;   
		case 6: //conta elementos
		       printf("Numero de elementos: %d\n",conta(pi));
		       break;
		case 7: //soma elementos
		       printf("Soma dos elementos: %.0f\n",soma(pi));
		       break;
		case 8://dobra elementos da pilha
			   if (pilha_vazia(pi))
			      printf("Pilha vazia\n");
			    else
		       	  dobra(pi);
		       	break;
       }  //switch
       printf("\n");
	   system("pause"); 
     } while(opmenu!=9);
   } 

