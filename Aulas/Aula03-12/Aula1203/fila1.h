#define N 5
//typedef diferenciado
typedef struct fila{
        float *vet;//ponteiro para o vetor
        int tamVetor;//tamanho do vetor
        int ini;
        int fim;
        }Fila;

Fila *fila_cria(){
      Fila *f=(Fila*)malloc(sizeof(Fila));
      f->ini=0;
      f->fim=0; 
      f->tamVetor=N;
      f->vet=(float*)malloc(sizeof(Fila)*f->tamVetor);
      return f;
} 
int fila_vazia(Fila *f){
    if(f->fim==f->ini) return 1;
	return 0; }
	
void compacta(Fila*f){//compactação só quando necessário
  int i;
  for (i=0;i<f->fim;i++)
      f->vet[i]=f->vet[i+f->ini];
 
  f->fim = (f->fim)-(f->ini);
  f->ini=0; 
}

void fila_insere (Fila *f, float v) {
	int tamFila=(f->fim )-(f->ini);
    if(f->fim==f->tamVetor){ //fila cheia?
       if(tamFila < f->tamVetor){//falso fila cheia
         compacta(f);
         
      }
       else{
	   	  printf("Capacidade da fila esgotada.\n");
      	  return; //retorna ao programa 
       }   //insere novo elemento
   }
   f->vet[f->fim]=v;
   f->fim++; 
}
float fila_retira(Fila *f){
     float v;
    //retira o elemento da fila
    v=f->vet[f->ini];
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
     for(i=f->ini;i<f->fim;i++)
              printf("%.0f\n",f->vet[i]);
     printf("\n");
} 

