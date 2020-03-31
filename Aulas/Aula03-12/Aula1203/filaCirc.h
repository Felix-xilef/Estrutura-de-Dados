#define N 5
typedef struct fila{
        float *vet;//ponteiro para o vetor
        int tamVetor;//tamanho do vetor
        int tamFila;//tamanho da fila
        int ini;
        int fim;
        }Fila;

Fila *fila_cria(){
      Fila *f=(Fila*)malloc(sizeof(Fila));
      f->ini=0;
      f->fim=0; 
      f->tamFila=0;
      f->tamVetor=N;
      f->vet=(float*)malloc(sizeof(Fila)*f->tamVetor);
      return f;
} 
int fila_vazia(Fila *f){
    if(f->tamFila==0) return 1;
	return 0; }
	
void fila_insere (Fila *f, float v) {
	if (f->tamFila==f->tamVetor){//não cabe
		  printf("Capacidade da fila esgotada.\n");
      	  return; //retorna ao programa 
    }
    if(f->fim==f->tamVetor){ //ultima posição já esta ocupada?
        //usa  a circularidade
         f->fim=0;
       
    }

   f->vet[f->fim]=v;
   f->fim++; 
   f->tamFila++;
}
float fila_retira(Fila *f){
     float v;
    //retira o elemento da fila
    
	v=f->vet[f->ini];
	f->tamFila--;
	if( f->ini == f->tamVetor-1)
	    f->ini=0;
	else
    	f->ini++;
    return v;
}
void fila_libera(Fila *f){
     free(f->vet);
     free(f);
}                           
void mostra_fila(Fila *f){
     printf("Conteudo da fila\n");
     int i;
     //a fila não circulou
     if(f->ini < f->fim){	 
     	for(i=f->ini;i<f->fim;i++)
              printf("%.0f\n",f->vet[i]);
     }
     else{//a fila circulou
         for(i=f->ini;i<f->tamVetor;i++)
     	 	printf("%.0f\n",f->vet[i]);
     	 for(i=0; i< f->fim;i++)
     	    printf("%.0f\n",f->vet[i]);
     }
	 printf("\n");
} 

